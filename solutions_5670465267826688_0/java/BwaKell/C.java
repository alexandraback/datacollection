import java.util.*;
import java.io.*;

public class C
{
	static final int[][] mul = new int[128][128];
	static
	{
		mul[1][1] = 1; mul[1]['i'] = 'i';  mul[1]['j'] = 'j'; mul[1]['k'] = 'k';
		mul['i'][1] = 'i'; mul['i']['i'] = -1; mul['i']['j'] = 'k'; mul['i']['k'] = -'j';
		mul['j'][1] = 'j'; mul['j']['i'] = -'k'; mul['j']['j'] = -1; mul['j']['k'] = 'i';
		mul['k'][1] = 'k'; mul['k']['i'] = 'j'; mul['k']['j'] = -'i'; mul['k']['k'] = -1;
	}
	private static int mul(int a, int b)
	{
		int sign = 1;
		if(a<0){ sign = -sign; a = -a; }
		if(b<0){ sign = -sign; b = -b; }
		return sign * mul[a][b];
	}

	public static void main(String[] klein)
	{
		final Kattio in = new Kattio(System.in);
		final PrintWriter out = new PrintWriter(System.out);

		int T = in.getInt();
		loop:for(int t = 1; t<=T; t++)
		{
			final int L = in.getInt(), X = in.getInt();
			final int len = L*X;
			final int[] s = new int[10000];
			final char[] cc = in.getWord().toCharArray();
			for(int j = 0; j<len; )
				for(int i = 0; i<L && j<len; j++, i++)
					s[j] = cc[i];

			int a = 1, ai = 0;
			for(; ai<len && a!='i'; ai++) a = mul(a,s[ai]);
			int b = 1, bi = ai;
			for(; bi<len && b!='j'; bi++) b = mul(b,s[bi]);
			int c = 1, ci = bi;
			for(; ci<len; ci++) c = mul(c,s[ci]);

			out.println("Case #"+t+": "+(a=='i'&&b=='j'&&c=='k' ? "YES" : "NO"));
		}

		out.flush();
	}

	private static int pow(final int sym, int exp)
	{
		int ans = 1;
		for(int b = sym; exp>0; b=mul(b,b), exp>>>=1)
			if((exp&1)!=0)
				ans = mul(ans,b);
		return ans;
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
