import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;
import java.util.TreeSet;

public class B {

	private static final String path = "/home/tolstov.a.a/codejam/b/";

	private static final String problem = "B-small";

	Scanner in;

	PrintWriter out;

	private static final long mudilo = 1000000007;

	char[][] strs;

	boolean used[];

	int arrange[];

	boolean before[][];

	long gen(int pos, TreeSet<Val> valz) {
		if (pos == strs.length) {
			if (valid(valz)) {
				return 1;
			}
			return 0;
		}
		long ans = 0;
		fori: for (int i = 0; i < used.length; i++) {
			if (!used[i]) {
				{
					if (pos == 0 || before[arrange[pos - 1]][i]) {

						int size = valz.size();
						List<Val> added = new ArrayList<>();
						for (int idx = 0; idx < strs[i].length; idx++) {
							Val v = new Val(strs[i][idx], idx + size);
							Val floor = valz.lower(v);

							if (floor != null) {
								if (floor.c == v.c) {
									if (floor.pos != v.pos - 1) {
										continue fori;
									}
								}
							}
							added.add(v);
						}

						valz.addAll(added);
						arrange[pos] = i;
						used[i] = true;
						ans += gen(pos + 1, valz);
						valz.removeAll(added);
						used[i] = false;
					}
				}
			}
		}
		return ans;
	}

	static class Val implements Comparable<Val> {

		char c;

		int pos;

		Val(char c, int pos) {
			this.c = c;
			this.pos = pos;
		}

		@Override
		public int compareTo(Val second) {
			if (this.c != second.c) {
				return Character.compare(this.c, second.c);
			} else {
				return Integer.compare(this.pos, second.pos);
			}
		}
	}

	boolean valid(TreeSet<Val> valz) {
		Iterator<Val> it = valz.iterator();
		Val prev = it.next();
		while (it.hasNext()) {
			Val curr = it.next();
			if (curr.c == prev.c) {
				if (curr.pos != prev.pos + 1) {
					return false;
				}
			}
			prev = curr;
		}
		return true;
	}

	boolean valid(char s[]) {
		TreeSet<Val> valz = new TreeSet<>();
		for (int i = 0; i < s.length; i++) {
			valz.add(new Val(s[i], i));
		}

		return valid(valz);
	}

	char[] compress(char s[]) {
		StringBuilder sb = new StringBuilder();
		sb.append(s[0]);
		for (int i = 1; i < s.length; i++) {
			if (s[i] != s[i - 1]) {
				sb.append(s[i]);
			}
		}
		return sb.toString().toCharArray();
	}

	void solveOne() {
		int count = in.nextInt();
		strs = new char[count][];
		for (int i = 0; i < count; i++) {
			strs[i] = compress(in.next().toCharArray());
		}
		used = new boolean[count];
		arrange = new int[count];
		Arrays.fill(used, false);
		for (char s[] : strs) {
			if (!valid(s)) {
				out.print(0);
				return;
			}
		}

		before = new boolean[count][count];
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++) {
				if (i != j) {
					StringBuilder sb = new StringBuilder();
					sb.append(strs[i]);
					sb.append(strs[j]);
					before[i][j] = valid(sb.toString().toCharArray());
				}
			}
		}

		out.print(gen(0, new TreeSet<Val>()));
	}

	void solve() {
		int nTests = in.nextInt();
		for (int i = 1; i <= nTests; i++) {
			out.print("Case #" + i + ": ");
			solveOne();
			out.println();
			out.flush();
		}
	}

	void run() {
		try {
			in = new Scanner(new FileReader(path + problem + ".in"));
			out = new PrintWriter(path + problem + ".out");
		} catch (IOException e) {
			in = new Scanner(System.in);
			out = new PrintWriter(System.out);
			out.println("cmd>");
			out.flush();
		}
		try {
			solve();
		} finally {
			out.close();
		}
	}

	public static void main(String[] args) {
		new B().run();
	}
}
