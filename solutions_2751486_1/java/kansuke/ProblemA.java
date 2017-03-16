import java.io.*;
import java.util.*;

public class ProblemA {
	static Scanner scan = new Scanner(System.in);
	static PrintStream out = System.out;
	
	static boolean isCons (char c) {
		if (c == 'a' || c == 'e' || c =='i' || c == 'o' || c == 'u') return false;
		return true;
	}
	
	static boolean isNCons (CharSequence sb) {
		for (char c : sb.toString().toCharArray()) {
			if (!isCons(c))
				return false;
		}
		return true;
	}
	
	static void test() {
		String input = scan.next();
		long n = scan.nextInt();
		long ans = 0;
		long N = input.length();
		ArrayList<Long> al = new ArrayList<Long> ();
		al.add(-1L);
		for (int i = 0; i < input.length(); ++i) {
			char c = input.charAt(i);
			if (!isCons(c))
				al.add(Long.valueOf(i));
		}
		al.add(N);
		long start = 0;
		for (int k = 0; k < al.size() - 1; ++k) {
			long l1 = al.get(k), l2 = al.get(k+1);
			if (l2 - l1 <= n)
				continue;
			ans += (l1 - start + 2) * (N - l1 - n);
			ans += (N-n+1)*(l2-n-l1-1) - (l2-n-l1-1)*(l2-n+l1+2)/2; 
			start = l2 - n + 1;
		}
		out.println (ans);
	}

	public static void main(String[] args) {
		int T = scan.nextInt();
		for (int i = 1; i <= T; ++i) {
			out.print("Case #" + i + ": ");
			test();
		}
	}
}
