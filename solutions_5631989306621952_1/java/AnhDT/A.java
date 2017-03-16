import static java.util.Arrays.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;
import java.util.*;
import java.math.*;
import java.io.*;

public class A implements Runnable
{
	String file = "A-large";
	
	void init() throws IOException {
		input = new BufferedReader(new FileReader(file + ".in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter(file + ".out")));
	}
	
	void solve() throws IOException {
		String s = next();
		StringBuilder sb = new StringBuilder();
		for (char c : s.toCharArray()) {
			if (sb.length() == 0) sb.append(c);
			else {
				char b = sb.charAt(0);
				if (c >= b) sb.insert(0, c);
				else sb.append(c);
			}
		}
		gcj(sb.toString());
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
		new Thread(null, new A(), "", 1 << 20).start();
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