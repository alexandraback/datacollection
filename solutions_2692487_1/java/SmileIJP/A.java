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

public class A implements Runnable {
	
	PrintWriter out;
	BufferedReader breader;
	StringTokenizer st;
	

	void solve() throws NoSuchAlgorithmException, IOException {
		int a = nextInt();
		int n = nextInt();
		int[] m = new int[n];
		for (int i = 0; i < n; ++i) {
			m[i] = nextInt();
		}
		Arrays.sort(m);
		int ans = n;
		int act = 0;
		for (int i = 0; i < n;) {
			for (; i < n && a > m[i]; ++i) {
				a += m[i];
			}
			ans = Math.min(ans, n - i + act);
			if (a == 1) {
				break;
			}
			for (; i < n && a <= m[i]; ++act) {
				a += a - 1;
			}
		}
		out.println(ans);		
//		System.out.println(ans);
	}
	
	/**
	 * @param args
	 * @throws NoSuchAlgorithmException 
	 * @throws IOException 
	 * @throws LineUnavailableException 
	 */
	
	public static void main(String[] args)  {
		(new Thread(new A())).start();
	}

	@Override
	public void run() {
		try {
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
