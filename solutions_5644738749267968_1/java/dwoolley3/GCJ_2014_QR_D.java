import java.io.*;    //PrintWriter
import java.math.*;  //BigInteger, BigDecimal
import java.util.*;  //StringTokenizer, ArrayList


public class GCJ_2014_QR_D
{	
	FastReader in;
	PrintWriter out;
	
	public static void main(String[] args)  {
		new GCJ_2014_QR_D().runWithFiles();
	}
	
	void run()
	{		
		in = new FastReader(System.in);
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}
	
	void runWithFiles() {
		//in = new FastReader(new File("src/D-ex.in"));
		//in = new FastReader(new File("src/D-small-attempt0.in"));
		in = new FastReader(new File("src/D-large.in"));
		try {
			//out = new PrintWriter(new File("src/D-ex.out"));
			//out = new PrintWriter(new File("src/D-small-attempt0.out"));
			out = new PrintWriter(new File("src/D-large.out"));
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
			int n = in.nextInt();
			
			double[] na = new double[n];
			for (int i = 0; i < n; i++) 
				na[i] = in.nextDouble();
	
			double[] ken = new double[n];
			for (int i = 0; i < n; i++) 
				ken[i] = in.nextDouble();
			
			Arrays.sort(na);
			Arrays.sort(ken);
			
			ArrayList<Double> alNa = new ArrayList<Double>();
			ArrayList<Double> alKen = new ArrayList<Double>();
			
			for (int i = 0; i < n; i++) 
			{
				alNa.add(na[i]);
				alKen.add(ken[i]);
			}
			Collections.reverse(alNa);
			Collections.reverse(alKen);
			
			int winNa1 = 0;
			for (int i = 0; i < n; i++)
			{
				if (alKen.get(n-1-i) > alNa.get(n-1-i))
				{
					alKen.remove(0);  //remove Ken's biggest
					alNa.remove(n-1-i);
				}
				else //Na is > Ken, concede and remove both smallest
				{
					winNa1++;
					alKen.remove(n-1-i);
					alNa.remove(n-1-i);
				}
			}
						
			for (int i = 0; i < n; i++) 
			{
				alNa.add(na[i]);
				alKen.add(ken[i]);
			}
			Collections.reverse(alNa);
			Collections.reverse(alKen);
			
			int winNa2 = 0;
			for (int i = 0; i < n; i++)
			{
				if (alKen.get(0) > alNa.get(0))
				{
					alKen.remove(0);
					alNa.remove(0);
				}
				else //Na is > Ken, concede but remove smallest
				{
					winNa2++;
					alKen.remove(alNa.size()-1);
					alNa.remove(0);
				}
			}
				
			String ans = winNa1 + " " + winNa2;
			
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
