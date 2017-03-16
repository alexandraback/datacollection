import java.lang.*;
import java.io.*;
import java.util.*;

public class Solution {
	public static BufferedReader br;
	public static PrintWriter out;
	public static StringTokenizer stk;

	// ///////////////// TO CHANGE ///////////////////////////
	public static boolean isServer = false;

	// ///////////////// TO CHANGE ///////////////////////////

	public static void main(String[] args) throws IOException {
		if (isServer) {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
		} else {
			br = new BufferedReader(new FileReader("in.txt"));
			out = new PrintWriter(new File("out.txt"));
		}

		(new Solution()).run();
	}

	public void loadLine() {
		try {
			stk = new StringTokenizer(br.readLine());
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public String nextLine() {
		try {
			return br.readLine();
		} catch (IOException e) {
			e.printStackTrace();
			return "";
		}
	}

	public String nextWord() {
		while (stk == null || !stk.hasMoreTokens())
			loadLine();
		return stk.nextToken();
	}

	public Integer nextInt() {
		while (stk == null || !stk.hasMoreTokens())
			loadLine();
		return Integer.valueOf(stk.nextToken());
	}

	public Long nextLong() {
		while (stk == null || !stk.hasMoreTokens())
			loadLine();
		return Long.valueOf(stk.nextToken());
	}

	public Double nextDouble() {
		while (stk == null || !stk.hasMoreTokens())
			loadLine();
		return Double.valueOf(stk.nextToken());
	}

	public Float nextFloat() {
		while (stk == null || !stk.hasMoreTokens())
			loadLine();
		return Float.valueOf(stk.nextToken());
	}
	
	public void run() {
		int tt = nextInt();
		for (int t = 0; t < tt; t++) {
			int n = nextInt();
			int[] p = new int[n];
			int X = 0;
			for (int i = 0; i < n; i++) {
				p[i] = nextInt();
				X += p[i];
			}
			double[] ans = new double[n];
			for (int i = 0; i < n; i++) {
				double l = 0.0;
				double r = 1.0;
				for (int u = 0; u < 50; u++) {
					double m = (l+r)/2;
					double rem = 1.0 - m;
					double myS = p[i]+X*m;
					double ss = 0.0;
					for (int j = 0; j < n; j++) {
						if (j == i) continue;
						double s = (p[i]+X*m-p[j]) / X;
						if (s < 0) s = 0; 
						ss += s;
					}
					if (ss <= rem) {
						l = m;
					} else {
						r = m;
					}
				}
				ans[i] = l;
			}
			out.printf("Case #%d:", t+1);
			for (int i = 0; i < n; i++) {
				out.print(' ');
				out.print(ans[i]*100);
			}
			out.println();
		}
		out.flush();
	}
}
