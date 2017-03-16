import java.util.*;
import java.io.*;

public class A
{
	static int[][][][][] dp = new int[21][21][20][20][20];
	static{
		for(int i = 0; i<21; i++)
			for(int j = 0; j<21; j++)
				for(int k = 0; k<20; k++)
					for(int a = 0; a<20; a++)
						for(int b = 0; b<20; b++)
							dp[i][j][k][a][b] = -1;
	}
	private static int solve(final int C, final int W, final int l, final int r, final int cnt)
	{
		if(C<W) return 0;
		if(r-l+1==W) return W-cnt;
		if(dp[C][W][l][r][cnt]>=0) return dp[C][W][l][r][cnt];
		int ans = C-cnt;
		for(int i = 0; i<l; i++) ans = Math.min(ans, 1 + Math.max(solve(C,W,i,r,cnt+1), solve(C-i-1,W,l-i-1,r-i-1,cnt)));
		for(int i = r+1; i<C; i++) ans = Math.min(ans, 1 + Math.max(solve(C,W,l,i,cnt+1), solve(i,W,l,r,cnt)));
		return dp[C][W][l][r][cnt] = ans;
	}
	private static int solve(final int C, final int W)
	{
		if(C<W) return 0;
		if(C==W) return W;
		if(dp[C][W][1][0][0]>=0) return dp[C][W][1][0][0];
		int ans = C;
		for(int i = 0; i<C; i++) ans = Math.min(ans, 1+Math.max(solve(C,W,i,i,1), solve(i,W) + solve(C-i-1,W)));
		return dp[C][W][1][0][0] = ans;
	}
	public static void main(String[] klein)
	{
		final Kattio in = new Kattio(System.in);
		final PrintWriter out = new PrintWriter(System.out);

		int T = in.getInt();
		loop:for(int t = 1; t<=T; t++)
		{
			final int R = in.getInt(), C = in.getInt(), W = in.getInt();

			int cnt = (R-1)*((C)/W) + solve(C,W);

			out.println("Case #"+t+": "+cnt);
		}

		out.flush();
	}

	private static class Kattio
	{
		public Kattio(final InputStream i)
		{
			r = new BufferedReader(new InputStreamReader(i));
		}

		public boolean hasMoreTokens() {
			return peekToken() != null;
		}

		public int getInt() {
			return Integer.parseInt(nextToken());
		}

		public double getDouble() {
			return Double.parseDouble(nextToken());
		}

		public float getFloat()
		{
			return Float.parseFloat(nextToken());
		}

		public long getLong() {
			return Long.parseLong(nextToken());
		}

		public String getWord() {
			return nextToken();
		}



		private BufferedReader r;
		private String line;
		private StringTokenizer st;
		private String token;

		private String peekToken() {
		if (token == null)
			try {
			while (st == null || !st.hasMoreTokens()) {
				line = r.readLine();
				if (line == null) return null;
				st = new StringTokenizer(line);
			}
			token = st.nextToken();
			} catch (IOException e) { }
		return token;
		}

		private String nextToken() {
		String ans = peekToken();
		token = null;
		return ans;
		}
	}
}

/**

#..#H#..#

*/
