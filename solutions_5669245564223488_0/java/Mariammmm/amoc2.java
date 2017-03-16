import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class amoc2 {
	private static boolean valid(String str) {
		for (char ch = 'a'; ch <= 'z'; ch++) {
			if (!checkChar(str, ch))
				return false;
		}
		return true;
	}

	private static boolean checkChar(String str, char ch) {
		int ind = findCh(0, str, ch);
		if (ind == -1)
			return true;

		int prev = ind;
		while (ind != -1) {
			ind = findCh(prev + 1, str, ch);
			if (ind == -1)
				return true;
			if (ind - prev > 1)
				return false;
			prev = ind;
		}
		return false;
	}

	private static int findCh(int start, String str, char ch) {

		for (int i = start; i < str.length(); i++) {
			if (str.charAt(i) == ch)
				return i;
		}
		return -1;
	}

	private static boolean allSame(String str) {
		if (str.length() <= 1)
			return true;
		for (int i = 1; i < str.length(); i++) {
			if (str.charAt(i) != str.charAt(i - 1))
				return false;
		}

		return true;
	}

	private static void sort(ArrayList<String> list,
			ArrayList<String> notAllSame, int[] countSame) {
		for (int i = 0; i < list.size(); i++) {
			if (allSame(list.get(i))) {
				countSame[list.get(i).charAt(0) - 'a']++;
			} else {
				notAllSame.add(list.get(i));
			}

		}
	}

	private static class cl {
		String value;
		long var;

		public cl(String value, long var) {
			this.value = value;
			this.var = var;
		}
	}

	private static int nasht = 1000000007;

	private static ArrayList<cl> intoClass(int[] countSame,
			ArrayList<String> notAllSame) {
		ArrayList<cl> res = new ArrayList<>();
		for (char i = 'a'; i <= 'z'; i++) {
			if (countSame[i - 'a'] == 0)
				continue;
			res.add(new cl("" + i + "" + i, fact(countSame[i - 'a'])));
		}

		for (int i = 0; i < notAllSame.size(); i++) {
			res.add(new cl(notAllSame.get(i), 1));
		}

		return res;
	}

	private static boolean merge(cl a, cl b) {
		String aval = a.value;
		String bval = b.value;

		if (aval.charAt(aval.length() - 1) == bval.charAt(0)) {
			b.value = aval + bval;
			b.var = b.var * a.var % nasht;
			return true;
		}

		if (bval.charAt(bval.length() - 1) == aval.charAt(0)) {
			b.value = bval + aval;
			b.var = b.var * a.var % nasht;
			return true;
		}
		return false;
	}

	private static long fact(int a) {
		long res = 1;
		for (int i = 1; i <= a; i++) {
			res = res * i % nasht;
		}

		return res;
	}

	private static long solve(ArrayList<String> list) {
		if (!ifPossible(list))
			return 0;

		int[] countSame = new int[30];
		ArrayList<String> notAllSame = new ArrayList<>();

		sort(list, notAllSame, countSame);

		ArrayList<cl> list1 = intoClass(countSame, notAllSame);

		while (list1.size() > 1) {
			boolean smthmerged = false;
			for (int k = 0; k < list.size() - 1; k++) {
				for (int i = k + 1; i < list1.size(); i++) {
					if (merge(list1.get(k), list1.get(i))) {
						if (!valid(list1.get(i).value))
							return 0;
						list1.remove(k);
						smthmerged = true;
						break;
					}
				}
			}
			if (!smthmerged)
				break;
		}

		StringBuilder build = new StringBuilder();
		for (int i = 0; i < list1.size(); i++) {
			build.append(list1.get(i).value);
		}

		if (!valid(build.toString()))
			return 0;

		long res = 1;
		for (int i = 0; i < list1.size(); i++) {
			res = res * list1.get(i).var % nasht;
		}
		res = res * fact(list1.size()) % nasht;
		return res;
	}

	private static void oneTest(BufferedReader in, PrintWriter out, int t)
			throws IOException {
		int n = Integer.parseInt(in.readLine());
		StringTokenizer tok = new StringTokenizer(in.readLine());
		ArrayList<String> list = new ArrayList<>();

		for (int i = 0; i < n; i++) {
			list.add(tok.nextToken());
		}
		out.print("Case #");
		out.print(t);
		out.print(": ");
		out.println(solve(list));
	}

	private static boolean ifPossible(ArrayList<String> list) {
		for (int i = 0; i < list.size(); i++) {
			if (!valid(list.get(i)))
				return false;
		}

		return true;
	}

	public static void main(String args[]) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("vag.in"));
		PrintWriter out = new PrintWriter(new FileWriter("vag.out"));

		int t = Integer.parseInt(in.readLine());

		for (int i = 1; i <= t; i++) {
			oneTest(in, out, i);
		}

		out.flush();
	}
}
