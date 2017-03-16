import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class test {
	private static long r;
	private static long t;

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader buf = new BufferedReader(new FileReader(
				"A-large.in"));
		// BufferedReader buf = new BufferedReader(
		// new InputStreamReader(System.in));
		PrintWriter writer = new PrintWriter(new File("A.out"));
		int tcase = Integer.parseInt(buf.readLine().trim());
		for (int i = 1; i <= tcase; i++) {
			StringTokenizer str = new StringTokenizer(buf.readLine());

			r = Long.parseLong(str.nextToken());
			t = Long.parseLong(str.nextToken());
			long lo = 0;
			long hi = t;

			int itr = 100;
			long mid = 0;
			while (itr-- > 0) {
				mid = (lo + hi) / 2;
				if (can(mid))
					lo = mid;
				else
					hi = mid - 1;
			}
			if (can(hi) && hi > lo)
				mid = hi;
			writer.println("Case #" + i + ": " + mid);
		}
		writer.close();
	}

	private static boolean can(long mid) {
		BigInteger i = BigInteger.valueOf(mid);
		BigInteger j = BigInteger.valueOf(r * 2);
		j = j.multiply(i);
		BigInteger k = BigInteger.valueOf(2 * mid);
		k = k.multiply(i);
		// k = k.multiply(BigInteger.valueOf(2));
		BigInteger ans = BigInteger.ZERO;
		ans = ans.subtract(i);
		ans = ans.add(j);
		ans = ans.add(k);
		BigInteger tt = BigInteger.valueOf(t);
		if (ans.compareTo(tt) <= 0)
			return true;
		return false;
	}
}
