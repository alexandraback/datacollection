import java.io.*;
import java.util.*;
import java.math.*;

final public class Main implements Runnable {
	private static boolean local;

	public static void main(String[] args) {
		if (args.length > 0 && args[0].equals("local")) {
			local = true;
		}
		new Thread(null, new Main(), "mainthread", 1 << 27).start();
	}

	public void run() {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;

		try {
			if (local) {
				inputStream = new FileInputStream("X:/coding/workspace/java/main/io/input.txt");
				outputStream = new FileOutputStream("X:/coding/workspace/java/main/io/output.txt");
			} else {
				// inputStream = new FileInputStream("input.txt");
				// outputStream = new FileOutputStream("output.txt");
			}
		} catch (Exception e) {
			throw new RuntimeException(e);
		}

		Task solver = new Task();
		solver.in = new InputReader(inputStream);
		solver.out = new OutputWriter(outputStream);
		if (local) {
			solver.dout = new DebugWriter(solver.out);
		}
		solver.solve();
		solver.out.close();
	}
}

final class Task {
	public InputReader in;
	public OutputWriter out;
	public DebugWriter dout;
	
	void err() {
		System.err.println("err");
	}
	
	void err(String s) {
		System.err.println(s);
	}

	public void solve() {
		int T = in.readInt();
		for (int t = 1; t <= T; ++t) {
			out.print("Case #" + t + ": ");
			
			mas = new ArrayList<>();
			value = new int[ADD * 2];
			
			int n = in.readInt();			
			for (int j = 0; j < n; ++j) {
				int day = in.readInt();
				int count = in.readInt();
				int L = in.readInt();
				int R = in.readInt();
				int str = in.readInt();
				
				int deltaDay = in.readInt();
				int deltaLength = in.readInt();
				int deltaStr = in.readInt();
				
				for (int i = 0; i < count; ++i) {
					mas.add(new ComparablePair<>(new ComparablePair<>(day, str), new ComparablePair<>(L, R)));
					day += deltaDay;
					L += deltaLength;
					R += deltaLength;
					str += deltaStr;
				}
			}
			
			SequenceUtils.quickSort(mas);
			
			// dout.printLine();
			// dout.printLine(mas);
			
			int res = 0;
			
			for (int j = 0; j < mas.size(); ++j) {
				int str = mas.get(j).first.second;
				int L = mas.get(j).second.first;
				int R = mas.get(j).second.second;
				
				for (int i = L; i < R; ++i)
					if (value[ADD + i] < str) {
						// dout.printLine(mas.get(j).first.first);
						++res;
						break;
					}
					
				if (j + 1 < mas.size() && mas.get(j).first.first == mas.get(j + 1).first.first)
					continue;
				
				for (int k = 0; k <= j; ++k)
					if (mas.get(k).first.first == mas.get(j).first.first) {
						str = mas.get(k).first.second;
						L = mas.get(k).second.first;
						R = mas.get(k).second.second;
						for (int i = L; i < R; ++i)	
							value[ADD + i] = Math.max(value[ADD + i], str);
					}
			}
			
			out.printLine(res);			
		}
	}
	
	final int ADD = 1 << 10;
	int[] value;
	// day, str, L, R
	ArrayList<ComparablePair<ComparablePair<Integer, Integer>, ComparablePair<Integer, Integer>>> mas;
}

final class InputReader {
	private boolean finished = false;

	private InputStream stream;
	private byte[] buf = new byte[1 << 13];
	private int curChar;
	private int numChars;

	public InputReader(InputStream stream) {
		this.stream = stream;
	}

	private int read() {
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

	public int peek() {
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

	public long readLong() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		long res = 0;
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
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	public static boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	private String readLine0() {
		StringBuilder buf = new StringBuilder();
		int c = read();
		while (c != '\n' && c != -1) {
			if (c != '\r')
				buf.appendCodePoint(c);
			c = read();
		}
		return buf.toString();
	}

	public String readLine() {
		String s = readLine0();
		while (s.trim().length() == 0)
			s = readLine0();
		return s;
	}

	public String readLine(boolean ignoreEmptyLines) {
		if (ignoreEmptyLines)
			return readLine();
		else
			return readLine0();
	}
	
	public String readToEnd() {
		StringBuilder buf = new StringBuilder();
		int c = read();
		while (c != -1) {
			if (c != '\r')
				buf.appendCodePoint(c);
			c = read();
		}
		return buf.toString();
	}

	public BigInteger readBigInteger() {
		try {
			return new BigInteger(readString());
		} catch (NumberFormatException e) {
			throw new InputMismatchException();
		}
	}

	public char readCharacter() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		return (char) c;
	}

	public double readDouble() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		double res = 0;
		while (!isSpaceChar(c) && c != '.') {
			if (c == 'e' || c == 'E')
				return res * Math.pow(10, readInt());
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		}
		if (c == '.') {
			c = read();
			double m = 1;
			while (!isSpaceChar(c)) {
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, readInt());
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				m /= 10;
				res += (c - '0') * m;
				c = read();
			}
		}
		return res * sgn;
	}

	public boolean isExhausted() {
		int value;
		while (isSpaceChar(value = peek()) && value != -1)
			read();
		return value == -1;
	}
	
	public void close() {
		try {
			stream.close();
		} catch (IOException e) {
			throw new RuntimeException();			
		}
	}
}

