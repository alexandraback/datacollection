package googlecodejam2012.round1b.safetyinnumbers;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Writer;

import scala.actors.threadpool.Arrays;

public class SafetyInNumbers {
	private static final double diff = 1.0 / 16384;

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		String lineSep = System.getProperty("line.separator");
		BufferedReader br = new BufferedReader(
				args.length > 0 ? new FileReader(args[0])
						: new InputStreamReader(System.in));
		try {
			Writer out = new BufferedWriter(args.length > 1 ? new FileWriter(
					args[1]) : new OutputStreamWriter(System.out));
			try {
				int numLines = Integer.parseInt(br.readLine().trim());
				for (int i = 1; i <= numLines; ++i) {
					String line = br.readLine();
					out.write("Case #" + i + ": " + print(minShares(line))
							+ lineSep);
				}
			} finally {
				out.close();
			}
		} finally {
			br.close();
		}
	}

	private static String print(double[] minShares) {
		double sum = 0;
		StringBuilder sb = new StringBuilder();
		for (double d : minShares) {
			sb.append(Math.max(0, d * 100));
			sb.append(' ');
			sum += d;
		}
		if (Math.abs(sum - 1) > diff) {
			System.out.println(Arrays.toString(minShares));
		}
		sb.setLength(sb.length() - 1);
		return sb.toString();
	}

	private static double[] minShares(String line) {
		String[] parts = line.split(" ");
		int n = Integer.parseInt(parts[0]);
		int[] judge = new int[n];
		long x = 0;
		for (int i = parts.length; i-- > 1;) {
			x += judge[i - 1] = Integer.parseInt(parts[i]);
		}
		System.out.println(((double) x) / n);
		double[] ret = new double[parts.length - 1];
		int[] judgeSorted = new int[n];
		System.arraycopy(judge, 0, judgeSorted, 0, n);
		Arrays.sort(judgeSorted);
		for (int i = n; i-- > 0;) {
			ret[i] = findMin2(judgeSorted, judge[i], x);
		}
		return ret;
	}

	private static double findMin2(int[] judgeSorted, int judgei, long x) {
		double average = ((double) x) / judgeSorted.length;
		int pos = Arrays.binarySearch(judgeSorted, (int) Math.floor(average));
		if (pos < 0) {
			pos = -pos - 1;
		}
		return Math.max(0, Math.min(1.0 / pos, (2 * average - judgei) / x));
	}
}
