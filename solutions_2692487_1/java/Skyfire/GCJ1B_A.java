import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class GCJ1B_A implements Runnable {

	private static final String FILE_NAME = "A-large.in";
	private static final String CASE_PREFIX = "Case #";
	private static final String CASE_MIDDLE = ": ";
	private static final int MAXN = 100;
	
	private int getAnswer() {
		int moteSize = in.readInt();
		int n = in.readInt();
		for (int i = 0; i < n; ++i) {
			a[i] = in.readInt();
		}
		Arrays.sort(a, 0, n);
		if (moteSize == 1) {
			return n;
		}
		else {
			int minResult = Integer.MAX_VALUE;
			for (int cnt = 0; cnt < 21; ++cnt) {
				int use = 0;
				int rem = 0;
				int size = moteSize;
				for (int i = 0; i < n; ++i) {
					if (a[i] < size) {
						size += a[i];
					}
					else {
						while (use < cnt && size <= a[i]) {
							++use;
							size += size-1;
						}
						if (size > a[i]) {
							size += a[i];
						}
						else {
							++rem;
						}
					}
				}
				if (minResult > use+rem) {
					minResult = use + rem;
				}
			}
			return minResult;
		}
	}
	
	private int[] a;
	
	private void begin() {
		try {
			in = new InputReader(new FileInputStream(new File(FILE_NAME)));
			out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(new FileOutputStream(new File("output.txt")))));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		a = new int[MAXN];
	}
	
	private void end() {
		out.flush();
	}
	
	private InputReader in;
	private PrintWriter out;
	
	@Override
	public void run() {
		begin();
		int nt = in.readInt();
		for (int t = 1; t <= nt; ++t) {
			out.println(CASE_PREFIX + t + CASE_MIDDLE + getAnswer());
		}
		end();
	}

	private class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[128];
		private int curChar;
		private int numChars;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int read() {
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
			while (isSpaceChar(c)) {
				c = read();
			}
			int sign = 1;
			if (c == '-') {
				sign = -1;
				c = read();
			}
			int res = 0;
			do {
				res *= 10;
				res += c - '0';
				c = read();
			} 
			while (!isSpaceChar(c));
			return res*sign;
		}
		
		public boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}
	}
	
	public static void main(String[] args) {
		new GCJ1B_A().run();
	}

}
