import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;

public class CJ131ARASL {

	/**
	 * @param args
	 * @throws IOException
	 * @throws NumberFormatException
	 */
	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader br = new BufferedReader(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter("output.txt");
		int T = Integer.parseInt(br.readLine());
		for (int i = 1; i <= T; i++) {
			String tokens[] = br.readLine().split("\\s+");
			long r = Long.parseLong(tokens[0]);
			long t = Long.parseLong(tokens[1]);
			pw.println("Case #" + i + ": " + b_s(r, t));
		}
		pw.close();
	}

	static long b_s(long r, long t) {
		long s = 1;
		long e = (long) (2 * Math.pow(10, 18));
		while (s < e) {
			long mid = s + (e - s + 1) / 2;
			if (valid(mid, r, t))
				s = mid;
			else
				e = mid - 1;
		}
		return s;
	}

	private static boolean valid(long n, long r, long t) {
		BigInteger b1 = new BigInteger(Long.toString(2*r +1));
		b1 = b1.multiply(new BigInteger(Long.toString(n)));
		BigInteger b3 = new BigInteger(Long.toString(2 * n - 2));
		b3 = b3.multiply(new BigInteger(Long.toString(n)));
		b1 = b1.add(b3);
		BigInteger b2 = new BigInteger(Long.toString(t));
		return b1.compareTo(b2) != 1l;
	}
}
