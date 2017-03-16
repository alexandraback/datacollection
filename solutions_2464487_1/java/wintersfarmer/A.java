import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.StringTokenizer;


public class A {
	public static void run() throws IOException {
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("out.txt")));
		BufferedReader in = new BufferedReader(new FileReader("in.txt"));
		
		int caseN = Integer.parseInt(in.readLine());
		for (int caseIndex = 0; caseIndex < caseN; caseIndex++) {
			String input[] = in.readLine().split(" ");
			BigInteger r = new BigInteger(input[0]);
			BigInteger t = new BigInteger(input[1]);
			out.println("Case #" + (caseIndex + 1) + ": " + solve(r, t));
		}
		in.close();
		out.close();
	}
	
	public static BigInteger solve(BigInteger r, BigInteger t) {
		BigInteger b = r.multiply(new BigInteger("2")).add(new BigInteger("3"));
		BigInteger c = r.multiply(new BigInteger("2")).add(BigInteger.ONE).subtract(t);
		BigInteger b24ac = b.multiply(b).subtract(c.multiply(new BigInteger("8")));
		BigInteger result = sqrt(b24ac).subtract(b).divide(BigInteger.valueOf(4));
		return result.add(BigInteger.ONE);
	}
	public static BigInteger sqrt(BigInteger n) {
		BigInteger two = BigInteger.valueOf(2);
		BigInteger b = n;
		BigInteger a = BigInteger.ZERO;
		while (b.subtract(a).compareTo(BigInteger.ONE) == 1) {
			BigInteger c = a.add(b).divide(two);
			BigInteger cc = c.multiply(c);
			switch(cc.compareTo(n)) {
			case 0:
				return c;
			case -1:
				a = c;
				break;
			case 1:
				b = c;
				break;
			}
		}
		return a;
	}
}
