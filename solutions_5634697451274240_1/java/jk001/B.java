import java.util.*;
import java.io.*;

public class B {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int TC = sc.nextInt();
		for (int i = 1; i <= TC; i++) {
			
			int ans = 0;
			
			String next = sc.next();
			next = throwAway(next);

			while (!next.isEmpty()) {
				if (next.isEmpty()) break;
				if (next.startsWith("+")) {
					next = flip(next);
				} else {
					//flip the whole stack
					next = reverseString(next);
				}
				ans++;
				next = throwAway(next);
			}
			
			
			System.out.println("CASE #" + i + ": " + ans);
		}
	}

	private static String throwAway(String next) {
		StringBuilder sb = new StringBuilder();
		boolean found = false;
		for (int i = next.length() - 1; i >= 0; i--) {
			if (!found && next.charAt(i) == '-') {
				found = true;
			}
			
			if (found) {
				sb.append(next.charAt(i));
			}
		}
		
		return sb.reverse().toString();
	}

	private static String flip(String next) {
		int i;
		StringBuilder sb = new StringBuilder();
		for (i = 0; next.charAt(i) == '+'; i++) {
			sb.append("-");
		}
		sb.append(next.substring(i));
		return sb.toString();
		
	}

	private static String reverseString(String next) {
		StringBuilder sb = new StringBuilder();
		for (int i = next.length() - 1; i >= 0; i--) {
			if (next.charAt(i) == '+') {
				sb.append("-");
			} else {
				sb.append("+");
			}
		}
		return sb.toString();
	}

	private static boolean allHappy(String next) {
		for (char c : next.toCharArray()) {
			if (c == '-') {
				return false;
			}
		}
		return true;
	}
}
