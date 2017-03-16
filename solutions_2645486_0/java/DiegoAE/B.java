import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class B {

	
	static class Scanner{
		BufferedReader br=null;
		StringTokenizer tk=null;
		public Scanner(){
			br=new BufferedReader(new InputStreamReader(System.in));
		}
		public String next() throws IOException{
			while(tk==null || !tk.hasMoreTokens())
				tk=new StringTokenizer(br.readLine());
			return tk.nextToken();
		}
		public int nextInt() throws NumberFormatException, IOException{
			return Integer.valueOf(next());
		}
		public long nextLong() throws NumberFormatException, IOException{
			return Long.valueOf(next());
		}
	}
	
	static Integer[][] dp;
	static int N,E,R;
	static int[] v;
	
	static int dp(int e, int i){
		if (i == N)
			return 0;
		if (dp[e][i] != null)
			return dp[e][i];
		int max = 0;
		for(int j = 0; j <= e; j++)
			max = Math.max(max, dp(Math.min(e - j + R, E), i + 1) + v[i] * j);
		dp[e][i] = max;
		return max;
	}
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner sc = new Scanner();
		int T = sc.nextInt();
		for(int c = 1; c <= T; c++){
			E = sc.nextInt();
			R = sc.nextInt();
			N = sc.nextInt();
			v = new int[N];
			for(int i = 0; i < N; i++)
				v[i] = sc.nextInt();
			dp = new Integer[E + 1][N];
			System.out.printf("Case #%d: %d\n",c,dp(E,0));
		}
	}
}
