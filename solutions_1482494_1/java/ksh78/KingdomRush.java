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
import java.util.Collections;
import java.util.Iterator;
import java.util.List;
import java.util.StringTokenizer;

public class KingdomRush {

	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		setStandardIO();
		setFileIO("kingdomrush");

		readLine();
		int T = nextInt();
		for (int t = 1; t <= T; ++t) {
			readLine();
			int N = nextInt();
			ArrayList<Pair> star2 = new ArrayList<Pair>();
			ArrayList<Pair> star1 = new ArrayList<Pair>();
			for (int i = 0; i < N; ++i) {
				readLine();
				long a = nextInt(); 
				long b = nextInt();
				star2.add(new Pair(a, b));
			}
			
			long K = 0;
			long S = 0;
			
			loop:
			while (!star2.isEmpty() || !star1.isEmpty()) 
			{
				// search for 2 star level
				for (Iterator it = star2.iterator(); it.hasNext();) {
					Pair pair = (Pair) it.next();
					if (pair.y <= K) {
						it.remove();
						K += 2;
						S += 1;
						continue loop;
					}					
				}

				// search for 1 star level
				for (Iterator it = star1.iterator(); it.hasNext();) {
					Pair pair = (Pair) it.next();
					if (pair.y <= K) {
						it.remove();
						K += 1;
						S += 1;
						continue loop;
					}					
				}

				Collections.sort(star2);
				// search for rest 2 star level
				for (Iterator it = star2.iterator(); it.hasNext();) {
					Pair pair = (Pair) it.next();
					if (pair.x <= K) {
						star1.add(pair);
						it.remove();
						K += 1;
						S += 1;
						continue loop;
					}					
				}
				
				break;
			}
			
			if (!star2.isEmpty() || !star1.isEmpty())
				println("Case #" + t + ": Too Bad");
			else
				println("Case #" + t + ": " + S);
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
		public long x, y;
		public Pair(long x, long y) {
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
			if (y > o.y) return -1;
			if (y < o.y) return 1;
			if (x > o.x) return -1;
			if (x < o.x) return 1;
			return 0;
		}
	}
}
