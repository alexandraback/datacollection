import java.io.*;
import java.util.*;
import java.math.*;

public class Timus implements Runnable {
	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;
	Random rnd;
	
	final int limit = 2000000;
	ArrayList<Integer>[] sets;
	
	void addShifts(int number) {
		String numStr = Integer.toString(number);
		int totalShifts = numStr.length() - 1;
		numStr += numStr;
		
		for(int i = 1; i <= totalShifts; i++) {
			String shiftStr = numStr.substring(i, i + totalShifts + 1);
			int shift = Integer.parseInt(shiftStr);
			
			if(shift > number && !sets[number].contains(shift)) {
				sets[number].add(shift);
			}
		}
	}
	
	void precalc() {
		sets = new ArrayList[limit + 1];
		
		for(int i = 0; i < sets.length; i++) {
			sets[i] = new ArrayList<Integer>();
		}
		
		for(int n = 0; n <= limit; n++) {
			addShifts(n);
			Collections.sort(sets[n]);
			//out.println(n + " " + sets[n]);
		}
	}
	
	int solveOne(int l, int r) {
		int res = 0;
		
		for(int n = l; n <= r; n++) {
			for(int m  : sets[n]) {
				if(m > r) {
					break;
				} else {
					++res;
				}
			}
		}
		
		return res;
	}
	
	void solve() throws IOException {
		precalc();
		
		int tests = nextInt();
		
		for(int test = 1; test <= tests; test++) {
			out.printf("Case #%d: %d\n", test, solveOne(nextInt(), nextInt()));
		}
	}

	public static void main(String[] args) {
		new Timus().run();
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);

			rnd = new Random();

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(42);
		}
	}

	String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = in.readLine();

			if (line == null) {
				return null;
			}

			st = new StringTokenizer(line);
		}

		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}