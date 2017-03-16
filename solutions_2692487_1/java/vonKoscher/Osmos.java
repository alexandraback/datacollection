package com.google.codejam._2013.round1B;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.util.Arrays;


public class Osmos {
	private static final String FILES_FOLDER = "files/2013/round1/osmos/";
	private static final String DEFAULT_INPUT_FILENAME = "A-large.in";
	private static final String OUTPUT_FILENAME = "osmos_out.txt";
	

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
			results[i] = handleTestCase(reader.readLine(), reader.readLine());
			System.out.println(getLogLine(i, results[i]));
		}
		
		this.printResults();
	}


	protected int handleTestCase(String line1, String line2) throws Exception {
		String[] in1 = line1.split(" ");
		long A = Long.parseLong(in1[0]);
		String[] in2 = line2.split(" ");
		int[] motes = new int[in2.length];
		for(int i=0; i<in2.length; i++){
			motes[i] = Integer.parseInt(in2[i]);
		}
		
		Arrays.sort(motes);
		

		if(A==1) return motes.length;
		
		
		int result = 0;
		
		int worstResult = motes.length;
		
		for(int i=0; i<motes.length; i++){
			if(result >= worstResult) return worstResult;
			
			int mote = motes[i];
			if(A > mote){
				A+=mote;
				if(A > motes[motes.length-1]){
					return result;
				}
			}else {
				
				if(A+A-1 > mote){
					result++;
					A += (A-1+mote);
				}else {
					//remove everything:
					worstResult = Math.min(worstResult, result + (motes.length-i));
					
					A+= A-1;
					i--;
					result++;
				}
			}
		}
	

		return result;
	}
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		Osmos a = new Osmos();
		a.run();
	}

	private String inputFilename;

	private Object[] results;
	
	public Osmos() {
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
