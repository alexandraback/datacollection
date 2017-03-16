import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B implements Runnable {
	
	PrintWriter out;
	BufferedReader breader;
	StringTokenizer st;
	
	double[][] c;
	
	void prep() {
		c = new double[1001][];
		for (int i = 0; i < c.length; ++i) {
			c[i] = new double[i + 1];
		}
		c[0][0] = 1;
		for (int n = 1; n < c.length; ++n) {
			c[n][0] = c[n - 1][0] / 2;
			c[n][n] = c[n - 1][n - 1] / 2;
			for (int k = 1; k < n; ++k) {
				c[n][k] = (c[n - 1][k] + c[n - 1][k - 1]) / 2; 
			}
		}
	}
	
	void solve() throws NoSuchAlgorithmException, IOException {
		int n = nextInt();
		int x = nextInt();
		int y = nextInt();
		
		int l = Math.abs(x) + y;
		n -= l * (l - 1) / 2;
		
		if (n <= 0) {
			out.println(0);
			return;
		}		
		
		if (n >= 2 * l + 1) {
			out.println(1);
			return;
		}
		if (x == 0) {
			out.println(0);
			return;
		}
		if (y < n - l) {
			out.println(1);
			return;
		}
		double[][] d = new double[l + 1][l + 1];
		d[0][0] = 1;
		for (int i = 0; i <= l; ++i) {
			for (int j = 0; j <= l; ++j) {
				if (i > 0) {
					d[i][j] += (j == l ? 1 : 0.5) * d[i - 1][j];
				}
				if (j > 0) {
					d[i][j] += (i == l ? 1 : 0.5) * d[i][j - 1];
				}
			}
		}
		double pr = 0;
		for (int i = y + 1; i <= l && n - i >= 0; ++i) {
			pr += d[i][n - i];
		}
					
		out.println(pr);		
	}
	
	/**
	 * @param args
	 * @throws NoSuchAlgorithmException 
	 * @throws IOException 
	 * @throws LineUnavailableException 
	 */
	
	public static void main(String[] args)  {
		(new Thread(new B())).start();
	}

	@Override
	public void run() {
		try {
			prep();
			//breader = new BufferedReader(new InputStreamReader(System.in));
			breader = new BufferedReader(new FileReader("inp.file"));
			st = new StringTokenizer("");
			out = new PrintWriter("res.file");
			int tst = nextInt();
			for (int i = 1; i <= tst; ++i) {
				out.print("Case #" + i + ": ");
				solve();
			}
			out.close();
		} catch (NoSuchAlgorithmException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String temp = breader.readLine();
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
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
}
