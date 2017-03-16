package CodeJam2015;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Round1B_A2 {
	
	static long distp[] = new long[15];
	
	static long reverse(long n) {
		long ans = 0;
		while (n > 0) {
			ans = ans*10 + (n % 10);
			n /= 10;
		}
		return ans;
	}
	
	static int size(long n) {
		int ans = 0;
		while (n > 0) {
			ans++;
			n /= 10;
		}
		return ans;
	}
	
	static long tento(int x) {
		long ans = 1;
		while (x-- > 0)
			ans *= 10;
		return ans;
	}

	public static void main(String[] args) {
		distp[0] = 1;
		distp[1] = 10;
		long a = 10;
		long b = 10;
		for (int i = 2; i < distp.length; i++) {
			//from 1000 0000 -> 1000 9999 -> 9999 0001 -> 9999 9999 -> 1000 00000
			distp[i] = distp[i-1] + b-1 + 1 + a-2 + 1;
			if (i % 2 == 0)
				b *= 10;
			else
				a *= 10;
			//System.out.println(i + ": " + distp[i]);
		}
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int cases = 1; cases <= T; cases++) {
			long N = sc.nextLong();
			if (N <= 19) {
				System.out.println("Case #" + cases + ": " + N);
				continue;
			}
			//from 1000 0000 -> 1000 rev(X) -> X 0001 -> X Y
			int siz = size(N);
			if (N == tento(siz-1)) {
				System.out.println("Case #" + cases + ": " + distp[siz-1]);
				continue;
			}
			int x = siz/2;
			int y = siz - x;
			long tentoo = tento(y);
			long Y = N % tentoo;
			long X = N / tentoo;
			if (Y == 0) {
				Y = tentoo;
				X--;
				//from 1000 0000 -> 1000 rev(X') -> X' 0001 -> X' 9999 -> X 0000
			}
			if (X == tento(x-1)) {
				System.out.println("Case #" + cases + ": " + (distp[siz-1]+Y));
				continue;
			}
			//from 1000 0000 -> 1000 rev(X) -> X 0001 -> X Y
			long ans = distp[siz-1] + reverse(X) + 1 + Y-1;
			System.out.println("Case #" + cases + ": " + ans);
		}
		sc.close();
	}

}
