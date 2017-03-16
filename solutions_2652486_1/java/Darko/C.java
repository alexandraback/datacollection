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
import java.util.TreeMap;

public class C {

	private Map<String, Set<Long>> all;

	private void generateAll() {
		all = new HashMap<String, Set<Long>>();
		go(0, 2);
	}

	int[] aa = new int[12];

	private void go(int k, int min) {
		if (k == 12) {
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < 12; i++) {
				sb.append(aa[i]);
			}
			String key = sb.toString();
			Set<Long> set = new HashSet<Long>();
			for (int i = 0; i < 1 << 12; i++) {
				long p = 1;
				for (int j = 0; j < 12; j++) {
					if (((1 << j) & i) != 0)
						p *= aa[j];
				}
				set.add(p);
			}
			all.put(key, set);
		} else {
			for (int i = min; i <= 8; i++) {
				aa[k] = i;
				go(k + 1, i);
			}
		}
	}

	private void work() throws IOException {

		Scanner sc = new Scanner(new FileReader("C-small-2-attempt1.in"));
		PrintWriter pw = new PrintWriter(new FileWriter(
				"C-small-2-attempt1.out"));

		// Scanner sc = new Scanner(new FileReader("c.in"));
		// PrintWriter pw = new PrintWriter(new FileWriter("c.out"));

		generateAll();
		System.out.println(all.size());

		Random rnd = new Random();

		int nc = sc.nextInt();
		for (int tc = 1; tc <= nc; tc++) {
			Map<Integer, Integer> counts = new TreeMap<Integer, Integer>();
			pw.printf("Case #%d:\n", tc);
			int r = sc.nextInt();
			int n = sc.nextInt();
			int m = sc.nextInt();
			int k = sc.nextInt();
			Set<Long> s = new HashSet<Long>();
			List<String> p = new ArrayList<String>();
			while (r-- > 0) {
				s.clear();
				for (int i = 0; i < k; i++) {
					s.add(sc.nextLong());
				}
				p.clear();
				for (Map.Entry<String, Set<Long>> e : all.entrySet()) {
					boolean ok = true;
					for (long i : s) {
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
				if (!counts.containsKey(p.size()))
					counts.put(p.size(), 0);
				counts.put(p.size(), counts.get(p.size()) + 1);
			}
			System.err.println(counts);
		}
		pw.close();

	}

	public static void main(String[] args) throws IOException {
		new C().work();
	}

}
