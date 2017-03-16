package google.codejam._2014.round_1C;

import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class ReorderingTrainCars {
	static int[] x;
	static int n;
	static String[] cars;
	static int nrSol;
	static boolean[] used;

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new FileReader("src/in.txt"));
		PrintWriter out = new PrintWriter("out.txt");

		int t = in.nextInt();

		for (int tc = 1; tc <= t; tc++) {
			in.nextLine();
			n = in.nextInt();
			in.nextLine();

			cars = new String[n];

			for (int i = 0; i < n; i++) {
				cars[i] = in.next();
			}

			used = new boolean[n];
			x = new int[n];
			nrSol = 0;
			bkt(0);

			out.println("Case #" + tc + ": " + nrSol);
		}

		in.close();
		out.close();
	}

	private static void bkt(int k) {
		if (k == n) {
			if (valid()) {
				nrSol++;
			}
		} else {
			for (int i = 0; i < n; i++) {
				if (!used[i]) {
					x[k] = i;
					used[i] = true;
					bkt(k + 1);
					used[i] = false;
				}
			}
		}
	}

	private static boolean valid() {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			sb.append(cars[x[i]]);
		}

		int len = sb.length();

		int idx = 0;
		char ch = sb.charAt(0);
		while (idx < len) {
			while (idx<len  && sb.charAt(idx)== ch) {
				idx++;
			}

			if (idx < len) {
				if (sb.indexOf("" + ch, idx) > 0) {
					return false;
				}
				
				ch = sb.charAt(idx);
			}
		}

		return true;
	}
}
