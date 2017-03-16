import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	
	static void solve() throws Exception {
		int n = nextInt();
		int x;
		boolean[] check = new boolean [10];
		String temp;
		
		for (int i = 1; i <= 100; i ++){
			x = n*i;
			temp = x + "";
			for (int j = 0; j < temp.length(); j ++){
				check[Integer.parseInt(temp.substring(j,j+1))] = true;
			}
			if (areAllTrue(check)){
				printCase();
				out.println(x);
				return;
			}
		}
			printCase();
			out.println("INSOMNIA");
		
		
	}
	
	public static boolean areAllTrue(boolean[] array){
		for(boolean b : array) if(!b) return false;
		return true;
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