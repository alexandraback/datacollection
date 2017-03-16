import java.util.*;
import java.io.*;

public class A {
    FastScanner in;
    PrintWriter out;
    public static long gcd(long a, long b) {
    	if (a == 0 || b == 0) return a + b;
    	else return gcd(b, a % b);
    }
    
    public void solve() throws IOException {
    	int t = in.nextInt();
    	for (int h = 1; h <= t; h++) {
    		out.print("Case #" + h + ": ");
    		String s = in.next();
    		long p = Long.parseLong(s.substring(0,s.indexOf('/')));
    		long q = Long.parseLong(s.substring(s.indexOf('/') + 1));
    		long c = gcd(p, q);
    		p /= c;
    		q /= c;
    		long i = 0;
    		for(i = q; i >= 1 && i % 2 == 0; i/=2);
    		if (i != 1) {
    			out.println("impossible");
    		} else {
    			int g = 0;
    			while (p < q) {
    				p*=2;
    				g++;
    			}
    			out.println(g);
    		}
    	}
    }

    public void run() {
        try {
        	//in = new FastScanner(System.in);
            //out = new PrintWriter(System.out);

            in = new FastScanner(new File("A-small-attempt0.in"));
            out = new PrintWriter(new File("A-small-attempt0.out"));

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
        
        FastScanner(InputStream f) {
            try {
                br = new BufferedReader(new InputStreamReader(f));
            } catch (Exception e) {
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