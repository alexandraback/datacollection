import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class Codejam2014QA {
	public static void main(String[] args) throws IOException {
		new Codejam2014QA().run();
	}

	final static int MAX = 50;
	final static int FAIL = -1;
	int[][][] dp = new int[MAX+1][MAX+1][MAX*MAX+1];

	boolean solve(int W, int H, int G) {
		for (int pos = 0; pos <= H; pos++)
			for (int prev = 0; prev <= W; prev++)
				Arrays.fill(dp[pos][prev], FAIL);
		
		boolean deg = W == 1 || H == 1;
		
		// The last+1 row can only have 0 width
		for (int prev = 0; prev <= W; prev++)
			dp[H][prev][0] = 0;
		
		// The last row can (normally) not get larger than the previous
		if (!deg) {
			for (int prev = 0; prev <= W; prev++) {
				Arrays.fill(dp[H-1][prev], FAIL);
				dp[H-1][prev][prev] = prev;
			}
			dp[H-1][0][1] = 1;
		}
		
		// Middle rows
		for (int p = deg ? H-1 : H-2; p >= 0; p--) {
			for (int prev = 0; prev <= W; prev++) {
				
				for (int goal = 0; goal <= G; goal++) {
					for (int val = prev; val <= W && val <= goal; val++) {
						if (dp[p+1][val][goal-val] != FAIL &&
								!(prev==0 && val==1 && !deg))
							dp[p][prev][goal] = val;
					}
				}
				
				
			}
		}
		
		return dp[0][0][G] != FAIL;
	}
	
	void print(int W, int H, int G) {
		int prev = 0;
		int goal = G;
		char[][] ar = new char[H][W];
		for (int y = 0; y < H; y++) {
			int val = dp[y][prev][goal];
			for (int x = 0; x < val; x++)
				ar[y][x] = '.';
			for (int x = val; x < W; x++)
				ar[y][x] = '*';
			prev = val;
			goal -= val;
		}
		ar[H-1][0] = 'c';
		for (char[] row : ar) {
			System.out.println(new String(row));
		}
	}
	
	
	
	public void run() throws IOException {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			int H = in.nextInt();
			int W = in.nextInt();
			int M = in.nextInt();
			int G = H*W-M;
			System.out.println("Case #"+t+":");
			if (solve(W,H,G))
				print(W,H,G);
			else
				System.out.println("Impossible");
		}
	}
}
