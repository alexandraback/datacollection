

import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class Bullseye {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int T = in.nextInt();
		BigInteger big2 = new BigInteger("2");
		for (int tc = 1; tc <= T; tc++) {
			BigInteger r = in.nextBigInteger();
			BigInteger t = in.nextBigInteger();
			BigInteger lo = new BigInteger("0");
			BigInteger hi = new BigInteger("" + t);
			for (int i = 0; i < 100; i++) {
				BigInteger x = (lo.add(hi)).divide(big2);
				BigInteger b = r.multiply(big2).subtract(BigInteger.ONE);
				if (x.multiply(x).multiply(big2).add(x.multiply(b)).subtract(t)
						.compareTo(BigInteger.ZERO) <= 0)
					lo = x;
				else
					hi = x;
			}
			out.println("Case #" + tc + ": " + lo);
		}

		out.flush();
		out.close();
		in.close();
	}
}
