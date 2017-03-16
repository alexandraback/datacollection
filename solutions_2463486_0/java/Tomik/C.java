package qualification;

import java.util.Scanner;

public class C {

	static int ciph[] = new int[400];
	
	static boolean testP(long k) {
		int d = 0;
		while (k > 0) {
			ciph[d++] = (int) (k%10);
			k /= 10;
		}
		for (int i = 0; i < d/2; i++) {
			if (ciph[i] != ciph[d-i-1]) {
				return false;
			}
		}
		return true;
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			long A = sc.nextLong();
			long B = sc.nextLong();
			
			long co = 0;
			long v = (long )Math.ceil(Math.sqrt(A));
			while (v*v <= B) {
				if (testP(v) && testP(v*v)) {
					++co;
				}
				++v;
			}
			System.out.println("Case #" + i + ": " + co);
		}
	}

}
