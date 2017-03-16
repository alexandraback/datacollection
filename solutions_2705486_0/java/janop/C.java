package round1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class C {

	String S;
	Map<Integer, Set<String>> m = new HashMap<Integer, Set<String>>();
	Map<String, Integer> mem = new HashMap<String, Integer>();

	public static void main(String[] args) throws Exception {
		new C().solve();
	}

	private void solve() throws Exception {
		Scanner dic = new Scanner(new File("C:\\dev\\gcj\\c\\dic.txt"));
		while (dic.hasNext()) {
			String ss = dic.next();
			Integer ssl = ss.length();
			Set<String> currm = m.get(ssl);
			if (currm == null) {
				currm = new HashSet<String>();
				m.put(ssl, currm);
			}
			currm.add(ss);
		}
		dic.close();
		Scanner s = new Scanner(new File("C:\\dev\\gcj\\c\\input.txt"));
		int T = s.nextInt();
		for (int i = 0; i < T; i++) {
			mem.clear();
			S = s.next();
			System.out.println("Case #" + (i + 1) + ": " + go());
		}
		s.close();
	}

	private int go() {
		return f(S);
	}

	private int f(String curr) {
		Integer calc = mem.get(curr);
		if (calc != null)
			return calc;
		if (curr.length() == 0)
			return 0;
		int best = Integer.MAX_VALUE;
		for (int i = 1; i <= curr.length(); i++) {
			String c = curr.substring(0, i);
			Set<String> temp = m.get(c.length());
			if (temp == null)
				continue;
			for (String all : temp) {
				int res = 0;
				int lastDiff = -1;
				boolean ok = true;
				for (int j = 0; j < c.length(); j++) {
					if (c.charAt(j) != all.charAt(j)) {
						res++;
						if (lastDiff != -1) {
							if (j - lastDiff < 5) {
								ok = false;
								break;
							}
						}
						lastDiff = j;
					}
				}
				if (ok) {
					int tr = f(curr.substring(i));
					if (tr != -1) {
						best = Math.min(best, tr + res);
					}
				}
			}
		}
		if (best == Integer.MAX_VALUE) {
			mem.put(curr, -1);
			return -1;
		}
		mem.put(curr, best);
		return best;
	}

}
