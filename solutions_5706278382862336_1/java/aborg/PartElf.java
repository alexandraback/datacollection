package googlecodejam2014.round1c.partelf;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Arrays;

public class PartElf {
	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(final String[] args) throws IOException {
		final String lineSep = System.getProperty("line.separator");
		final BufferedReader br = new BufferedReader(
				args.length > 0 ? new FileReader(args[0])
						: new InputStreamReader(System.in));
		try {
			final Writer out = new BufferedWriter(args.length > 1 ? new FileWriter(args[1]): new OutputStreamWriter(System.out));
			try {
				final int numCases = Integer.parseInt(br.readLine().trim());
				for (int i = 1; i <= numCases;++i) {
					final String[] lineParts = br.readLine().split("/");
					final long p = Long.parseLong(lineParts[0]), q = Long
							.parseLong(lineParts[1]);
					out.write("Case #" + i + ": "
 + closestAncestor(p, q)
							+ lineSep);
				}
			} finally {
				out.close();
			}
		} finally {
			br.close();
		}
	}

	static final long[] powersOfTwo = new long[41];
	static {
		long l = 1;
		for (int i = 0; i < powersOfTwo.length; ++i) {
			powersOfTwo[i] = l;
			l = l + l;
		}
	}

	private static String closestAncestor(long p, long q) {
		final long gcd = gcd(p, q);
		if (Arrays.binarySearch(powersOfTwo, q / gcd) < 0) {
			return "impossible";
		}
		p /= gcd;
		q/=gcd;
		if (2 * p >= q) {
			return "1";
		}
		int i = Arrays.binarySearch(powersOfTwo, p);
		final int o = Arrays.binarySearch(powersOfTwo, q);
		if (i < 0) {
			i = -i - 2;
		}
		return Integer.toString(o-i);
		// return Integer.toString((int) (Math.log(q / p) / Math.log(2)));
	}

	private static long gcd(final long p, final long q) {
		if (p < q) {
			return gcd(q, p);
		}
		final long rem = p % q;
		if (rem == 0) {
			return q;
		}
		return gcd(q, rem);
	}

}
