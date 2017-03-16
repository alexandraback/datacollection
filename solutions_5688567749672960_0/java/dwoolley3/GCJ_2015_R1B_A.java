import java.io.*;    //PrintWriter
import java.math.*;  //BigInteger, BigDecimal
import java.util.*;  //StringTokenizer, ArrayList

public class GCJ_2015_R1B_A
{	
	FastReader in;
	PrintWriter out;
//	final String PROBLEM_NAME = "A-ex";
	final String PROBLEM_NAME = "A-small-attempt0";
//	final String PROBLEM_NAME = "A-small-attempt1";
//	final String PROBLEM_NAME = "A-large";
	
	public static void main(String[] args) throws IOException  {
		new GCJ_2015_R1B_A().runWithFiles();
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
			long n = in.nextLong();
			long cur = 1, cnt = 1;
			if (n <= 20)
			{
				cnt = n;
			}			
			else if (n > 20)
			{
				int lenn = (n+"").length();				
				long pow10 = 1;    //10 ^ 0
				long step=0, stepRev=0;
				
				for (int i = 1; i < lenn; i++)
				{
					pow10 *= 10;
					int j = 2;
					while (j <= 9 && j*pow10+1 <= n) j++;
					j--;
					if (j == 1)		
					{
						step = n;
						stepRev = n;
					}
					else
					{
						step = pow10 + j;
						stepRev = j * pow10 + 1;
						cnt++; //Reverse on next count
					}					
					cnt += step - cur;
					cur = stepRev;					
				}
				if (cur < n)
					cnt += (n-cur);
			}

			
			String ans = cnt+"";
			
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
