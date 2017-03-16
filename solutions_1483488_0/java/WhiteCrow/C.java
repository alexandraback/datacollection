package com.whitecrow.codejam2012.qualification;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class C {

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		String filename = "C-small-attempt0";

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

			for (int idx = 0; idx < T; idx++) {
				int result = 0;
				StringTokenizer token = new StringTokenizer(reader.readLine(), " ");

				int a = Integer.parseInt(token.nextToken());
				int b = Integer.parseInt(token.nextToken());
				int length = String.valueOf(a).length();
				for (int i = a; i <= b; i++) {
					ArrayList<Integer> check = new ArrayList<Integer> ();
					for (int j = 1; j < length; j++) {
						int divide = (int) Math.pow(10, j);
						int add = (int) Math.pow(10, length - j);
						int k = i / divide + (i % divide) * add;
						
						if (i < k && a <= i && k <= b && !check.contains(k)) {
							check.add(k);
							//System.out.println(i+", "+k);
							result++;
						}
					}
					// System.out.println(i);
				}

				out = "Case #" + (idx + 1) + ": " + result;
				System.out.println(out);
				writer.write(out + "\n");
			}

			reader.close();
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(0);
		}
	}

}
