package gcj;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class B {

	// private static final String FILE_NAME = "B-large";

	private static final String FILE_NAME = "B-small-attempt0";
	// private static final String FILE_NAME = "B";

	private static int k, l, s;
	private static String keyboard, target;

	private static void permu(List<String> list, StringBuffer sb) {
		if (sb.length() == s) {
			list.add(sb.toString());
			return;
		}
		for (int i = 0; i < k; ++i) {
			sb.append(keyboard.charAt(i));
			permu(list, sb);
			sb.deleteCharAt(sb.length() - 1);
		}
	}

	private static void work(Scanner in, PrintStream out, int caseNum) {
		k = in.nextInt();
		l = in.nextInt();
		s = in.nextInt();
		in.nextLine();
		keyboard = in.nextLine();
		target = in.nextLine();
		int max = 0;
		double expect = 0.0;
		int overlap = 0;
		for (int i = 1; i < l; ++i) {
			String prefix = target.substring(0, i);
			String suffix = target.substring(l - i, l);
			if (prefix.equals(suffix)) {
				overlap = Math.max(overlap, i);
			}
		}
		max = (s - l) / (l - overlap) + 1;
		int[] kFlag = new int[26];
		int[] tFlag = new int[26];
		for (int i = 0; i < k; ++i) {
			++kFlag[keyboard.charAt(i) - 'A'];
		}
		for (int i = 0; i < l; ++i) {
			++tFlag[target.charAt(i) - 'A'];
		}
		for (int i = 0; i < 26; ++i) {
			if (tFlag[i] != 0 && kFlag[i] == 0) {
				out.print(0.0);
				return;
			}
		}
		List<String> list = new ArrayList<>();
		permu(list, new StringBuffer());
		int cnt = 0;
		for (String str : list) {
			int idx = -1;
			int cn = -1;
			do {
				++cn;
				idx = str.indexOf(target, idx + 1);
			} while (idx != -1);

			cnt += cn;
		}
		expect = (double) cnt / (double) list.size();
		out.print(max - expect);
	}

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File(FILE_NAME + ".in"));
		PrintStream out = new PrintStream(new File(FILE_NAME + ".out"));
		int loopNum = in.nextInt();

		for (int caseNum = 1; caseNum <= loopNum; caseNum++) {
			out.print("Case #" + caseNum + ": ");
			work(in, out, caseNum);
			out.println();
		}

		in.close();
		out.close();
	}
}
