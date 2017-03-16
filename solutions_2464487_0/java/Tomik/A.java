package round1a;

import java.util.Scanner;

public class A {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			int r = sc.nextInt();
			long t = sc.nextInt();
			
			int c = 0;
			long r1 = r;
			do {
				long r2 = r1+1;
				t -= (r2*r2-r1*r1);
				if (t >= 0) {
					++c;
				}
				r1+=2;
			} while (t > 0);
			
			System.out.println("Case #" + i + ": " + c);
		}
	}

}
