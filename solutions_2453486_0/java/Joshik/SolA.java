import java.util.*;
import java.io.*;

//import java.math.*;

public class SolA implements Runnable {
	public static void main(String[] args) {
		new Thread(new SolA()).start();
	}

	@Override
	public void run() {
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	private final String FNAME = "A-small";

	int[] dx = new int[] { -1, -1, -1, 0, 0, 1, 1, 1 };
	int[] dy = new int[] { -1, 0, 1, -1, 1, -1, 0, 1 };

	void solve() {
		int tests = nextInt();
		all: for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			char[][] tab = new char[4][];
			for (int i = 0; i < 4; i++) {
				tab[i] = nextToken().toCharArray();
			}
			boolean isFree = false;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (tab[i][j] == '.') {
						isFree = true;
					}
					if (tab[i][j] != 'X' && tab[i][j] != 'O')
						continue;
					for (int dir = 0; dir < dx.length; dir++) {
						int x = i;
						int y = j;
						int cnt = 1;
						while (true) {
							x += dx[dir];
							y += dy[dir];
							if (x < 0 || y < 0 || x >= 4 || y >= 4) break;
							if (tab[x][y] != 'T' && tab[x][y] != tab[i][j]) break;
							cnt++;
						}
						if (cnt == 4) {
							out.println(tab[i][j] + " won");
							continue all;
						}
					}
				}
			}
			if (isFree) {
				out.println("Game has not completed");
			} else {
				out.println("Draw");
			}
		}
	}
}
