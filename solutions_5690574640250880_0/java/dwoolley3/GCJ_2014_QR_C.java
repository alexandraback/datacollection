import java.io.*;    //PrintWriter
import java.math.*;  //BigInteger, BigDecimal
import java.util.*;  //StringTokenizer, ArrayList


public class GCJ_2014_QR_C //Name: Minesweeper Master
{	
	FastReader in;
	PrintWriter out;
	
	public static void main(String[] args)  {
		new GCJ_2014_QR_C().runWithFiles();
	}
	
	void run()
	{		
		in = new FastReader(System.in);
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}
	
	void runWithFiles() {
		//in = new FastReader(new File("src/C-ex.in"));
		in = new FastReader(new File("src/C-small-attempt1.in"));
		//in = new FastReader(new File("src/C-large.in"));
		try {
			//out = new PrintWriter(new File("src/C-ex.out"));
			out = new PrintWriter(new File("src/C-small-attempt1.out"));
			//out = new PrintWriter(new File("src/C-large.out"));
		} 
		catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		solve();
		out.close();
	}
	
	void solve()
	{
		int T = in.nextInt();  

		for (int tc = 1; tc <= T; tc++)
		{
			int r = in.nextInt();
			int c = in.nextInt();
			int m = in.nextInt();
			
			char[][] a = new char[r][c];
			String ans = "";
			String lf = "\r\n";
			if (r*c == m+1)
			{
				for (int i = 0; i < r-1; i++)
				{					
					ans += lf;
					for (int j = 0; j < c; j++)
						ans += "*";
				}
				ans += lf;
				for (int j = 0; j < c-1; j++)
					ans += "*";
				ans += "c";	
			}
			else if (c == 1)
			{
				for (int i = 0; i < r-1; i++)
					if (i < m) ans += lf + "*";
					else ans += lf + ".";
				ans += lf + "c";
			}
			else if (r == 1)
			{
				ans += lf;
				for (int i = 0; i < c-1; i++)
					if (i < m) ans += "*";
					else ans += ".";
				ans += "c";
			}
			else if (c == 2 && (r*c-m) % 2 == 0 && r*c-m >= 4)
			{
				for (int i = 0; i < r-1; i++)
					if (i < m/2) ans += lf + "**";
					else ans += lf + "..";
				ans += lf + ".c";
			}
			else if (r == 2 && (r*c-m) % 2 == 0 && r*c-m >= 4)
			{						
				for (int i = 0; i < r; i++)
				{
					ans += lf;				
					for (int j = 0; j < c; j++)
						if (j < m/2) 
							ans += "*";
						else
							if (i==r-1 && j== c-1)
								ans += "c";
							else
								ans += ".";
				}
			}
			else if (r > 2 && c > 2)
			{
				int empty = r*c - m;
				if (empty == 2 || empty == 3 || empty == 5 || empty == 7)
					ans = lf + "Impossible";
				else
				{
					int d = r*2 + (c-2)*2;
					if (empty >= d)
					{
						for (int i = 0; i < r; i++)
							for (int j = 0; j < 2; j++)
								a[i][j] = '.';
						
						for (int i = 0; i < 2; i++)
							for (int j = 2; j < c; j++)
								a[i][j] = '.';
						
						empty -= d;
						int i = 2, j = 2;
						while (empty > 0)
						{
							a[i][j] = '.';
							i++;
							if (i == r) { 
								i = 2; j++;
							}
							empty--;
						}
					}
					else //empty < d but valid
					{

						for (int i = 0; i < 2; i++)
							for (int j = 0; j < 2; j++)
								a[i][j] = '.';
						empty -= 4;
						
						int rr = 2, cc = 2;
						while (empty > 1 && (rr < r || cc < c))
						{
							if (empty > 1 && rr < r)
							{
								a[rr][0] = '.';
								a[rr][1] = '.';
								rr++;
								empty -= 2;
							}
							if (empty > 1 && cc < c)
							{
								a[0][cc] = '.';
								a[1][cc] = '.';
								cc++;
								empty -= 2;
							}						
						}
						if (empty == 1)
							a[2][2] = '.';
					}
					
					for (int i = 0; i < r; i++)
						for (int j = 0; j < c; j++)
							if (a[i][j] != '.') a[i][j] = '*';
					
					a[0][0] = 'c';
					
					for (int i = 0; i < r; i++)
					{
						ans += lf;						
						for (int j = 0; j < c; j++)
							ans += a[i][j];
					}
				}
			}
			else
				ans = lf + "Impossible";
			

			
			System.out.println("Case #" + tc + ": " + ans);
			out.println("Case #" + tc + ": " + ans);
		}
	}

	//-----------------------------------------------------

	
	class FastReader
	{
	    BufferedReader br;
	    StringTokenizer tokenizer;
	    
	    public FastReader(InputStream stream)
	    {
	        br = new BufferedReader(new InputStreamReader(stream));
	        tokenizer = null;
	    }
		public FastReader(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
				tokenizer = null;
			}
			catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}
	    
	    private String next() {
	        while (tokenizer == null || !tokenizer.hasMoreTokens())
	            try {
	            	tokenizer = new StringTokenizer(br.readLine());
	            }
	            catch (IOException e) {
	                throw new RuntimeException(e);
	            }
	        return tokenizer.nextToken();
	    }
		public String nextLine() {
			try	{
				return br.readLine();
			}
			catch(Exception e) {
				throw(new RuntimeException());
			}
		}

	    int nextInt() {
	        return Integer.parseInt(next());
	    }
	    long nextLong() {
	        return Long.parseLong(next());
	    }
	    double nextDouble() {
	        return Double.parseDouble(next());
	    }	    
	    BigInteger nextBigInteger() {
	        return new BigInteger(next());
	    }
	    BigDecimal nextBigDecimal() {
	        return new BigDecimal(next());
	    }
	}
}
