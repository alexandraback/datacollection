import java.util.*;
import java.math.*;

class p1 {
	public static void main(String[]sadsac ) {
		Scanner in = new Scanner(System.in);

		int T = in.nextInt();
		in.nextLine();
		for (int t = 0; t < T; t++) {
			System.out.print("Case #"+(t+1)+": ");
			String[] nums =in.nextLine().split("/");
			BigInteger P = new BigInteger(nums[0]);
			BigInteger Q = new BigInteger(nums[1]);
			BigInteger n = P.gcd(Q);
			P = P.divide(n);
			Q = Q.divide(n);
			long value = Q.longValue();
			
			double gen = Math.log(value)/Math.log(2);
			long gen1 = (long)(Math.log(value)/Math.log(2));
			if (Math.abs(gen - gen1) < Math.pow(10, -6) && gen1 < Math.pow(2, 40)) System.out.println(gen1 - (long)(Math.log(P.longValue())/Math.log(2)) );
			else System.out.println("impossible"); 
		}
	}
}


