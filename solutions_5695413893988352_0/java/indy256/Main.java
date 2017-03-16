import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "B-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("b.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class TaskB {
		int curDiff;
		char[] ra;
		char[] rb;

		public void solve(int testNumber, InputReader in, PrintWriter out) {
			char[] a = in.next().toCharArray();
			char[] b = in.next().toCharArray();

			curDiff = Integer.MAX_VALUE;
			f(a, b, 0, 0);

			out.printf("Case #%d: %s %s\n", testNumber, String.valueOf(ra), String.valueOf(rb));
		}

		void f(char[] a, char[] b, int i, int j) {
			if (i == a.length && j == a.length) {
				int d = Math.abs(Integer.parseInt(String.valueOf(a)) - Integer.parseInt(String.valueOf(b)));
				if (curDiff > d || curDiff == d && (Integer.parseInt(String.valueOf(a)) < Integer.parseInt(String.valueOf(ra))
						|| Integer.parseInt(String.valueOf(a)) == Integer.parseInt(String.valueOf(ra)) && Integer.parseInt(String.valueOf(b)) < Integer.parseInt(String.valueOf(rb)))) {
					curDiff = d;
					ra = a.clone();
					rb = b.clone();
				}
				return;
			}
			if (i < a.length) {
				if (a[i] != '?') {
					f(a, b, i + 1, j);
				} else {
					for (char k = '0'; k <= '9'; k++) {
						a[i] = k;
						f(a, b, i + 1, j);
					}
					a[i] = '?';
				}
			} else if (j < b.length) {
				if (b[j] != '?') {
					f(a, b, i, j + 1);
				} else {
					for (char k = '0'; k <= '9'; k++) {
						b[j] = k;
						f(a, b, i, j + 1);
					}
					b[j] = '?';
				}
			}
		}

	}

	static class InputReader {
		final InputStream is;
		final byte[] buf = new byte[1024];
		int pos;
		int size;

		public InputReader(InputStream is) {
			this.is = is;
		}

		public String next() {
			int c = read();
			while (isWhitespace(c))
				c = read();
			StringBuilder sb = new StringBuilder();
			do {
				sb.append((char) c);
				c = read();
			} while (!isWhitespace(c));
			return sb.toString();
		}

		int read() {
			if (size == -1)
				throw new InputMismatchException();
			if (pos >= size) {
				pos = 0;
				try {
					size = is.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (size <= 0)
					return -1;
			}
			return buf[pos++] & 255;
		}

		static boolean isWhitespace(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

	}
}

