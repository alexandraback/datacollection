import java.util.*;
import java.io.*;

public class B {
	static final HashMap<String, Integer> hm = new HashMap<String, Integer>();

	public static void main(String[] args) throws Exception {
		hm.put("", 0);

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int keis = Integer.valueOf(br.readLine());

		for (int kei = 1; kei <= keis; kei++) {
			String s = br.readLine();
			s = simplify(s);
			s = s.replaceAll("\\+", "0");
			s = s.replaceAll("-", "1");
			System.out.printf("Case #%d: %d\n", kei, solve(s));
		}
	}

	static int solve(String x) {
		String s = x.substring(0);

		// end case
		if (s.length() == 0)
			return 0;

		// solved
		if (hm.containsKey(s))
			return hm.get(s);
		
		// ends with 0, solve smaller-1 case
		if (s.charAt(s.length()-1) == '0') {
			int ans = solve(s.substring(0, s.length()-1));
			hm.put(x, ans);
			return ans;
		}

		// ends with 1
		if (s.length() % 2 == 1) {
			// odd length, e.g. 101
			// flip whole, solve smaller-1 case
			s = flip(s);
			int ans = solve(s.substring(0, s.length()-1)) + 1;
			hm.put(x, ans);
			return ans;
		} else {
			// even length, e.g. 0101
			// flip first, flip whole, solve smaller-2 case
			s = "1" + s.substring(1, s.length());
			s = flip(s);
			int ans = solve(s.substring(0, s.length()-2)) + 2;
			hm.put(x, ans);
			return ans;
		}
	}

	static String flip(String s) {
		String f = "";
		for (int i = 0; i < s.length(); i++) {
			char dig = s.charAt(i) == '0' ? '1' : '0';
			f = dig + f;
 		}
 		return f;
	}

	static String simplify(String s) {
		// combine contiguous 0s and 1s
		String ans = "";
		char prev = 'x';
		for (int i = 0; i < s.length(); i++) {
			char c = s.charAt(i);
			if (c != prev) {
				ans += c;
				prev = c;
			}
		}
		return ans;
	}
}