import java.io.*;    //PrintWriter
import java.math.*;  //BigInteger, BigDecimal
import java.util.*;  //StringTokenizer, ArrayList

public class GCJ_2015_R1C_C
{	
	FastReader in;
	PrintWriter out;
//	final String PROBLEM_NAME = "C-ex";
	final String PROBLEM_NAME = "C-small-attempt0";
//	final String PROBLEM_NAME = "C-small-attempt1";
//	final String PROBLEM_NAME = "C-large";
	
	public static void main(String[] args) throws IOException  {
		new GCJ_2015_R1C_C().runWithFiles();
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
			int c = in.nextInt();
			int d = in.nextInt();
			int v = in.nextInt();
			
			int[] a = new int[d];
			for (int i = 0; i < d; i++) 
				a[i] = in.nextInt();
			
			int[] b = new int[100_000];
	        int it = (1 << d);
	        for (int i = 0; i < it; i++)
	        {
	            int sum = 0;
	            for (int j = 0; j < d; j++)
	            {
	                if ((i & (1 << j)) > 0)
	                {
	                    sum += a[j];
	                }
	                b[sum] = 1;
	            }
	        }
	        
	        
			int cnt = 0;
			int pow2 = 1;
			while (pow2 <= v)
			{
				if (b[pow2] == 0) cnt++;
//				boolean containsPow2 = false;
//				for (int j = 0; j < d; j++)
//					if (a[j] == pow2) containsPow2 = true;
//				if (!containsPow2) cnt++;
				pow2 *= 2;
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
