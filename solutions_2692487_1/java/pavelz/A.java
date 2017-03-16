package round1b;

import java.util.Arrays;
import java.util.Scanner;

public class A {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int tt =0;tt<t;tt++) {
			long a = sc.nextLong();
			int n = sc.nextInt();
			long motes[] = new long[n];
			for(int i=0;i<n;i++) motes[i] = sc.nextLong();
			Arrays.sort(motes);
			int min = n;
			int added = 0;
			if (a != 1) { 
				for(int i=0;i<n;i++) {
					while (a <= motes[i]) {
						added++;
						a += a - 1;
					}
					a += motes[i];
					if (added + n - i - 1 < min) min = added + n - i - 1;
				}
			}
			System.out.println("Case #" + (tt + 1) + ": " + min);
			
		}
		sc.close();

	}

}