final class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream), 1 << 13));
	}

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}


	public void print(Object... objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(Object... objects) {
		print(objects);
		writer.println();
	}

	public void printFormat(String format, Object... objects) {
		writer.printf(format, objects);
	}


	public void print(char[] objects) {
		writer.print(objects);
	}

	public void printLine(char[] objects) {
		writer.println(objects);
	}

	public void printLine(char[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
	}


	public void print(int[] objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(int[] objects) {
		print(objects);
		writer.println();
	}

	public void printLine(int[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
	}


	public void print(short[] objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(short[] objects) {
		print(objects);
		writer.println();
	}

	public void printLine(short[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
	}


	public void print(long[] objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(long[] objects) {
		print(objects);
		writer.println();
	}

	public void printLine(long[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
	}


	public void print(double[] objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(double[] objects) {
		print(objects);
		writer.println();
	}

	public void printLine(double[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
	}


	public void print(byte[] objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(byte[] objects) {
		print(objects);
		writer.println();
	}

	public void printLine(byte[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
	}


	public void print(boolean[] objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(boolean[] objects) {
		print(objects);
		writer.println();
	}

	public void printLine(boolean[][] objects) {
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
	}


	public void close() {
		writer.close();
	}

	public void flush() {
		writer.flush();
	}
}

final class DebugWriter {
	private final OutputWriter writer;

	public DebugWriter(OutputWriter writer) {
		this.writer = writer;
	}

	private void printDebugMessage() {
		writer.print("DEBUG:\t");
	}


	public void printLine(Object... objects) {
		flush();
		printDebugMessage();
		writer.printLine(objects);
		flush();
	}

	public void printFormat(String format, Object... objects) {
		flush();
		printDebugMessage();
		writer.printFormat(format, objects);
		flush();
	}


	public void printLine(char[] objects) {
		flush();
		printDebugMessage();
		writer.printLine(objects);
		flush();
	}

	public void printLine(char[][] objects) {
		flush();
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}


	public void printLine(double[] objects) {
		flush();
		printDebugMessage();
		writer.printLine(objects);
		flush();
	}

	public void printLine(double[][] objects) {
		flush();
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}


	public void printLine(int[] objects) {
		flush();
		printDebugMessage();
		writer.printLine(objects);
		flush();
	}

	public void printLine(int[][] objects) {
		flush();
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}


	public void printLine(short[] objects) {
		flush();
		printDebugMessage();
		writer.printLine(objects);
		flush();
	}

	public void printLine(short[][] objects) {
		flush();
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}


	public void printLine(long[] objects) {
		flush();
		printDebugMessage();
		writer.printLine(objects);
		flush();
	}

	public void printLine(long[][] objects) {
		flush();
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}


	public void printLine(byte[] objects) {
		flush();
		printDebugMessage();
		writer.printLine(objects);
		flush();
	}

	public void printLine(byte[][] objects) {
		flush();
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}


	public void printLine(boolean[] objects) {
		flush();
		printDebugMessage();
		writer.printLine(objects);
		flush();
	}

	public void printLine(boolean[][] objects) {
		flush();
		for (int i = 0; i < objects.length; ++i)
			printLine(objects[i]);
		flush();
	}


	public void flush() {
		writer.flush();
	}
}

final class Pair<F, S> {
	public F first;
	public S second;

	public Pair(F first, S second) {
		this.first = first;
		this.second = second;
	}

	public int hashCode() {
		int hFirst = first != null ? first.hashCode() : 0;
		int hSecond = second != null ? second.hashCode() : 0;
		return 31 * hFirst + hSecond;
	}

	public boolean equals(Pair<F, S> pair) {
		if (this == pair) return true;

		return (first != null ? first.equals(pair.first) : pair.first == null) &&
				(second != null ? second.equals(pair.second) : pair.second == null);
	}

	public Pair<F, S> clone() {
		return new Pair<F, S>(first, second);
	}

	public String toString() {
		return "(" + first + ", " + second + ")";
	}
}

// final class SplayTreeNoKey {
// 	private final class Node {
// 		Node left = null;
// 		Node right = null;
// 		int size = 1;
// 		int L;
// 		int R;
// 		int min;
// 		int sum;

// 		Node(int L, int R) {
// 		}
// 	}

// 	private Node root;

// 	private int getSize(Node x) {
// 		return x == null ? 0 : x.size;
// 	}
	
// 	private int getSum(Node x) {
// 		return x == null ? 0 : x.sum;
// 	}
	
// 	private int getMin(Node x) {
// 		return x == null ? Integer.MAX_VALUE : x.min;
// 	}

// 	private int getKey(Node x) {
// 		return x == null ? 0 : getSize(x.left) + 1;
// 	}

// 	private void update(Node x) {
// 		if (x != null) x.size = 1 + getSize(x.left) + getSize(x.right);
// 	}

// 	// <- (p,x)
// 	private void rotateLeft(Node x, Node p) {
// 		p.right = x.left;
// 		x.left = p;
// 	}

// 	// (x,p) ->
// 	private void rotateRight(Node x, Node p) {
// 		p.left = x.right;
// 		x.right = p;
// 	}

// 	private Node splay(Node x, int key) {
// 		if (x == null) return null;
// 		Node left = null;
// 		Node right = null;

// 		while (true) {
// 			if (key < getKey(x)) {
// 				Node y = x.left;
// 				if (y == null) break;
// 				if (key < getKey(y)) { // left zig-zig
// 					rotateRight(y, x);
// 					update(x);
// 					x = y;
// 					if (x.left == null) break;
// 				}
// 				// link right
// 				y = x.left;
// 				x.left = right;
// 				right = x;
// 				// move left
// 				x = y;
// 			} else if (key > getKey(x)) {
// 				Node y = x.right;
// 				key -= getKey(x);
// 				if (y == null) break;
// 				if (key > getKey(y)) { // left zig-zig
// 					key -= getKey(y);
// 					rotateLeft(y, x);
// 					update(x);
// 					x = y;
// 					if (x.right == null) break;
// 				}
// 				//link left
// 				y = x.right;
// 				x.right = left;
// 				left = x;
// 				//move right
// 				x = y;
// 			} else break;
// 		}

// 		Node low, high;
// 		// assemble left
// 		low = x.left;
// 		while (left != null) {
// 			high = left.right;
// 			left.right = low;
// 			update(left);
// 			low = left;
// 			left = high;
// 		}
// 		x.left = low;
// 		// assemble right
// 		low = x.right;
// 		while (right != null) {
// 			high = right.left;
// 			right.left = low;
// 			update(right);
// 			low = right;
// 			right = high;
// 		}
// 		x.right = low;

// 		update(x);
// 		return x;
// 	}

// 	private Node join(Node left, Node right) {
// 		if (left == null) return right;
// 		if (right == null) return left;
// 		left = splay(left, Integer.MAX_VALUE);
// 		left.right = right;
// 		update(left);
// 		return left;
// 	}

// 	// left <= key, key < right
// 	private Pair<Node, Node> split(Node x, int key) {
// 		if (key > size() + 1) throw new RuntimeException();
// 		x = splay(x, key);
// 		// cut right
// 		Node right = x.right;
// 		x.right = null;
// 		update(x);
// 		return new Pair<Node, Node>(x, right);
// 	}

// 	// API:

// 	public int size() {
// 		return getSize(root);
// 	}

// 	public void add(int key, int value) {
// 		if (root == null) root = new Node(value);
// 		else {
// 			if (key > size() + 1) throw new RuntimeException();
// 			Pair<Node, Node> pair = split(root, key);
// 			root = new Node(value);
// 			root.left = pair.first;
// 			root.right = pair.second;
// 			update(root);
// 		}
// 	}

// 	public int get(int key) {
// 		if (key > size()) throw new RuntimeException();
// 		root = splay(root, key);
// 		return root.value;
// 	}

// 	public void remove(int key) {
// 		if (key > size()) throw new RuntimeException();
// 		root = splay(root, key);
// 		root = join(root.left, root.right);
// 	}

// 	// DEBUG:

// 	public ArrayList<Integer> getValues() {
// 		ArrayList<Integer> list = new ArrayList<Integer>();
// 		dfs(root, list);
// 		return list;
// 	}

// 	private void dfs(Node v, ArrayList<Integer> list) {
// 		if (v == null) return;
// 		dfs(v.left, list);
// 		list.add(v.value);
// 		dfs(v.right, list);
// 	}

// 	@Override
// 	public String toString() {
// 		return getValues().toString();
// 	}
// }

final class SequenceUtils {
	// swap
	public final static <T> void swap(List<T> sequence, int j, int i) {
		T tmp = sequence.get(j);
		sequence.set(j, sequence.get(i));
		sequence.set(i, tmp);
	}

	public final static <T> void swap(T[] sequence, int j, int i) {
		T tmp = sequence[j];
		sequence[j] = sequence[i];
		sequence[i] = tmp;
	}

	public final static void swap(int[] sequence, int j, int i) {
		int tmp = sequence[j];
		sequence[j] = sequence[i];
		sequence[i] = tmp;
	}

	public final static void swap(long[] sequence, int j, int i) {
		long tmp = sequence[j];
		sequence[j] = sequence[i];
		sequence[i] = tmp;
	}

	public final static void swap(char[] sequence, int j, int i) {
		char tmp = sequence[j];
		sequence[j] = sequence[i];
		sequence[i] = tmp;
	}

	public final static void swap(double[] sequence, int j, int i) {
		double tmp = sequence[j];
		sequence[j] = sequence[i];
		sequence[i] = tmp;
	}

	public final static void swap(boolean[] sequence, int j, int i) {
		boolean tmp = sequence[j];
		sequence[j] = sequence[i];
		sequence[i] = tmp;
	}

	public final static void swap(short[] sequence, int j, int i) {
		short tmp = sequence[j];
		sequence[j] = sequence[i];
		sequence[i] = tmp;
	}

	public final static void swap(byte[] sequence, int j, int i) {
		byte tmp = sequence[j];
		sequence[j] = sequence[i];
		sequence[i] = tmp;
	}

	// reverse
	public final static <T> void reverse(List<T> sequence) {
		for (int left = 0, right = sequence.size() - 1; left < right; ++left, --right)
			swap(sequence, left, right);
	}

	public final static <T> void reverse(T[] sequence) {
		for (int left = 0, right = sequence.length - 1; left < right; ++left, --right)
			swap(sequence, left, right);
	}

	public final static void reverse(int[] sequence) {
		for (int left = 0, right = sequence.length - 1; left < right; ++left, --right)
			swap(sequence, left, right);
	}

	public final static void reverse(long[] sequence) {
		for (int left = 0, right = sequence.length - 1; left < right; ++left, --right)
			swap(sequence, left, right);
	}

	public final static void reverse(char[] sequence) {
		for (int left = 0, right = sequence.length - 1; left < right; ++left, --right)
			swap(sequence, left, right);
	}

	public final static void reverse(double[] sequence) {
		for (int left = 0, right = sequence.length - 1; left < right; ++left, --right)
			swap(sequence, left, right);
	}

	public final static void reverse(boolean[] sequence) {
		for (int left = 0, right = sequence.length - 1; left < right; ++left, --right)
			swap(sequence, left, right);
	}

	public final static void reverse(short[] sequence) {
		for (int left = 0, right = sequence.length - 1; left < right; ++left, --right)
			swap(sequence, left, right);
	}

	public final static void reverse(byte[] sequence) {
		for (int left = 0, right = sequence.length - 1; left < right; ++left, --right)
			swap(sequence, left, right);
	}

	// next permutation
	public final static <T extends Comparable<T>> boolean nextPermutation(List<T> sequence) {
		for (int j = sequence.size() - 2; j >= 0; --j) {
			if (sequence.get(j).compareTo(sequence.get(j + 1)) < 0) {
				reverse(sequence.subList(j + 1, sequence.size()));
				for (int i = j + 1; i < sequence.size(); ++i)
					if (sequence.get(j).compareTo(sequence.get(i)) < 0) {
						swap(sequence, j, i);
						return true;
					}
			}
		}
		return false;
	}

	public final static <T> boolean nextPermutation(List<T> sequence, Comparator<T> comparator) {
		for (int j = sequence.size() - 2; j >= 0; --j) {
			if (comparator.compare(sequence.get(j), sequence.get(j + 1)) < 0) {
				reverse(sequence.subList(j + 1, sequence.size()));
				for (int i = j + 1; i < sequence.size(); ++i)
					if (comparator.compare(sequence.get(j), sequence.get(i)) < 0) {
						swap(sequence, j, i);
						return true;
					}
			}
		}
		return false;
	}

	// random shuffle
	public final static <T> void shuffle(List<T> sequence) {
		Random random = new Random(System.nanoTime());
		for (int i = 1; i < sequence.size(); ++i)
			swap(sequence, random.nextInt(i + 1), i);
	}

	public final static <T> void shuffle(T[] sequence) {
		Random random = new Random(System.nanoTime());
		for (int i = 1; i < sequence.length; ++i)
			swap(sequence, random.nextInt(i + 1), i);
	}

	public final static void shuffle(int[] sequence) {
		Random random = new Random(System.nanoTime());
		for (int i = 1; i < sequence.length; ++i)
			swap(sequence, random.nextInt(i + 1), i);
	}

	public final static void shuffle(long[] sequence) {
		Random random = new Random(System.nanoTime());
		for (int i = 1; i < sequence.length; ++i)
			swap(sequence, random.nextInt(i + 1), i);
	}

	public final static void shuffle(char[] sequence) {
		Random random = new Random(System.nanoTime());
		for (int i = 1; i < sequence.length; ++i)
			swap(sequence, random.nextInt(i + 1), i);
	}

	public final static void shuffle(double[] sequence) {
		Random random = new Random(System.nanoTime());
		for (int i = 1; i < sequence.length; ++i)
			swap(sequence, random.nextInt(i + 1), i);
	}

	public final static void shuffle(boolean[] sequence) {
		Random random = new Random(System.nanoTime());
		for (int i = 1; i < sequence.length; ++i)
			swap(sequence, random.nextInt(i + 1), i);
	}

	public final static void shuffle(short[] sequence) {
		Random random = new Random(System.nanoTime());
		for (int i = 1; i < sequence.length; ++i)
			swap(sequence, random.nextInt(i + 1), i);
	}

	public final static void shuffle(byte[] sequence) {
		Random random = new Random(System.nanoTime());
		for (int i = 1; i < sequence.length; ++i)
			swap(sequence, random.nextInt(i + 1), i);
	}

	// merge sort
	public final static <T extends Comparable<T>> void mergeSort(List<T> sequence) {
		int n = sequence.size();
		T[] tmp = (T[]) new Object[n];
		for (int step = 1; step < n; step *= 2) {
			for (int i = 0; i < n; ++i)
				tmp[i] = sequence.get(i);
			for (int i = 0; i + step < n; i += 2 * step)
				merge(sequence, tmp, i, i + step - 1, Math.min(i + step * 2 - 1, n - 1));
		}
	}

	private final static <T extends Comparable<T>> void merge(List<T> sequence, T[] tmp, int left, int mid, int right) {
		int pLeft = left;
		int pRight = mid + 1;
		for (int i = left; i <= right; ++i)
			if (pLeft > mid) sequence.set(i, tmp[pRight++]);
			else if (pRight > right) sequence.set(i, tmp[pLeft++]);
			else if (tmp[pLeft].compareTo(tmp[pRight]) <= 0) sequence.set(i, tmp[pLeft++]);
			else sequence.set(i, tmp[pRight++]);
	}


	public final static <T extends Comparable<T>> void mergeSort(T[] sequence) {
		int n = sequence.length;
		T[] tmp = (T[]) new Object[n];
		for (int step = 1; step < n; step *= 2) {
			for (int i = 0; i < n; ++i)
				tmp[i] = sequence[i];
			for (int i = 0; i + step < n; i += 2 * step)
				merge(sequence, tmp, i, i + step - 1, Math.min(i + step * 2 - 1, n - 1));
		}
	}

	private final static <T extends Comparable<T>> void merge(T[] sequence, T[] tmp, int left, int mid, int right) {
		int pLeft = left;
		int pRight = mid + 1;
		for (int i = left; i <= right; ++i)
			if (pLeft > mid) sequence[i] = tmp[pRight++];
			else if (pRight > right) sequence[i] = tmp[pLeft++];
			else if (tmp[pLeft].compareTo(tmp[pRight]) <= 0) sequence[i] = tmp[pLeft++];
			else sequence[i] = tmp[pRight++];
	}


	public final static <T> void mergeSort(List<T> sequence, Comparator<T> comparator) {
		int n = sequence.size();
		T[] tmp = (T[]) new Object[n];
		for (int step = 1; step < n; step *= 2) {
			for (int i = 0; i < n; ++i)
				tmp[i] = sequence.get(i);
			for (int i = 0; i + step < n; i += 2 * step)
				merge(sequence, tmp, i, i + step - 1, Math.min(i + step * 2 - 1, n - 1), comparator);
		}
	}

	private final static <T> void merge(List<T> sequence, T[] tmp, int left, int mid, int right, Comparator<T> comparator) {
		int pLeft = left;
		int pRight = mid + 1;
		for (int i = left; i <= right; ++i)
			if (pLeft > mid) sequence.set(i, tmp[pRight++]);
			else if (pRight > right) sequence.set(i, tmp[pLeft++]);
			else if (comparator.compare(tmp[pLeft], tmp[pRight]) <= 0) sequence.set(i, tmp[pLeft++]);
			else sequence.set(i, tmp[pRight++]);
	}


	public final static <T> void mergeSort(T[] sequence, Comparator<T> comparator) {
		int n = sequence.length;
		T[] tmp = (T[]) new Object[n];
		for (int step = 1; step < n; step *= 2) {
			for (int i = 0; i < n; ++i)
				tmp[i] = sequence[i];
			for (int i = 0; i + step < n; i += 2 * step)
				merge(sequence, tmp, i, i + step - 1, Math.min(i + step * 2 - 1, n - 1), comparator);
		}
	}

	private final static <T> void merge(T[] sequence, T[] tmp, int left, int mid, int right, Comparator<T> comparator) {
		int pLeft = left;
		int pRight = mid + 1;
		for (int i = left; i <= right; ++i)
			if (pLeft > mid) sequence[i] = tmp[pRight++];
			else if (pRight > right) sequence[i] = tmp[pLeft++];
			else if (comparator.compare(tmp[pLeft], tmp[pRight]) <= 0) sequence[i] = tmp[pLeft++];
			else sequence[i] = tmp[pRight++];
	}


	public final static void mergeSort(int[] sequence) {
		int n = sequence.length;
		int[] tmp = new int[n];
		for (int step = 1; step < n; step *= 2) {
			for (int i = 0; i < n; ++i)
				tmp[i] = sequence[i];
			for (int i = 0; i + step < n; i += 2 * step)
				merge(sequence, tmp, i, i + step - 1, Math.min(i + step * 2 - 1, n - 1));
		}
	}

	private final static void merge(int[] sequence, int[] tmp, int left, int mid, int right) {
		int pLeft = left;
		int pRight = mid + 1;
		for (int i = left; i <= right; ++i)
			if (pLeft > mid) sequence[i] = tmp[pRight++];
			else if (pRight > right) sequence[i] = tmp[pLeft++];
			else if (tmp[pLeft] <= tmp[pRight]) sequence[i] = tmp[pLeft++];
			else sequence[i] = tmp[pRight++];
	}


	public final static void mergeSort(long[] sequence) {
		int n = sequence.length;
		long[] tmp = new long[n];
		for (int step = 1; step < n; step *= 2) {
			for (int i = 0; i < n; ++i)
				tmp[i] = sequence[i];
			for (int i = 0; i + step < n; i += 2 * step)
				merge(sequence, tmp, i, i + step - 1, Math.min(i + step * 2 - 1, n - 1));
		}
	}

	private final static void merge(long[] sequence, long[] tmp, int left, int mid, int right) {
		int pLeft = left;
		int pRight = mid + 1;
		for (int i = left; i <= right; ++i)
			if (pLeft > mid) sequence[i] = tmp[pRight++];
			else if (pRight > right) sequence[i] = tmp[pLeft++];
			else if (tmp[pLeft] <= tmp[pRight]) sequence[i] = tmp[pLeft++];
			else sequence[i] = tmp[pRight++];
	}


	public final static void mergeSort(char[] sequence) {
		int n = sequence.length;
		char[] tmp = new char[n];
		for (int step = 1; step < n; step *= 2) {
			for (int i = 0; i < n; ++i)
				tmp[i] = sequence[i];
			for (int i = 0; i + step < n; i += 2 * step)
				merge(sequence, tmp, i, i + step - 1, Math.min(i + step * 2 - 1, n - 1));
		}
	}

	private final static void merge(char[] sequence, char[] tmp, int left, int mid, int right) {
		int pLeft = left;
		int pRight = mid + 1;
		for (int i = left; i <= right; ++i)
			if (pLeft > mid) sequence[i] = tmp[pRight++];
			else if (pRight > right) sequence[i] = tmp[pLeft++];
			else if (tmp[pLeft] <= tmp[pRight]) sequence[i] = tmp[pLeft++];
			else sequence[i] = tmp[pRight++];
	}


	public final static void mergeSort(double[] sequence) {
		int n = sequence.length;
		double[] tmp = new double[n];
		for (int step = 1; step < n; step *= 2) {
			for (int i = 0; i < n; ++i)
				tmp[i] = sequence[i];
			for (int i = 0; i + step < n; i += 2 * step)
				merge(sequence, tmp, i, i + step - 1, Math.min(i + step * 2 - 1, n - 1));
		}
	}

	private final static void merge(double[] sequence, double[] tmp, int left, int mid, int right) {
		int pLeft = left;
		int pRight = mid + 1;
		for (int i = left; i <= right; ++i)
			if (pLeft > mid) sequence[i] = tmp[pRight++];
			else if (pRight > right) sequence[i] = tmp[pLeft++];
			else if (tmp[pLeft] <= tmp[pRight]) sequence[i] = tmp[pLeft++];
			else sequence[i] = tmp[pRight++];
	}


	public final static void mergeSort(boolean[] sequence) {
		int n = sequence.length;
		boolean[] tmp = new boolean[n];
		for (int step = 1; step < n; step *= 2) {
			for (int i = 0; i < n; ++i)
				tmp[i] = sequence[i];
			for (int i = 0; i + step < n; i += 2 * step)
				merge(sequence, tmp, i, i + step - 1, Math.min(i + step * 2 - 1, n - 1));
		}
	}

	private final static void merge(boolean[] sequence, boolean[] tmp, int left, int mid, int right) {
		int pLeft = left;
		int pRight = mid + 1;
		for (int i = left; i <= right; ++i)
			if (pLeft > mid) sequence[i] = tmp[pRight++];
			else if (pRight > right) sequence[i] = tmp[pLeft++];
			else if (!tmp[pLeft] || tmp[pRight]) sequence[i] = tmp[pLeft++];
			else sequence[i] = tmp[pRight++];
	}


	public final static void mergeSort(short[] sequence) {
		int n = sequence.length;
		short[] tmp = new short[n];
		for (int step = 1; step < n; step *= 2) {
			for (int i = 0; i < n; ++i)
				tmp[i] = sequence[i];
			for (int i = 0; i + step < n; i += 2 * step)
				merge(sequence, tmp, i, i + step - 1, Math.min(i + step * 2 - 1, n - 1));
		}
	}

	private final static void merge(short[] sequence, short[] tmp, int left, int mid, int right) {
		int pLeft = left;
		int pRight = mid + 1;
		for (int i = left; i <= right; ++i)
			if (pLeft > mid) sequence[i] = tmp[pRight++];
			else if (pRight > right) sequence[i] = tmp[pLeft++];
			else if (tmp[pLeft] <= tmp[pRight]) sequence[i] = tmp[pLeft++];
			else sequence[i] = tmp[pRight++];
	}


	public final static void mergeSort(byte[] sequence) {
		int n = sequence.length;
		byte[] tmp = new byte[n];
		for (int step = 1; step < n; step *= 2) {
			for (int i = 0; i < n; ++i)
				tmp[i] = sequence[i];
			for (int i = 0; i + step < n; i += 2 * step)
				merge(sequence, tmp, i, i + step - 1, Math.min(i + step * 2 - 1, n - 1));
		}
	}

	private final static void merge(byte[] sequence, byte[] tmp, int left, int mid, int right) {
		int pLeft = left;
		int pRight = mid + 1;
		for (int i = left; i <= right; ++i)
			if (pLeft > mid) sequence[i] = tmp[pRight++];
			else if (pRight > right) sequence[i] = tmp[pLeft++];
			else if (tmp[pLeft] <= tmp[pRight]) sequence[i] = tmp[pLeft++];
			else sequence[i] = tmp[pRight++];
	}

	// quick sort
	public final static <T extends Comparable<T>> void quickSort(List<T> sequence) {
		shuffle(sequence);
		quickSortImplementation(sequence, 0, sequence.size() - 1);
	}

	private final static <T extends Comparable<T>> void quickSortImplementation(List<T> sequence, int left, int right) {
		if (left >= right) return;

		int lessThen = left;
		int greaterThen = right;
		int i = left;
		T value = sequence.get(left);

		while (i <= greaterThen) {
			int cmp = sequence.get(i).compareTo(value);
			if (cmp < 0) swap(sequence, i++, lessThen++);
			else if (cmp > 0) swap(sequence, i, greaterThen--);
			else ++i;
		}

		quickSortImplementation(sequence, left, lessThen - 1);
		quickSortImplementation(sequence, greaterThen + 1, right);
	}


	public final static <T extends Comparable<T>> void quickSort(T[] sequence) {
		shuffle(sequence);
		quickSortImplementation(sequence, 0, sequence.length - 1);
	}

	private final static <T extends Comparable<T>> void quickSortImplementation(T[] sequence, int left, int right) {
		if (left >= right) return;

		int lessThen = left;
		int greaterThen = right;
		int i = left;
		T value = sequence[left];

		while (i <= greaterThen) {
			int cmp = sequence[i].compareTo(value);
			if (cmp < 0) swap(sequence, i++, lessThen++);
			else if (cmp > 0) swap(sequence, i, greaterThen--);
			else ++i;
		}

		quickSortImplementation(sequence, left, lessThen - 1);
		quickSortImplementation(sequence, greaterThen + 1, right);
	}


	public final static <T> void quickSort(List<T> sequence, Comparator<T> comparator) {
		shuffle(sequence);
		quickSortImplementation(sequence, 0, sequence.size() - 1, comparator);
	}

	private final static <T> void quickSortImplementation(List<T> sequence, int left, int right, Comparator<T> comparator) {
		if (left >= right) return;

		int lessThen = left;
		int greaterThen = right;
		int i = left;
		T value = sequence.get(left);

		while (i <= greaterThen) {
			int cmp = comparator.compare(sequence.get(i), value);
			if (cmp < 0) swap(sequence, i++, lessThen++);
			else if (cmp > 0) swap(sequence, i, greaterThen--);
			else ++i;
		}

		quickSortImplementation(sequence, left, lessThen - 1, comparator);
		quickSortImplementation(sequence, greaterThen + 1, right, comparator);
	}


	public final static <T> void quickSort(T[] sequence, Comparator<T> comparator) {
		shuffle(sequence);
		quickSortImplementation(sequence, 0, sequence.length - 1, comparator);
	}

	private final static <T> void quickSortImplementation(T[] sequence, int left, int right, Comparator<T> comparator) {
		if (left >= right) return;

		int lessThen = left;
		int greaterThen = right;
		int i = left;
		T value = sequence[left];

		while (i <= greaterThen) {
			int cmp = comparator.compare(sequence[i], value);
			if (cmp < 0) swap(sequence, i++, lessThen++);
			else if (cmp > 0) swap(sequence, i, greaterThen--);
			else ++i;
		}

		quickSortImplementation(sequence, left, lessThen - 1, comparator);
		quickSortImplementation(sequence, greaterThen + 1, right, comparator);
	}


	public final static void quickSort(int[] sequence) {
		shuffle(sequence);
		quickSortImplementation(sequence, 0, sequence.length - 1);
	}

	private final static void quickSortImplementation(int[] sequence, int left, int right) {
		if (left >= right) return;

		int lessThen = left;
		int greaterThen = right;
		int i = left;
		int value = sequence[left];

		while (i <= greaterThen) {
			if (sequence[i] < value) swap(sequence, i++, lessThen++);
			else if (sequence[i] > value) swap(sequence, i, greaterThen--);
			else ++i;
		}

		quickSortImplementation(sequence, left, lessThen - 1);
		quickSortImplementation(sequence, greaterThen + 1, right);
	}


	public final static void quickSort(long[] sequence) {
		shuffle(sequence);
		quickSortImplementation(sequence, 0, sequence.length - 1);
	}

	private final static void quickSortImplementation(long[] sequence, int left, int right) {
		if (left >= right) return;

		int lessThen = left;
		int greaterThen = right;
		int i = left;
		long value = sequence[left];

		while (i <= greaterThen) {
			if (sequence[i] < value) swap(sequence, i++, lessThen++);
			else if (sequence[i] > value) swap(sequence, i, greaterThen--);
			else ++i;
		}

		quickSortImplementation(sequence, left, lessThen - 1);
		quickSortImplementation(sequence, greaterThen + 1, right);
	}


	public final static void quickSort(char[] sequence) {
		shuffle(sequence);
		quickSortImplementation(sequence, 0, sequence.length - 1);
	}

	private final static void quickSortImplementation(char[] sequence, int left, int right) {
		if (left >= right) return;

		int lessThen = left;
		int greaterThen = right;
		int i = left;
		char value = sequence[left];

		while (i <= greaterThen) {
			if (sequence[i] < value) swap(sequence, i++, lessThen++);
			else if (sequence[i] > value) swap(sequence, i, greaterThen--);
			else ++i;
		}

		quickSortImplementation(sequence, left, lessThen - 1);
		quickSortImplementation(sequence, greaterThen + 1, right);
	}


	public final static void quickSort(double[] sequence) {
		shuffle(sequence);
		quickSortImplementation(sequence, 0, sequence.length - 1);
	}

	private final static void quickSortImplementation(double[] sequence, int left, int right) {
		if (left >= right) return;

		int lessThen = left;
		int greaterThen = right;
		int i = left;
		double value = sequence[left];

		while (i <= greaterThen) {
			if (sequence[i] < value) swap(sequence, i++, lessThen++);
			else if (sequence[i] > value) swap(sequence, i, greaterThen--);
			else ++i;
		}

		quickSortImplementation(sequence, left, lessThen - 1);
		quickSortImplementation(sequence, greaterThen + 1, right);
	}


	public final static void quickSort(boolean[] sequence) {
		shuffle(sequence);
		quickSortImplementation(sequence, 0, sequence.length - 1);
	}

	private final static void quickSortImplementation(boolean[] sequence, int left, int right) {
		if (left >= right) return;

		int lessThen = left;
		int greaterThen = right;
		int i = left;
		boolean value = sequence[left];

		while (i <= greaterThen) {
			if (!sequence[i] && value) swap(sequence, i++, lessThen++);
			else if (sequence[i] && !value) swap(sequence, i, greaterThen--);
			else ++i;
		}

		quickSortImplementation(sequence, left, lessThen - 1);
		quickSortImplementation(sequence, greaterThen + 1, right);
	}


	public final static void quickSort(short[] sequence) {
		shuffle(sequence);
		quickSortImplementation(sequence, 0, sequence.length - 1);
	}

	private final static void quickSortImplementation(short[] sequence, int left, int right) {
		if (left >= right) return;

		int lessThen = left;
		int greaterThen = right;
		int i = left;
		short value = sequence[left];

		while (i <= greaterThen) {
			if (sequence[i] < value) swap(sequence, i++, lessThen++);
			else if (sequence[i] > value) swap(sequence, i, greaterThen--);
			else ++i;
		}

		quickSortImplementation(sequence, left, lessThen - 1);
		quickSortImplementation(sequence, greaterThen + 1, right);
	}


	public final static void quickSort(byte[] sequence) {
		shuffle(sequence);
		quickSortImplementation(sequence, 0, sequence.length - 1);
	}

	private final static void quickSortImplementation(byte[] sequence, int left, int right) {
		if (left >= right) return;

		int lessThen = left;
		int greaterThen = right;
		int i = left;
		byte value = sequence[left];

		while (i <= greaterThen) {
			if (sequence[i] < value) swap(sequence, i++, lessThen++);
			else if (sequence[i] > value) swap(sequence, i, greaterThen--);
			else ++i;
		}

		quickSortImplementation(sequence, left, lessThen - 1);
		quickSortImplementation(sequence, greaterThen + 1, right);
	}

	// unique
	public static <T> ArrayList<T> unique(ArrayList<T> sequence) {
		int size = 1;
		for (int i = 1; i < sequence.size(); ++i)
			if (!sequence.get(i).equals(sequence.get(i - 1)))
				++size;

		ArrayList<T> newSequence = new ArrayList<T>(size);
		newSequence.add(sequence.get(0));

		for (int i = 1; i < sequence.size(); ++i)
			if (!sequence.get(i).equals(sequence.get(i - 1)))
				newSequence.add(sequence.get(i));

		return newSequence;
	}

	public static <T> T[] unique(T[] sequence) {
		int size = 1;
		for (int i = 1; i < sequence.length; ++i)
			if (!sequence[i].equals(sequence[i - 1]))
				++size;

		T[] newSequence = (T[]) new Object[size];
		newSequence[0] = sequence[0];
		size = 0;

		for (int i = 1; i < sequence.length; ++i)
			if (!sequence[i].equals(sequence[i - 1]))
				newSequence[++size] = sequence[i];

		return newSequence;
	}

	public static int[] unique(int[] sequence) {
		int size = 1;
		for (int i = 1; i < sequence.length; ++i)
			if (sequence[i] != sequence[i - 1])
				++size;

		int[] newSequence = new int[size];
		newSequence[0] = sequence[0];
		size = 0;

		for (int i = 1; i < sequence.length; ++i)
			if (sequence[i] != sequence[i - 1])
				newSequence[++size] = sequence[i];

		return newSequence;
	}

	public static long[] unique(long[] sequence) {
		int size = 1;
		for (int i = 1; i < sequence.length; ++i)
			if (sequence[i] != sequence[i - 1])
				++size;

		long[] newSequence = new long[size];
		newSequence[0] = sequence[0];
		size = 0;

		for (int i = 1; i < sequence.length; ++i)
			if (sequence[i] != sequence[i - 1])
				newSequence[++size] = sequence[i];

		return newSequence;
	}

	public static char[] unique(char[] sequence) {
		int size = 1;
		for (int i = 1; i < sequence.length; ++i)
			if (sequence[i] != sequence[i - 1])
				++size;

		char[] newSequence = new char[size];
		newSequence[0] = sequence[0];
		size = 0;

		for (int i = 1; i < sequence.length; ++i)
			if (sequence[i] != sequence[i - 1])
				newSequence[++size] = sequence[i];

		return newSequence;
	}

	public static double[] unique(double[] sequence) {
		int size = 1;
		for (int i = 1; i < sequence.length; ++i)
			if (sequence[i] != sequence[i - 1])
				++size;

		double[] newSequence = new double[size];
		newSequence[0] = sequence[0];
		size = 0;

		for (int i = 1; i < sequence.length; ++i)
			if (sequence[i] != sequence[i - 1])
				newSequence[++size] = sequence[i];

		return newSequence;
	}

	public static boolean[] unique(boolean[] sequence) {
		int size = 1;
		for (int i = 1; i < sequence.length; ++i)
			if (sequence[i] != sequence[i - 1])
				++size;

		boolean[] newSequence = new boolean[size];
		newSequence[0] = sequence[0];
		size = 0;

		for (int i = 1; i < sequence.length; ++i)
			if (sequence[i] != sequence[i - 1])
				newSequence[++size] = sequence[i];

		return newSequence;
	}

	public static short[] unique(short[] sequence) {
		int size = 1;
		for (int i = 1; i < sequence.length; ++i)
			if (sequence[i] != sequence[i - 1])
				++size;

		short[] newSequence = new short[size];
		newSequence[0] = sequence[0];
		size = 0;

		for (int i = 1; i < sequence.length; ++i)
			if (sequence[i] != sequence[i - 1])
				newSequence[++size] = sequence[i];

		return newSequence;
	}

	public static byte[] unique(byte[] sequence) {
		int size = 1;
		for (int i = 1; i < sequence.length; ++i)
			if (sequence[i] != sequence[i - 1])
				++size;

		byte[] newSequence = new byte[size];
		newSequence[0] = sequence[0];
		size = 0;

		for (int i = 1; i < sequence.length; ++i)
			if (sequence[i] != sequence[i - 1])
				newSequence[++size] = sequence[i];

		return newSequence;
	}
}

final class ComparablePair<F extends Comparable<F>, S extends Comparable<S>> implements Comparable<ComparablePair<F, S>> {
	public F first;
	public S second;

	public ComparablePair(F first, S second) {
		this.first = first;
		this.second = second;
	}

	public int compareTo(ComparablePair<F, S> o) {
		int value = first.compareTo(o.first);
		if (value != 0) return value;
		return second.compareTo(o.second);
	}

	public int hashCode() {
		int hFirst = first != null ? first.hashCode() : 0;
		int hSecond = second != null ? second.hashCode() : 0;
		return 31 * hFirst + hSecond;
	}

	public boolean equals(ComparablePair<F, S> pair) {
		if (this == pair) return true;

		return (first != null ? first.equals(pair.first) : pair.first == null) &&
				(second != null ? second.equals(pair.second) : pair.second == null);
	}

	public ComparablePair<F, S> clone() {
		return new ComparablePair<F, S>(first, second);
	}

	public String toString() {
		return "(" + first + ", " + second + ")";
	}
}