import java.io.*;
import java.math.*;
import java.util.*;

public class D {

	final static boolean DEBUG = true;
	
	class S implements Comparable<S> {
		int a; 
		int [] b;

		public int compareTo(S s) {
			if (a != s.a)
				return a - s.a;
			else
				return b[0] - s.b[0];
		}
		
		boolean merge(S s) {
			if (a == s.a && b[1] >= s.b[0]) {
				b[0] = Math.min(b[0], s.b[0]);
				b[1] = Math.max(b[1], s.b[1]);
				return true;
			} else
				return false;
		}
		public String toString() {
			return "a=" + a + "; b=" + Arrays.toString(b);
		}
	}
	
	void add(List<S> L, int a, int b1, int b2) {
		S m = new S();
		m.a = a; m.b = new int [] { b1, b2 };
		L.add(m);
	}
	
	List<S> normalize(List<S> L) {
		List<S> tmp = new ArrayList<S>();
		Collections.sort(L);
		S c = null;
		for (S s : L) {
			if (c == null)
				c = s;
			else {
				if (!c.merge(s)) {
					tmp.add(c);
					c = s;
				}
			}
		}
		assert(c != null);
		tmp.add(c);
		return tmp;
	}
	
	public Object solve () throws IOException {
		int ZZ = 300;
		
		int H = 2 * sc.nextInt();
		int W = 2 * sc.nextInt();
		int D = 2 * sc.nextInt();
		
		int MH = H-4, MW = W-4;

		int [] ME = null;
		S[] LV,UV,LH,UH;
		{		
		List<S> _LH = new ArrayList<S>();
		List<S> _LV = new ArrayList<S>();		
		List<S> _UH = new ArrayList<S>();
		List<S> _UV = new ArrayList<S>();
		
		add(_LV, 0, -1, MH+1);
		add(_UV, MW, -1, MH+1);
		add(_LH, 0, -1, MW+1);
		add(_UH, MH, -1, MW+1);
		
		sc.nextLine();
		for (int i = 0; i < MH/2; ++i) {
			char [] R = sc.nextChars();
			for (int j = 0; j < MW/2; ++j) {
				char z = R[j+1];
				if (z == 'X')
					ME = new int [] { 2*j+1, 2*i+1 };
				if (z == '#') {
					int vl = 2*i, vu = 2*i+2, hl = 2*j, hu = 2*j+2;
					int dvl = 0, dvu = 0, dhl = 0, dhu = 0;
					if (vl == 0) ++dvl; if(vu == MH) ++dvu; if (hl == 0) ++dhl; if (hu == MW) ++dhu;
					add(_LV, hu, vl-dvl, vu+dvu);
					add(_UV, hl, vl-dvl, vu+dvu);
					add(_LH, vu, hl-dhl, hu+dhu);
					add(_UH, vl, hl-dhl, hu+dhu);
				}
			}
		}
		sc.nextLine();

		_LV = normalize(_LV);
		_UV = normalize(_UV);
		_LH = normalize(_LH);
		_UH = normalize(_UH);
		
		LV = _LV.toArray(new S[0]);
		UV = _UV.toArray(new S[0]);
		LH = _LH.toArray(new S[0]);
		UH = _UH.toArray(new S[0]);
		}
		
		int cnt = 0;
		for (int ax = -ZZ; ax <= ZZ; ++ax)
			for (int ay = -ZZ; ay <= ZZ; ++ay)
				if (gcd(ax, ay) == 1)  {
					double d = 0, px = ME[0], py = ME[1];
					int tax = ax, tay = ay;
					while (d < D) {
						X slv = new X(), suv = new X(), slh = new X(), suh = new X();
						if (tax < 0) slv = T(LV, px, py, tax, tay, ME[0], ME[1], MH);
						if (tax > 0) suv = T(UV, px, py, tax, tay, ME[0], ME[1], MH);
						if (tay < 0) slh = T(LH, py, px, tay, tax, ME[1], ME[0], MW);
						if (tay > 0) suh = T(UH, py, px, tay, tax, ME[1], ME[0], MW);
						
						double minvd = 1e20, minhd = 1e20, mind = 1e20;
						minvd = Math.min(slv.d, minvd);
						minvd = Math.min(suv.d, minvd);
						minhd = Math.min(slh.d, minhd);
						minhd = Math.min(suh.d, minhd);
						mind = Math.min(minvd, minhd);
						
						d += Math.sqrt(mind);
						if (d > D + seps)
							break;
						
						if (slv.d == mind && slv.kill) { 
							if (slv.me) 
								++cnt; 
							break; }
						if (suv.d == mind && suv.kill) { 
							if (suv.me)
								++cnt;
							break; }
						if (slh.d == mind && slh.kill) { 
							if (slh.me)
								++cnt;
							break; }
						if (suh.d == mind && suh.kill) { 
							if (suh.me)
								++cnt; 
							break; }
						
						if (Math.abs(minvd - minhd) < eps) {
							if (d < D/2.0 + seps) 
								++cnt; 
							break;
						}
						
						if (slv.d == mind) { px = slv.pa; py = slv.pb; tax = slv.aa; tay = slv.ab; };
						if (suv.d == mind) { px = suv.pa; py = suv.pb; tax = suv.aa; tay = suv.ab; };
						if (slh.d == mind) { px = slh.pb; py = slh.pa; tax = slh.ab; tay = slh.aa; };
						if (suh.d == mind) { px = suh.pb; py = suh.pa; tax = suh.ab; tay = suh.aa; };
					}
				}
		
		return cnt;
	}
	
