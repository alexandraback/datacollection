import java.io.*;
import java.util.*;

public class P2 {
	static int MOD = 1000000007;
	static String[] s;
	static Vector<String> sb;
	static boolean[] sel;
	static int N;
	static long res;
	static boolean isValid (String str, boolean add) {
		boolean[] done = new boolean [26];
		int n = str.length(), i = 0;
		String temp = "";
		while (i < n) {
			if (i > 0 && str.charAt(i) == str.charAt(i - 1)) {
				i++;
				continue;
			}
			int j = str.charAt(i) - 'a';
			if (done[j])
				return false;
			done[j] = true;
			temp += str.charAt(i);
			i++;
		}
		if (add)
			sb.add(temp);
		return true;
	}
	static long fact (int n) {
		if (n < 2)
			return 1;
		long ret = 2;
		for (int i = 3; i <= n; i++) {
			ret *= (long) i;
			ret = ret % MOD;
		}
		return ret;
	}
	public static void main (String[] args) throws FileNotFoundException {
//		Scanner sc = new Scanner (System.in);
//		PrintStream op = System.out;
		Scanner sc = new Scanner (new FileInputStream ("D:\\Internet\\B-small-attempt1.in"));
		PrintStream op = new PrintStream ("output.txt");
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			N = sc.nextInt();
			sc.nextLine();
			s = sc.nextLine().split(" ");
			op.print("Case #" + t + ": ");
			sb = new Vector <String> ();
			boolean testDone = false;
			for (int i = 0; i < N; i++) {
				if (!isValid(s[i], true)) {
					op.println(0);
					testDone = true;
					break;
				}
			}
			if (testDone)
				continue;
			sel = new boolean [26];
			int[] rCount = new int [26];
			Collections.sort(sb);
			for (int i = 0; i < sb.size(); i++) {
				String p = sb.get(i);
				int n = p.length();
//				op.println(p);
				if (n == 1) {
					int ind = p.charAt(0) - 'a';
					rCount[ind]++;
				}
			}
			boolean done = false;
			while (!done) {
				done = true;
				int n = sb.size();
				Collections.sort(sb);
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (i == j)
							continue;
						String p = sb.get(i);
						String q = sb.get(j);
						int pn = p.length();
						if (q.charAt(0) == p.charAt(pn - 1)) {
							int min = Math.min(i, j);
							int max = Math.max(i, j);
							sb.remove(max);
							sb.remove(min);
							sb.add(p + q);
							done = false;
							break;
						}
					}
					if (!done)
						break;
				}
			}
			for (String str : sb) {
				if (!isValid(str, false)) {
					op.println(0);
					testDone = true;
					break;
				}
			}
			if (testDone)
				continue;
			sel = new boolean [26];
			for (String str : sb) {
				int n = str.length(), i = 0;
				while (i < n) {
					char c = str.charAt(i);
					if (i > 0 &&  c == str.charAt(i - 1)) {
						i++;
						continue;
					}
					int ind = c - 'a';
					if (sel[ind]) {
						op.println(0);
						testDone = true;
						break;
					}
					sel[ind] = true;
					i++;
				}
				if (testDone)
					break;
			}
			if (testDone)
				continue;
			int n = sb.size();
			res = fact (n);
			for (int i = 0; i < 26; i++) {
				res *= fact(rCount[i]);
				res = res % MOD;
			}
			op.println(res);
		}
	}
}