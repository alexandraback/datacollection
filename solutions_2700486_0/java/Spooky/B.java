package r1b2013;

import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

public class B
{

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in).useLocale(Locale.US);
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File("B.out"));

		for (int t = in.nextInt(), cs = 1; t > 0; t--, cs++) {
			out.print("Case #" + cs + ": ");
			
			int n = in.nextInt(), x = in.nextInt(), y = in.nextInt();
			int a = (K-1)/2 + (x - y)/2;
			int b = (K-1)/2 + (x + y)/2;
			if (a < 0 || a >= K || b < 0 || b >= K) out.println("0.0");
			else out.println(1.0*cnt[n-1][a][b]/(1 << n));
		}
		
		out.flush();
	}

	static final int N = 20, K = 7;
	static final int[][][] cnt = new int[N][K][K];
	static {
		solve(0, new boolean[K][K]);
	}
	
	static void solve(int p, boolean[][] b) {
		if (p >= N) return;
		
		int[] posLeft = fallLeft(b);
		b[posLeft[0]][posLeft[1]] = true;
		count(p, b);
		solve(p+1, b);
		b[posLeft[0]][posLeft[1]] = false;
		
		int[] posRight = fallRight(b);
		b[posRight[0]][posRight[1]] = true;
		count(p, b);
		solve(p+1, b);
		b[posRight[0]][posRight[1]] = false;
	}
	
	static int[] fallLeft(boolean[][] b) {
		int x = 0, y = K-1;
		while (!b[x+1][y-1] && x != y) {
			x++;
			y--;
		}
		if (x == y) return new int[]{x, y};
		while (x != y && !b[x][y-1]) {
			y--;
		}
		while (x != y && !b[x+1][y]) {
			x++;
		}
		return new int[]{x, y};
	}
	
	static int[] fallRight(boolean[][] b) {
		int x = 0, y = K-1;
		while (!b[x+1][y-1] && x != y) {
			x++;
			y--;
		}
		if (x == y) return new int[]{x, y};
		while (x != y && !b[x+1][y]) {
			x++;
		}
		while (x != y && !b[x][y-1]) {
			y--;
		}
		return new int[]{x, y};
	}
	
	static void count(int p, boolean[][] b) {
		for (int i = 0; i < K; i++)
			for (int j = 0; j < K; j++)
				if (b[i][j])
					cnt[p][i][j]++;
	}
}
