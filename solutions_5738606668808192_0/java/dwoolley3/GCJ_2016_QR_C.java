import java.io.*;    //PrintWriter
import java.math.*;  //BigInteger, BigDecimal
import java.util.*;  //StringTokenizer, ArrayList

public class GCJ_2016_QR_C
{	
	FastReader in;
	PrintWriter out;
//	final String PROBLEM_NAME = "C-ex";
	final String PROBLEM_NAME = "C-small-attempt0";
//	final String PROBLEM_NAME = "C-small-attempt1";
//	final String PROBLEM_NAME = "C-large";
	
	public static void main(String[] args) throws IOException  {
		new GCJ_2016_QR_C().runWithFiles();
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
			int N = in.nextInt();
			int J = in.nextInt();
			
			String ans = "";
			System.out.println("Case #" + tc + ": " + ans);
			out.println("Case #" + tc + ": " + ans);
			
			String[] s = new String[] {
					"1000000000000001 3 2 5 2 7 2 3 2 7",
					"1000000000000101 13 11 3 4751 173 3 53 109 3",
					"1000000000000111 3 2 5 2 7 2 3 2 11",
					"1000000000001001 73 5 3 19 19 3 5 19 3",
					"1000000000001101 3 2 5 2 7 2 3 2 11",
					"1000000000010011 3 2 5 2 7 2 3 2 7",
					"1000000000011001 3 2 5 2 7 2 3 2 11",
					"1000000000011011 5 1567 15559 6197 5 5 1031 7 83",
					"1000000000011111 3 2 3 2 7 2 3 2 3",
					"1000000000100101 3 2 5 2 7 2 3 2 7",
					"1000000000101011 3 7 13 3 5 43 3 73 7",
					"1000000000101111 5 2 3 2 37 2 5 2 3",
					"1000000000110001 3 2 5 2 7 2 3 2 11",
					"1000000000110101 23 17 11 23 5 299699 43 239 59",
					"1000000000110111 3 2 3 2 7 2 3 2 3",
					"1000000000111011 17 2 3 2 73 2 17 2 3",
					"1000000000111101 3 2 3 2 7 2 3 2 3",
					"1000000001000011 3 2 5 2 7 2 3 2 11",
					"1000000001001001 3 2 5 2 7 2 3 2 7",
					"1000000001001111 3 2 3 2 7 2 3 2 3",
					"1000000001010101 3 7 13 3 5 17 3 53 7",
					"1000000001010111 5 2 3 2 37 2 5 2 3",
					"1000000001011001 11 5 281 101 5 67 5 13 19",
					"1000000001011011 3 2 3 2 7 2 3 2 3",
					"1000000001011101 17 2 3 2 1297 2 11 2 3",
					"1000000001011111 59 113 7 157 19 1399 7 43 107",
					"1000000001100001 3 2 5 2 7 2 3 2 11",
					"1000000001100011 23 19 11 105491 5 47 11117 1787 127",
					"1000000001100111 3 2 3 2 7 2 3 2 3",
					"1000000001101011 5 2 3 2 37 2 5 2 3",
					"1000000001101101 3 2 3 2 7 2 3 2 3",
					"1000000001110011 3 2 3 2 7 2 3 2 3",
					"1000000001110101 5 2 3 2 37 2 5 2 3",
					"1000000001111001 3 2 3 2 7 2 3 2 3",
					"1000000001111011 31 557 7 19 23 1129 7 5441 241",
					"1000000001111101 7 19 43 17 55987 23 7 7 31",
					"1000000001111111 3 2 5 2 7 2 3 2 7",
					"1000000010000011 167 2 11 2 58427 2 23 2 839",
					"1000000010000101 3 2 5 2 7 2 3 2 11",
					"1000000010001001 5 2 7 2 1933 2 29 2 157",
					"1000000010010001 3 2 5 2 7 2 3 2 7",
					"1000000010010111 3 2 3 2 7 2 3 2 3",
					"1000000010011001 7 1667 179 13 5 11 23 7 311",
					"1000000010011011 11 2 3 2 13 2 47 2 3",
					"1000000010011101 3 2 3 2 7 2 3 2 3",
					"1000000010100011 3 1259 421 3 5 8893 3 67 17",
					"1000000010100111 5 2 3 2 37 2 5 2 3",
					"1000000010101001 3 5 13 3 5 43 3 73 7",
					"1000000010110011 47 2 3 2 11 2 204311 2 3",
					"1000000010110101 3 2 3 2 7 2 3 2 3",
			};
			
			int ind = 0;
			for (ind = 0; ind < s.length; ind++)
			{
				System.out.println(s[ind]);
				out.println(s[ind]);
			}
			if (ind >= s.length) return;
			
			int[] a = new int[N];
			a[0] = 1; a[N-1] = 1;

			
			int cnt = 0;
			
			for (int i = 0; i < (1 << (N-2)); i++)
			{				
				boolean ok = false;
				ans = "";
				for (int b = 2; b <= 10; b++)
				{
					long num = 0;
					for (int j = 0; j < N; j++)
						num = num * b + a[j];					

					ok = false;
					for (long j = 2; j*j <= num && !ok; j++)
						if (num % j == 0)
						{
							ans += " " + j;
							ok = true;
						}
					if (!ok) break;
				}
				if (ok)
				{
					cnt++;
					String numSt = "";
					for (int j = 0; j < N; j++)
						numSt += a[j];
					ans = '"' + numSt + ans + '"' + ",";
					System.out.println(ans);
					out.println(ans);
					if (cnt == J) break;
				}
				
				//Add 1
				for (int j = N-2; j > 0; j--)
					if (a[j] == 1)
						a[j] = 0;
					else if (a[j] == 0)
					{
						a[j] = 1;
						break;
					}
			}
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
