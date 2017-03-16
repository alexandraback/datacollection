package se.pathed.codejam.consonant;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;



public class Consonant {
	public BufferedReader getInputReader(String fileName) throws FileNotFoundException{
		String dataFolder = "C:\\Users\\Patrik\\workspaces\\codejam\\Practis\\data\\";
		File f = new File(dataFolder + fileName);
		FileReader fReader = new FileReader(f);
		BufferedReader reader = new BufferedReader(fReader);
		
		return reader;
	}
	
	public PrintWriter getOutputWriter(String fileName) throws FileNotFoundException{
		String dataFolder = "C:\\Users\\Patrik\\workspaces\\codejam\\Practis\\data\\";
		File outputFile = new File(dataFolder + fileName);
		if( outputFile.exists()) outputFile.delete();
		return new PrintWriter(outputFile);
	}
	
	public static void main(String args[]) throws Exception{
		new Consonant().run();
	}
	
	static class Problem {
		String name;
		int n;
	}
	
	int problemsLeft = 0;
			
	Problem parseProblem(BufferedReader r) throws IOException {
		Problem p = new Problem();
		String[] split = r.readLine().split(" ");
		p.name = split[0];
		p.n = Integer.parseInt(split[1]);
		return p;
	}

	private void run() throws IOException {
		BufferedReader reader = getInputReader("A-small-attempt0.in");
		PrintWriter output = getOutputWriter("out.txt");
		int c = Integer.parseInt(reader.readLine());
		for(int i = 0; i < c; i++){
			Problem p = parseProblem(reader);
			long res = solve(p);
			
			
			String answer = "Case #" + (i+1) + ": " + res;
			System.out.println(answer);
			output.println(answer);
		}
		output.flush();
		output.close();
	}
	
	
	
	private long solve(Problem p) {
		long found = 0;
		for( int x = 0; x < p.name.length(); x++){
			found += recSolve(p.name,x,p.name.length(),p.n);
		}
		return found;
	}
	
	private long recSolve(String s, int posA, int posB, int consec){
		if( ( posB - posA ) < consec) return 0;
		// Add cache
		long found = 0;
		found += recSolve(s,posA, posB-1, consec);
		
		if(found != 0) return found +1;
		
		long hits = 0;
		for( int p = posA; p < posB; p++ ){
			if( ! isVowel(s.charAt(p)) ){
				
				hits++;
				if(hits >= consec){
					found++;
					break;
				}
			} else {
				hits = 0;
			}
		}
		return found;
	}
	
	private boolean isVowel(char x){
		return x == 'a' || x== 'e' || x == 'i' || x == 'o' || x == 'u';
	}
}
