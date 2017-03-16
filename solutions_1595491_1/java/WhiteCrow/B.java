package com.whitecrow.codejam2012.qualification;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class B {

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		String filename = "B-small-attempt0";

		FileReader input;
		FileWriter output;
		try {
			input = new FileReader(filename + ".in");
			output = new FileWriter(filename + ".out");

			BufferedReader reader = new BufferedReader(input);
			BufferedWriter writer = new BufferedWriter(output);

			// String in = "";
			String out = "";

			int T = Integer.parseInt(reader.readLine());

			int N;
			int S;
			int p;
			for (int i = 0; i < T; i++) {
				StringTokenizer token = new StringTokenizer(reader.readLine(), " ");
				int result = 0;
				int suprising = 0;

				N = Integer.parseInt(token.nextToken());
				S = Integer.parseInt(token.nextToken());
				p = Integer.parseInt(token.nextToken());
				/*
				 * for (int j = 0; j < token.countTokens(); j++) { }
				 */

				int t = 0;
				int m;
				int e;
				for (int j = 0; j < N; j++) {
					t = Integer.parseInt(token.nextToken());
					m = t / 3;
					e = t % 3;

					if (m >= p || (m >= p - 1 && e >= 1)) { // Qualified
						result++;
					} else if ((m + e != 0) && ((m == p - 1 && e == 0) || (m == p - 2 && e == 2))) { // Surprising
						suprising++;
						if (S >= suprising) {
							result++;
						}
					}
				}

				out = "Case #" + (i + 1) + ": " + result;
				System.out.println(out + "\tSuprising : " + suprising);
				writer.write(out+"\n");
			}

			reader.close();
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(0);
		}
	}
}
