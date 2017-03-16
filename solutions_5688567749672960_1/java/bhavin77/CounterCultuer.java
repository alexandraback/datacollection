package round1b;

import java.util.Scanner;


public class CounterCultuer {
	
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		
		for(int zz = 1; zz <= T;zz++){

			long N = in.nextLong();
			
			long count = 0;
			long t = 0;
			while (N>=1) {
				
				
				
				
				if (N > (t = reverse(N))) {
					N = t;					
				} else {
					N--;
				}				
				count++;
//				System.out.println(count + " :" + N);
			}
						
			System.out.format("Case #%d: %d\n", zz, count);
		}		
	}
	
	static long reverse(long n) {
		String s = "" + n;
		if (s.length() > 1) {
			s = s.substring(s.length() - (s.length()/2));		
			if (Long.parseLong(s)==1) {
				long reverse = 0;
				while (n>0) {
					reverse = reverse*10 + n%10;
					n = n/10;
				}
				return reverse;
			}
		}
		
		
		return n;
	}
}
