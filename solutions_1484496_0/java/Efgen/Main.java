import java.io.*;
import java.util.*;
import java.math.*;

public class Main implements Runnable {

	double eps = 1e-8;
    void solve() throws IOException {
    	int tt = nextInt();
    	for (int t=1; t<=tt; t++) {
    		out.println("Case #"+t+": ");
    		int n = nextInt();
    		int[] a = new int[n];
    		for (int i=0; i<n; i++) 
    			a[i] = nextInt();
    		int sz = 1<<n;
    		int[] sum = new int[sz];
    		for (int msk=1; msk<sz; msk++) {
    			int x = 0;
    			for (int i=0; i<n; i++)
    				if ((msk&(1<<i))>0) x += a[i];
    			sum[msk] = x;
    		}
    		
    		int res = -1;
    		int part = -1;
    		
    		for (int msk=1; msk<sz; msk++) {
    			if (sum[msk]%2==1) continue;
    			int req = sum[msk]/2;
    			
    			for (int k=msk; k>0; k = msk&(k-1)) {
    				if (sum[k]==req) {
    					part = k; break;
    				}
    			}
    			if (part>=0) {
    				res = msk; break;
    			}
    		}
    		if (res<0) out.println("Impossible"); else {
    			for (int i=0; i<n; i++) 
    				if ((part&(1<<i))>0) out.print(a[i]+" ");
    			out.println();
    			part = res-part;
    			for (int i=0; i<n; i++) 
    				if ((part&(1<<i))>0) out.print(a[i]+" ");
    			out.println();
    		}
    		
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
