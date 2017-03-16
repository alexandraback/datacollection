import java.io.FileInputStream;
import java.math.BigInteger;
import java.util.Scanner;

public class A {
	
	private static BigInteger sqrt(BigInteger n) {
		BigInteger a = BigInteger.ONE;
		BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
		while(b.compareTo(a) >= 0) {
			BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
			if(mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
			else a = mid.add(BigInteger.ONE);
		}
		return a.subtract(BigInteger.ONE);
	}	

	private static String process(Scanner in) {
		long r = in.nextLong();
		long t = in.nextLong();
		double a = 2;
		BigInteger b = new BigInteger(Long.toString(2*r-1));
		BigInteger c = new BigInteger(Long.toString(-t));
		BigInteger eight = new BigInteger("8");
		long res = (long)((sqrt(b.multiply(b).subtract(c.multiply(eight))).subtract(b).longValue())/2/a);
		return Long.toString(res);
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in.available() > 0 ? System.in : 
			new FileInputStream(Thread.currentThread().getStackTrace()[1].getClassName() + ".practice.in"));
		int T = in.nextInt();
		for(int i = 1; i <= T; i++) 
			System.out.format("Case #%d: %s\n", i, process(in));
	}
}
