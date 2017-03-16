import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Map;
import java.util.HashMap;
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
			final String regex = "C-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("c.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}

	static class TaskC {
		public void solve(int testNumber, InputReader in, PrintWriter out) {
			int n = in.nextInt();
			Map<String, Integer> ma = new HashMap<>();
			Map<String, Integer> mb = new HashMap<>();
			int[] a = new int[n];
			int[] b = new int[n];
			for (int i = 0; i < n; i++) {
				String sa = in.next();
				if (!ma.containsKey(sa)) {
					ma.put(sa, ma.size());
				}
				a[i] = ma.get(sa);
				String sb = in.next();
				if (!mb.containsKey(sb)) {
					mb.put(sb, mb.size());
				}
				b[i] = mb.get(sb);
			}

			int[] dp = new int[1 << n];
			for (int mask = 0; mask < 1 << n; mask++) {
				for (int i = 0; i < n; i++) {
					if ((mask & 1 << i) == 0) {
						boolean va = false;
						boolean vb = false;
						for (int k = 0; k < n; k++) {
							if ((mask & 1 << k) != 0) {
								va |= a[k] == a[i];
								vb |= b[k] == b[i];
							}
						}
						dp[mask | (1 << i)] = Math.max(dp[mask | (1 << i)], dp[mask] + (va && vb ? 1 : 0));
					}
				}
			}
			int res = dp[(1 << n) - 1];
			out.printf("Case #%d: %d\n", testNumber, res);
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

