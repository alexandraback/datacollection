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
import java.util.StringTokenizer;

public class DancingWithTheGooglers {

	
	public static void main(String[] args) throws IOException {
		setStandardIO();
		setFileIO("dancingwiththegooglers");

		readLine();
		int T = nextInt();
		for (int t = 1; t <= T; ++t) {
			readLine();
			int N = nextInt();
			int S = nextInt();
			int p = nextInt();
			int tab[] = new int[N];
			int ta[] = new int[N];
			int tb[] = new int[N];
			for (int i = 0; i < N; ++i) {
				tab[i] = nextInt();
				switch (tab[i] % 3) {
				case 0:
					ta[i] = tab[i] / 3; 
					tb[i] = (ta[i] == 0 ? ta[i] : ta[i] + 1);
					break;
				case 1:
					ta[i] = tab[i] / 3 + 1; 
					tb[i] = ta[i];
					break;
				case 2:
					ta[i] = tab[i] / 3 + 1; 
					tb[i] = ta[i] + 1;
					break;
				}
			}
			
			int count = 0;
			for (int i = 0; i < N; ++i)
				if (ta[i] >= p) count++;
			
			for (int i = 0; i < N && S > 0; ++i)
				if (ta[i] < p && tb[i] >= p) {
					count++;
					S--;
				}
			
			println("Case #" + t + ": " + count);
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
	
	public static class Pair {
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
	}
}
