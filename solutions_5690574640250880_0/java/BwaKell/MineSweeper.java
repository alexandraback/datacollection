import java.util.*;
import java.io.*;

public class MineSweeper
{
	public static void main(String[] klein)
	{
		final Kattio in = new Kattio(System.in);
		final PrintWriter out = new PrintWriter(System.out);

		int T = in.getInt();
		loop:for(int t = 1; t<=T; t++)
		{
			final int R = in.getInt(), C = in.getInt(), M = in.getInt(), E = R*C-M;

			//If R or C == 1, Yes. If E=1 then Yes. If E<=3 then No.
			final char[][] ans = new char[R][C];
			for(int i = 0; i<R; i++) Arrays.fill(ans[i],'*');

			out.println("Case #"+t+":");

			if(R==1){ for(int i = 0; i<E; i++) ans[0][i] = '.'; ans[0][0] = 'c'; }
			else if(C==1){ for(int i = 0; i<E; i++) ans[i][0] = '.'; ans[0][0] = 'c'; }
			else if(E==1) ans[0][0] = 'c';
			else if(E<=3){ out.println("Impossible"); continue; }
			else
			{
				int width = Math.min(C,E/2);
				for(; width>=2; width--)
				{
					final int[] h = new int[C];
					final int tmp = E/width, tmp2 = E%width;
					if(tmp+(tmp2==0 ? 0 : 1)>R){ out.println("Impossible"); continue loop; }
					for(int i = 0; i<width; i++) h[i] = tmp;
					for(int i = 0; i<tmp2; i++) h[i]++;
					if(tmp2==1) if(width==2 || tmp==2) continue; else{ h[1]++; h[width-1]--; }

					for(int i = 0, cnt = 0; cnt<E; i++)
						for(int j = 0; j<width && cnt<E && h[j]>0; h[j++]--, cnt++)
							ans[i][j] = '.';
					ans[0][0] = 'c';
					break;
				}

				if(width<2){ out.println("Impossible"); continue loop; }
			}

			for(int i = 0; i<R; i++) out.println(ans[i]);
		}

		out.flush();
	}
/*

***.
....
....
....

*/
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
