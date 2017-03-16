import java.io.*;
import java.util.*;

public class C {

	final static boolean DEBUG = false;
	final int MOD = 1000000007;
	final double eps = 1e-9;
	
	long [][] H; int N;
	
	public Object solve () throws IOException {
		N = sc.nextInt(); int M = (1 << N);
		int [] S = new int [N];
		for (int i = 0; i < N; ++i)
			S[i] = sc.nextInt();

		int A = 0, B = 0;
		Map<Integer, Integer> H = new HashMap<Integer, Integer> ();
		for (int m = 1; m < M; ++m) {
			int X = 0;
			for (int i = 0; i < 20; ++i)
				if (((1 << i) & m ) != 0)
					X += S[i];
			if (!H.containsKey(X))
				H.put(X, m);
			else {
				A = H.get(X);
				B = m;
				break;
			}
		}
		
		if (A == 0) return "Impossible";
		MyWriter W = new MyWriter();
		W.println();
		
		StringBuffer AA = new StringBuffer(), BB = new StringBuffer();
		for (int i = 0; i < N; ++i) { 
			if ((A & (1 << i)) != 0)
				AA.append(" " + S[i]);
			if ((B & (1 << i)) != 0)
				BB.append(" " + S[i]);
		}
		
		W.println(AA.toString().trim());
		W.print(BB.toString().trim());
		return W;
	}
	
	void init () {
	}
	
	////////////////////////////////////////////////////////////////////////////////////
	
	public C () throws IOException {
		init();
		int N = sc.nextInt();
		for (int n = 1; n <= N; ++n)
			print("Case #" + n + ": " + solve());
	}
	
	////////////////////////////////////////////////////////////////////////////////////
	
	static MyScanner sc;
	
	static class MyScanner {
		String next() throws IOException {
			newLine();
			return line[index++];
		}
		
		char nextChar() throws IOException {
			return next().charAt(0);
		}
				
		int nextInt() throws IOException {
			return Integer.parseInt(next());
		}
		
		long nextLong() throws IOException {
			return Long.parseLong(next());
		}
		
		double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}
		
		String nextLine() throws IOException {
			line = null;
			return r.readLine();
		}
		
		String [] nextStrings() throws IOException {
			line = null;
			return r.readLine().split(" ");
		}
		
		char [] nextChars() throws IOException {
			return next().toCharArray();
		}

		int [] nextInts() throws IOException {
			String [] L = nextStrings();
			int [] res = new int [L.length];
			for (int i = 0; i < L.length; ++i)
				res[i] = Integer.parseInt(L[i]);
			return res;
		}	
		
		long [] nextLongs() throws IOException {
			String [] L = nextStrings();
			long [] res = new long [L.length];
			for (int i = 0; i < L.length; ++i)
				res[i] = Long.parseLong(L[i]);
			return res;
		}

		double [] nextDoubles() throws IOException {
			String [] L = nextStrings();
			double [] res = new double [L.length];
			for (int i = 0; i < L.length; ++i)
				res[i] = Double.parseDouble(L[i]);
			return res;
		}

		boolean eol() {
			return index == line.length;
		}

		//////////////////////////////////////////////
		
		private final BufferedReader r;

		MyScanner () throws IOException {
			this(new BufferedReader(new InputStreamReader(System.in)));
		}
		
		MyScanner(BufferedReader r) throws IOException { 
			this.r = r;
		}
		
		private String [] line;
		private int index;

		private void newLine() throws IOException {
			if (line == null || eol()) {
				line = r.readLine().split(" ");
				index = 0;
			}
		}		
	}
	
	static class MyWriter {
		StringWriter sw = new StringWriter();
		PrintWriter pw = new PrintWriter(sw);
		
		void print(Object o) {
			pw.print(o);
		}
		
		void println(Object o) { 
			pw.println(o);
		}
		
		void println() {
			pw.println();
		}
		
		public String toString() {
			return sw.toString();
		}
	}
	
	////////////////////////////////////////////////////////////////////////////////////
	
	public static void main(String[] args) throws IOException {
		start();
		run();
		exit();
	}

	static void start() {
		t = millis();
	}

	static void run () throws IOException {
		sc = new MyScanner ();
		new C();
	}
		
	static void exit () {
		if (DEBUG) {
			System.err.println("------------------");
			System.err.println("Time: " + secs());
		}
		System.exit(0);
	}

	static void print (Object o) {
		System.out.println(o);
		if (DEBUG)
			System.err.println(o + " (Time: " + secs() + ")");
	}
		
	static long t;	

	static long millis() {
		return System.currentTimeMillis();
	}
	
	static double secs() {
		return (millis() - t) / 1000.0;
	}
}
