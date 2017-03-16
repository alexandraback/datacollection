import java.io.*;    //PrintWriter
import java.math.*;  //BigInteger, BigDecimal
import java.util.*;  //StringTokenizer, ArrayList


public class GCJ_2014_QR_B
{	
	FastReader in;
	PrintWriter out;
	
	public static void main(String[] args)  {
		new GCJ_2014_QR_B().runWithFiles();
	}
	
	void run()
	{		
		in = new FastReader(System.in);
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}
	
	void runWithFiles() {
		//in = new FastReader(new File("src/B-ex.in"));
		//in = new FastReader(new File("src/B-small-attempt0.in"));
		//in = new FastReader(new File("src/B-large-attempt0.in"));
		in = new FastReader(new File("src/B-large.in"));
		try {
			//out = new PrintWriter(new File("src/B-ex.out"));
			//out = new PrintWriter(new File("src/B-small-attempt0.out"));
			//out = new PrintWriter(new File("src/B-large-attempt0.out"));
			out = new PrintWriter(new File("src/B-large.out"));
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
		//in.nextLine(); //use after a nextInt() and prior to reading another in.nextLine()

		for (int tc = 1; tc <= T; tc++)
		{
			double c = in.nextDouble();
			double f = in.nextDouble();
			double x = in.nextDouble();
			
			double min = getSeconds(0, c, f, x);
			int i = 1;
			double nextM = getSeconds(i, c, f, x);
			while (min > nextM)
			{
				min = nextM;
				i++;
				nextM = getSeconds(i, c, f, x);
			}
			
			String ans = min + "";
			
			System.out.println("Case #" + tc + ": " + ans);
			out.println("Case #" + tc + ": " + ans);
		}
	}
	
	private double getSeconds(int iter, double c, double f, double x)
	{
		double rate = 2.0, seconds = 0.0;
		for (int i = 0; i < iter; i++)
		{
			seconds += c / rate;
			rate += f;
		}		
		seconds += x / rate;		
		return seconds;
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
