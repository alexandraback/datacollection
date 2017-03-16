import static java.math.BigInteger.ONE;

import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class A_Bullseye {
	
	static final int INF = 1 << 28, MAX = 1000;
	static final double EPS = 1E-9;
	static BigInteger S;
	static BigInteger TWO = new BigInteger("2");
	static BigInteger FOUR = new BigInteger("4");
	
	static BigInteger f(BigInteger x) {
		return x.subtract(ONE).multiply(FOUR).add(S);
	}
	
	static BigInteger sum(BigInteger n) {
		return n.multiply(S.add(f(n))).divide(TWO);
	}
	
	static void solve() {
		Scanner scan = new Scanner(in);
		int T = scan.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			out.print("Case #" + tc + ": ");
			BigInteger r = scan.nextBigInteger();
			BigInteger t = scan.nextBigInteger();
			
			S = r.add(BigInteger.ONE).pow(2).subtract(r.pow(2));
			BigInteger l = BigInteger.ONE;
			BigInteger u = t;
			while (l.compareTo(u.subtract(FOUR)) <= 0) {
				BigInteger m = l.add(u).divide(TWO);
				BigInteger x = sum(m);
				if (x.compareTo(t) <= 0)
					l = m;
				else
					u = m;
					
			}
			while (sum(l).compareTo(t) <= 0)
				l = l.add(ONE);
			out.println(l.subtract(ONE));
		}
	}
	
	static String read() {
		try { return in.readLine(); } catch (IOException e) { return null; }
	}
	public static void main(String[] args) throws IOException {
//		in = new BufferedReader(new InputStreamReader(System.in));
//		out = new PrintWriter(new BufferedOutputStream(System.out));
		String file = "A-large";
		in = new BufferedReader( new FileReader(file + ".in") );
		out = new PrintWriter( new FileOutputStream(file + "_" + System.currentTimeMillis() + ".out") );
		solve(); out.flush();
	}
	static BufferedReader in; static PrintWriter out;
}
