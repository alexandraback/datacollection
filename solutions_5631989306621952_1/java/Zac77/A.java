/**
 * Source code for Google Code Jam 2016 - Online Round 1: Sub-Round A - Problem A
 * Author: Zac ZHANG (zac771989@gmail.com)
 * Date: 04/15/2016
 */

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class A {
	
	public static final String FILE_NAME = "A-large";
	
	private BufferedReader in;
	
	public static void main(String[] args) throws IOException {
		A main = new A();
		main.start();
	}
	
	private void start() throws IOException {
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(FILE_NAME + ".out")));
		in = new BufferedReader(new FileReader(FILE_NAME + ".in"));
		
		int numCases = Integer.parseInt(in.readLine());
		for (int iCase = 1; iCase <= numCases; iCase++)
			out.println("Case #" + iCase + ": " + solve());
		
		in.close();
		out.close();
	}
	
	private String solve() throws IOException {
		char[] S = in.readLine().toCharArray();
		StringBuilder sb = new StringBuilder(S.length);
		sb.append(S[0]);
		for (int i = 1; i < S.length; i++) {
			if (S[i] >= sb.charAt(0))
				sb.insert(0, S[i]);
			else
				sb.append(S[i]);
		}
		return sb.toString();
	}
	
}
