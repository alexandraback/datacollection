import java.util.*;
import java.io.*;

public class A {
    FastScanner in;
    PrintWriter out;

    private int solutionForTest(int a, int n, int[] motes) {
    	int ans = n;
    	if (a == 1) {
    		return n;
    	}
    	int cur = n;
    	Arrays.sort(motes);
    	for (int i = 0; i < n; i++) {
    		while (a <= motes[i]) {
    			cur++;
    			a = 2 * a - 1;
    		}
    		cur--;
    		a += motes[i];
    		ans = Math.min(cur, ans);
    	}
    	return ans;
    }
    
    public void solve() throws IOException {
        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
        	int a = in.nextInt(), n = in.nextInt();
        	int[] motes = new int[n];
        	for (int j = 0; j < n; j++) {
        		motes[j] = in.nextInt();
        	}
        	out.println("Case #" + (i + 1) + ": " + solutionForTest(a, n, motes));
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("A-large.in"));
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
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] arg) {
        new A().run();
    }
}