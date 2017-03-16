package round1c;

import java.util.Scanner;

public class ProblemC {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int cases = sc.nextInt();

		for (int cs = 1; cs <= cases; cs++) {

			int n = sc.nextInt();

			int m = sc.nextInt();

			int k = sc.nextInt();

			int temp = n;
			
			n = Math.max(n, m);

			m = Math.min(temp, m);

			int []ans = new int[n*m + 1];
			
			for(int i = 0 ; i < ans.length; i++) {
				ans[i] = k;
			}
			
			if ((m == 3) && (n == 3)) {
				for(int i = 5; i < ans.length; i++) {
					ans[i] = k - 1;
				}
			}
			
			if ((m == 3) && (n == 4)) {
				for(int i = 5; i <= 7; i++) {
					ans[i] = k - 1;
				}

				for(int i = 8; i < ans.length; i++) {
					ans[i] = k - 2;
				}
			}

			if ((m == 3) && (n == 5)) {
				
				for(int i = 5; i <= 7; i++) {
					ans[i] = k - 1;
				}
				 
				for(int i = 8; i <= 10; i++) {
					ans[i] = k - 2;
				}
				
				for(int i = 11; i <= 15; i++) {
					ans[i] = k - 3;
				}
			}

			if ((m == 3) && (n == 6)) {
				
				for(int i = 5; i <= 7; i++) {
					ans[i] = k - 1;
				}
				 
				for(int i = 8; i <= 10; i++) {
					ans[i] = k - 2;
				}
				
				for(int i = 11; i <= 13; i++) {
					ans[i] = k - 3;
				}
				
				for(int i = 14; i <= 18; i++) {
					ans[i] = k - 4;
				}
			}

			if ((m == 4) && (n == 4)) {

				for(int i = 5; i <= 7; i++) {
					ans[i] = k - 1;
				}
				
				for(int i = 8; i <= 10; i++) {
					ans[i] = k - 2;
				}
				
				for(int i = 11; i <= 12; i++) {
					ans[i] = 8;
				}
				
				for(int i = 13; i <= 16; i++) {
					ans[i] = k - 4;
				}
			}
			
			if ((m == 4) && (n == 5)) {
				
				for(int i = 5; i <= 7; i++) {
					ans[i] = k - 1;
				}
				
				for(int i = 8; i <= 10; i++) {
					ans[i] = k - 2;
				}
				
				for(int i = 11; i <= 12; i++) {
					ans[i] = 8;
				}
				
				for(int i = 13; i <= 14; i++) {
					ans[i] = k - 4;
				}
				
				for(int i = 15; i <= 16; i++) {
					ans[i] = 10;
				}
				
				for(int i = 17; i <= 20; i++) {
					ans[i] = k - 6;
				}
			}

			System.out.println("Case #" + cs + ": " + ans[k]);
		}
	}
}
