import static java.util.Arrays.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;
import java.util.*;
import java.math.*;
import java.io.*;

public class B implements Runnable
{
	String file = "B-large";
	
	void init() throws IOException {
		input = new BufferedReader(new FileReader(file + ".in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter(file + ".out")));
	}
	
	void solve() throws IOException {
		int n = nextInt();
		int[] count = new int[3000];
		for (int i = 0; i < 2 * n - 1; i++) {
			for (int j = 0; j < n; j++) count[nextInt()]++;
		}
		
		out.print("Case #" + test + ": ");
		System.out.print("Case #" + test + ": ");
		for (int i = 0; i < 3000; i++)
			if (count[i] % 2 != 0) {
				out.print(i + " ");
				System.out.print(i + " " );
			}
		out.println();
		System.out.println();
	}
	
	String next() throws IOException {
		if(st == null || !st.hasMoreTokens()) st = new StringTokenizer(input.readLine());
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	
	void debug(Object... o) {
		System.out.println(deepToString(o));
	}
	
	void gcj(Object o) {
		String s = String.valueOf(o);
		out.println("Case #" + test + ": " + s);
		System.out.println("Case #" + test + ": " + s);
	}
	
	BufferedReader input;
	PrintWriter out;
	StringTokenizer st;
	int test;
	
	public static void main(String[] args) throws IOException {
		new Thread(null, new B(), "", 1 << 20).start();
	}
	
	public void run() {
		try {
			init();
			int TEST = nextInt();
			for(test = 1; test <= TEST; test++) {
				System.out.println("Running on testcase #" + test);	
				solve();
			}	
			out.close();		
		}
		catch(Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
}