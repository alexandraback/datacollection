import java.math.BigInteger;
import java.util.Scanner;

public class ProbA {

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);

		int T = in.nextInt();

		for (int caseNum = 1; caseNum <= T; caseNum++) {
			long r = in.nextLong();
			long t = in.nextLong(); 
			
			long res = 1;
			
			long low = 1;
			long high = 1000000000000000l;
			
			BigInteger two = BigInteger.valueOf(2);
			BigInteger br = BigInteger.valueOf(r);
			BigInteger bt = BigInteger.valueOf(t);
			while ( true ) {
				long mid = (low + high) / 2;
				BigInteger bmid = BigInteger.valueOf(mid);
				BigInteger needed = two.multiply(bmid).multiply(bmid).add(two.multiply(br).subtract(BigInteger.ONE).multiply(bmid));
				int cmp = needed.compareTo(bt);
				if (cmp < 0) {
					if ( mid == low) {
						res = mid;
						break;
					}
					low = mid;
				} else if (cmp > 0) {
					high = mid;
				} else {
					res = mid;
					break;
				}
			}
			
			System.out.printf("Case #%d: %d%n", caseNum, res);
		}
	}

}
