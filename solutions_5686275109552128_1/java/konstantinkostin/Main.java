import java.io.*;
import java.util.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;

public class Main {

	public static void main(String[] args) throws IOException {
		new Main().run();
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer st = new StringTokenizer("");
	
	final String fileName = "b";

	private void run() throws IOException {
		in = new BufferedReader(new FileReader(fileName + ".in"));
		out = new PrintWriter(fileName + ".out");
		
		solve();
		
		in.close();
		out.close();
	}
	
	final int MAX_SPLIT = 1001;
	final int MAX_N = 1001;
	
	int n;
	int a[] = new int[MAX_N];
	
	void solve() throws IOException {
		int countTest = nextInt();
		for (int test = 1; test <= countTest; ++test) {
			n = nextInt();
			int ans = 0;
			for (int i = 0; i < n; ++i) {
				a[i] = nextInt();
				ans = max(ans, a[i]);
			}
			
			for (int maxVal = 1; maxVal <= ans; ++maxVal) {
				int splitCount = 0;
				for (int i = 0; i < n; ++i)
					splitCount += (a[i] + maxVal - 1) / maxVal - 1;
				ans = min(ans, splitCount + maxVal);
			}
			
			out.println("Case #" + test + ": " + ans);
			
		}
	}

	String nextLine() throws IOException {
		st = new StringTokenizer("");
		return in.readLine();
	}

	String nextToken() throws IOException {
		while (!st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	boolean EOF() throws IOException {
		while (!st.hasMoreTokens()) {
			String str = in.readLine();
			if (str == null)
				return true;
			st = new StringTokenizer(str);
		}
		return false;
	}

}
