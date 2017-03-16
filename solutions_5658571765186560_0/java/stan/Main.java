import java.util.LinkedList;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Queue;
import java.io.IOException;
import java.util.Arrays;
import java.io.InputStream;
import java.util.Collection;
import java.io.OutputStreamWriter;
import java.io.PrintStream;
import java.util.Comparator;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Stanislav Pak
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		OminousOmino solver = new OminousOmino();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class OminousOmino {
	static class Figure {
		final int[] x;
		final int[] y;
		final int r;
		final int c;

		Figure(int[] x, int[] y, int r, int c) {
			this.x = x;
			this.y = y;
			this.r = r;
			this.c = c;
		}

		Figure rotated() {
			int[] nx = new int[x.length];
			int[] ny = new int[x.length];
			for (int i = 0; i < x.length; ++i) {
				ny[i] = x[i];
				nx[i] = c - 1 - y[i];
			}
			return new Figure(nx, ny, c, r);
		}

		Figure flipped() {
			int[] nx = new int[x.length];
			int[] ny = new int[x.length];
			for (int i = 0; i < x.length; ++i) {
				nx[i] = x[i];
				ny[i] = c - 1 - y[i];
			}
			return new Figure(nx, ny, r, c);

		}

		public String toString() {
			char[][] t = new char[r][c];
			ArrayUtils.fill(t, '.');
			for (int i = 0; i < x.length; ++i) {
				t[x[i]][y[i]] = '#';
			}
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < r; ++i) {
				sb.append(new String(t[i]));
				sb.append("\n");
			}
			return sb.toString();
		}
	}
	static final List<Figure>[] figureLists = new ArrayList[7];
	static final Pos[] SHIFT = new Pos[]{new Pos(-1, 0), new Pos(1, 0), new Pos(0, -1), new Pos(0, 1)};

	static {
		figureLists[4] = new ArrayList<>();
		figureLists[4].add(new Figure(new int[]{0, 1, 2, 3}, new int[]{0, 0, 0, 0}, 4, 1));
		figureLists[4].add(new Figure(new int[]{0, 0, 0, 0}, new int[]{0, 1, 2, 3}, 1, 4));
		genFigures(figureLists[4], 4, 0, 0, new int[3][3]);

		figureLists[5] = new ArrayList<>();
		figureLists[5].add(new Figure(new int[]{0, 1, 2, 3, 4}, new int[]{0, 0, 0, 0, 0}, 5, 1));
		figureLists[5].add(new Figure(new int[]{0, 0, 0, 0, 0}, new int[]{0, 1, 2, 3, 4}, 1, 5));
		genFigures(figureLists[5], 5, 0, 0, new int[4][4]);


		figureLists[6] = new ArrayList<>();
		figureLists[6].add(new Figure(new int[]{0, 1, 2, 3, 4, 5}, new int[]{0, 0, 0, 0, 0, 0}, 6, 1));
		figureLists[6].add(new Figure(new int[]{0, 0, 0, 0, 0, 0}, new int[]{0, 1, 2, 3, 4, 5}, 1, 6));
		genFigures(figureLists[6], 6, 0, 0, new int[5][5]);

		System.err.println(figureLists[6].size());
//		for (Figure figure : figureLists[5]) {
//			System.err.println(figure.toString());
//		}
	}

	private static void genFigures(List<Figure> figureList, int count, int x, int y, int[][] figure) {
		if (count == 0) {
			if (isValid(figure)) {
				addFigure(figureList, figure);
			}
			return;
		}
		++y;
		if (y == figure.length) {
			y = 0;
			++x;
		}
		if (x == figure.length) return;
		genFigures(figureList, count, x, y, figure);
		figure[x][y] = 1;
		genFigures(figureList, count - 1, x, y, figure);
		figure[x][y] = 0;
	}

	private static void addFigure(List<Figure> figureList, int[][] figure) {
		int n = figure.length;
		int x1 = n, y1 = n;
		int x2 = 0, y2 = 0;
		int count = 0;
		for (int x = 0; x < n; ++x) {
			for (int y = 0; y < n; ++y) {
				if (figure[x][y] > 0) {
					++count;
					x1 = Math.min(x1, x);
					x2 = Math.max(x2, x);
					y1 = Math.min(y1, y);
					y2 = Math.max(y2, y);
				}
			}
		}
		int[] px = new int[count];
		int[] py = new int[count];
		int i = 0;
		for (int x = 0; x < n; ++x) {
			for (int y = 0; y < n; ++y) {
				if (figure[x][y] > 0) {
					px[i] = x - x1;
					py[i] = y - y1;
					++i;
				}
			}
		}
		figureList.add(new Figure(px, py, x2 - x1 + 1, y2 - y1 + 1));
	}

	static class Pos {
		final int x;
		final int y;

		Pos(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	private static boolean isValid(int[][] figure) {
		int n = figure.length;
		boolean[][] used = new boolean[n][n];
		Queue<Pos> queue = new LinkedList<>();
		for (int x = 0; x < n; ++x) {
			for (int y = 0; y < n; ++y) {
				if (figure[x][y] > 0) {
					queue.add(new Pos(x, y));
					break;
				}
			}
			if (!queue.isEmpty()) break;
		}
		used[queue.peek().x][queue.peek().y] = true;
		assert(queue.size() == 1);
		while (!queue.isEmpty()) {
			Pos p = queue.remove();
			for (Pos sh : SHIFT) {
				int x = p.x + sh.x;
				int y = p.y + sh.y;
				if (x >= 0 && x < n && y >= 0 && y < n && !used[x][y] && figure[x][y] > 0) {
					used[x][y] = true;
					queue.add(new Pos(x, y));
				}
			}
		}
		for (int x = 0; x < n; ++x) {
			for (int y = 0; y < n; ++y) {
				if (figure[x][y] > 0 && !used[x][y]) return false;
			}
		}
		return true;
	}

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		System.err.println("Test: " + testNumber);
		int x = in.readInt();
		int n = in.readInt();
		int m = in.readInt();
		out.printLine("Case #" + testNumber + ":", getGameResult(x, n, m) ? "RICHARD" : "GABRIEL");
    }

	private boolean getGameResult(int x, int n, int m) {
		if (n > m) {
			int c = n;
			n = m;
			m = c;
		}
		if (x > m) return true;
		if (n * m % x > 0) return true;
		if ((x + 1) / 2 > n) return true;
		if (x > 6) return true;
		if (x < 4) return false;
		if (x <= n) return false;
		for (Figure figure : figureLists[x]) {
			if (!fitsAny(figure, n, m)) return true;
		}
		return false;
	}

	private boolean fitsAny(Figure figure, int n, int m) {
		for (int i = 0; i < 4; ++i) {
			if (fits(figure, n, m)) return true;
			figure = figure.rotated();
		}
		figure = figure.flipped();
		for (int i = 0; i < 4; ++i) {
			if (fits(figure, n, m)) return true;
			figure = figure.rotated();
		}
		return false;
	}

	static final boolean[][] a = new boolean[30][30];
	private boolean fits(Figure figure, int n, int m) {
		int x = figure.x.length;
		for (int i = 0; i + figure.r <= n; ++i) {
			for (int j = 0; j + figure.c <= m; ++j) {
				for (int k = 0; k < x; ++k) {
					a[figure.x[k] + i][figure.y[k] + j] = true;
				}
				boolean res = areValidParts(a, x, n, m);
				for (int k = 0; k < x; ++k) {
					a[figure.x[k] + i][figure.y[k] + j] = false;
				}
				if (res) return true;
			}
		}
		return false;
	}

	private boolean areValidParts(boolean[][] a, int c, int n, int m) {
		boolean[][] used = new boolean[n][m];
		for (int x = 0; x < n; ++x) {
			for (int y = 0; y < m; ++y) {
				if (!used[x][y] && !a[x][y]) {
					if (dfs(x, y, a, used, n, m) % c > 0) {
						return false;
					}
				}
			}
		}
		return true;
	}

	private int dfs(int x, int y, boolean[][] a, boolean[][] used, int n, int m) {
		int res = 1;
		used[x][y] = true;
		for (Pos sh : SHIFT) {
			int xx = x + sh.x;
			int yy = y + sh.y;
			if (xx >= 0 && xx < n && yy >= 0 && yy < m && !used[xx][yy] && !a[xx][yy]) {
				res += dfs(xx, yy, a, used, n, m);
			}
		}
		return res;
	}
}

class ArrayUtils {

	public static void fill(char[][] array, char value) {
		for (char[] row : array)
			Arrays.fill(row, value);
	}

}

class InputReader {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private SpaceCharFilter filter;

	public InputReader(InputStream stream) {
		this.stream = stream;
	}

	public int read() {
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}

	public int readInt() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}

	public String readString() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			if (Character.isValidCodePoint(c))
				res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	public boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public String next() {
		return readString();
	}

	public interface SpaceCharFilter {
		public boolean isSpaceChar(int ch);
	}
}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}

	public void print(Object...objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(Object...objects) {
		print(objects);
		writer.println();
	}

	public void close() {
		writer.close();
	}

}

