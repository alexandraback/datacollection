package gcj.r1c;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class MainB {

	static int[] pow = {1, 10, 100, 1000, 10000, 100000};

	public static void main(String[] args) throws FileNotFoundException {
		// 問題の読み込み
		Scanner sc = new Scanner(new File("src/in.txt"));

		int T = sc.nextInt();

		for (int t=1; t<=T; t++) {
			int N = sc.nextInt();

			List<String> trains = new ArrayList<String>();
			for (int i=0; i<N; i++) {
				String str1 = sc.next();

				char past = '%';
				String str2 = "";
				for (int j=0; j<str1.length(); j++) {
					if (j==0) {
						str2 = str2 + str1.substring(0,1);
					} else if (past == str1.charAt(j)) {
						// 何もしない
					} else {
						str2 = str2 + str1.substring(j,j+1);
					}
					past = str1.charAt(j);
				}

				trains.add(str2);
			}

			output(t, solve(trains));
		}

	}

	static int solve(List<String> trains) {
		int ret = 0;


		for(int[] p : new Permutation(trains.size())) {
			String str1 = "";

			for (int i=0; i<p.length; i++) {
				str1 = str1 + trains.get(p[i]);
			}

			char past = '%';
			String str2 = "";
			for (int j=0; j<str1.length(); j++) {
				if (j==0) {
					str2 = str2 + str1.substring(0,1);
				} else if (past == str1.charAt(j)) {
					// 何もしない
				} else {
					str2 = str2 + str1.substring(j,j+1);
				}
				past = str1.charAt(j);
			}

			Set<String> s = new HashSet<String>();
			for (int j=0; j<str2.length(); j++) {
				s.add(str2.substring(j,j+1));
			}
			if (s.size() == str2.length()) {
				ret++;
			}
		}

		return ret;
	}

	static void output(int i, Object ans) {
		System.out.println("Case #" + i + ": " + ans);
	}

	static class Permutation implements Iterable<int[]> {
		private final int size;

		public Permutation(int size) {
			if (size <= 0) throw new IllegalArgumentException();
			this.size = size;
		}

		public Iterator<int[]> iterator() {
			return new Iter(size);
		}

		private class Iter implements Iterator<int[]> {
			private final int[] source;
			private boolean isFirst = true;

			private Iter(int size) {
				source = new int[size];
				for(int i = 0; i < size; ++i) {
					source[i] = i;
				}
			}

			public boolean hasNext() {
				if (isFirst) {
					isFirst = false;
					return true;
				}

				int n = source.length;
				for (int i = n - 1; i > 0; i--) {
					if (source[i - 1] < source[i]) {
						int j = n;
						while (source[i - 1] >= source[--j]);
						swap(source, i - 1, j);
						reverse(source, i, n);
						return true;
					}
				}
				reverse(source, 0, n);
				return false;
			}

			public int[] next() {
				return source;
			}

			public void remove() {
				throw new UnsupportedOperationException();
			}

			private void swap(int[] is, int i, int j) {
				int t = is[i];
				is[i] = is[j];
				is[j] = t;
			}

			private void reverse(int[] is, int s, int t) {
				while (s < --t) swap(is, s++, t);
			}
		}
	}
}