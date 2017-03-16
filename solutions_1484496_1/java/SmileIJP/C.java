import java.awt.Polygon;
import java.awt.geom.Point2D;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C implements Runnable {

	ArrayList< Long > left;
	ArrayList< Long > right;
	long[] a;
	
	boolean f(int cur, int l, int r, long b, long curs) {
		if (curs < Math.abs(b)) {
			return false;
		}
		if (l > 0 && r > 0 && b == 0) {
			return true;
		}
		if (cur == a.length) {
			return l > 0 && r > 0 && b == 0;
		}
		curs -= a[cur];
		if (f(cur + 1, l, r, b, curs)) {
			return true;
		}
		if (f(cur + 1, l + 1, r, b + a[cur], curs)) {
			left.add(a[cur]);
			return true;
		}		
		if (f(cur + 1, l, r + 1, b - a[cur], curs)) {
			right.add(a[cur]);
			return true;
		}
		return false;
	}
	
	int sum = 0;
	
	private void solve() throws IOException {
		int n = nextInt();
		left = new ArrayList<Long>();
		right = new ArrayList<Long>();
		a = new long[n];
		
		
		for (int i = 0; i < n; ++i) {
			a[i] = nextLong();
			sum += a[i];
		}
		Arrays.sort(a);
		for (int i = 0; 2 * i < a.length; ++i) {
			long tmp = a[i];
			a[i] = a[a.length - 1 - i];
			a[a.length - 1 - i] = tmp;
		}
		
		if (!f(0, 0, 0, 0, sum)) {
			out.println("Impossible");	
		} else {
			int lsum = 0;
			out.println();
			for (Long l : left) {
				lsum += l;
				out.print(l + " ");
			}
			out.println();
			int rsum = 0;
			for (Long r : right) {
				rsum += r;
				out.print(r + " ");
			}
			System.out.println(lsum + " " + rsum);
			out.println();
		}
	}

	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		(new Thread(new C())).start();
	}

	private BufferedReader br;
	private StringTokenizer st;
	private PrintWriter out;
	private String filename = "";

	@Override
	public void run() {
		try {
			br  = new BufferedReader(new FileReader("input.txt"));
			st  = new StringTokenizer("");
			out = new PrintWriter("output.txt");
			int T = nextInt();
			for (int i = 1; i <= T; ++i) {
				out.print("Case #" + i + ": ");
				solve();
			}
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(-1);
		}		
	}

	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String temp = br.readLine();
			if (temp == null) {
				return null;
			}
			st = new StringTokenizer(temp);
		}
		return st.nextToken();		
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
}
