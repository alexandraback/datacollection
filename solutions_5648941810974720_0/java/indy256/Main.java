import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
			final String regex = "A-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("a.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class TaskA {
		final static String[] numbers = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

		public void solve(int testNumber, InputReader in, PrintWriter out) {
			char[] s = in.next().toCharArray();
			int[] f = new int[256];
			for (char c : s) {
				++f[c];
			}

			StringBuilder res = new StringBuilder();

			for (int len = 0, i = 0; len < s.length; ) {
				for (; i < numbers.length; i++) {
					String w = numbers[i];
					for (char c : w.toCharArray()) {
						--f[c];
					}
					if (can(f)) {
						res.append(String.valueOf(i));
						len += w.length();
						break;
					}
					for (char c : w.toCharArray()) {
						++f[c];
					}
				}
			}

			out.printf("Case #%d: %s\n", testNumber, res.toString());
		}

		static boolean can(int[] f) {
			int[] d = new int[10];
			d[0] = f['Z'];
			d[2] = f['W'];
			d[4] = f['U'];
			d[6] = f['X'];
			d[8] = f['G'];
			d[5] = f['F'] - d[4];
			d[3] = f['T'] - d[2] - d[8];
			d[7] = f['S'] - d[6];
			d[9] = f['I'] - d[5] - d[6] - d[8];
			d[1] = f['O'] - d[0] - d[2] - d[4];

			for (int v : d) {
				if (v < 0) return false;
			}
			int[] ff = new int[256];
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < d[i]; j++) {
					for (char c : numbers[i].toCharArray()) {
						++ff[c];
					}
				}
			}

			return Arrays.equals(f, ff);
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

