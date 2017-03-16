import java.io.*;
import java.util.*;
import java.math.*;

public class Task implements Runnable {
	
	
    void solve() throws IOException {
    	int tt = nextInt();
    	for (int ttt=1; ttt<=tt; ttt++) {
    		
    		int s = nextInt();
    		int n = nextInt();
    		int[] a = new int[n];
    		for (int i=0; i<n; i++) a[i] = nextInt();
    		Arrays.sort(a);
    		int res = n;
    		int cnt = 0;
    		if (s>1) {
    		for (int i=0; i<n; i++) {
    			int x = a[i];
    			if (x<s) {
    				s += x;    			
    			}  else {
    				while (x>=s) {
    					s += s-1;
    					cnt++;
    				}    			
    				s += x;
    			}
    			res = Math.min(res, cnt+n-i-1);
    		}}
    		out.printf(Locale.US, "Case #%d: %d\n", ttt, res);
    	}
  
    }

    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public void run() {
        try {            
            br = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");
        	//br = new BufferedReader(new InputStreamReader(System.in));
            //out = new PrintWriter(System.out);
            solve();
            br.close();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(123);
        }
    }

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String s = br.readLine();
            if (s == null)
                return null;
            st = new StringTokenizer(s);
        }
        return st.nextToken();
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    public static void main(String[] args) {
        new Thread(new Task()).start();
    }
}
