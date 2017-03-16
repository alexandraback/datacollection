package com.google.codejam._2013.round1C;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.Map;


public class Consonants {
	private static final String FILES_FOLDER = "files/2013/round1/consonants/";
	private static final String DEFAULT_INPUT_FILENAME = "A-small-attempt2.in";
	private static final String OUTPUT_FILENAME = "consonants_out.txt";
	

	protected String getLogLine(int i, Object obj) {
		return "Case #" + (i+1) + ": " + obj;
	}

	public void run() throws Exception {
		InputStream in = new FileInputStream(FILES_FOLDER + inputFilename);
		InputStreamReader is = new InputStreamReader(in);
		BufferedReader reader = new BufferedReader(is);
		
		int cases = Integer.parseInt(reader.readLine());
		this.results = new Object[cases];
		
		
		for(int i=0; i<cases; i++){
			String line = reader.readLine();
			results[i] = handleTestCase(line);
			System.out.println(getLogLine(i, results[i]));
		}
		
		this.printResults();
	}


	protected int handleTestCase(String line) throws Exception {
		String[] in = line.split(" ");
		String name = in[0];
		int n = Integer.parseInt(in[1]);
		
		int result = 0;
		
		Map<Integer, Integer> seq = new HashMap<Integer, Integer>();
		
		char[] charArr = name.toCharArray();
		int start=0;
		int num = 0;
		for(int i=0; i<charArr.length; i++){
			char c = charArr[i];
			if(c == 'a' || c == 'e' || c == 'i' || c== 'o' || c == 'u'){
				num=0;
			}else {
				if(num==0) start=i;
				num++;
				if(num >= n){
					seq.put(start, i);
					start++;
					num--;
				}
			}
		}
		
		for(int i=0; i<name.length(); i++){
			for(int j=i+n; j<=name.length(); j++){
				String s = name.substring(i, j);
				for(Map.Entry<Integer, Integer> e : seq.entrySet()){
					int st = e.getKey();
					int end = e.getValue();
					
					if(i<= st && j>end){						
						result++;
						break;
					}
				}
			}
		}
		
		
		return result;
	}

	
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		Consonants a = new Consonants();
		a.run();
	}

	private String inputFilename;

	private Object[] results;
	
	public Consonants() {
		this.inputFilename = DEFAULT_INPUT_FILENAME;
	}
	
	
	public void setInputFilename(String inputFilename) {
		this.inputFilename = inputFilename;
	}


	
	protected void printResults() throws IOException {
		OutputStream out = new FileOutputStream(FILES_FOLDER + OUTPUT_FILENAME);
		OutputStreamWriter os = new OutputStreamWriter(out);
		BufferedWriter w = new BufferedWriter(os);
		for(int i=0; i<results.length; i++){
			
			String log = getLogLine(i, results[i]);			
			w.write(log);
			if(i+1 < results.length){
				w.write("\n");
			}
			w.flush();			
		}
	}
}
