

import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.Arrays;

public class Round1ProblemA {	// let's just read standard input guys
	private static final String outputFile = "round1problemA.out";
	
	private static boolean debug = false; // print log statements
	private static BufferedReader br;
	private static PrintWriter out;
	private static String nl;
	
	private static void readNextLine() throws IOException {
		if (debug) {
			System.out.print("INPUT: ");
		}
		nl = br.readLine();
	}
	
	private static void log(String bla) {
		if (debug) {
			System.out.println("LOG: " + bla);
		}
	}
	
	private static void printOutput(String line) {
		//if (debug) {
			System.out.println("OUTPUT: " + line);
		//}
		out.println(line);
	}
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader((System.in)));
		out = new PrintWriter(new BufferedWriter(new FileWriter(outputFile)));
		
		// begin program
		
		readNextLine();
		int T = Integer.parseInt(nl);
		
		log(T + " test cases");
		
		for (int i = 0; i < T; i++) {
			readNextLine();
			StringTokenizer st = new StringTokenizer(nl);
			
			int r = Integer.parseInt(st.nextToken());
			int t = Integer.parseInt(st.nextToken());
			
			String result = solve(r, t);
			
			printOutput("Case #" + (i + 1) + ": " + result.toString());
			
		}
		
		// end program
		
		out.close();
	}
	
	private static String solve(int r, int t) {
		int numRings = 0, i = r, paintLeft = t;
		while (true) {
			paintLeft -= (2 * i + 1);
			
			if (paintLeft < 0) break;
			
			i += 2;
			numRings++;
		}
		
		return numRings + "";
	}
}
