import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class B {

	void solve() throws IOException {
		int t=nextInt();
		for(int testCase=0;testCase<t;testCase++){
			int e=nextInt();
			int r=nextInt();
			int n=nextInt();
			int[] v=new int[n];
			for(int i=0;i<n;i++)
				v[i]=nextInt();
			int[][] dp=new int[n+1][e+1];
			for(int i=0;i<n;i++){
				for(int j=0;j<=e;j++){
					for(int k=0;k<=j;k++){
						int ne=Math.min(e,j-k+r);
						dp[i+1][ne]=Math.max(dp[i+1][ne],dp[i][j]+v[i]*k);
					}
				}
			}
			int ans=0;
			for(int i=0;i<=e;i++)
				ans=Math.max(ans,dp[n][i]);
			out.printf("Case #%d: %d\n",testCase+1,ans);
		}

	}

	public static void main(String[] args) throws IOException {
		new B().run();
	}

	void run() throws IOException {

		tokenizer = null;
//		reader = new BufferedReader(new InputStreamReader(System.in));
		reader = new BufferedReader(new FileReader("input.txt"));
//		out = new PrintWriter(new OutputStreamWriter(System.out));
		out = new PrintWriter(new FileWriter("output.txt"));
		solve();
		reader.close();
		out.flush();

	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter out;

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}
}
