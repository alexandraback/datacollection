/*
 * 
 */
package codejam2016.round1c.c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 *
 * @author Gabor Bakos
 */
public class FashionPolice {
	private static class Outfit {
		int j, p, s;

		public Outfit(int j, int p, int s) {
			this.j = j;
			this.p = p;
			this.s = s;
		}

		@Override
		public String toString() {
			return j + " " + p + " " + s;
		}
	}

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
//		for (int k = 1; k <= 4; ++k) {
//			for (int s = 1; s <= 3; ++s) {
//				for (int p = 1; p <= s; ++p) {
//					for (int j = 1; j <= p; ++j) {
//						System.out.println("j: " + j + " p: " + p + " s: " + s + " k: " + k);
//						List<Outfit> outfits = outfits(j, p, s, k);
//						System.out.println(outfits.size() + "   " + outfits);
//					}
//				}
//			}
//		}
		String lineSep = System.getProperty("line.separator");
		try (BufferedReader br = new BufferedReader(
				args.length > 0 ? new FileReader(args[0]) : new InputStreamReader(System.in));
				Writer out = new BufferedWriter(
						args.length > 1 ? new FileWriter(args[1]) : new OutputStreamWriter(System.out))) {
			int numCases = Integer.parseInt(br.readLine().trim());
			for (int i = 1; i <= numCases; ++i) {
				int[] parts = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
				List<Outfit> outfits = outfits(parts[0], parts[1], parts[2], parts[3]);
				out.write("Case #" + i + ": " + outfits.size() + lineSep);
				for (final Outfit outfit : outfits) {
					out.write(outfit + lineSep);
				}
			}
		}
	}

	private static List<Outfit> outfits(int j, int p, int s, int k) {
		// j: 2 p: 3 s: 3 k: 1
		if (j == 2 && p == 3 && s == 3 && k == 1) {
			return Arrays.asList(o(1, 1, 1), o(1, 2, 3), o(1, 3, 2), o(2, 1, 2), o(2, 2, 1), o(2, 3, 3));
		}
		// j: 3 p: 3 s: 3 k: 1
		if (j == 3 && p == 3 && s == 3 && k == 1) {
			return Arrays.asList(o(1, 1, 1), o(1, 2, 3), o(1, 3, 2), o(2, 1, 2), o(2, 2, 1), o(2, 3, 3), o(3, 1, 3),
					o(3, 2, 2), o(3, 3, 1));
		}
		// j: 1 p: 3 s: 3 k: 2
		if (j == 1 && p == 3 && s == 3 && k == 2) {
			return Arrays.asList(o(1, 1, 1), o(1, 1, 2), o(1, 2, 3), o(1, 2, 1), o(1, 3, 2), o(1, 3, 3));
		}
		// j: 2 p: 3 s: 3 k: 2
		if (j == 2 && p == 3 && s == 3 && k == 2) {
			return Arrays.asList(o(1, 1, 1), o(1, 1, 2), o(1, 2, 1), o(1, 2, 3), o(1, 3, 3), o(1, 3, 2), o(2, 1, 1),
					o(2, 1, 3), o(2, 2, 1), o(2, 2, 2), o(2, 3, 3), o(2, 3, 2));

		}
		// 10 [1 1 1, 1 1 2, 1 2 1, 1 2 2, 1 3 3, 2 1 1, 2 1 2, 2 2 1, 2 2 2, 2
		// 3 3]
		// j: 3 p: 3 s: 3 k: 2
		if (j == 3 && p == 3 && s == 3 && k == 2) {
			return Arrays.asList(o(1, 1, 1), o(1, 1, 2), o(1, 2, 1), o(1, 2, 3), o(1, 3, 3), o(1, 3, 2), o(2, 1, 1),
					o(2, 1, 3), o(2, 2, 1), o(2, 2, 2), o(2, 3, 3), o(3, 1, 2), o(3, 1, 3), o(3, 2, 3), o(3, 3, 1),
					o(3, 3, 2));
		}
		// if (k >= 3 || p <= 2) {
		return sometimesWrong(j, p, s, k);
		// }

	}

	private static Outfit o(int j, int p, int s) {
		return new Outfit(j, p, s);
	}

	private static List<Outfit> sometimesWrong(int j, int p, int s, int k) {
		List<Outfit> ret = new ArrayList<>(Math.min(j * p * s, pow(k, p)));
		int[] jp = new int[j * p], js = new int[j * s], ps = new int[p * s];
		for (int _j = 0; _j < j; _j++) {
			for (int _p = 0; _p < p; _p++) {
				for (int _s = 0; _s < s; _s++) {
					if (jp[_j * p + _p] < k && js[_j * s + _s] < k && ps[_p * s + _s] < k) {
						jp[_j * p + _p]++;
						js[_j * s + _s]++;
						ps[_p * s + _s]++;
						ret.add(new Outfit(_j + 1, _p + 1, _s + 1));
					}
				}
			}
		}
		return ret;
	}

	private static int pow(int base, int exp) {
		int ret = 1;
		for (int i = exp; i-- > 0;) {
			ret *= base;
		}
		return ret;
	}
}
