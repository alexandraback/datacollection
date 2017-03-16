/**
 * Source code for Google Code Jam 2016 - Online Round 1: Sub-Round A - Problem B
 * Author: Zac ZHANG (zac771989@gmail.com)
 * Date: 04/15/2016
 */

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class B {
	
	public static final String FILE_NAME = "B-small-attempt0";
	
	public static final int LIMIT_HEIGHT = 2500;
	
	private BufferedReader in;
	
	public static void main(String[] args) throws IOException {
		B main = new B();
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
		int[] counter = new int[LIMIT_HEIGHT];
		int T = Integer.parseInt(in.readLine());
		for (int i = 0; i < 2 * T - 1; i++) {
			String[] numbers = in.readLine().split(" ");
			for (int j = 0; j < numbers.length; j++) {
				int height = Integer.parseInt(numbers[j]) - 1;
				counter[height]++;
			}
		}
		
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < counter.length; i++)
			if (counter[i] % 2 != 0) {
				sb.append(i + 1);
				sb.append(' ');
			}
		sb.deleteCharAt(sb.length() - 1);
		return sb.toString();
	}
	
}
