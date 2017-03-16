import java.io.*;
import java.util.*;

public class B {

	final static boolean DEBUG = true;
	
	public Object solve () throws IOException {
		int N = sc.nextInt();
		int S = sc.nextInt();
		int P = sc.nextInt();
		
		int [] T = new int [N];
		for (int i = 0; i < N; ++i)
			T[i] = sc.nextInt();
		
		if (P == 0)
			return N;
		
		if (P == 1) {
			int cnt = 0;
			for (int i = 0; i < N; ++i)
				if (T[i] > 0)
					++cnt;
			return cnt;
		}
		
		int cnt = 0;
		for (int i = 0; i < N; ++i) {
			int s = T[i];
			if (s >= 3*P-2)
				++cnt;
			else if (s >= 3*P-4 && S > 0) {
				++cnt; --S;
			}
		}
		
		return cnt;
	}
	
	void init () {
	}
	
	////////////////////////////////////////////////////////////////////////////////////
	
	public B () throws IOException {
		init();
		int N = sc.nextInt();
		start();
		for (int n = 1; n <= N; ++n)
			print("Case #" + n + ": " + solve());
		exit();
	}
	
	static MyScanner sc;
	static long t;
	
	static void print (Object o) {
		System.out.println(o);
		if (DEBUG)
			System.err.println(o + " (" + ((millis() - t) / 1000.0) + ")");
	}
	
	static void exit () {
		if (DEBUG) {
			System.err.println();
			System.err.println((millis() - t) / 1000.0);
		}
		System.exit(0);
	}
	
	static void run () throws IOException {
		sc = new MyScanner ();
		new B();
	}
	
	public static void main(String[] args) throws IOException {
		run();
	}
	
	static long millis() {
		return System.currentTimeMillis();
	}
	
	static void start() {
		t = millis();
	}
	
	static class MyScanner {
		String next() throws IOException {
			newLine();
			return line[index++];
		}
		
		char [] nextChars() throws IOException {
			return next().toCharArray();
		}
		
		double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}
		
		int nextInt() throws IOException {
			return Integer.parseInt(next());
		}
		
		long nextLong() throws IOException {
			return Long.parseLong(next());
		}
		
		String nextLine() throws IOException {
			line = null;
			return r.readLine();
		}
		
		
		String [] nextStrings() throws IOException {
			line = null;
			return r.readLine().split(" ");
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
			if (line == null || index == line.length) {
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
	
	char [] toArray (Character [] C) {
		char [] c = new char[C.length];
		for (int i = 0; i < C.length; ++i)
			c[i] = C[i];
		return c;
	}

	char [] toArray (Collection<Character> C) {
		char [] c = new char[C.size()]; int i = 0;
		for (char z : C)
			c[i++] = z;
		return c;
	}
	
	Object [] toArray(int [] a) {
		Object [] A = new Object[a.length];
		for (int i = 0; i < A.length; ++i)
			A[i] = a[i];
		return A;
	}
	
	String toString(Object [] a) {
		StringBuffer b = new StringBuffer();
		for (Object o : a)
			b.append(" " + o);
		return b.toString().trim();
	}	
	
	String toString(int [] a) {
		return toString(toArray(a));
	}
}
