package TaskC;

import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.math.BigInteger;
import java.util.Collections;
import java.io.InputStream;

/**
 * Thank you to Egor Kulikov for Java Template
 * Built using CHelper plug-in
 * @author Richard Hua (rich@rkhua.com)
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("input.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
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
		out.printLine("Case #" + testNumber + ":");
		int R = in.readInt();
		int N = in.readInt();
		int M = in.readInt();
		int K = in.readInt();
		assert (N == 3);
		assert (M == 5);

		for (int i = 0; i < R; i++) {
			int[] factors = new int[M + 1];
			int[] occurrences = new int[M + 1];
			for (int j = 2; j < factors.length; j++) {
				factors[j] = 0;
				occurrences[j] = 0;
			}
			
			for (int j = 0; j < K; j++) {
				int product = in.readInt();
				int[] tempFactors = new int[M + 1];
				for (int k = factors.length - 1; k >= 2; k--) {
					int reps = numFactors(product, k);
					tempFactors[k] = reps;
					occurrences[k] += reps;
				}
				tempFactors[2] = tempFactors[2] % 2;
				for (int k = 2; k < factors.length; k++) {
					if (tempFactors[k] > factors[k]) {
						factors[k] = tempFactors[k];
					}
				}
			}
			
			int count = 0;
			for (int k = 2; k < factors.length; k++) {
				count += factors[k];
			}
			assert count <= N;
			if ((count < N) && (factors[4] > 0)) {
				factors[2] += 2;
				factors[4] -= 1;
				count++;
			}
			while (count < N) {
				int factor = 2;
				int maxOccurrences = 0;
				for (int k = 2; k < factors.length; k++) {
					if (occurrences[k] > maxOccurrences) {
						factor = k;
						maxOccurrences = occurrences[k];
					}
				}
				factors[factor]++;
				occurrences[factor] /= 2;
				count++;
			}
			
			for (int k = 2; k < factors.length; k++) {
				while (factors[k] > 0) {
					out.print(k);
					factors[k]--;
				}
			}
			out.printLine();
		}

	}
	
	public int numFactors(int product, int factor) {
		int count = 0;
		while (product % factor == 0) {
			product = product / factor;
			count++;
		}
		return count;
	}
}

class InputReader {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;

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
	
	public char readChar() {
		int c;
		do {
			c = read();
		} while (isSpaceChar(c));
		
		return (char) c;
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
		StringBuffer res = new StringBuffer();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	public static boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public String next() {
		return readString();
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

	public void close() {
		writer.close();
	}

	}

class IOUtils {

	public static void readIntArrays(InputReader in, int[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readInt();
		}
	}

	public static void readBoard(InputReader in, char[][] board) {
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[i].length; j++)
				board[i][j] = in.readChar();
		}
	}

	}

class MiscUtils {

	public static void decreaseByOne(int[]...arrays) {
		for (int[] array : arrays) {
			for (int i = 0; i < array.length; i++)
				array[i]--;
		}
	}

	}

class ArrayUtils {

	public static void fill(int[][] array, int value) {
		for (int[] row : array)
			Arrays.fill(row, value);
	}
}

	
	
	