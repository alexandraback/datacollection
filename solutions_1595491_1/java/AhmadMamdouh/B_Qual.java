import java.io.*;
import java.util.*;

public class B_Qual {
	static int n, s, score;
	static int inf = 1 << 25;
	static int[][] dp = new int[128][128];
	static int[] points=new int[128];
	public static int go(int index, int surprise) {
		if(surprise>s)return -inf;
		if (index == n) {
			if (surprise == s)
				return 0;
			return -inf;
		}
		if (dp[index][surprise] != -1)
			return dp[index][surprise];
		int res = 0;
		for (int i = 0; i <= 10; i++) {
			for (int j = -1; j <= 1; j++) {
				for (int k = -1; k <= 1; k++) {
					int a = i, b = i + j, c = i + k;
					int max = Math.max(Math.max(a, b), c);
					if (a+b+c==points[index]&&ValidTriple(a,b,c)&&!surp(a,b,c)) {
						if (max >= score)
							res = Math.max(res, 1 + go(index + 1, surprise));
						else
							res = Math.max(res, go(index + 1, surprise));
					}
				}
			}
		}
		for (int i = 0; i <= 10; i++) {
			for (int j = -2; j <= 2; j ++) {
				for (int k = -2; k <= 2; k ++) {
					int a = i, b = i + j, c = i + k;
					int max = Math.max(Math.max(a, b), c);
					if (a+b+c==points[index]&&ValidTriple(a,b,c)&&surp(a,b,c)) {
						if (max >= score)
							res = Math.max(res, 1 + go(index + 1, surprise + 1));
						else
							res = Math.max(res, go(index + 1, surprise + 1));
					}
				}
			}
		}
		return dp[index][surprise] = res;
	}

	private static boolean surp(int a, int b, int c) {
		int[] x={a,b,c};
		for (int i = 0; i < x.length; i++) {
			for (int j = 0; j < x.length; j++) {
				if(x[i]-x[j]==2)return true;
			}
		}
		return false;
	}

	private static boolean ValidTriple(int a, int b, int c) {
		int[] x={a,b,c};
		Arrays.sort(x);
		for (int i = 0; i < x.length; i++) {
			if(!valid(x[i]))
				return false;
		}
		for (int i = 0; i < x.length; i++) {
			for (int j = i+1; j < x.length; j++) {
				if(x[j]-x[i]>2)
					return false;
			}
		}
		return true;
	}

	private static boolean valid(int a) {
		return a >= 0 && a <= 10;
	}

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int tt = 1; tt <= T; tt++) {
			for (int[] x : dp)
				Arrays.fill(x, -1);
			n = in.nextInt();
			s = in.nextInt();
			score = in.nextInt();
			for(int i=0;i<n;i++){
				points[i]=in.nextInt();
			}
			System.out.printf("Case #%d: %d\n", tt, go(0, 0));
		}
	}
}