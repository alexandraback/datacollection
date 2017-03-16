import java.util.*;
import java.io.*;

public class Task {
	FastScanner in;
	PrintWriter out;

	int n, t;
	int[] s;
	double[] ans;

	public void solve() throws IOException {
       t = in.nextInt();
       for (int test = 0; test < t; test++) {
    	   n = in.nextInt();
    	   s = new int[n];
       	   double sum = 0;
    	   for (int i = 0; i < n; i++) {
    		   s[i] = in.nextInt();
    		   sum += s[i];
    	   }
    	   ans = new double [n];
    	   for (int i = 0; i < n; i++) {
    		   double l = 0, r = 1;
    		   for (int iter = 0; iter < 50; iter++) {
    			   double m = (l + r) / 2;
    			   double my = s[i] + sum * m;
    			   double summ = m;
    			   for (int j = 0; j < n; j++) 
    			   	if (i != j) {
    	       	       double cur = 0; 
    				   cur = (my - s[j]) / sum; 
    	       	       summ += Math.max(cur, 0);
    			   	}
    			   if (summ > 1) r = m;
    			   else l = m;
    		   }
    		   ans[i] = l;
    	   }
       	   out.print("Case #" + (test + 1) + ": ");
       	   for (int i = 0; i < n; i++) out.print(100 * ans[i] + " ");
       	   out.println("");
       }
    }

	public void run() {
		try {
			in = new FastScanner(new File("multimap.in"));
			out = new PrintWriter(new File("multimap.out"));

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