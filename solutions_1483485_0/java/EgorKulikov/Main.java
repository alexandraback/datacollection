import java.util.List;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.AbstractList;
import java.io.Writer;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Egor Kulikov (egor@egork.net)
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("taska.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("taska.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
	char[] original = "ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjvyeq ".toCharArray();
	char[] result = "ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveupaoz ".toCharArray();
	char[] map = new char[256];

	{
		for (int i = 0; i < original.length; i++)
			map[original[i]] = result[i];
		for (int i = 0; i < 26; i++) {
			if (map[i + 'a'] == 0) {
				for (int j = 0; j < 26; j++) {
					if (Array.wrap(result).indexOf((char)(j + 'a')) == -1) {
						map[i + 'a'] = (char) (j + 'a');
						break;
					}
				}
			}
		}
	}

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		String s = in.readLine();
		out.print("Case #" + testNumber + ": ");
		for (char c : StringWrapper.wrap(s))
			out.print(map[c]);
		out.printLine();
	}
}

abstract class Array<T> extends AbstractList<T> {

	public static List<Character> wrap(char...array) {
		return new CharArray(array);
	}

	protected static class CharArray extends Array<Character> {
		protected final char[] array;

		protected CharArray(char[] array) {
			this.array = array;
		}

		public int size() {
			return array.length;
		}

		public Character get(int index) {
			return array[index];
		}

		public Character set(int index, Character value) {
			char result = array[index];
			array[index] = value;
			return result;
		}
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

	private String readLine0() {
		StringBuffer buf = new StringBuffer();
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

	public String next() {
		return readString();
	}
}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(outputStream);
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

class StringWrapper extends AbstractList<Character> {
	private final CharSequence string;

	public static List<Character> wrap(CharSequence string) {
		return new StringWrapper(string);
	}

	private StringWrapper(CharSequence string) {
		this.string = string;
	}

	public int size() {
		return string.length();
	}

	public Character get(int index) {
		return string.charAt(index);
	}
}

