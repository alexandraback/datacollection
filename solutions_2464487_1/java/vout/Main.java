import java.io.File;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	static BigInteger f(BigInteger n, BigInteger r) {
		return n.multiply(n.add(n).add(r).add(r).subtract(BigInteger.ONE));
	}
	
	public static void main(String[] argv) {
		File inFile = new File("input.txt");
		Scanner in = new Scanner(new InputStreamReader(inFile));
		int Tc = in.nextInt();
		
		for (int re = 1; re <= Tc; ++re) {
			BigInteger r, t;
			r = in.nextBigInteger();
			t = in.nextBigInteger();
			BigInteger hi = t, low = BigInteger.ONE;
			while (hi.compareTo(low) > 0) {
				BigInteger mid = hi.add(low).add(BigInteger.ONE).divide(BigInteger.valueOf(2));
				BigInteger v = f(mid, r);
				if (v.compareTo(t) <= 0) {
					low = mid;
				} else {
					hi = mid.subtract(BigInteger.ONE);
				}
			}
			System.out.println("Case #" + re + ": " + low);
		}
	}
}
