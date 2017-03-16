import java.io.*;
import java.util.*;

public class ProblemA {
	static Scanner scan = new Scanner(System.in);
	static PrintStream out = System.out;
	static int P = 1000000;
	
	static boolean isCons (char c) {
		if (c == 'a' || c == 'e' || c =='i' || c == 'o' || c == 'u') return false;
		return true;
	}
	
	static boolean isNCons(String s, int n) {
		for (int i = 0; i <= s.length() - n; ++i) {
			String sub = s.substring(i, i + n);
			boolean isNCons = true;
			for (int j = 0; j < n; ++j) {
				if (!isCons(sub.charAt(j))) {
					isNCons = false;
					break;
				}
			}
			if (isNCons)
				return true;
		}
		return false;
	}
	
	static void test() {
		String input = scan.next();
		int n = scan.nextInt();
		int ans = 0;
		for (int i = 0; i <= input.length() - n; ++i)
			for (int j = i + n; j <= input.length(); ++j) {
				String tmp = input.substring(i, j);
				if (isNCons(tmp, n))
					++ans;
			}
		out.println(ans);
	}

	public static void main(String[] args) {
		int T = scan.nextInt();
		for (int i = 1; i <= T; ++i) {
			out.print("Case #" + i + ": ");
			test();
		}
	}
}
