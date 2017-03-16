import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class PartElf {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static String frac;


    static void solve() throws IOException {
    	printCase();
    	frac = next();
    	String[] f = frac.split("/");
    	Long n = Long.parseLong(f[0]);
    	Long d = Long.parseLong(f[1]);
    	Long gcd = gcd(n, d);
    	n /= gcd;
    	d /= gcd;
    	//out.println(n + " " + d);
    	if ((d & (d-1)) != 0) {
    		out.println("impossible");
    		return;
    	}
    	int counter = 0;
    	while(d > n) {
    		d /= 2;
    		counter++;
    	}
    	out.println(counter);
    }
  
    static Long gcd(Long a, Long b) {
    	return a == 0 ? b : gcd(b % a, a);
    }
    
    static class Assert{
    	static void check(boolean e){
    		if(!e) throw new Error();
    	}
    }

	
	static void printCase() {
		out.print("Case #" + test + ": ");
	}
	
	static void printlnCase() {
		out.println("Case #" + test + ":");
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new FileReader("A-large.in"));
			out = new PrintWriter("A-large.out");
			//in = new BufferedReader(new InputStreamReader(System.in));
			//out = new PrintWriter(new OutputStreamWriter(System.out));
			int tests = nextInt();
			for (test = 1; test <= tests; test++) {
				solve();
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}
