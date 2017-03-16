import java.io.*;
import java.util.*;

class energy {
	public static void main (String [] args) throws IOException {
		long start = System.currentTimeMillis();
		BufferedReader br = new BufferedReader(new FileReader("energy.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("energy.out")));
		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int E = Integer.parseInt(st.nextToken());
			int R = Integer.parseInt(st.nextToken());
			if (R > E) R = E;
			int N = Integer.parseInt(st.nextToken());
			int[] vals = new int[N];
			int[][] dp = new int[E+1][N];
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				vals[j] = Integer.parseInt(st.nextToken());
			}
			if (N == 1) out.println("Case #" + (i+1) + ": " + (E*vals[0]));
			else if (R == E) {
				int sum = 0;
				for (int j = 0; j < N; j++) {
					sum += E*vals[j];
				}
				out.println("Case #" + (i+1) + ": " + sum);
			}
			else {
				for (int j = R; j <= E; j++) {
					dp[j][0] = (E-j+R)*vals[0];
				}
				for (int j = 1; j < N; j++) {
					for (int k = R; k <= E; k++) {
						dp[k][j] = -1;
						for (int l = Math.max(R, k-R); l <= E; l++) {
							dp[k][j] = Math.max(dp[k][j], (l+R-k)*vals[j] + dp[l][j-1]);
						}
					}
				}
				int answer = 0;
				for (int j = R; j <= E; j++) {
					answer = Math.max(answer, dp[j][N-1]);
				}
				out.println("Case #" + (i+1) + ": " + answer);
			}
		}
		long end = System.currentTimeMillis();
		System.out.println(end-start);
		out.close();
		System.exit(0);
	}
}

