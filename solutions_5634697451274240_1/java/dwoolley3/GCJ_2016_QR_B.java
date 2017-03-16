import java.io.*;    //PrintWriter
import java.math.*;  //BigInteger, BigDecimal
import java.util.*;  //StringTokenizer, ArrayList

public class GCJ_2016_QR_B
{	
	FastReader in;
	PrintWriter out;
//	final String PROBLEM_NAME = "B-ex";
//	final String PROBLEM_NAME = "B-small-attempt0";
//	final String PROBLEM_NAME = "B-small-attempt1";
	final String PROBLEM_NAME = "B-large";
	
	public static void main(String[] args) throws IOException  {
		new GCJ_2016_QR_B().runWithFiles();
	}
	
	void run()
	{		
		in = new FastReader(System.in);
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}
	
	void runWithFiles() throws IOException  {
		in = new FastReader(new File("src/" + PROBLEM_NAME + ".in")); //"_in.txt"));
		out = new PrintWriter(new File("src/" + PROBLEM_NAME + ".out")); //"_out.txt"));

		solve();
		out.close();
	}
	
	void solve()
	{
		int T = in.nextInt();  

		for (int tc = 1; tc <= T; tc++)
		{
			String s = in.next();
			int n = s.length();
			char[] c = s.toCharArray();
			
			int cnt = 0;
			for (int i = n-1; i >= 0; i--)
			{
				if (c[i] == '-') 
				{
					int j = 0;
					boolean changed = false;
					for (j = 0; j < i; j++)
					{
						if (c[j] == '+')
						{
							c[j] = '-';
							changed = true;
						}
						else break;
					}
					if (changed) cnt++;
					for (int k = 0; k <= i/2; k++)
					{
						char t = c[k];
						if (c[i-k] == '-') c[k] = '+'; else c[k] = '-';
						if (k == i/2 && i % 2 == 0) continue;
						if (t == '-') c[i-k] = '+'; else c[i-k] = '-';
					}
					cnt++;					
				}			
			}
			
			String ans = cnt + "";
			
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
