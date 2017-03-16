package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Solver {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader reader = new BufferedReader(new FileReader("input.in"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("output.out"));

		int t = Integer.parseInt(reader.readLine());

		for (int c = 1; c <= t; ++c) {
			double result = 0.0;

			String[] values = reader.readLine().split(" ");
			int k = Integer.parseInt(values[0]);
			int l = Integer.parseInt(values[1]);
			int s = Integer.parseInt(values[2]);
			int posStarts = s - l + 1;

			char[] input = reader.readLine().toCharArray();
			char[] word = reader.readLine().toCharArray();
			double[] posWord = new double[word.length];

			boolean impossible = false;
			double posTotal = 1.0;
			for (int i = 0; i < word.length; i++) {
				float count = 0;

				for (int j = 0; j < input.length; j++) {
					if (input[j] == word[i]) {
						count++;
					}
				}

				if (count == 0) {
					impossible = true;
					break;
				}

				posWord[i] = count / (float) input.length;
				posTotal *= posWord[i];
			}

			if (!impossible) {
				double abgabe = posStarts * posTotal;
				
				int anzahl = 1;
				char[] moeglich = new char[s];
				for (int i = 0; i < s; i++) {
					moeglich[i] = '?';
				}
				for (int i = 0; i < l; i++) {
					moeglich[i] = word[i];
				}
				
				for (int n = 1; n < s && (n + l) <= s; n++) {
					
					boolean possible = true;
					for (int m = 0; m < l; m++) {
						if (!(moeglich[n + m] == word[m] || moeglich[n + m] == '?')) {
							possible = false;
						}
					}
					
					if (possible) {
						for (int m = 0; m < l; m++) {
							moeglich[n + m] = word [m];
						}
						anzahl++;
					}
				}
				
				result = Math.round((anzahl - abgabe) * 10000000) / 10000000.0;
			}

			System.out.println("Case #" + c + ": " + result);
			writer.write("Case #" + c + ": " + result);
			writer.newLine();
		}

		writer.flush();
		writer.close();
		reader.close();
	}

}
