package codejam.s2015.r1b;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;

class Alarge0 {
	public static void main(String[] args) throws IOException {
		int t = Parser.nextInt();
		for (int tt = 1; tt <= t; tt++) {
			System.out.println("Case #" + tt + ": " + solve());
		}
	}

	private static String solve() throws IOException {
		return null;
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
		public boolean equals(Object o) {
			if (this == o) {
				return true;
			}
			if (o == null || getClass() != o.getClass()) {
				return false;
			}

			Tuple tuple = (Tuple) o;

			if (!Arrays.equals(x, tuple.x)) {
				return false;
			}

			return true;
		}

		@Override
		public int hashCode() {
			return x != null ? Arrays.hashCode(x) : 0;
		}

		@Override
		public String toString() {
			return "Tuple{" +
					"x=" + Arrays.toString(x) +
					'}';
		}
	}
}
