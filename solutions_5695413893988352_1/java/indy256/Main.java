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
		long curDiff;
		char[] ra;
		char[] rb;

		public void solve(int testNumber, InputReader in, PrintWriter out) {
			char[] a = in.next().toCharArray();
			char[] b = in.next().toCharArray();

			curDiff = Long.MAX_VALUE;
			f(a, b, 0);

			out.printf("Case #%d: %s %s\n", testNumber, String.valueOf(ra), String.valueOf(rb));
		}

		void f(char[] a, char[] b, int i) {
			if (i == a.length) {
				long d = Math.abs(Long.parseLong(String.valueOf(a)) - Long.parseLong(String.valueOf(b)));
				if (curDiff > d || curDiff == d && (Long.parseLong(String.valueOf(a)) < Long.parseLong(String.valueOf(ra))
						|| Long.parseLong(String.valueOf(a)) == Long.parseLong(String.valueOf(ra)) && Long.parseLong(String.valueOf(b)) < Long.parseLong(String.valueOf(rb)))) {
					curDiff = d;
					ra = a.clone();
					rb = b.clone();
				}
				return;
			}
			int sign = 0;
			for (int j = 0; j < i; j++) {
				if (a[j] != b[j]) {
					sign = Character.compare(a[j], b[j]);
					break;
				}
			}
			if (a[i] == '?' && b[i] == '?') {
				if (sign == 0) {
					a[i] = '0';
					b[i] = '0';
					f(a, b, i + 1);
					a[i] = '0';
					b[i] = '1';
					f(a, b, i + 1);
					a[i] = '1';
					b[i] = '0';
					f(a, b, i + 1);
				}
				if (sign < 0) {
					a[i] = '9';
					b[i] = '0';
					f(a, b, i + 1);
				}
				if (sign > 0) {
					a[i] = '0';
					b[i] = '9';
					f(a, b, i + 1);
				}
				a[i] = '?';
				b[i] = '?';
				return;
			}

			if (a[i] == '?') {
				if (sign == 0) {
					a[i] = b[i];
					f(a, b, i + 1);
					if (b[i] < '9') {
						a[i] = (char) (b[i] + 1);
						f(a, b, i + 1);
					}
					if (b[i] > '0') {
						a[i] = (char) (b[i] - 1);
						f(a, b, i + 1);
					}
				}
				if (sign < 0) {
					a[i] = '9';
					f(a, b, i + 1);
				}
				if (sign > 0) {
					a[i] = '0';
					f(a, b, i + 1);
				}
				a[i] = '?';
				return;
			}

			if (b[i] == '?') {
				if (sign == 0) {
					b[i] = a[i];
					f(a, b, i + 1);
					if (a[i] < '9') {
						b[i] = (char) (a[i] + 1);
						f(a, b, i + 1);
					}
					if (a[i] > '0') {
						b[i] = (char) (a[i] - 1);
						f(a, b, i + 1);
					}
				}
				if (sign < 0) {
					b[i] = '0';
					f(a, b, i + 1);
				}
				if (sign > 0) {
					b[i] = '9';
					f(a, b, i + 1);
				}
				b[i] = '?';
				return;
			}

			f(a, b, i + 1);
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

