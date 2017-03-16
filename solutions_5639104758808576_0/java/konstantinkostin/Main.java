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
	
//	final String fileName = "input.txt";

	private void run() throws IOException {
		in = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		
		solve();
		
		in.close();
		out.close();
	}
	
	void solve() throws IOException {
		int countTest = nextInt();
		for (int test = 1; test <= countTest; test++) {
			nextInt();
			char s[] = nextToken().toCharArray();
			
			int ans = 0;
			int sum = 0;
			for (int i = 0; i < s.length; ++i)
				if (s[i] != '0') {
					if (sum >= i)
						sum += (s[i] - '0');
					else {
						ans += (i - sum);
						sum = i + (s[i] - '0');
					}
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
