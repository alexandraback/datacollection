import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class A {

	void solve() throws IOException {
		int t=nextInt();
		for(int testCase=0;testCase<t;testCase++){
			int a=nextInt();
			int n=nextInt();
			int[] b=new int[n];
			for(int i=0;i<n;i++)
				b[i]=nextInt();
			Arrays.sort(b);
			int[][] dp=new int[n+1][1000001];
			for(int i=0;i<=n;i++)
				for(int j=0;j<1000001;j++)
					dp[i][j]=1000000000;
			dp[0][a]=0;
			for(int i=0;i<n;i++){
				for(int j=1;j<1000001;j++){
					if(j>b[i])
						dp[i+1][Math.min(j+b[i],1000000)]=Math.min(dp[i+1][Math.min(j+b[i],1000000)],dp[i][j]);
					else{
						dp[i+1][j]=Math.min(dp[i+1][j],dp[i][j]+1);
						int x=j;
						if(x==1)continue;
						int add=0;
						while(x<=b[i]){
							x+=x-1;
							add++;
						}
						dp[i+1][Math.min(1000000,x+b[i])]=Math.min(dp[i+1][Math.min(1000000,x+b[i])],dp[i][j]+add);
					}
				}
			}
			int ans=dp[n][0];
			for(int i=1;i<1000001;i++)
				ans=Math.min(ans,dp[n][i]);
			out.printf("Case #%d: %d\n",testCase+1,ans);
		}

	}

	public static void main(String[] args) throws IOException {
		new A().run();
	}

	void run() throws IOException {
//		reader = new BufferedReader(new InputStreamReader(System.in));
		reader = new BufferedReader(new FileReader("input.txt"));
		tokenizer = null;
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
