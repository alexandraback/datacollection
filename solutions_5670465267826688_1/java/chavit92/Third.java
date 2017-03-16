import java.io.*;
import java.util.*;

public class Third {

	boolean solve() throws IOException {
		int n = nextInt();
		long k = nextLong();
		k = Math.min(k, 20 - k %4);
		String str = next();
		String s = "";
		for (int i = 0; i < k; i++) {
			s += str;
		}
		int state = 0;
		int sign = 1;
		int need = 1;
		for (int i = 0; i < s.length(); i++) {
			int next = getState(s.charAt(i));
			sign = sign*getSign(state,next);
			state = state ^ next;
			if (state == need && sign == 1) {
				need++;
				state = 0;
				sign = 1;
			}
		}
		return need == 4 && state == 0 && sign == 1;
		
	}

	private int getSign(int state, int next) {
		if (state == 1) {
			if (next % 2 == 1) {
				return -1;
			} else {
				return 1;
			}
		}
		if (state == 2) {
			if (next ==1 || next == 2) {
				return -1;
			} else {
				return 1;
			}
		}
		if (state == 3) {
			if (next >=2) {
				return -1;
			} else {
				return 1;
			}
		}
		return 1;
	}

	private int getState(char c) {
		if (c == 'i') {
			return 1;
		} else if (c == 'j') {
			return 2;
		} else {
			return 3;
		}
	}

	void run() throws IOException {
		in = new BufferedReader(new FileReader("C.in"));
		out = new PrintWriter("C.out");
		int n = nextInt();
		for (int i = 0; i < n; i++) {
			out.println("Case #"+(i+1)+": "+(solve() ? "YES" : "NO"));
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new Third().run();
	}

	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;

	String next() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String temp = in.readLine();
			if (temp == null) {
				return null;
			}
			st = new StringTokenizer(temp);
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	long nextLong() throws IOException {
		return Long.parseLong(next());
	}

}
