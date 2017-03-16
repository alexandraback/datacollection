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


public class Pogo {
	private static final String FILES_FOLDER = "files/2013/round1/pogo/";
	private static final String DEFAULT_INPUT_FILENAME = "B-large.in";
	private static final String OUTPUT_FILENAME = "pogo_out.txt";
	

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


	protected String handleTestCase(String line) throws Exception {
		String[] in = line.split(" ");
		int destX = Integer.parseInt(in[0]);
		int destY = Integer.parseInt(in[1]); 
		
		int dist = Math.abs(destX)+Math.abs(destY);
		int distCopy = dist;
		int minMoves=0;
		while(distCopy > 0){
			minMoves++;
			distCopy -= minMoves;
		}
		
		
		while(true){
			int currX = destX;
			int currY = destY;
			char[] moves = new char[minMoves];
			for(int i=minMoves; i>0; i--){
				if(Math.abs(currX) >= Math.abs(currY)){
					if(currX > 0){
						currX-=i;
						moves[i-1] = 'E';
					}else {
						currX+=i;
						moves[i-1] = 'W';
					}
				}else {
					if(currY > 0){
						currY-=i;
						moves[i-1] = 'N';
					}else {
						currY+=i;
						moves[i-1] = 'S';
					}
				}
			}

			if(currX == 0 && currY == 0){
				String result = new String(moves);
				return result;
			}else {
				minMoves++;
			}
		}

	

	}

		

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		Pogo a = new Pogo();
		a.run();
	}

	private String inputFilename;

	private Object[] results;
	
	public Pogo() {
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