	class X {
		double pa, pb, d = 1e20;
		int aa, ab;
		boolean me = false, kill = false;
		
		public String toString() {
			if (d == 1e20)
				return "NO";
			if (me)
				return "ME; d=" + d;
			else if (kill)
				return "KILL; d=" + d;				
			return "d=" + Math.sqrt(d) + "; pa=" + pa + "; pb=" + pb + "; aa=" + aa + "ab=" + ab;
		}
	}
	
	double eps = 1e-9;
	double seps = Math.sqrt(eps);
	
	X T(S[] L, double pa, double pb, int aa, int ab, double mea, double meb, int M) {
		double aaa = Math.abs(aa);
		double nab = ab/aaa, naa = aa/aaa;
		
		double dme = 1e20;
		double tme = (mea - pa)/naa;
		if (tme > 0 && Math.abs(meb - (tme*nab + pb)) < eps)
			dme = (mea-pa)*(mea-pa) + (meb-pb)*(meb-pb);
		
		X x = new X();
		
		int P = -1, Q = L.length;
		int p = P, q = Q, m;
		while (q - p > 1) {
			m = (p+q)/2; if (m == P) ++m;
			if (L[m].a > pa)
				q = m;
			else
				p = m;
		}
		
		int z = naa > 0 ? q : p;
		int da = naa > 0 ? 1 : -1;
		int db = nab > 0 ? 1 : -1;
		
		for (; ; z += da) {
			S s = L[z];
			double t = Math.abs(s.a - pa);
			// double sa = pa + t * naa;
			double sb = pb + t * nab;
			
			double d = (s.a-pa)*(s.a-pa) + (sb-pb)*(sb-pb);
			if (d > dme) {
				x.me = x.kill = true;
				x.d = dme;
				return x;
			}
			if (sb < -eps || sb > M + eps)
				return x;
			if (Math.abs(sb - s.b[(1-db)/2]) < eps) {
				x.kill = true;
				x.d = d;
				return x;
			}
			if (sb > s.b[0] && sb < s.b[1]) {
				x.pa = s.a; x.pb = sb; x.aa = -aa; x.ab = ab; x.d = d;
				return x;
			}
		}
		
		//throw new Error("NO WAY!");
	}
	
	int gcd (int a, int b) {
		a = Math.abs(a); b = Math.abs(b);
		if (a*b != 0)
			return BigInteger.valueOf(a).gcd(BigInteger.valueOf(b)).intValue();
		else
			return a+b;
	}
	
	void init () {
	}
	
	////////////////////////////////////////////////////////////////////////////////////
	
	public D () throws IOException {
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
		new D();
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
