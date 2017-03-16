package codjam;

import java.util.*;

public class DancingWithTheGooglers {
	
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		
		for (int k = 1; k <= T; k++) {
			
			int N = in.nextInt();
			int S = in.nextInt();
			int p = in.nextInt();
			
			int c = 0;
			int To = 0;
			
			for (int i = 0; i < N; i++) {
				
				To = in.nextInt();
				int a = To/3; // Integer division
				int n = To%3;
				if (To == 0) {
					if (p == 0) c++;
				} else {
					int tmax = (n == 0) ? a : a+1;
					if (tmax >= p) {
						c++;
						continue;
					} else if (S > 0 && tmax == p-1 && (n == 0 || n == 2)) {
						S--;
						c++;
						continue;
					}
				}
				
			}
			
			System.out.println("Case #" + k + ": " + c);
			
		}
		
	}

}
