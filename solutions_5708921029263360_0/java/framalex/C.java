package gcj.c2016.r1c;


import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.*;

public class C implements Runnable {

	int j, p, s, k;
	public void run() {
		int tests = nextInt();
		for (int iter = 1; iter <= tests; ++iter) {
			j = nextInt();
			p = nextInt();
			s = nextInt();
			k = nextInt();

			time = System.currentTimeMillis();
			aaa = new HashSet<String>();
			rec(0, new HashSet<String>(), new HashMap<String, Integer>());
			out.println("Case #" + iter+": " + aaa.size());
			for (String s : aaa) {
				out.println(pr(s.charAt(0)) + " " + pr(s.charAt(1)) + " " + pr(s.charAt(2)));
			}
			System.err.println(iter);
		}
		out.flush();
	}

	int pr(char c) {
		return (int)(c-'0') + 1;
	}
	long time = 0;
	HashSet<String> aaa;
	private void rec(int i, HashSet<String> used, HashMap<String, Integer> pairs) {

		if (System.currentTimeMillis() - time > 1500) {
			return;
		}
		int max = i;
		for (int jj = 0; jj < j; ++jj) {
			for (int pp = 0; pp < p; ++pp) {
				for (int ss = 0; ss < s; ++ss) {
					if (!used.contains("" + jj + "" + pp + "" + ss)) {
						Integer p1 = pairs.get("" + jj + "" + pp + "!");
						Integer p2 = pairs.get("" + jj + "!" + ss);
						Integer p3 = pairs.get("!" + pp + "" + ss);
						p1 = p1 == null ? 0 : p1;
						p2 = p2 == null ? 0 : p2;
						p3 = p3 == null ? 0 : p3;
						if (p1 < k && p2 < k && p3 < k) {
							HashSet<String> na = used;
							na.add("" + jj + "" + pp + "" + ss);
							HashMap<String, Integer> np = pairs;
							np.put("" + jj + "" + pp + "!", p1+1);
							np.put("" + jj + "!" + ss, p2+1);
							np.put("!" + pp + "" + ss, p3+1);
							rec(i+1, na, np);

							if (na.size() > aaa.size()) {
								aaa = (HashSet<String>) na.clone();
							}


							na.remove("" + jj + "" + pp + "" + ss);
							np.put("" + jj + "" + pp + "!", p1);
							np.put("" + jj + "!" + ss, p2);
							np.put("!" + pp + "" + ss, p3);
						}
					}
				}
			}
		}
	}


	private static BufferedReader br = null;
	private static PrintWriter out = null;
	private static StringTokenizer stk = null;
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader(new File("C.txt")));
		out = new PrintWriter("CC.txt");
		(new C()).run();
	}

	private void loadLine() {
		try {
			stk = new StringTokenizer(br.readLine());
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}

	private String nextLine() {
		try {
			return (br.readLine());
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}

	private int nextInt() {
		while (stk == null || !stk.hasMoreElements()) loadLine();
		return Integer.parseInt(stk.nextToken());
	}

	private long nextLong() {
		while (stk == null || !stk.hasMoreElements()) loadLine();
		return Long.parseLong(stk.nextToken());
	}

	private double nextDouble() {
		while (stk == null || !stk.hasMoreElements()) loadLine();
		return Double.parseDouble(stk.nextToken());
	}

	private String nextWord() {
		while (stk == null || !stk.hasMoreElements()) loadLine();
		return (stk.nextToken());
	}
}
