/**
 * Source code for Google Code Jam 2016 - Online Round 1: Sub-Round B - Problem A
 * Author: Zac ZHANG (zac771989@gmail.com)
 * Date: 04/30/2016
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
		int[] letterCounter = new int[26];
		for (int i = 0; i < S.length; i++)
			letterCounter[S[i] - 'A']++;
		
		int[] digitsCounter = new int[10];
		digitsCounter[0] = letterCounter['Z' - 'A'];
		digitsCounter[2] = letterCounter['W' - 'A'];
		digitsCounter[4] = letterCounter['U' - 'A'];
		digitsCounter[5] = letterCounter['F' - 'A'] - digitsCounter[4];
		digitsCounter[6] = letterCounter['X' - 'A'];
		digitsCounter[7] = letterCounter['V' - 'A'] - digitsCounter[5];
		digitsCounter[8] = letterCounter['G' - 'A'];
		digitsCounter[9] = letterCounter['I' - 'A'] - digitsCounter[5] - digitsCounter[6] - digitsCounter[8];
		digitsCounter[3] = letterCounter['H' - 'A'] - digitsCounter[8];
		digitsCounter[1] = letterCounter['N' - 'A'] - digitsCounter[7] - 2 * digitsCounter[9];
		
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < digitsCounter.length; i++)
			for (int j = 0; j < digitsCounter[i]; j++)
				sb.append(i);
		
		return sb.toString();
	}
	
}
