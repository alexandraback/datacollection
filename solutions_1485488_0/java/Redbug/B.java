import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class B {

	final static boolean DEBUG = true;
	final int MOD = 1000000007;
	final double eps = 1e-9;
	final int INF = 1000;
	final Error NO = new Error("NO");
	
	boolean less(double x, double y) { return  x < y - eps; }
	boolean more(double x, double y) { return x > y + eps; }
	boolean eq(double x, double y) { return abs(x - y) < eps; }	

	public Object solve () throws IOException {
		int H = sc.nextInt();
		int N = sc.nextInt();
		int M = sc.nextInt();
		
		int [][] C = new int [N][], F = new int [N][];
		for (int i = 0; i < N; ++i)
			C[i] = sc.nextInts();
		for (int i = 0; i < N; ++i)
			F[i] = sc.nextInts();

		double [][] D = new double[N][M];
		for (double [] d : D) fill(d, -1);
		
		Queue<double []> Q = new PriorityQueue<double []>(10,
			new Comparator<double []>() {
				public int compare(double [] x, double [] y) {
					if (more(x[2], y[2])) return 1;
					if (less(x[2], y[2])) return -1;
					return 0;
				}
		});
		
		Q.add(new double [] { 0, 0, 0 });

		while (!Q.isEmpty()) {
			double [] z = Q.poll();
			int x = (int)z[0], y = (int)z[1];
			double d = z[2];
			D[x][y] = d;
			if (x == N-1 && y == M-1)
				return d;

			int u, v; double val;
			// up
			u = x; v = y-1;
			val = calc(d, x, y, u, v, N, M, H, C, F, D);
			if (val > -.5)
				Q.add(new double [] { u, v, val });
			
			// down
			u = x; v = y+1;
			val = calc(d, x, y, u, v, N, M, H, C, F, D);
			if (val > -.5)
				Q.add(new double [] { u, v, val });
			
			// left
			u = x-1; v = y;
			val = calc(d, x, y, u, v, N, M, H, C, F, D);
			if (val > -.5)
				Q.add(new double [] { u, v, val });
			
			// right
			u = x+1; v = y;
			val = calc(d, x, y, u, v, N, M, H, C, F, D);
			if (val > -.5)
				Q.add(new double [] { u, v, val });			
		}
		
		throw NO;
	}
	
	double calc(double d, int x, int y, int u, int v, int N, int M, int H, int [][] C, int [][] F, double [][] D) {
		if (u >= 0 && u < N && v >= 0 && v < M && D[u][v] < 0) {
			double c1 = C[x][y], c2 = C[u][v], f1 = F[x][y], f2 = F[u][v], c = min(c1, c2);
			if (!less(c - f2, 50)) {
				double dw = max(d, (50.0 + H - c) / 10.0);
				double wh = H - 10.0 * dw - f1;
				if (more(dw, 0)) {
					if (less(wh, 20))
						dw += 10.0;
					else
						dw += 1;
				}
				return dw;
			}
		}	
		return -1;
	}
	
	void init () {
	}
	
	////////////////////////////////////////////////////////////////////////////////////
	
	public B () throws IOException {
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
		new B();
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
