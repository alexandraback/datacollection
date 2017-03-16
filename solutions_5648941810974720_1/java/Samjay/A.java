package con2016.con2016R1B;


import java.io.*;
import java.util.*;

public class A {
	
	private static final String islarge = "-large";
	private static final String fileLoc = "src/con2016/con2016R1B/files/";
	private static final String fileName = fileLoc+A.class.getSimpleName().toLowerCase()+islarge;
	private static final String inputFileName = fileName + ".in";
	private static final String outputFileName = fileName + ".out";
	private static InputReader in;
	private static OutputWriter out;
	
	static final int ALF = 26;
	static final String[] nums = new String[]{"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
	// "FIVE", "NINE"
	private void solve() {
		String s = in.readString();
		int[]count = new int[ALF];
		for(int i=0;i<s.length();i++){
			count[s.charAt(i)-'A']++;
		}
		ArrayList<Integer> res = new ArrayList<Integer>();
		// SIX
		while(count[(int)('X'-'A')]>0){
			res.add(6);
			dec(count,'X');
			dec(count,'I');
			dec(count,'S');
		}
		// ZERO
		while(count[(int)('Z'-'A')]>0){
			res.add(0);
			dec(count,'Z');
			dec(count,'E');
			dec(count,'R');
			dec(count,'O');
		}
		// FOUR
		while(count[(int)('U'-'A')]>0){
			res.add(4);
			dec(count,'F');
			dec(count,'O');
			dec(count,'U');
			dec(count,'R');
		}
		// EIGHT
		while(count[(int)('G'-'A')]>0){
			res.add(8);
			dec(count,'E');
			dec(count,'I');
			dec(count,'G');
			dec(count,'H');
			dec(count,'T');
		}
		// TWO
		while(count[(int)('W'-'A')]>0){
			res.add(2);
			dec(count,'T');
			dec(count,'W');
			dec(count,'O');
		}
		// THREE
		while(count[(int)('H'-'A')]>0){
			res.add(3);
			dec(count,'T');
			dec(count,'H');
			dec(count,'R');
			dec(count,'E');
			dec(count,'E');
		}
		// ONE
		while(count[(int)('O'-'A')]>0){
			res.add(1);
			dec(count,'O');
			dec(count,'N');
			dec(count,'E');
		}
		// SEVEN
		while(count[(int)('S'-'A')]>0){
			res.add(7);
			dec(count,'S');
			dec(count,'E');
			dec(count,'V');
			dec(count,'E');
			dec(count,'N');
		}
		// FIVE
		while(count[(int)('V'-'A')]>0){
			res.add(5);
			dec(count,'F');
			dec(count,'I');
			dec(count,'V');
			dec(count,'E');
		}
		// NINE
		while(count[(int)('N'-'A')]>0){
			res.add(9);
			dec(count,'N');
			dec(count,'I');
			dec(count,'N');
			dec(count,'E');
		}
		Collections.sort(res);
		for(int n : res){
			out.print(n);
		}
		out.printLine();
	}
	
	static final void dec(int[]count, char c){
		count[(int)(c-'A')]--;
	}
	
	public static void main(String[] args) throws IOException {
		long start = System.currentTimeMillis();
		in = new InputReader(new FileInputStream(inputFileName));
		out = new OutputWriter(new FileOutputStream(outputFileName));
		int tests = in.readInt();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			new A().solve();
			System.out.println("Case #" + t + ": solved");
		}
		out.close();
		long stop = System.currentTimeMillis();
		System.out.println(stop-start+" ms");
	}
	

	static class InputReader {
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

		public String readLine() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isEndOfLine(c));
			return res.toString();
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

		public boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public boolean isEndOfLine(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}
	}

	static class OutputWriter {
		private final PrintWriter writer;

		public OutputWriter(OutputStream outputStream) {
			writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
					outputStream)));
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

		public void close() {
			writer.close();
		}
	}
}
