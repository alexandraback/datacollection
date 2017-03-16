import java.io.*;
import java.util.*;

public class taskB {

	PrintWriter out;
	BufferedReader br;
	StringTokenizer st;

	String nextToken() throws IOException {
		while ((st == null) || (!st.hasMoreTokens()))
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public void solve() throws IOException {
		int x = nextInt();
		int y = nextInt();
		String s = "WE";
		if (x < 0)
			s = "EW";
		for (int i = 0; i < Math.abs(x); i++) {
			out.print(s);
		}
		
		s = "SN";
		if (y < 0)
			s = "NS";
		for (int i = 0; i < Math.abs(y); i++) {
			out.print(s);
		}
		out.println();
	}

	public void run() {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);

			br = new BufferedReader(new FileReader("taskB.in"));
			out = new PrintWriter("taskB.out");
			int n = nextInt();
			for (int i = 0; i < n; i++) {

				out.print("Case #" + (i + 1) + ": ");
				solve();
			}
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		new taskB().run();
	}
}
