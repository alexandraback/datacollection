
import java.io.*;
import java.util.*;

public class D {
	class Omino {
		int type = -1;
		int[] x, y;
		int minx, maxx, miny, maxy;
		int n;

		boolean has(int _x, int _y) {
			for (int i = 0 ; i < n ; i++) {
				if (x[i] == _x && y[i] == _y) return true;
			}
			return false;
		}

		void init() {
			n = x.length;
			for (int i = 0 ; i < n ; i++) {
				if (x[i] < minx) minx = x[i];
				if (x[i] > maxx) maxx = x[i];
				if (y[i] < miny) miny = y[i];
				if (y[i] > maxy) maxy = y[i];
			}
			int yshift = Integer.MAX_VALUE;
			for (int i = 0 ; i < n ; i++) {
				if (x[i] == minx && y[i] < yshift) yshift = y[i];
			}
			for (int i = 0 ; i < n ; i++) {
				x[i] -= minx;
				y[i] -= yshift;
			}
			maxx -= minx;
			minx = 0;
			maxy -= yshift;
			miny -= yshift;
		}

		Omino(int _x, int _y) {
			x = new int[]{_x};
			y = new int[]{_y};
			init();
		}

		Omino(Omino other, boolean rotate) {
			x = new int[other.n];
			y = new int[other.n];
			if (rotate) {
				for (int i = 0 ; i < other.n ; i++) {
					x[i] = other.y[i];
					y[i] = -other.x[i];
				}
			} else { // flip
				for (int i = 0 ; i < other.n ; i++) {
					x[i] = other.x[i];
					y[i] = -other.y[i];
				}
			}
			init();
		}

		Omino(Omino other, int _x, int _y) {
			x = Arrays.copyOf(other.x, other.n+1);
			y = Arrays.copyOf(other.y, other.n+1);
			x[other.n] = _x;
			y[other.n] = _y;
			init();
		}

		public String toString() {
			char[][] board = new char[maxx-minx+1][maxy-miny+1];
			for (char[] row : board) Arrays.fill(row, '.');
			for (int i = 0 ; i < n ; i++) board[x[i]-minx][y[i]-miny] = '#';
			StringBuilder sb = new StringBuilder();
			for (char[] row : board) {
				for (char c : row) {
					sb.append(c);
				}
				sb.append("\n");
			}
			return sb.toString();
		}

		boolean sloppyEquals(Omino other) {
			return other.toString().equals(toString());
		}

		boolean strictEquals(Omino other) {
			if (sloppyEquals(other)) return true;
			for (int i = 0 ; i < 3 ; i++) {
				other = new Omino(other, true);
				if (sloppyEquals(other)) return true;
			}
			other = new Omino(other, false);
			if (sloppyEquals(other)) return true;
			for (int i = 0 ; i < 3 ; i++) {
				other = new Omino(other, true);
				if (sloppyEquals(other)) return true;
			} 
			return false;
		}
	}

	List<Omino> strict, sloppy;
	boolean[] used;

	boolean test(boolean[][] board) {
		int R = board.length;
		int C = board[0].length;
		for (int x = 0 ; x < R ; x++) {
			for (int y = 0 ; y < C ; y++) {
				if (!board[x][y]) {
					boolean success = false;
ominos:				for (Omino p : sloppy) {
						if (x + p.minx >= 0 && x + p.maxx < R &&
							y + p.miny >= 0 && y + p.maxy < C) {
							for (int i = 0 ; i < p.n ; i++) {
								if (board[x + p.x[i]][y + p.y[i]]) continue ominos;
							}
							for (int i = 0 ; i < p.n ; i++) {
								board[x + p.x[i]][y + p.y[i]] = true;
							}
							if (test(board)) success = used[p.type] = true;
							for (int i = 0 ; i < p.n ; i++) {
								board[x + p.x[i]][y + p.y[i]] = false;
							}
						}
					}
					if (!success) return false;
				}
			}
		}
		return true;
	}

