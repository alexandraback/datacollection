import java.io.*;
import java.util.*;
import java.math.*;

/**
 * Iron Maiden - Number of the Beast.
 * 
 * @author Gorokhov Nikita (wackloner@gmail.com)
 */

public class Cslow implements Runnable {
	
	void solve() {
		int t = nextInt();
		for (int testNumber = 1; testNumber <= t; testNumber++) {
			int n = nextInt(), m = nextInt();
			final String[] zip = new String[n];
			for (int i = 0; i < n; i++)
				zip[i] = nextString();
			ArrayList<Integer>[] g = new ArrayList[n];
			for (int i = 0; i < n; i++)
				g[i] = new ArrayList<Integer>();
			for (int i = 0; i < m; i++) {
				int x = nextInt() - 1, y = nextInt() - 1;
				g[x].add(y);
				g[y].add(x);
			}
			min = null;
			used = new boolean[n];
			p = new int[n];
			len = new int[n];
			rec(0, n, g, zip);
			print("Case #");
			print(testNumber);
			print(": ");
			println(min);
		}
	}

	
	int need;
	int[] p, len;
	boolean[] used;
	String min;
	boolean yes;
	
	void dfs(int v, int prev, ArrayList<Integer>[] g, int n) {
		if (need == n) {
			yes = true;
			return;
		}
		for (; len[v] < g[v].size(); len[v]++) {
			if (need == n) {
				yes = true;
				return;
			}
			int to = g[v].get(len[v]);
			if (to == p[need]) {
				need++;
				dfs(to, v, g, n);
			}
		}
		if (prev != -1)
			len[prev] = -1;
	}
	
	void rec(int cur, int n, ArrayList<Integer>[] g, String[] zip) {
		if (cur == n) {
			need = 1;
			for (int i = 0; i < n; i++)
				len[i] = 0;
			yes = false;
			dfs(p[0], -1, g, n);
			if (yes)
				updateAnswer(n, zip);
			return;
		}
		for (int i = 0; i < n; i++)
			if (!used[i]) {
				used[i] = true;
				p[cur] = i;
				rec(cur + 1, n, g, zip);
				used[i] = false;
			}
	}
	
	void updateAnswer(int n, String[] zip) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++)
			sb.append(zip[p[i]]);
		String res = sb.toString();
		if (min == null || min.compareTo(res) > 0)
			min = res;
	}
	
	public static void main(String[] args) throws IOException {
		new Cslow("input.txt", "output.txt").run();
	}
	
	Cslow() {
		this.stream = System.in;
		this.writer = new PrintWriter(System.out);
	}
	
	Cslow(String input, String output) throws IOException {
		File inputFile = new File(input);
		inputFile.createNewFile();
		stream = new FileInputStream(inputFile);
		File outputFile = new File(output);
		outputFile.createNewFile();
		writer = new PrintWriter(outputFile);
	}
	
	public void run() {
		solve();
		writer.close();
	}
	
	void halt() {
		writer.close();
		System.exit(0);
	}
	
	PrintWriter writer;;
	
	void print(Object... objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}
	
	void println(Object... objects) {
		print(objects);
		writer.println();
	}
	
	void printArray(int[] array) {
		for (int i = 0; i < array.length; i++) {
			if (i != 0) writer.print(' ');
			writer.print(array[i]);
		}
		writer.println();
	}
	
	void printArray(long[] array) {
		for (int i = 0; i < array.length; i++) {
			if (i != 0) writer.print(' ');
			writer.print(array[i]);
		}
		writer.println();
	}
	
	void printMatrix(int[][] matrix) {
		for (int i = 0; i < matrix.length; i++)
			printArray(matrix[i]);
	}
	
	void printMatrix(long[][] matrix) {
		for (int i = 0; i < matrix.length; i++)
			printArray(matrix[i]);
	}
	
	/**
	 * Pure Egor's code is straight ahead.
	 */
	
	InputStream stream;
	byte[] buf = new byte[1024];
	int curChar, numChars;
	
	int nextInt() {
		int c = next();
		while (isWhitespace(c))
			c = next();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = next();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = next();
		} while (!isWhitespace(c));
		return res * sgn;
	}
	
	long nextLong() {
		int c = next();
		while (isWhitespace(c))
			c = next();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = next();
		}
		long res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = next();
		} while (!isWhitespace(c));
		return res * sgn;
	}
	
	double nextDouble() {
		int c = next();
		while (isWhitespace(c))
			c = next();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = next();
		}
		double res = 0;
		while (!isWhitespace(c) && c != '.') {
			if (c == 'e' || c == 'E')
				return res * Math.pow(10, nextInt());
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = next();
		}
		if (c == '.') {
			c = next();
			double m = 1;
			while (!isWhitespace(c)) {
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, nextInt());
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				m /= 10;
				res += (c - '0') * m;
				c = next();
			}
		}
		return res * sgn;
	}
	
	BigInteger nextBigInteger() {
		try {
			return new BigInteger(nextString());
		} catch (NumberFormatException e) {
			throw new InputMismatchException();
		}
	}
	
	int next() {
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
	
	String nextString() {
		int c = next();
		while (isWhitespace(c))
			c = next();
		StringBuilder res = new StringBuilder();
		do {
			if (Character.isValidCodePoint(c))
				res.appendCodePoint(c);
			c = next();
		} while (!isWhitespace(c));
		return res.toString();
	}
	
	String nextLine() {
		StringBuilder buf = new StringBuilder();
		int c = next();
		while (c != '\n' && c != -1) {
			if (c != '\r')
				buf.appendCodePoint(c);
			c = next();
		}
		return buf.toString();
	}
	
	boolean EOF() {
		int value;
		while (isWhitespace(value = peek()) && value != -1)
			next();
		return value == -1;
	}
	
	int peek() {
		if (numChars == -1)
			return -1;
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				return -1;
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar];
	}
	
	boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}
}