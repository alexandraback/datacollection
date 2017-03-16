import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	enum InputType {
		EXAMPLE, SMALL, LARGE
	}

	static final InputType INPUT_TYPE = InputType.LARGE;
	static final int ATTEMPT_NUMBER = 0;

	void solve() throws IOException {
		char[][] f = new char[4][];
		for (int i = 0; i < 4; i++) {
			f[i] = nextToken().toCharArray();
		}
		
		boolean winX = false;
		boolean winO = false;
		
		for (int i = 0; i < 4; i++) {
			boolean curX = true;
			boolean curO = true;
			for (int j = 0; j < 4; j++) {
				if (f[i][j] == '.' || f[i][j] == 'O') {
					curX = false;
				}
				if (f[i][j] == '.' || f[i][j] == 'O') {
					curO = false;
				}
			}
			winX |= curX;
			winO |= curO;
		}
		
		for (int j = 0; j < 4; j++) {
			boolean curX = true;
			boolean curO = true;
			for (int i = 0; i < 4; i++) {
				if (f[i][j] == '.' || f[i][j] == 'O') {
					curX = false;
				}
				if (f[i][j] == '.' || f[i][j] == 'X') {
					curO = false;
				}
			}
			winX |= curX;
			winO |= curO;
		}
		
//		System.err.println(winX);
		
		boolean curX = true;
		boolean curO = true;
		for (int i = 0; i < 4; i++) {
			if (f[i][i] == '.' || f[i][i] == 'O') {
				curX = false;
			}
			if (f[i][i] == '.' || f[i][i] == 'X') {
				curO = false;
			}
		}
		winX |= curX;
		winO |= curO;
		
		curX = true;
		curO = true;
		for (int i = 0; i < 4; i++) {
			char c = f[i][3 - i];
			if (c == '.' || c == 'O') {
				curX = false;
			}
			if (c == '.' || c == 'X') {
				curO = false;
			}
		}
		winX |= curX;
		winO |= curO;
		
		if (winX) {
			out.println("X won");
			return;
		}
		if (winO) {
			out.println("O won");
			return;
		}
		
		boolean draw = true;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (f[i][j] == '.')
					draw = false;
		if (draw)
			out.println("Draw");
		else
			out.println("Game has not completed");
	}

	A() throws IOException {
		switch (INPUT_TYPE) {
		case EXAMPLE: {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			break;
		}
		case SMALL: {
			br = new BufferedReader(new FileReader("A-small-attempt" + ATTEMPT_NUMBER
					+ ".in"));
			out = new PrintWriter("A-small-attempt" + ATTEMPT_NUMBER + ".out");
			break;
		}
		case LARGE: {
			br = new BufferedReader(new FileReader("A-large.in"));
			out = new PrintWriter("A-large.out");
			break;
		}
		}
		int t = nextInt();
		for (int i = 1; i <= t; i++) {
			System.err.println("Test " + i);
			out.print("Case #" + i + ": ");
			solve();
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
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