/*
 * 
 */
package codejam2016.q.c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.stream.Collectors;

/**
 *
 * @author Gabor Bakos
 */
public class CoinJam {
	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		String lineSep = System.getProperty("line.separator");
		try (BufferedReader br = new BufferedReader(
				args.length > 0 ? new FileReader(args[0]) : new InputStreamReader(System.in));
				Writer out = new BufferedWriter(
						args.length > 1 ? new FileWriter(args[1]) : new OutputStreamWriter(System.out))) {
			int numCases = Integer.parseInt(br.readLine().trim());
			for (int i = 1; i <= numCases; ++i) {
				String[] parts = br.readLine().split(" ");
				int n = Integer.parseInt(parts[0]), j = Integer.parseInt(parts[1]);
				out.write("Case #" + i + ":" + lineSep + String.join(lineSep, examples(n, j)));
			}
		}
	}

	private static String[] examples(int n, int j) {
		String[] ret = new String[j];
		String zeroes = "0000000000000000000000000000000000000000000000000000000000000000000000000000";
		int index = 0;
		long v = -1;
		int[] divisors = new int[11];
		outer: while (index < j) {
			v++;
			String binaryString = Long.toBinaryString(v);
			String number = new StringBuilder("1").append(zeroes.substring(0, n - 2 - binaryString.length())).append(binaryString).append('1').toString();
			if (n < 17) {
				for (int radix = 2; radix <= 10; ++radix) {
					long value = Long.parseLong(number, radix);
					int aDivisor = divisor(value);
					if (aDivisor == 1) {
						continue outer;
					}
					divisors[radix] = aDivisor;
				}
				ret[index++] = number + " " + String.join(" ", Arrays.stream(divisors).skip(2).mapToObj(i -> String.valueOf(i)).collect(Collectors.toList()));
			} else {
				for (int radix = 2; radix <= 10; ++radix) {
					BigInteger value = new BigInteger(number, radix);
					int aDivisor = divisor(value);
					if (aDivisor == 1) {
						continue outer;
					}
					divisors[radix] = aDivisor;
				}
				ret[index++] = number + " " + String.join(" ", Arrays.stream(divisors).skip(2).mapToObj(i -> String.valueOf(i)).collect(Collectors.toList()));
			}
		}
		return ret;
	}

	private static int divisor(long value) {
		int divisor = 1;
		for (int i = 3; i < 20000 && i < value; i += 2) {
			if (value % i == 0) {
				return i;
			}
		}
		return divisor;
	}
	private static int divisor(BigInteger value) {
		int divisor = 1;
		for (int i = 3; i < 20000; i += 2) {
			if (value.mod(BigInteger.valueOf(i)).equals(BigInteger.ZERO)) {
				return i;
			}
		}
		return divisor;
	}
}
