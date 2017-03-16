import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayList;

class Asmall0 {
	public static void main(String[] args) throws IOException {
		int t = Parser.nextInt();
		for (int tt = 1; tt <= t; tt++) {
			System.out.println("Case #" + tt + ": " + solve());
		}
	}

	private static String solve() throws IOException {
		String s = Parser.nextString();
		int n = Parser.nextInt();
		long res = 0;
		int c = 0;
		int last = 0;
		for (int i = 0; i < s.length() + 1; i++) {
			char ii = i < s.length() ? s.charAt(i) : 'a';
			if (isConsonant(ii)) {
				c++;
			} else {
				if (c >= n) {
					for (int zac = i - c; zac < i - n + 1; zac++) {
						res += (long) (zac - last + 1) * (long) (s.length() - (zac + n - 1));
						last = zac + 1;
					}
					last = i - n + 1;
				}
				c = 0;
			}
		}
		return String.valueOf(res);
	}

	private static boolean isConsonant(char c) {
		return
				c != 'a' &&
						c != 'e' &&
						c != 'i' &&
						c != 'o' &&
						c != 'u';
	}

	// Prewritten code

	private static class Parser {
		private static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		private static String line;
		private static ArrayList<String> stringArray = new ArrayList<String>();
		private static int arrayPosition = 0;

		private static Integer nextInt() throws IOException {
			if (arrayPosition == stringArray.size()) {
				if (readLine() == null)
					return null;
			}
			return Integer.parseInt(stringArray.get(arrayPosition++));
		}

		private static Long nextLong() throws IOException {
			if (arrayPosition == stringArray.size()) {
				if (readLine() == null)
					return null;
			}
			return Long.parseLong(stringArray.get(arrayPosition++));
		}

		private static String nextString() throws IOException {
			if (arrayPosition == stringArray.size()) {
				if (readLine() == null)
					return null;
			}
			return stringArray.get(arrayPosition++);
		}

		private static String nextLine() throws IOException {
			arrayPosition = stringArray.size();
			return in.readLine();
		}

		private static String readLine() throws IOException {
			line = in.readLine();
			if (line == null) {
				return null;
			} else {
				stringArray = new ArrayList<String>();
				arrayPosition = 0;

				int p, lastP = 0;
				while (true) {
					p = line.indexOf(" ", lastP);
					if (p == lastP) {
						lastP++;
					} else if (p != -1) {
						stringArray.add(line.substring(lastP, p));
						lastP = p + 1;
					} else {
						if (lastP < line.length()) {
							stringArray.add(line.substring(lastP));
						}
						break;
					}
				}
				return line;
			}
		}
	}

	private static class Tuple<T extends Comparable<T>> implements Comparable<Tuple<T>> {
		T[] x;

		@SuppressWarnings({"unchecked"})
		private Tuple(T... xs) {
			x = (T[]) Array.newInstance(xs[0].getClass(), xs.length);
			System.arraycopy(xs, 0, x, 0, xs.length);
		}

		@Override
		public int compareTo(Tuple<T> o) {
			for (int i = 0; i < x.length && i < o.x.length; ++i) {
				int cmp = x[i].compareTo(o.x[i]);
				if (cmp != 0) {
					return cmp;
				}
			}
			return 0;
		}

		@Override
		public boolean equals(Object obj) {
			if (obj instanceof Tuple) {
				for (int i = 0; i < x.length && i < ((Tuple) obj).x.length; ++i) {
					if (!x[i].equals(((Tuple) obj).x[i])) {
						return false;
					}
				}
				return true;
			}
			return false;
		}

		@Override
		public int hashCode() {
			int res = 27;
			for (T i : x) {
				res = 31 * res + i.hashCode();
			}
			return res;
		}

		@Override
		public String toString() {
			String res = "";
			for (int i = 0; i < x.length; i++) {
				if (i == 0) {
					res += x[i].toString();
				} else {
					res += " " + x[i].toString();
				}
			}
			res += "";
			return res;
		}
	}

	static boolean nextPermutation(int[] p) {
		for (int i = p.length - 2; i >= 0; --i) {
			if (p[i] < p[i + 1])
				for (int j = p.length - 1; ; --j) {
					if (p[j] > p[i]) {
						int t = p[i];
						p[i] = p[j];
						p[j] = t;
						for (++i, j = p.length - 1; i < j; ++i, --j) {
							t = p[i];
							p[i] = p[j];
							p[j] = t;
						}
						return true;
					}
				}
		}
		return false;
	}
}
