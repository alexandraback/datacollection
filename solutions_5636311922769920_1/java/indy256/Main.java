import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.stream.Collectors;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;
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
			final String regex = "D-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("d.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskD solver = new TaskD();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class TaskD {
		public void solve(int testNumber, InputReader in, PrintWriter out) {
			int k = in.nextInt();
			int c = in.nextInt();
			int s = in.nextInt();

			List<Long> res = new ArrayList<>();

			if (c == 1) {
				for (int i = 1; i <= k; i++) {
					res.add((long) i);
				}
			} else {
				long len = 1;
				for (int i = 0; i < c - 1; i++) {
					len *= k;
				}
				for (int i = 0; i < (k + 1) / 2; i++) {
					res.add(Math.min(i * 2 * len + (i + 1) * 2, len * k));
				}
			}

			if (res.size() <= s) {
				out.printf("Case #%d: %s\n", testNumber, res.stream().map(x -> Long.toString(x)).collect(Collectors.joining(" ")));
			} else {
				out.printf("Case #%d: IMPOSSIBLE\n", testNumber);
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

		public int nextInt() {
			int c = read();
			while (isWhitespace(c))
				c = read();
			int sign = 1;
			if (c == '-') {
				sign = -1;
				c = read();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = read();
			} while (!isWhitespace(c));
			return res * sign;
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

