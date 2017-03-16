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

public class Main 
{	
	public static void main(String args[]) throws IOException {
		setStandardIO();
		setFileIO("test");

		readLine();
		int T = nextInt();
		for (int t = 1; t <= T; ++t) {
			readLine();
			int X = nextInt();
			int Y = nextInt();
			
			print("Case #" + t + ": ");
			if (X > 0)
				for (int i = 0; i < X; ++i) print("WE");
			else if (X < 0)
				for (int i = 0; i < -X; ++i) print("EW");
			
			if (Y > 0)
				for (int i = 0; i < Y; ++i) print("SN");
			else if (Y < 0)
				for (int i = 0; i < -Y; ++i) print("NS");				
		
			println("");
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
		public double x, y;
		public Pair(double x, long y) {
			this.x = x;
			this.y = y;
		}
		@Override
		public String toString() {
			return "Pair [x=" + x + ", y=" + y + "]";
		}
		@Override
		public int compareTo(Pair o) {
			return ((Double)y).compareTo(o.y);
		}
	}
}