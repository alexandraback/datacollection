import java.util.*;
import java.math.*;
public class A {
	static long MOD = 1000002013;
	public static void main (String [] arg) {
		Scanner sc = new Scanner(System.in);
		int T = Integer.parseInt(sc.nextLine());
		
		
		
		for (int ii = 1; ii<=T; ++ii) {
			String s = sc.next();
			String [] b = s.split("\\/");
			
			long P = Long.parseLong(b[0]);
			long Q = Long.parseLong(b[1]);
			long g = gcd(P,Q);
			P 	   = P / g;
			Q 	   = Q / g;
			boolean impossible = (Long.bitCount(Q) != 1);
			
			int ans = 0;
			while (P < Q) {
				P += P;
				ans++;
			}
			
			System.out.printf("Case #%d: %s\n",ii,(impossible) ? "impossible" : ""+ans);
		}
	}
	
	public static long gcd(long a, long b) {
		while (b != 0) {
			long tmp = b;
			b = (a % b);
			a = tmp;
		}
		return a;
	}

	
	

	
}