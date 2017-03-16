import java.util.*;
import java.io.*;


public class B {
	static int N, NN;
	static int dp[];
	static int cost[];
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(System.in);
		System.setOut(new PrintStream(new File("B.out")));
		
		int T = sc.nextInt();
		for(int tc = 1; tc <= T; tc++) {
			N = sc.nextInt();
			NN = 2 * N;
			dp = new int[1 << NN];
			Arrays.fill(dp, -1);
			cost = new int[NN];
			for(int i=0; i<NN; i++)
				cost[i] = sc.nextInt();
			int ans = search(0);		
			if (ans < 1 << 29)System.out.printf("Case #%d: %d\n", tc, ans);
			else System.out.printf("Case #%d: Too Bad\n", tc);
		}
	}
	static int search(int S) {
		if(dp[S] >= 0) return dp[S];
		boolean ok = true;
		int cnt = 0;
		for(int i=1; i < NN; i+=2)
			if((S & (1 << i)) == 0) {
				ok = false;
				if((S & (1 << (i-1))) > 0) cnt++;
			} else {
				cnt += 2;
			}
		if(ok) return 0;
		int res = 1 << 29;
		for(int i=0; i < NN; i++) {
			if((S & (1 << i)) > 0) continue;
			if(cost[i] > cnt) continue;
			res = Math.min(search(S | (1 << i)) + 1, res);
		}
		return dp[S] = res;
	}
}
