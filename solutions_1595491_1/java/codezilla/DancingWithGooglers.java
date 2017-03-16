package codejam2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Hashtable;
import java.util.Scanner;

public class DancingWithGooglers {

	public static void main(String[] args) throws Exception {

		Scanner scanner = new Scanner(new BufferedReader(new FileReader(
				"A-large-practice.in.txt")));
		Output out = new Output("B.out");

		int T = scanner.nextInt();

		for (int t = 1; t <= T; t++) {

			int N = scanner.nextInt();
			int S = scanner.nextInt();
			int p = scanner.nextInt();

			int[] scores = new int[N];

			for (int i = 0; i < N; i++) {
				scores[i] = scanner.nextInt();
			}

			Arrays.sort(scores);

			int count = 0;
			int num_s = 0;

			int[] roundUp = { 0, 2, 1 };
			int[] makeUp = { 1, 0, 1 };
			int[] makeDown = { 1, 1, 0 };

			for (int i = scores.length - 1; i >= 0; i--) {

				int score = scores[i];
				int mod = score % 3;

				int hi = (score + roundUp[mod]) / 3;
				int low = score / 3 - makeDown[mod];

				if (hi >= p) {
					count++;
				} else if (num_s < S && (hi + makeUp[mod]) >= p && low >= 0) {
					count++;
					num_s++;
				} else {
					//break;
				}
			}

			out.format("Case #%d: %d\n", t, count);
		}

		scanner.close();
		out.close();
	}

	static class Output {

		PrintWriter pw;

		public Output(String filename) throws IOException {
			pw = new PrintWriter(new BufferedWriter(new FileWriter(filename)));
		}

		public void print(String s) {
			pw.print(s);
			System.out.print(s);
		}

		public void println(String s) {
			pw.println(s);
			System.out.println(s);
		}

		public void format(String format, Object... args) {
			pw.format(format, args);
			System.out.format(format, args);
		}

		public void close() {
			pw.close();
		}
	}

}
