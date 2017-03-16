package codeJamRound1B;


import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.TreeMap;


public class C {

	static int[] u, v;
	static int n;
	
	static int bt(int idx, int left, int right)
	{
		if(left + right == 0)
			return 0;
		if(idx == n)
			return (int)1e9;
		return Math.min(1 + bt(idx + 1, (left & ~(1<<u[idx])), (right & ~(1<<v[idx]))), bt(idx + 1, left, right));
	}
	public static void main(String[] args) throws IOException 
	{
		Scanner sc = new Scanner(new FileReader("C-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new FileWriter("problem_C.out"));
//		Scanner sc = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		
		int tc = sc.nextInt();
		for(int t = 1; t <= tc; ++t)
		{
			TreeMap<String, Integer> left = new TreeMap<String, Integer>(), right = new TreeMap<String, Integer>();
			n = sc.nextInt();
			u = new int[n]; v = new int[n];
			int idx1 = 0, idx2 = 0;
			for(int i = 0; i < n; ++i)
			{
				String s1 = sc.next(), s2 = sc.next();
				Integer uu = left.get(s1), vv = right.get(s2);
				if(uu == null)
					left.put(s1, uu = idx1++);
				if(vv == null)
					right.put(s2, vv = idx2++);
				u[i] = uu; v[i] = vv;
			}
			
			
			out.printf("Case #%d: %d\n", t, n - bt(0, ((1<<idx1) - 1), ((1<<idx2) - 1)));
		}
		out.flush();
		out.close();

	}

	static class Scanner 
	{
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream s){	br = new BufferedReader(new InputStreamReader(s));}
		
		public Scanner(FileReader r){	br = new BufferedReader(r);}

		public String next() throws IOException 
		{
			while (st == null || !st.hasMoreTokens()) 
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public int nextInt() throws IOException {return Integer.parseInt(next());}

		public long nextLong() throws IOException {return Long.parseLong(next());}

		public String nextLine() throws IOException {return br.readLine();}

		public double nextDouble() throws IOException
		{
			String x = next();
			StringBuilder sb = new StringBuilder("0");
			double res = 0, f = 1;
			boolean dec = false, neg = false;
			int start = 0;
			if(x.charAt(0) == '-')
			{
				neg = true;
				start++;
			}
			for(int i = start; i < x.length(); i++)
				if(x.charAt(i) == '.')
				{
					res = Long.parseLong(sb.toString());
					sb = new StringBuilder("0");
					dec = true;
				}
				else
				{
					sb.append(x.charAt(i));
					if(dec)
						f *= 10;
				}
			res += Long.parseLong(sb.toString()) / f;
			return res * (neg?-1:1);
		}

		public boolean ready() throws IOException {return br.ready();}


	}
}