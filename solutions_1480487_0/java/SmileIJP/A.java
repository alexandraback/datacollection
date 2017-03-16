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

public class A implements Runnable {

	
	
	private void solve() throws IOException {
		int n = nextInt();
		double[] a = new double[n];
		double x = 0;
		for (int i = 0; i < n; ++i) {
			a[i] = nextDouble();
			x += a[i];
		}
				
		for (int i = 0; i < n; ++i) {
			double up = 1.;
			double down = 0.;
			double mid = 0.;
			double lim = 0;
			double h = 0;
			while (up - down > 1e-9) {
				mid = (up + down) / 2;
				lim = mid * x;
				h = a[i] + mid * x;				
				for (int j = 0; j < n; ++j) {
					if (i != j && a[j] < h) {
						lim += h - a[j];
					}
				}
				if (lim > x) {
					up = mid; 
				} else {
					down = mid;
				}
			}
			out.printf("%.6f ", up * 100);			
		}
		out.println();
				
	}

	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		(new Thread(new A())).start();
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
