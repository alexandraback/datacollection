import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class B implements Runnable {

	static class State {
		int x, y, move;
		String path;
		
		State(int x, int y, int m, String p) {
			this.x = x;
			this.y = y;
			this.move = m;
			path = p;
		}
	}
	
	private void solve() throws IOException {
		int t = nextInt();
		while (t-- > 0) {
			int x = nextInt();
			int y = nextInt();
			pf();
			pl(solve(x, y));
		}
	}

	private String solve(int x, int y) {
		Queue<State> q = new LinkedList<State>();
		boolean[][][] v = new boolean[205][205][502];
		v[100][100][0] = true;
		q.add(new State(0, 0, 0, ""));
		while (!q.isEmpty()) {
			State cur = q.poll();
			if (cur.x == x && cur.y == y) {
				if (cur.move > 500) continue;
				return cur.path;
			}
			if (cur.x + cur.move + 101 <= 200 && cur.y + 100 <= 200 && cur.move <= 500 && !v[cur.x + cur.move + 101][cur.y + 100][cur.move + 1]) {
				v[cur.x + cur.move + 101][cur.y + 100][cur.move + 1] = true;
				q.add(new State(cur.x + cur.move + 1, cur.y, cur.move + 1, cur.path + "E"));
			}
			if ((cur.x - (1 + cur.move)) + 100 >= 0 && cur.y + 100 <= 200 && cur.move <= 500 && !v[(cur.x - (1 + cur.move)) + 100][cur.y + 100][cur.move + 1]) {
				v[(cur.x - (1 + cur.move)) + 100][cur.y + 100][cur.move + 1] = true;
				q.add(new State((cur.x - (1 + cur.move)), cur.y, cur.move + 1, cur.path + "W"));
			}
			if (cur.x + 100 <= 200 && cur.y + cur.move + 101 <= 200 && cur.move <= 500 && !v[cur.x + 100][cur.y + cur.move + 101][cur.move + 1]) {
				v[cur.x + 100][cur.y + cur.move + 101][cur.move + 1] = true;
				q.add(new State(cur.x, cur.y + cur.move + 1, cur.move + 1, cur.path + "N"));
			}
			if (cur.x + 100 <= 200 && (cur.y - (1 + cur.move)) + 100 >= 0 && cur.move <= 500 && !v[cur.x + 100][(cur.y - (1 + cur.move)) + 100][cur.move + 1]) {
				v[cur.x + 100][(cur.y - (1 + cur.move)) + 100][cur.move + 1] = true;
				q.add(new State(cur.x, (cur.y - (1 + cur.move)), cur.move + 1, cur.path + "S"));
			}
		}
		return "-1";
	}

	public static void main(String[] args) {
		new B().run();
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	public void run() {
		try {
//			reader = new BufferedReader(new InputStreamReader(System.in));
			reader = new BufferedReader(new FileReader("B-small-attempt0.in"));
//			reader = new BufferedReader(new FileReader("B-large.in"));
//			writer = new PrintWriter(System.out);
			writer = new PrintWriter("B-small.out");
//			writer = new PrintWriter("B-large.out");
			tokenizer = null;
			solve();
			reader.close();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
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

	BigInteger nextBigInteger() throws IOException {
		return new BigInteger(nextToken());
	}

	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	void p(Object... objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	void pl(Object... objects) {
		p(objects);
		writer.println();
	}

	int cc;

	void pf() {
		writer.printf("Case #%d: ", ++cc);
	}

}