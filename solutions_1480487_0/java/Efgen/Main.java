import java.io.*;
import java.util.*;
import java.math.*;

public class Main implements Runnable {

	double eps = 1e-8;
    void solve() throws IOException {
    	int tt = nextInt();
    	for (int t=1; t<=tt; t++) {
    		out.print("Case #"+t+": ");
    		int n = nextInt();
    		double[] s = new double[n];
    		for (int i=0; i<n; i++) s[i] = nextInt();
    		double S = 0;
    		for (double x:s) S += x;
    		for (int i=0; i<n; i++) {
	    		double l = 0, r = 1;
	    		while (r-l>eps) {
	    			double x = (l+r)/2;
	    			double b = s[i]+S*x;
	    			double alf = x;
	    			for (int j=0; j<n; j++)
	    				if (i!=j) 
	    					alf += Math.max(0, (b-s[j])/S);
	    			if (alf>=1+eps) r = x; else l = x;
	    			
	    		}
	    		out.printf(Locale.US,"%1.6f ", (l+r)*50);
    		}
    		
    		out.println();
    	}
    	
    }

    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public void run() {
        try {
            //br = new BufferedReader(new InputStreamReader(System.in));
            //out = new PrintWriter(System.out);
            br = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");
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
        new Thread(new Main()).start();
    }
}
