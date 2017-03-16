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
			int[] arr = new int[n];
			int sum = 0;
			for (int i = 0; i < n; i++) {
				arr[i] = nextInt();
				sum += arr[i];
			}
			int M = 100000*20;
			int[] ff = new int[M];
			out.printf("Case #%d:\n", t+1);
			for (int m = 0; m < (1<<n); m++) {
				int s = 0;
				for (int i = 0; i < n; i++) {
					if (((m>>i)&1) == 1) {
						s += arr[i];
					}
				}
				if (ff[s] != 0) {
					int m1 = ff[s];
					for (int i = 0; i < n; i++) {
						if (((m1>>i)&1) == 1) {
							out.print(arr[i]);
							out.print(' ');
						}
					}
					out.println();
					for (int i = 0; i < n; i++) {
						if (((m>>i)&1) == 1) {
							out.print(arr[i]);
							out.print(' ');
						}
					}
					break;
				} else {
					ff[s] = m;
				}
			}
			out.println();
		}
		out.flush();
	}
}
