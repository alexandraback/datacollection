import java.io.*;
import static java.math.BigInteger.*;
import java.math.*;
import java.util.*;

public class a {

	private static BigInteger r;
	private static BigInteger t;

	public static void main(String[] args) throws Exception {

		/*
		Scanner in = new Scanner(System.in);
 	PrintStream out = System.out; 
 	/		 */
		Scanner in = new Scanner(new FileInputStream("1.in"));
	PrintWriter out = new PrintWriter(new FileWriter("1.out"));
	//	PrintStream out = System.out; 
		// */
		int T = in.nextInt(), tt = 1;

		while (T-- > 0) {
			r = in.nextBigInteger();
			t = in.nextBigInteger();
			out.printf("Case #%d: %d\n", tt++, bs(ZERO, t));
		}
		out.close();
	}

	private static BigInteger bs(BigInteger st, BigInteger end) {
		while (st.compareTo(end) < 0) {
			BigInteger mid = st.add(end).add(ONE).shiftRight(1);
			if (ok(mid))
				st = mid;
			else
				end = mid.subtract(ONE);
		}
		return st.add(ONE);
	}

	private static boolean ok(BigInteger n) {

		return (n.add(ONE)).multiply(
				n.shiftLeft(1).add(r.shiftLeft(1)).add(ONE)).compareTo(t) <= 0;

	}

}
