import java.math.*;
import java.io.*;
import java.util.*;

class A {
	static Scanner scanner = new Scanner(System.in);

	static BigInteger sqrt(BigInteger i) {
		BigInteger a, b = BigInteger.ONE.shiftLeft((i.bitLength() + 1) >> 1);
		do {
			a = b;
			b = a.add(i.divide(a)).shiftRight(1);
		} while(b.compareTo(a) < 0);
		return a;
	}

	static BigInteger solve() throws IOException {
		BigInteger	r, t;

		r = new BigInteger(scanner.next());
		t = new BigInteger(scanner.next());

		return r.multiply(new BigInteger("-2")).add(BigInteger.ONE).add(sqrt(r.multiply(new BigInteger("2")).subtract(BigInteger.ONE).pow(2).add(new BigInteger("8").multiply(t)))).divide(new BigInteger("4"));
	}

	public static void main(String []argv) throws IOException {
		int T = scanner.nextInt();
		for(int i = 0 ; i < T ; ++i)
			System.out.println("Case #" + String.valueOf(i + 1) + ": " + solve().toString());
	}
}

