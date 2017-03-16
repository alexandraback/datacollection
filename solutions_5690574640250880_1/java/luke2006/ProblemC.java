import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;

public class ProblemC
{
	Scanner in = null;
	Writer out = null;
	
	private void solve() throws IOException
	{
		int testCount = in.nextInt();
		in.nextLine();
		for (int test = 0; test < testCount; ++test)
		{
			int h = in.nextInt();
			int w = in.nextInt();
			int m = in.nextInt();
			int im = m;
			boolean isPossible = true;
			char[][] f = new char[w][h];
			
			if (m + 1 == h * w)
			{
				for (int y = 0; y < h; ++y)
					for (int x = 0; x < w; ++x)
						f[x][y] = '*';
				f[w - 1][h - 1] = 'c';
				m = 0;
			}
			else
			{
				for (int y = 0; y < h; ++y)
					for (int x = 0; x < w; ++x)
						f[x][y] = '.';
				f[w - 1][h - 1] = 'c';
				
				int lasty = 0;
				for (int y = 0; (y < h - 3 || w == 2) && m >= w; ++y)
				{
					for (int x = 0; x < w; ++x)
						f[x][y] = '*';
					m -= w;
					++lasty;
				}
				
				boolean completeLastRow = true;
				if (m >= w && lasty == h - 3)
				{
					if ((m - w) % 2 == 0)
					{
						for (int x = 0; x < w; ++x)
							f[x][lasty] = '*';
						m -= w;
						++lasty;
					}
					else
					{
						int d = Math.max(w - 3, 0);
						if (d > 0)
						{
							completeLastRow = false;
							for (int x = 0; x < d; ++x)
								f[x][lasty] = '*';
							m -= d;
							++lasty;
						}
					}
					
				}
				
				int lastx = 0;
				for (int x = 0; (x < w - 3 || (completeLastRow && x < w - 2)) && x < w && m >= h - lasty; ++x)
				{
					++lastx;
					for (int y = lasty; y < h; ++y)
						f[x][y] = '*';
					m -= h - lasty;
				}
				
				for (int x = lastx; x < w - 2 && m > 0; ++x)
					for (int y = lasty; y < h - 2 && m > 0; ++y)
					{
						f[x][y] = '*';
						--m;
					}
				
				isPossible = f[w - 1][h - 1] == 'c' && m == 0;
				if (isPossible)
				{
					int countMines = 0;
					int countNotMines = 0;
					for (int x = Math.max(0, w - 2); x < w; ++x)
						for (int y = Math.max(0, h - 2); y < h; ++y)
							if (f[x][y] == '*')
								++countMines;
							else if (f[x][y] == '.')
								++countNotMines;
					isPossible = (countMines == 0 && countNotMines != 0) || (countMines != 0 && countNotMines == 0) || (countMines == 0 && countNotMines == 0);
				}
			}
			out.writeln("Case #" + (test + 1) + ":");
			if (isPossible)
			{
				//out.writeln(w + "x" + h + "  " + m + "/" + im + " " + isPossible);
				for (int y = 0; y < h; ++y)
				{
					for (int x = 0; x < w; ++x)
						out.write(f[x][y]);
					out.newLine();
				}
				//out.newLine();
			}
			else
			{
				out.writeln("Impossible");
			}
		}
	}
	
	public static void main(String[] args) throws IOException
	{
		new ProblemC();
	}

	private ProblemC() throws IOException
	{
		in = new Scanner(new FileInputStream("ProblemCIn.txt"));
		out = new Writer(new OutputStreamWriter(new FileOutputStream("ProblemCOut.txt"), "utf-8"));
		solve();
		if (in != null)
			in.close();
		if (out != null)
			out.close();
	}
	
	private class Writer extends BufferedWriter
	{
		public Writer(java.io.Writer out)
		{
			super(out);
		}
		
		public void writeln(String str) throws IOException
		{
			write(str);
			newLine();
		}
		
		public void writeln(Object str) throws IOException
		{
			writeln(str.toString());
		}
	}
}
