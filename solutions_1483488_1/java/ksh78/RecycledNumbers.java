import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

import junit.framework.TestCase;

public class RecycledNumbers extends TestCase
{
	public void testMain() throws IOException {
		RecycledNumbers.main(null);
	}
	
	public static void main(String[] args) throws IOException {
		setStandardIO();
		setFileIO("recyclednumbers");

		readLine();
		int T = nextInt();
		for (int t = 1; t <= T; ++t) {
			readLine();
			int A = nextInt();
			int B = nextInt();
			int N = String.valueOf(A).length() - 1;
			
			if (N == 0) 
				println("Case #" + t + ": " + 0);
			else {
				Set<Pair> pairs = new TreeSet<Pair>();
				for (int i = A; i <= B; ++i) {
					for (int j = 0; j < N; ++j) {
						String x = String.valueOf(i);
						String y = x.substring(N - j) + x.substring(0, N - j);
						
						if (y.charAt(0) == '0')
							continue;
						
						int X = Integer.valueOf(x);
						int Y = Integer.valueOf(y);
						
						if (X == Y)
							continue;
						
						if (Y < A)
							continue;
						
						if (Y > B)
							continue;
						
						if (X < Y)
							pairs.add(new Pair(X, Y));
						else
							pairs.add(new Pair(Y, X));
					}						
				}
				
				println("Case #" + t + ": " + pairs.size());
			}
		}
		
		flush();
	}

	//~ ----------------------------------------------------------------------------------------------------------------
	//~ - Auxiliary code -----------------------------------------------------------------------------------------------	
	//~ ----------------------------------------------------------------------------------------------------------------
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer st;

	private static void setStandardIO() {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	}

	private static void setFileIO(String fileName) throws FileNotFoundException, IOException {
		in = new BufferedReader(new FileReader(fileName + ".in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter(fileName + ".out")));
	}

	public static void readLine() throws IOException {
		st = new StringTokenizer(in.readLine());
	}

	public static int nextInt() {
		return Integer.parseInt(st.nextToken());
	}

	public static long nextLong() {
		return Long.parseLong(st.nextToken());
	}
	
	public static String nextString() {
		return st.nextToken();
	}

	public static List<String> nextStrings() {
		List<String> strings = new ArrayList<String>();
		while (st.hasMoreTokens())
			strings.add(st.nextToken());		
		
		return strings;
	}
	
	public static void flush() {
		out.flush();
	}
	
	public static void println(Object object) {
		out.println(object);
	}
	
	public static void print(Object object) {
		out.print(object);
	}

	public static long gcd(long a, long b) {
		if (b == 0) return a;
		return gcd(b, a % b);
	}
	
	public static class Pair implements Comparable<Pair>{
		public int x, y;
		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
		@Override
		public String toString() {
			return "Pair [x=" + x + ", y=" + y + "]";
		}
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + (int) (x ^ (x >>> 32));
			result = prime * result + (int) (y ^ (y >>> 32));
			return result;
		}
		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Pair other = (Pair) obj;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}
		@Override
		public int compareTo(Pair o) {
			if (x < o.x)
				return -1;
			if (x > o.x)
				return 1;
			
			return y - o.y;
		}		
	}
}
