import java.util.*;
import java.io.*;

public class B {
	static int dp[][];
	static int N, S, p, t[];
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(System.in);
		System.setOut(new PrintStream(new File("B.out")));
		int T = sc.nextInt();
		for(int ca = 1; ca <= T; ca++) {
			N = sc.nextInt();
			S = sc.nextInt();
			p = sc.nextInt();
			t = new int[N];
			for(int i=0; i<N; i++)
				t[i] = sc.nextInt();
			dp = new int[N+1][S+1];
			for(int i=0; i<=N; i++)
				Arrays.fill(dp[i], -1);
			int ans = Math.max(search(N, S), 0);
			System.out.printf("Case #%d: %d\n", ca, ans);
		}
	}
	static int search(int n, int s) {
		if(s < 0) return -10000;
		if(n == 0 && s > 0) return -10000;
		if(n == 0) return 0;
		if(dp[n][s] >= 0) return dp[n][s];
		int res = 0;
		for(int x=0; x<=10; x++) {
			for(int y=x; y<=x+2&&y<=10; y++) {
				int z = t[n-1] - x - y;
				if(z < 0 || z > 10) continue;
				if(z < y - 2 || z > x + 2) continue;
				int max = Math.max(y, z);
				if(Math.abs(x - y) == 2 || Math.abs(x-z) == 2 || Math.abs(y-z) == 2) {
					if(max >= p) res = Math.max(res, search(n-1, s-1) + 1);
					else res = Math.max(res, search(n-1, s-1));
				} else {
					if(max >= p) res = Math.max(res, search(n-1, s) + 1);
					else res = Math.max(res, search(n-1, s));
				}
			}
		}
		return dp[n][s] = res;
	}
}
