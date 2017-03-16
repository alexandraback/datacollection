package googlecodejam2013.qualification.fairsquare;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Arrays;

public class FairAndSquare {
	private static long[] smallFairAndSquare = new long[] { 1L, 4L, 9L, 121L,
			484L, 10201L, 12321L, 14641L, 40804L, 44944L, 1002001L, 1234321L,
			4008004L, 100020001L, 102030201L, 104060401L, 121242121L,
			123454321L, 125686521L, 400080004L, 404090404L, 10000200001L,
			10221412201L, 12102420121L, 12345654321L, 40000800004L,
			1000002000001L, 1002003002001L, 1004006004001L, 1020304030201L,
			1022325232201L, 1024348434201L, 1210024200121L, 1212225222121L,
			1214428244121L, 1232346432321L, 1234567654321L, 4000008000004L,
			4004009004004L, };

	public static void main(String[] args) throws IOException {
		String lineSep = System.getProperty("line.separator");
		BufferedReader br = new BufferedReader(
				args.length > 0 ? new FileReader(args[0])
						: new InputStreamReader(System.in));
		try {
			Writer out = new BufferedWriter(args.length > 1 ? new FileWriter(
					args[1]) : new OutputStreamWriter(System.out));
			try {
				int testCases = Integer.parseInt(br.readLine().trim());
				for (int i = 1; i <= testCases; ++i) {
					String[] sizeLine = br.readLine().split(" ");
					long n = Long.parseLong(sizeLine[0]);
					long m = Long.parseLong(sizeLine[1]);
					out.write("Case #" + i + ": " + findIndices(n, m) + lineSep);
				}
			} finally {
				out.close();
			}
		} finally {
			br.close();
		}
		// Random r = new Random();
		// long start = System.nanoTime();
		// for (int i = 100000; i-- > 0;) {
		// long small = r.nextLong() % 10000000000L;
		// long large = (small + r.nextLong()) % 10000000000000L;
		// long f = findIndices(small, large);
		// }
		// System.out.println((System.nanoTime() - start) / 1E9 + " sec");
	}

	private static int findIndices(long n, long m) {
		return findInsertionPoint(m + 1) - findInsertionPoint(n);
	}

	private static int findInsertionPoint(long m) {
		int i = Arrays.binarySearch(smallFairAndSquare, m);
		return i < 0 ? -(i + 1) : i;
	}

	private static String count(long n, long m) {
		long sqrtM = (long) Math.ceil(Math.sqrt(m));
		long count = 0;
		for (long i = (long) Math.floor(Math.sqrt(n)); i <= sqrtM; ++i) {
			long sqr = i * i;
			if (sqr >= n && sqr <= m && isPalindrome(i) && isPalindrome(sqr)) {
				System.out.println(sqr);
				count++;
			}
		}
		return Long.toString(count);
	}

	private static boolean isPalindrome(long sqr) {
		String s = Long.toString(sqr);
		int l = s.length();
		for (int i = (l + 1) / 2; i-- > 0;) {
			if (s.charAt(i) != s.charAt(l - 1 - i)) {
				return false;
			}
		}
		return true;
	}
}
