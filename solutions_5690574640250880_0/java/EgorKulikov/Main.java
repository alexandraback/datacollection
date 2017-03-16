import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Locale;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.File;
import java.io.Writer;
import java.io.FilenameFilter;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Egor Kulikov (egor@egork.net)
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "C-.*[.]in";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("c.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int rowCount = in.readInt();
		int columnCount = in.readInt();
		int mines = in.readInt();
		out.printLine("Case #" + testNumber + ":");
		char[][] answer = new char[rowCount][columnCount];
		int notMines = 0;
		if (mines + 1 == rowCount * columnCount) {
			ArrayUtils.fill(answer, '*');
			answer[0][0] = 'c';
		} else if (rowCount == 1 || columnCount == 1) {
			notMines = 1;
			answer[0][0] = 'c';
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < columnCount; j++) {
					if (answer[i][j] == 0) {
						if (notMines + mines == rowCount * columnCount)
							answer[i][j] = '*';
						else {
							answer[i][j] = '.';
							notMines++;
						}
					}
				}
			}
		} else if (rowCount == 2 || columnCount == 2) {
			if (mines % 2 != 0 || rowCount * columnCount - mines == 2)
				answer = null;
			else {
				if (rowCount == 2) {
					for (int i = 0; i < columnCount - mines / 2; i++) {
						answer[0][i] = answer[1][i] = '.';
					}
					for (int i = columnCount - mines / 2; i < columnCount; i++) {
						answer[0][i] = answer[1][i] = '*';
					}
					answer[0][0] = 'c';
				} else {
					for (int i = 0; i < rowCount - mines / 2; i++) {
						answer[i][0] = answer[i][1] = '.';
					}
					for (int i = rowCount - mines / 2; i < rowCount; i++) {
						answer[i][0] = answer[i][1] = '*';
					}
					answer[0][0] = 'c';
				}
			}
		} else {
			int requiredNotMines = rowCount * columnCount - mines;
			if (requiredNotMines == 3 || requiredNotMines == 5 || requiredNotMines == 7 || requiredNotMines == 2)
				answer = null;
			else {
				if (requiredNotMines % 2 == 1) {
					answer[2][0] = answer[2][1] = answer[2][2] = '.';
					notMines += 3;
				}
				for (int i = 0; i < columnCount; i++) {
					if (notMines + mines == rowCount * columnCount)
						answer[0][i] = answer[1][i] = '*';
					else {
						answer[0][i] = answer[1][i] = '.';
						notMines += 2;
					}
				}
				for (int i = 2; i < rowCount; i++) {
					if (answer[i][0] == 0) {
						if (notMines + mines == rowCount * columnCount)
							answer[i][0] = answer[i][1] = '*';
						else {
							answer[i][0] = answer[i][1] = '.';
							notMines += 2;
						}						
					}
				}
				for (int i = 2; i < rowCount; i++) {
					for (int j = 2; j < columnCount; j++) {
						if (answer[i][j] == 0) {
							if (notMines + mines == rowCount * columnCount)
								answer[i][j] = '*';
							else {
								answer[i][j] = '.';
								notMines++;
							}
						}
					}
				}
				answer[0][0] = 'c';
			}
		}
		if (answer == null)
			out.printLine("Impossible");
		else {
			for (char[] row : answer)
				out.printLine(row);
		}
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

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
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

	public void printLine(char[] array) {
		writer.println(array);
	}

	public void close() {
		writer.close();
	}

	}

class ArrayUtils {

	public static void fill(char[][] array, char value) {
		for (char[] row : array)
			Arrays.fill(row, value);
	}

	}

