import java.io.*;
import java.util.*;

public class A {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int casenum = 1; casenum <= T; casenum++) {
			String s = in.next();
			String cur = "";
			for (int i = 0; i < s.length(); i++) {
				String first = s.charAt(i) + cur;
				String second = cur + s.charAt(i);
				if (first.compareTo(second) > 0) {
					cur = first;
				} else {
					cur = second;
				}
			}
			System.out.println("Case #" + casenum + ": " + cur);
		}
	}
}
