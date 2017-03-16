import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class A {
	public static void main(String[] args) throws IOException {
		String name = "A-large";
		Scanner sc = new Scanner(new File(name + ".in"));
		// Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new FileWriter(name + ".out"));
		int n = sc.nextInt();
		for (int c = 1; c <= n; c++) {
			long r = sc.nextLong();
			long t = sc.nextLong();
			double x = r;
			x *= r;
			x *= 4;
			x -= 4 * r;
			x += 1 + 8 * t;
			x = Math.sqrt(x);
			x += 1 - 2 * r;
			x /= 4;

			BigInteger y = new BigInteger(String.valueOf(2 * r - 1));
			y = y.multiply(y);
			BigInteger z = new BigInteger(String.valueOf(t));
			z = z.multiply(new BigInteger("8"));
			y = y.add(z);
			y = sqrt(y);
			y = y.subtract(new BigInteger(String.valueOf(2 * r)));
			y = y.add(BigInteger.ONE);
			y = y.divide(new BigInteger("4"));
			out.println("Case #" + c + ": " + y.toString());
			System.out.println("Case #" + c + ": " + y.toString());
		}
		out.close();
		sc.close();
	}

	public static BigInteger sqrt(BigInteger c) {
		BigInteger a = BigInteger.ONE;
		BigInteger b = new BigInteger(c.shiftRight(5).add(new BigInteger("8"))
				.toString());
		while (b.compareTo(a) >= 0) {
			BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
			if (mid.multiply(mid).compareTo(c) > 0)
				b = mid.subtract(BigInteger.ONE);
			else
				a = mid.add(BigInteger.ONE);
		}
		return a.subtract(BigInteger.ONE);
	}

}
