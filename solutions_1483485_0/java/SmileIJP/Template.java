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

public class Template implements Runnable {

	
	
	char[] map = "yhesocvxduiglbkrztnwjpfmaq".toCharArray();
	
	
	
	private void solve() throws IOException {
		String a = br.readLine();
		char[] ans = new char[a.length()];
		for (int i = 0; i < a.length(); ++i) {
			if ('a' <= a.charAt(i) && a.charAt(i) <= 'z') {
				ans[i] = map[a.charAt(i) - 'a'];				
			} else {
				ans[i] = a.charAt(i);
			}
		}
		out.println(ans);
	}

	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		(new Thread(new Template())).start();
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
