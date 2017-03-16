package qualA2016;

import java.util.*;

public class A {
	public static void main(String... args) {
		Scanner s = new Scanner(System.in);
		
		final int T = s.nextInt();
		
		for (int t = 1; t <= T; t++) {
			String st = s.next();
			System.out.printf("Case #%d: %s\n", t, solve(st));
		}
		
		s.close();
	}
	
	static String solve(String s) {
		char[] cs = s.toCharArray();
		
		Deque<Character> l = new ArrayDeque<>();
		
		for (int i = 0; i < cs.length; i++) {
			if (l.isEmpty() || l.peekFirst() <= cs[i]) {
				l.addFirst(cs[i]);
			} else {
				l.addLast(cs[i]);
			}
		}
		
		StringBuilder sb = new StringBuilder();
		for (Character c : l) sb.append(c);
		
		return sb.toString();
	}
}

