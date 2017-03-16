import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import java.math.BigInteger;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	
	static void solve() throws Exception {
		int n = nextInt();
		int j = nextInt();
		
		printlnCase();
		for (int i = (int) Math.pow(2,n-1); i < Math.pow(2,n) && j != 0; i ++ ){
			BigInteger num =  new BigInteger(Integer.toString(i,2));
			if(num.toString().charAt(n-1) =='0'){
				continue;
			}
			String output = "" + num;
			for (int k = 2; k <= 10; k ++){
				int prime = isPrime(toBase(num,k)); //decimal big int
				if (prime != -1){
					output += " " + prime;
				}
				else{
					break;
				}
				
				if (k == 10){
					out.println(output);
					j--;
				}
			}
		}
	}
	
	static int isPrime(BigInteger n) {
	    if (n.mod(new BigInteger("2")).equals(BigInteger.ZERO)) return 2;
	    for(BigInteger b = BigInteger.valueOf(3); (b.pow(2)).compareTo(n)<=0; b = b.add(BigInteger.valueOf(2))) {
	        if(n.mod(b).equals(BigInteger.ZERO))
	            return b.intValue();
	    }
	    return -1;
	}
	
	static BigInteger toBase(BigInteger n,int base){
		return new BigInteger(n.toString(),base);
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
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
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