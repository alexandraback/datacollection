import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.StringTokenizer;

public class probBSmall {
	static String input = "probC.in";
	static String output = "probC.out";

	public static void main(String[] args) throws IOException {
//		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
//		PrintWriter out = new PrintWriter(System.out);
		 BufferedReader in =new BufferedReader(new FileReader(input));
		 PrintWriter out = new PrintWriter(new FileWriter(output));

		int t = Integer.parseInt(in.readLine());

		for (int i = 1; i <= t; i++) {
			out.print("Case #" + i + ": ");
			int n = Integer.parseInt(in.readLine());

			out.println(oneTest(n, in, out));
			out.flush();
		}

	}

	private static int oneTest(int n, BufferedReader in, PrintWriter out)
			throws IOException {
		bff = bff(in.readLine(), n);

		isGood(new ArrayList<>(Arrays.asList(10, 3, 9, 7, 1, 6, 8, 2)));
		return rec(new ArrayList<Integer>(), new HashSet<Integer>(), n);
	}

	private static int rec(ArrayList<Integer> circle, HashSet<Integer> all,
			int n) {
		HashMap<Integer, Integer> bff1 = bff;
		if (all.size() == n) {
			if (isGood(circle)) {
				return circle.size();
			} else {
				return 0;
			}
		}

		int res = 0;
		if (circle.size() == 1)
			res = 1;
		if (circle.size() > 1 && isGood(circle)) {
			// System.out.println(circle.toString());
			res = Math.max(res, circle.size());
		}
		for (int i = 1; i <= n; i++) {
			if (all.contains(i))
				continue;
			all.add(i);
			circle.add(i);
			if (!stop(circle)) {
				res = Math.max(res, rec(circle, all, n));
			}
			all.remove(i);
			circle.remove(circle.size() - 1);
		}
		return res;
	}

	private static boolean isGood(ArrayList<Integer> circle) {
		if (circle.size() == 1)
			return true;
		HashMap<Integer, Integer> bff1 = bff;
		for (int i = 1; i < circle.size(); i++) {
			int a = circle.get(i);
			if (bff.get(a) == circle.get(i - 1)
					|| bff.get(a) == circle.get((i + 1) % circle.size())) {
				continue;
			} else {
				return false;
			}

		}

		int first = circle.get(0);
		int last = circle.get((circle.size() - 1));
		if (bff.get(first) == last || bff.get(first) == circle.get(1))
			return true;
		return false;
	}

	private static HashMap<Integer, Integer> bff;

	private static HashMap<Integer, Integer> bff(String str, int n) {
		HashMap<Integer, Integer> res = new HashMap<>();
		StringTokenizer tok = new StringTokenizer(str);

		for (int i = 1; i <= n; i++) {
			int a = Integer.parseInt(tok.nextToken());
			res.put(i, a);

		}

		return res;
	}

	private static boolean stop(ArrayList<Integer> circle) {
		if (circle.size() < 3)
			return false;
		for (int i = 1; i < circle.size() - 1; i++) {
			int a = circle.get(i);
			if (bff.get(a) == circle.get(i - 1)
					|| bff.get(a) == circle.get((i + 1) % circle.size())) {
				continue;
			} else {
				return true;
			}
		}

		return false;
	}
}
