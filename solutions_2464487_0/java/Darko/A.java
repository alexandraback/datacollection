import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class A {

	private void work() throws IOException {
		// Scanner sc = new Scanner(new FileReader("A-large.in"));
		// PrintWriter pw = new PrintWriter(new FileWriter("A-large.out"));
		Scanner sc = new Scanner(new FileReader("A-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("A-small-attempt0.out"));
		// Scanner sc = new Scanner(new FileReader("a.in"));
		// PrintWriter pw = new PrintWriter(new FileWriter("a.out"));
		int nc = sc.nextInt();
		for (int tc = 1; tc <= nc; tc++) {
			long r = sc.nextLong();
			long t = sc.nextLong();
			long k = Math.round(Math.floor((1 - 2 * r + Math.sqrt((2 * r - 1.0)
					* (2 * r - 1.0) + 8.0 * t)) / 4.0));
			if (k > 0)
				k--;
			while (eval(k, r, t))
				k++;
			pw.printf("Case #%d: %d\n", tc, k - 1);
		}
		pw.close();
	}

	private BigInteger TWO = BigInteger.valueOf(2);

	private boolean eval(long k, long r, long t) {
		BigInteger K = BigInteger.valueOf(k);
		BigInteger R = BigInteger.valueOf(r);
		BigInteger T = BigInteger.valueOf(t);
		BigInteger expr = TWO.multiply(K.multiply(K)).add(
				(TWO.multiply(R).subtract(BigInteger.ONE)).multiply(K))
				.subtract(T);
		return expr.compareTo(BigInteger.ZERO) <= 0;
	}

	public static void main(String[] args) throws IOException {
		new A().work();
	}
}
