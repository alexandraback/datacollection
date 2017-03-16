import java.util.*;
import java.io.*;

public class War
{
	private static int dWar(final double[] n, final double[] k, final int N)
	{
		int score = 0;
		for(int i = 0, j = 0; ; j++, i++)
		{
			while(i<N && n[i]<k[j]) ++i;
			if(i==N) break;
			++score;
		}
		return score;
	}
	private static int war(final double[] n, final double[] k, final int N)
	{
		int score = 0;
		for(int i = N-1, a = 0, b = N-1; i>=0; i--)
		{
			if(n[i]>k[b]){ ++score; a++; }
			else b--;
		}
		return score;
	}

	public static void main(String[] klein)
	{
		final Kattio in = new Kattio(System.in);
		final PrintWriter out = new PrintWriter(System.out);

		int T = in.getInt();
		loop:for(int t = 1; t<=T; t++)
		{
			final int N = in.getInt();
			final double[] naomi = new double[N], ken = new double[N];
			for(int i = 0; i<N; i++) naomi[i] = in.getDouble();
			for(int i = 0; i<N; i++) ken[i] = in.getDouble();

			Arrays.sort(naomi); Arrays.sort(ken);

			out.println("Case #"+t+": " + dWar(naomi,ken,N) + " " + war(naomi,ken,N));
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
