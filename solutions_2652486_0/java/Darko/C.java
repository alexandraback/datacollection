import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.Scanner;
import java.util.Set;

public class C {

	class Pair {
		int a, b;

		Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}

		public int hashCode() {
			return 31 * a + b;
		}

		public boolean equals(Object o) {
			Pair p = (Pair) o;
			return a == p.a && b == p.b;
		}
	}

	private Map<String, Set<Integer>> all;

	private void generateAll() {
		all = new HashMap<String, Set<Integer>>();
		int[] a = new int[3];
		for (int i = 2; i <= 5; i++) {
			for (int j = i; j <= 5; j++) {
				for (int k = j; k <= 5; k++) {
					String key = i + "" + j + "" + k;
					a[0] = i;
					a[1] = j;
					a[2] = k;
					Set<Integer> set = new HashSet<Integer>();
					for (int l = 0; l < 8; l++) {
						int p = 1;
						for (int m = 0; m < 3; m++) {
							if (((1 << m) & l) != 0)
								p *= a[m];
						}
						set.add(p);
					}
					all.put(key, set);
				}
			}
		}
	}

	private void work() throws IOException {

		// Scanner sc = new Scanner(new FileReader("C-large.in"));
		// PrintWriter pw = new PrintWriter(new FileWriter("C-large.out"));
		Scanner sc = new Scanner(new FileReader("C-small-1-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter(
				"C-small-1-attempt0.out"));

		// Scanner sc = new Scanner(new FileReader("c.in"));
		// PrintWriter pw = new PrintWriter(new FileWriter("c.out"));

		generateAll();

		Random rnd = new Random();

		int nc = sc.nextInt();
		for (int tc = 1; tc <= nc; tc++) {
			pw.printf("Case #%d:\n", tc);
			int r = sc.nextInt();
			int n = sc.nextInt();
			int m = sc.nextInt();
			int k = sc.nextInt();
			Set<Integer> s = new HashSet<Integer>();
			List<String> p = new ArrayList<String>();
			while (r-- > 0) {
				s.clear();
				for (int i = 0; i < k; i++) {
					s.add(sc.nextInt());
				}
				p.clear();
				for (Map.Entry<String, Set<Integer>> e : all.entrySet()) {
					boolean ok = true;
					for (int i : s) {
						if (!e.getValue().contains(i)) {
							ok = false;
							break;
						}
					}
					if (ok)
						p.add(e.getKey());
				}
				// System.out.println(p.size());
				if (p.size() == 1) {
					pw.println(p.get(0));
				} else {
					pw.println(p.get(rnd.nextInt(p.size())));
				}
			}
		}
		pw.close();

	}

	public static void main(String[] args) throws IOException {
		new C().work();
	}

}
