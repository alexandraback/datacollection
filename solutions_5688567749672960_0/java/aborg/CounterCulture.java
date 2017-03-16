/*
 * 
 */
package codejam2015.round1b.a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Writer;

/**
 *
 * @author Gabor Bakos
 */
public class CounterCulture {
	private static final int[] CACHE = new int[1000001];

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		fillCache();
		for (int i : new int[]{30001, 20, 21, 22, 23, 29, 31, 99, 100, 111, 30001}) {
			System.out.println(i + " : " + minCount(i));
		}
		String lineSep = System.getProperty("line.separator");
		try (BufferedReader br = new BufferedReader(
				args.length > 0 ? new FileReader(args[0])
						: new InputStreamReader(System.in));
				Writer out = new BufferedWriter(
						args.length > 1 ? new FileWriter(args[1])
								: new OutputStreamWriter(System.out))) {
			int numCases = Integer.parseInt(br.readLine().trim());
			for (int i = 1; i <= numCases; ++i) {
				out.write("Case #" + i + ": " + minCount(Integer.parseInt(br.readLine()))
						+ lineSep);
			}
		}
	}

	private static void fillCache() {
		for (int i = 1; i < 21; ++i) {
			CACHE[i] = i;
		}
		for (int i = 21; i < CACHE.length; ++i) {
			if (i % 10 != 0) {
				int reverse = reverse(i);
				CACHE[i] = reverse < i ? Math.min(CACHE[i - 1] + 1, CACHE[reverse] + 1) : CACHE[i - 1] + 1;
			} else {
				CACHE[i] = CACHE[i - 1] + 1;
			}
		}
	}

	private static long minCount(int x) {
			return CACHE[x];
//		long ones = x%10;
//		if (x < 100 && ones == 0) {
//			return minCount(x - 9) + 9;
//		}
//		long tens = x/10;
//		if (x < 100 && ones < tens) {
//			return minCount(tens + 10 * ones) + 1;
//		}
//		long diff = ones == 1 ? 0 : ((ones - 11) % 10 + 10);
//		
//		long straight;
//		if (ones == 1) {
//			straight = reverse(x) == x ? minCount(x-10) + 10 : minCount(reverse(x)) + 1;
//		} else if (ones != 0 && ones < Long.toString(x).charAt(0) - '0'){ 
//			long reverse = reverse(x - diff);
//			return (minCount(reverse) + diff + 1);
//		} else {
//			straight = minCount(x - diff) + diff + 1;
//		}
//		if (ones != 0 && ones < Long.toString(x).charAt(0) - '0') {
//			return Math.min(reverse(minCount(reverse(x))), straight);
//		}
//		return straight;
	}

	private static int reverse(int l) {
		return Integer.parseInt(new StringBuilder(Integer.toString(l)).reverse().toString());
	}

}
