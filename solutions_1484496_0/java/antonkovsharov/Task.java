import java.util.*;
import java.io.*;

public class Task {
	FastScanner in;
	PrintWriter out;

	int n, t;
	int[] s;
	int[] ans;
	boolean wasAns;
	int test;
	
	void gen(int i, int sum1, int sum2) {
		if (i == n) {
			if (wasAns) return;
			if (sum1 == sum2) {
				if (sum1 == 0) return;
				out.println("Case #" + (test + 1) + ": ");
		       	for (int j = 0; j < n; j++)
		       		if (ans[j] == 1) out.print(s[j] + " ");
		       	out.println("");
		       	for (int j = 0; j < n; j++)
		       		if (ans[j] == 2) out.print(s[j] + " ");
		       	out.println("");
		       	wasAns = true;
			}
			return;
		}
		ans[i] = 1;
		gen(i + 1, sum1 + s[i], sum2);
		if (wasAns) return;
		ans[i] = 0;
		gen(i + 1, sum1, sum2);
		if (wasAns) return;
		ans[i] = 2;
		gen(i + 1, sum1, sum2 + s[i]);
		if (wasAns) return;
	}
	
	public void solve() throws IOException {
       t = in.nextInt();
       for (test = 0; test < t; test++) {
    	   n = in.nextInt();
    	   wasAns = false;
    	   s = new int[n];
    	   ans = new int[n];
    	   for (int i = 0; i < n; i++) s[i] = in.nextInt();
    	   gen(0, 0, 0);
       	   if (!wasAns) {
       		   out.println("Case #" + (test + 1) + ": ");
       		   out.println("Impossible");
       	   }
       }
    }

	public void run() {
		try {
			in = new FastScanner(new File("input.in"));
			out = new PrintWriter(new File("output.out"));

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					String s = br.readLine();
					if (s == null)
						return null;
					st = new StringTokenizer(s);
				} catch (IOException e) {
					return null;
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}
	}

	public static void main(String[] arg) {
		new Task().run();
	}
}