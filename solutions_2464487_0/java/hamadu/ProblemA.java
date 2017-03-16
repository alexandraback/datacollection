import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;


public class ProblemA {
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		
		int T = in.nextInt();
		for (int cn = 1 ; cn <= T ; cn++) {
			long r = in.nextLong();
			long t = in.nextLong();
			out.println("Case #" + cn + ": " + solve(r, t));
		}
		out.flush();
	}

	
	private static long solve(long r, long t) {
		long min = 0;
		long max = Long.MAX_VALUE - 100;
		for (int cur = 0 ; cur < 200 ; cur++) {
			long med = (min + max) / 2;
			if (isok(r, t, med)) {
				min = med;
			} else {
				max = med;
			}
		}
		
		long ans = min;
		for (long ad = 0 ; ad <= 2 ; ad++) {
			long tr = min+ad;
			if (isok(r, t, tr)) {
				ans = tr;
			}
		}
		return ans;
	}


	private static boolean isok(long r, long t, long tr) {
		if (tr == 0) {
			return true;
		}
		BigInteger have = BigInteger.valueOf(t);
		BigInteger paint = BigInteger.valueOf(r);
		paint = paint.multiply(BigInteger.valueOf(2));
		paint = paint.multiply(BigInteger.valueOf(tr));
		
		BigInteger paint2 = BigInteger.valueOf(4);
		paint2 = paint2.multiply(BigInteger.valueOf(tr));
		paint2 = paint2.subtract(BigInteger.valueOf(2));
		paint2 = paint2.multiply(BigInteger.valueOf(tr));
		paint2 = paint2.divide(BigInteger.valueOf(2));
		
		paint = paint.add(paint2);
		
		// TODO Auto-generated method stub
		return have.compareTo(paint) >= 0;
	}


	public static void debug(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}
}
