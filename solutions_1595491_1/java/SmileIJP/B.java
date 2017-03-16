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

public class B implements Runnable {

	
	
	private void solve() throws IOException {
		int N = nextInt();
		int S = nextInt();
		int p = nextInt();
		int[] t  =new int[N];
		for (int i = 0; i < N; ++i) {
			t[i] = nextInt();			
		}
		Arrays.sort(t);
		int[] a = new int[N];
		for (int i = 0; i < N; ++i) {
			a[i] = (t[i] + 2) / 3;
		}
		int ans = 0;
		int l = 0;
		for (l = N - 1; l >= 0 && a[l] >= p; --l) {
			++ans;
		}
		for (; l >= 0 && S > 0; --l) {
			if (t[l] % 3 == 0 && t[l] / 3 + 1 >= p && t[l] / 3 + 1 <= 10 && t[l] / 3 - 1 >= 0) {
				++ans;
				--S;
			}
			if (t[l] % 3 == 2 && t[l] / 3 + 2 >= p && t[l] / 3 + 2 <= 10) {
				--S;
				++ans;
			}
		}
		out.println(ans);
	}

	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		(new Thread(new B())).start();
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