	boolean test(int X, int R, int C) {
		strict = generateStrict(X);
		sloppy = generateSloppy(X);
		used = new boolean[strict.size()];
		for (Omino p : sloppy) {
			for (int i = 0 ; i < strict.size() ; i++) {
				if (p.strictEquals(strict.get(i))) {
					p.type = i;
					break;
				}
			}
		}
		boolean[][] board = new boolean[R][C];
		test(board);
		for (boolean b : used) if (!b) return false;
		return true;
	}

	List<Omino> generateStrict(int n) {
		if (n == 1) return Collections.singletonList(new Omino(0,0));
		List<Omino> list = new ArrayList<>();
		List<Omino> pred = generateStrict(n-1);
		for (Omino p : pred) {
			for (int x = p.minx - 1 ; x <= p.maxx+1 ; x++) {
				for (int y = p.miny - 1 ; y <= p.maxy+1 ; y++) {
					if ((p.has(x-1, y) || 
								p.has(x, y-1) ||
								p.has(x+1, y) ||
								p.has(x, y+1)) &&
							!p.has(x, y)) {
						Omino q = new Omino(p, x, y);
						boolean include = true;
						for (Omino o : list) {
							if (o.strictEquals(q)) {
								include = false;
								break;
							}
						}
						if (include) list.add(q);
					}
				}
			}
		}
		return list;
	}

	List<Omino> generateSloppy(int n) {
		if (n == 1) return Collections.singletonList(new Omino(0,0));
		List<Omino> list = new ArrayList<>();
		List<Omino> pred = generateSloppy(n-1);
		for (Omino p : pred) {
			for (int x = p.minx - 1 ; x <= p.maxx+1 ; x++) {
				for (int y = p.miny - 1 ; y <= p.maxy+1 ; y++) {
					if ((p.has(x-1, y) || 
								p.has(x, y-1) ||
								p.has(x+1, y) ||
								p.has(x, y+1)) &&
							!p.has(x, y)) {
						Omino q = new Omino(p, x, y);
						boolean include = true;
						for (Omino o : list) {
							if (o.sloppyEquals(q)) {
								include = false;
								break;
							}
						}
						if (include) list.add(q);
					}
				}
			}
		}
		return list;
	}

	int getInt(BufferedReader in) throws IOException {
		return Integer.parseInt(in.readLine());
	}

	int[] getInts(BufferedReader in) throws IOException {
		String[] words = in.readLine().split(" ");
		int[] ret = new int[words.length];
		for (int i = 0 ; i < words.length ; i++) ret[i] = Integer.parseInt(words[i]);
		return ret;
	}

	boolean alwaysTileable(int X, int R, int C) {
		assert 0 < X && X < 5 && 0 < R && R < 5 && 0 < C && C < 5;
		int min = Math.min(R, C);
		int max = Math.max(R, C);
		if (R * C % X != 0) return false;  // no tilings at all with X-ominoes
		switch (X) {
			case 1:
			case 2:
				return true;
			case 3:
				return min >= 2;
			case 4:
				return min >= 3;
			case 5:
			case 6:
				return min >= 5;
			default:
				return false;
		}
	}

	void run(String[] args) {
		try {
			BufferedReader in = new BufferedReader(new FileReader(args[0]));
			PrintStream out = new PrintStream(args[0] + ".out");
			int T = getInt(in);
			for (int t = 1 ; t <= T ; t++) {
				int[] input = getInts(in);
				int X = input[0];
				int R = input[1];
				int C = input[2];
				if (alwaysTileable(X, R, C)) {
					out.printf("Case #%d: GABRIEL\n", t);
				} else {
					out.printf("Case #%d: RICHARD\n", t);
				}
			}
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	void test(String[] args) {
		int X = Integer.parseInt(args[0]);
		int R = Integer.parseInt(args[1]);
		int C = Integer.parseInt(args[2]);
		System.out.println(test(X, R, C));
	}

	public static void main (String[] args) {
		new D().run(args);
	}
}
