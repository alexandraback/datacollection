import java.util.*;
import java.math.*;

public class a {
	static BigInteger r, t;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int n = in.nextInt();
		for(int casen=1; casen<=n; ++casen) {
			r = new BigInteger(in.nextLong()+""); t = new BigInteger(in.nextLong()+"");

			System.out.println("Case #"+casen+": "+(binarySearch(0, 100000000000L)-1));
		}
	}

	private static long binarySearch(long lo, long hi) {
		while(lo < hi) {
			long mid = lo + (hi-lo)/2;

			if(f(new BigInteger(mid+"")))
				hi = mid;
			else
				lo = mid+1;
		}
			
		return hi;
	}

	private static boolean f(BigInteger n) {
		BigInteger bi = new BigInteger("2").multiply(r).multiply(n).add(n).add(new BigInteger("2").multiply(n.subtract(BigInteger.ONE).multiply(n)));
		// System.out.println("D: "+bi+" "+n);
		if(bi.compareTo(t) > 0) return true;
		return false;
	}
}