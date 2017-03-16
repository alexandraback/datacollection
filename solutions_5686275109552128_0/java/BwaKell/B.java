import java.util.*;
import java.io.*;

public class B
{
	public static void main(String[] klein)
	{
		final Kattio in = new Kattio(System.in);
		final PrintWriter out = new PrintWriter(System.out);

		int T = in.getInt();
		loop:for(int t = 1; t<=T; t++)
		{
			final int D = in.getInt();
			final int[] cnt = new int[1001];

			for(int i = 0; i<D; i++) cnt[in.getInt()]++;

			int best = 1000;
			for(; cnt[best]==0; --best);
			int time = 0;
			for(int i = best; time<best && i>0; --i)
			if(cnt[i]>0)
			{
				if(time+i<best) best = time+i;
				time += cnt[i];
				cnt[i/2] += cnt[i];
				cnt[i-i/2] += cnt[i];
			}

			out.println("Case #"+t+": "+best);
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
