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

	
	int rotate(int a, int pw) {
		return (a / 10) + (a % 10) * pw;
	}
	
	private void solve() throws IOException {
		int a = nextInt();
		int b = nextInt();
		
		int pw10 = 1;
		for (; pw10 * 10 <= a; pw10 *= 10)
			;
		
//		System.out.println(rotate(1, 10));
			
		boolean[] was = new boolean[b + 1];
		int qlen = 0;
		long ans = 0;
		for (int i = a; i <= b; ++i) {
			
			qlen = 1;
			was[i] = true;
			for (int j = rotate(i, pw10); j > b || !was[j]; j = rotate(j, pw10)) {
				if (a <= j && j <= b) {
					was[j] = true;
					++qlen;
				}				
			}
			ans += qlen * (qlen - 1) / 2;
		}
		out.println(ans);		
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
