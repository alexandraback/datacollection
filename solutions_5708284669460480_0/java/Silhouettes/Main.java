package TaskB;

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
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
	int keyLen;
	int wordLen;
	int stringLen;
	char[] keys;
	char[] word;
	int numStrings;
	int count;
	char[] current;
	
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		out.print("Case #" + testNumber + ": ");
		keyLen = in.readInt();
		wordLen = in.readInt();
		stringLen = in.readInt();
		keys = in.readString().toCharArray();
		assert keys.length == keyLen;
		word = in.readString().toCharArray();
		assert word.length == wordLen;
		
		for (int i = 0; i < word.length; i++) {
			boolean found = false;
			for (int j = 0; j < keys.length; j++) {
				if (keys[j] == word[i]) {
					found = true;
					break;
				}
			}

			if (!found) {
				out.printLine("0.0");
				return;
			}
		}

		int overlap;
		for (overlap = wordLen - 1; overlap > 0; overlap--) {
			boolean isOverlap = true;
			for (int i = 0; i < overlap; i++) {
				if (word[i] != word[wordLen - overlap + i]) {
					isOverlap = false;
					break;
				}
			}
			
			if (isOverlap) {
				break;
			}
		}
		
		int numBananas = (stringLen - overlap) / (wordLen - overlap);
		
		numStrings = 0;
		count = 0;
		current = null;
		countAllInstances(0);
		
		double remaining = (double)numBananas - (double)count / (double)numStrings;
		
		out.printLine(String.format("%.1f", remaining));
	}
	
	public void countAllInstances(int index) {
		if (index == 0) {
			current = new char[stringLen];
		}
		
		if (index == stringLen) {
			onStringComplete();
			return;
		}
		
		for (int i = 0; i < keyLen; i++) {
			current[index] = keys[i];
			countAllInstances(index + 1);
		}
	}
	
	public void onStringComplete() {
		numStrings++;
		
		for (int i = 0; i < stringLen - wordLen + 1; i++) {
			boolean isWord = true;
			int currentIndex = i;
			for (int j = 0; j < wordLen; j++, currentIndex++) {
				if (current[currentIndex] != word[j]) {
					isWord = false;
					break;
				}
			}
			
			if (isWord)
				count++;
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
	
	public float readFloat() {
		return Float.parseFloat(readString());
	}
	
	public double readDouble() {
		return Double.parseDouble(readString());
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
	
	public void readArray(char[] array) {
		for (int i = 0; i < array.length; i++) {
				array[i] = readChar();
		}
	}
	
	public void readArray(int[] array) {
		for (int i = 0; i < array.length; i++) {
				array[i] = readInt();
		}
	}

	public void readArray(char[][] array) {
		for (int i = 0; i < array.length; i++) {
			for (int j = 0; j < array[i].length; j++)
				array[i][j] = readChar();
		}
	}

	public void readArray(int[][] array) {
		for (int i = 0; i < array.length; i++) {
			for (int j = 0; j < array[i].length; j++)
				array[i][j] = readInt();
		}
	}

	public void readVerticalArrays(int[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = readInt();
		}
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

	
	
	