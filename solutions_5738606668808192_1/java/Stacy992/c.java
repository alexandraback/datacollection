import java.util.*;
import java.io.*;
import java.math.BigInteger;
public class c {
	public static void main(String[] args) throws IOException {
		in.init(System.in);
		PrintWriter out = new PrintWriter(System.out);

		in.nextInt();
		n = in.nextInt();
		int k = in.nextInt();
		
		String[] ans = new String[k];
		String[][] div = new String[k][9];
		int p1 = 0;
		
		String at = "1";
		for(int i = 0; i < n-2; i ++)
			at+='0';
		at+='1';
		
		while(p1<k)
		{
			String[] divs = new String[9];
			for(int i = 2; i <= 10; i ++)
				divs[i-2] = getDiv(at, i);
	
			boolean works = true;
			for(int i = 0; i < 9; i ++)
				if(divs[i] == null)
					works = false;
			if(at == null)
				break;
			if(!works)
			{
				at = getNext(at);
				continue;
			}
			ans[p1] = at;
			for(int i = 0; i < 9; i ++)
				div[p1][i] = divs[i];
			p1++;	
			at = getNext(at);
		}
		
		if(p1 < k)
			out.println("Couldn't find enough. Found " + p1);
		else
		{
			out.println("Case #1: ");
			for(int i = 0; i < k; i ++)
			{
				out.print(ans[i]);
				for(int j = 0; j < 9; j ++)
					out.print(" " + div[i][j]);
				out.println();
			}
		}
		out.close();
	}
	static String getDiv(String at, int base)
	{
		BigInteger a = new BigInteger(at, base);
//		System.out.println(at + " => " + base + " = " + a.toString());
		for(int i = 2; i < 10000; i++)
		{
			BigInteger ii = new BigInteger(Integer.toString(i));
			if(a.compareTo(ii) <= 0)
				return null;
			if(a.mod(ii) == BigInteger.ZERO)
			{
//				System.out.println("    " + i);
				return Integer.toString(i);
			}
		}
		return null;
	}
	static int n;
	static String getNext(String at)
	{
		if(!at.contains("0"))
			return null;
		BigInteger a = new BigInteger(at.substring(0,n-1), 2);
		a = a.add(BigInteger.ONE);
		String s = a.toString(2);
		s+='1';
		return s;
	}
	public static class in {
		static BufferedReader reader;
		static StringTokenizer tokenizer;

		static void init(InputStream in) {
			reader = new BufferedReader(new InputStreamReader(in));
			tokenizer = new StringTokenizer("");
		}

		static String next() throws IOException {
			while (!tokenizer.hasMoreTokens()) {
				tokenizer = new StringTokenizer(reader.readLine());
			}
			return tokenizer.nextToken();
		}

		static int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		static double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		static long nextLong() throws IOException {
			return Long.parseLong(next());
		}
	}
}
