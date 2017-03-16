package r1a2012;

import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

public class B {

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in).useLocale(Locale.US);
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File("B.out"));

		for (int t = in.nextInt(), cs = 1; t > 0; t--, cs++) {
			out.print("Case #" + cs + ": ");
			
			int n = in.nextInt();
			s = new int[n][2];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < 2; j++) {
					s[i][j] = in.nextInt();
				}
			}
			
			state = new int[n];
			int ans = 0;
			x = 0;
			
			while (true) {
				int best = -1;
				for (int i = 0; i < n; i++) {
					if (state[i] < 2 && can(i) > 0) {
						if (best == -1 || better(i, best)) {
							best = i;
						}
					}
				}
				
				if (best == -1) break;
				go(best);
				ans++;
				if (x == 2*n) break;
			}
			
			out.println(x == 2*n ? ans : "Too Bad");
		}
		
		out.flush();
	}

	
	static int[][] s;
	static int[] state;
	static int x;
	
	static boolean better(int a, int b) {
		int canA = can(a), canB = can(b);
		if (canB > canA) return false;
		if (canA > canB) return true;
		if (canA == 2 && canB == 2) return false;
		if (canA == 1 && canB == 1) {
			if (state[b] == 1) return false;
			if (state[a] == 1) return true;
			return s[a][1] > s[b][1];
		}
		return false;
	}
	
	static int can(int a) {
		if (state[a] == 0) {
			if (x >= s[a][1]) return 2;
			else if (x >= s[a][0]) return 1;
			else return 0;
		}
		else if (state[a] == 1) {
			if (x >= s[a][1]) return 1;
			else return 0;
		}
		else return 0;
	}
	
	static void go(int a) {
		if (state[a] == 0) {
			if (x >= s[a][1]) {
				state[a] = 2;
				x += 2;
			}
			else if (x >= s[a][0]) {
				state[a] = 1;
				x += 1;
			}
		}
		else if (state[a] == 1) {
			if (x >= s[a][1]) {
				state[a] = 2;
				x += 1;
			}
		}
	}
}
