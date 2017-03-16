import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int no = 1; no <= T; no++) {
			char[] str = in.next().toCharArray();
			int n = in.nextInt();

			List<Integer> bs = new ArrayList<>();
			List<Integer> cs = new ArrayList<>();
			int begin = -1;
			int count = 0;
			for (int i = 0; i < str.length; i++) {
				if (isCon(str[i])) {
					if (begin == -1) {
						begin = i;
						count = 1;
					} else {
						count++;
					}
				} else {
					if (begin != -1 && count >= n) {
						bs.add(begin);
						cs.add(count);
					}
					begin = -1;
					count = 0;
				}
			}
			if (begin != -1 && count >= n) {
				bs.add(begin);
				cs.add(count);
			}

			//System.err.println(bs);
			//System.err.println(cs);
			long ans = 0;
			int ind = 0;
			for (int i = 0; i < str.length; i++) {
				if (ind >= bs.size())
					break;
				int b = bs.get(ind);
				int c = cs.get(ind);
				//System.err.printf("%d %d %d%n", b, c, i);
				if (b + c - i >= n) {
					int ri = str.length - (Math.max(i, b) + n) + 1;
					//System.err.printf("%d%n", ri);
					ans += ri;
				} else {
					ind++;
					i--;
					continue;
				}
			}
			System.out.printf("Case #%d: %d%n", no, ans);
		}
	}

	static boolean isCon(char c) {
		return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
	}

}
