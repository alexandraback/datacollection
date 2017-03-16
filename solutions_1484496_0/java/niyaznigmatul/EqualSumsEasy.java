import java.io.*;
import java.util.*;

public class EqualSumsEasy {
	public static void main(String[] args) throws Throwable {
		Scanner in = new Scanner(new File("eqsums.in"));
		PrintWriter out = new PrintWriter("eqsums.out");
		int testCount = Integer.parseInt(in.nextLine().trim());
		for (int i = 0; i < testCount; i++) {
			out.println("Case #" + (i + 1) + ":");
			solve(in, out);
		}
		out.close();
	}

	static void solve(Scanner in, PrintWriter out) {
		int n = in.nextInt();
		int[] a = new int[n];
		int sum = 0;
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
			sum += a[i];
		}
		List<Integer>[] lists = new ArrayList[sum + 1];
		for (int i = 1; i < 1 << n; i++) {
			int sum1 = 0;
			for (int j = 0; j < n; j++) {
				if (((i >> j) & 1) == 1) {
					sum1 += a[j];
				}
			}
			if (lists[sum1] == null) {
				lists[sum1] = new ArrayList<Integer>(3);
			}
			lists[sum1].add(i);
		}
		for (List<Integer> e : lists) {
			if (e == null) {
				continue;
			}
			for (int j : e) {
				for (int k : e) {
					if ((j & k) == 0) {
						printAnswer(a, j, k, out);
						return;
					}
				}
			}
		}
		out.println("Impossible");
	}

	static void printAnswer(int[] a, int mask1, int mask2, PrintWriter out) {
		List<Integer> ans1 = getMask(a, mask1);
		List<Integer> ans2 = getMask(a, mask2);
		printList(ans1, out);
		printList(ans2, out);
	}

	static List<Integer> getMask(int[] a, int mask) {
		List<Integer> ret = new ArrayList<Integer>();
		for (int i = 0; i < a.length; i++) {
			if (((mask >> i) & 1) == 1) {
				ret.add(a[i]);
			}
		}
		Collections.sort(ret);
		return ret;
	}

	static void printList(List<Integer> a, PrintWriter out) {
		for (int i = 0; i < a.size(); i++) {
			if (i > 0) {
				out.print(' ');
			}
			out.print(a.get(i));
		}
		out.println();
	}

}
