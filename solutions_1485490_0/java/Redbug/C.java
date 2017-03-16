import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;

public class C {

	final static boolean DEBUG = false;
	final int MOD = 1000000007;
	final double eps = 1e-9;
	
	public Object solve () throws IOException {
		int N = sc.nextInt(), M = sc.nextInt();
		long [] a = new long [N], A = new long[N];
		for (int i = 0; i < N; ++i) {
			a[i] = sc.nextLong();
			A[i] = sc.nextLong();
		}
		
		long [] b = new long[M], B = new long[M];
		for (int i = 0; i < M; ++i) {
			b[i] = sc.nextLong();
			B[i] = sc.nextLong();
		}

		long res = 0;
		
		if (N == 1) {
			long cnt = 0;
			long [] x = copyOf(a, N); long [] y = copyOf(b, M);
			for (int i = 0; i < M; ++i)
				if (B[i] == A[0]) {
					long d = min(x[0], y[i]);
					x[0] -= d; y[i] -= d; 
					cnt += d;
				}
			res = cnt;
		}
		
		if (N == 2) {
			long cnt = 0;
			for (int i = 0; i <= M; ++i) {
				long cc = 0; 
				long [] x = copyOf(a, N); long [] y = copyOf(b, M);
				// Pick first i with x[0], the rest with x[1]
				for (int j = 0; j < i; ++j) {
					if (B[j] == A[0]) {
						long d = min(x[0], y[j]);
						x[0] -= d; y[j] -= d;
						cc += d;
					}
				}
				
				if (i > 0 && y[i-1] > 0 && B[i-1] == A[1]) {
					long d = min(x[1], y[i-1]);
					x[1] -= d; y[i-1] -= d;
					cc += d;
				}
				
				for (int j = i; j < M; ++j) {
					if (B[j] == A[1]) {
						long d = min(x[1], y[j]);
						x[1] -= d; y[j] -= d;
						cc += d;
					}
				}
				cnt = max(cnt, cc);
			}
			res = cnt;
		}
		
		if (N == 3) {
			long cnt = 0;
			for (int i = 0; i <= M; ++i) {
				for (int j = i; j <= M; ++j) {
					long cc = 0;
					long [] x = copyOf(a, N); long [] y = copyOf(b, M);
			
					// Pick first i with a[0], the next j-i with a[1], the rest with a[2]
					for (int k = 0; k < i; ++k) {
						if (B[k] == A[0]) {
							long d = min(x[0], y[k]);
							x[0] -= d; y[k] -= d;
							cc += d;
						}
					}
				
					if (i > 0 && y[i-1] > 0 && B[i-1] == A[1]) {
						long d = min(x[1], y[i-1]);
						x[1] -= d; y[i-1] -= d;
						cc += d;
					}
				
					for (int k = i; k < j; ++k) {
						if (B[k] == A[1]) {
							long d = min(x[1], y[k]);
							x[1] -= d; y[k] -= d;
							cc += d;
						}
					}
				
					if (j > 0 && y[j-1] > 0 && B[j-1] == A[2]) {
						long d = min(x[1], y[j-1]);
						x[2] -= d; y[j-1] -= d;
						cc += d;
					}
				
					for (int k = j; k < M; ++k) {
						if (B[k] == A[2]) {
							long d = min(x[2], y[k]);
							x[2] -= d; y[k] -= d;
							cc += d;
						}
					}				
				
					cnt = max(cnt, cc);
				}
			}
			
			res = cnt;
		}
		
		return res;
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
