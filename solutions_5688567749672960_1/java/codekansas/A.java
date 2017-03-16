package codejam2015.roundtwo;

import java.util.Scanner;

public class A {
	public static void main(String... args) {
		Scanner s = new Scanner(System.in);
		int T = s.nextInt();
		for (int i = 0; i < T; i++) {
			solve(i, s.nextLong());
		}
		s.close();
	}
	
	public static void solve(int case_num, long N) {
		long total = 0;
		while (true) {
			String num = Long.toString(N);
			if (num.charAt(num.length()-1) == '0') {
				N--;
				total++;
				continue;
			}
			int l = num.length();
			if (N < 10) {
				total += N;
				break;
			}
			String lh1 = num.substring(0, (l+1)/2), rh1 = num.substring((l+1)/2, l), lh2 = num.substring(0, l/2), rh2 = num.substring(l/2, l);
			if (Long.parseLong(flip(lh2)) + Long.parseLong(rh2) < Long.parseLong(flip(lh1)) + Long.parseLong(rh1)) {
				// Flip
				total++;
				rh1 = lh2;
				lh1 = rh2;
			}
			if (Long.parseLong(flip(lh2)) > 1)
				total++;
			total += Long.parseLong(flip(lh1)) + Long.parseLong(rh1);
			num = "";
			for (int i = 0; i < l - 1; i++) {
				num += "9";
			}
			if (num.length() > 0) {
				N = Long.parseLong(num);
			} else {
				break;
			}
		}
		System.out.printf("Case #%d: %d\n", case_num + 1, total);
	}
	
	public static String flip(String s) {
		String reverse = "";
		int l = s.length();
		for (int i = l-1; i >= 0; i--) {
			reverse = reverse + s.charAt(i);
		}
		return reverse;
	}
	
	public static long flip(long N) {
		return Long.parseLong(flip(Long.toString(N)));
	}
}