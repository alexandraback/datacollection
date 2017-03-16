package r1a2013;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Bullseye {
	public static void main(String[] args) throws Exception {
		String fileName = args[0];
		Bullseye obj = new Bullseye();
		obj.solve(fileName);
	}

	public void solve(String fileName) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(fileName));
		BufferedWriter bw = new BufferedWriter(
				new FileWriter(fileName + ".out"));

		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			String str = br.readLine();
			StringTokenizer token = new StringTokenizer(str);
			String r = token.nextToken();
			String t = token.nextToken();

			BigInteger ans = null;
			if ((Long.parseLong(r)) % 2 == 0) {
				// even
				BigInteger bk = new BigInteger(r).divide(TWO);
				BigInteger bt = new BigInteger(t);

				BigInteger bd = bk.multiply(bk).multiply(new BigInteger("-2"))
						.add(bk).add(BigInteger.ONE).subtract(bt)
						.multiply(new BigInteger("-8")).add(new BigInteger("9"));
				BigInteger bn = sqrt(bd).subtract(new BigInteger("3")).divide(new BigInteger("4"));
				ans = bn.subtract(bk).add(BigInteger.ONE);
			} else {
				// odd
				BigInteger bk = new BigInteger(r).subtract(BigInteger.ONE).divide(TWO);
				BigInteger bt = new BigInteger(t);

				BigInteger bd = bk.multiply(bk).multiply(new BigInteger("-2"))
						.subtract(bk).add(new BigInteger("3")).subtract(bt)
						.multiply(new BigInteger("-8")).add(new BigInteger("25"));
				BigInteger bn = sqrt(bd).subtract(new BigInteger("5")).divide(new BigInteger("4"));
				ans = bn.subtract(bk).add(BigInteger.ONE);
			}

			bw.write("Case #" + (i + 1) + ": " + ans.toString());
			bw.write("\r\n");
		}
		bw.close();
		br.close();
	}

	static BigInteger TWO = new BigInteger("2");
	private BigInteger sqrt(BigInteger a) {
		int x = a.toString().length();
		BigInteger min = BigInteger.ONE;
		BigInteger max = a;
		while (max.subtract(min).subtract(BigInteger.ONE)
				.compareTo(BigInteger.ZERO) > 0) {
			BigInteger mid = min.add(max).divide(TWO);
			BigInteger sqr = mid.multiply(mid);
			if (sqr.compareTo(a) <= 0) {
				min = mid;
			} else {
				max = mid;
			}
		}
		return min;
	}
}
