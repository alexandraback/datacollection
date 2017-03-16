package round1c;

import java.util.Scanner;

public class ProblemA {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int cases = sc.nextInt();

		for (int cs = 1; cs <= cases; cs++) {
			
			String str = sc.next();
			
			long num = Long.parseLong(str.substring(0, str.indexOf("/")));
			
			long den = Long.parseLong(str.substring(str.indexOf("/")+1));
			
			long gc = gcd(num, den);
			
			num /= gc;
			
			den /= gc;
			
			long mask = 1L;
			
			long power = 1L;
			
			boolean found = false;
			
			for (int i = 0; i < 50; i++) {
				if ((den & (mask << i)) == den) {
					found = true;
					power = i;
					break;
				}
			}
			 
			if(!found) {
				System.out.println("Case #" + cs + ": impossible");
			} else {
				
				long ans = power;
				
				int i = 1;
				
				long mask2 = 1L;
				
				while(num > (mask2 << i)) {
					ans--;
					i++;
				}
				
				System.out.println("Case #" + cs + ": " + ans);	
			}
		}
	}
	
	public static long gcd(long a, long b) {
		long t = 0;
		while (b != 0) {
			t = b;
			b = a % b;
			a = t;
		}
		return a;
	}
}
