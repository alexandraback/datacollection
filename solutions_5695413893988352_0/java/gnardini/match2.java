package codejam;

import java.util.Scanner;

public class match2 {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int T = s.nextInt();
		for (int i = 1; i <= T; i++) {
			String first = s.next();
			String second = s.next();
			StringBuilder fans = new StringBuilder();
			StringBuilder sans = new StringBuilder();
			
			minDiff = Integer.MAX_VALUE;
			mins1 = "";
			mins2 = "";
			tryAll(first, second, fans, sans, 0);
			
			System.out.println("Case #" + i + ": " + mins1 + " " + mins2);
		}
	}
	
	private static int minDiff;
	private static String mins1;
	private static String mins2;
	
	private static void tryAll(String s1, String s2, StringBuilder ans1, StringBuilder ans2, int index) {
		if (index == s1.length()) {
			int first = Integer.valueOf(ans1.toString());
			int second = Integer.valueOf(ans2.toString());
			int diff = Math.abs(first - second);
			if ((diff < minDiff) || (diff == minDiff && Math.min(first, second) < Math.min(Integer.valueOf(mins1), Integer.valueOf(mins2)))) {
				minDiff = diff;
				mins1 = ans1.toString();
				mins2 = ans2.toString();
			}
			return;
		}
		if (s1.charAt(index) == '?') {
			for (int i = 0 ; i < 10; i++) {
				if (s2.charAt(index) == '?') {
					for (int j = 0; j < 10; j++) {
						ans1.append(i);
						ans2.append(j);
						tryAll(s1, s2, ans1, ans2, index+1);
						ans1.deleteCharAt(ans1.length() - 1);
						ans2.deleteCharAt(ans2.length() - 1);
					}
				} else {
					ans1.append(i);
					ans2.append(s2.charAt(index));
					tryAll(s1, s2, ans1, ans2, index+1);
					ans1.deleteCharAt(ans1.length() - 1);
					ans2.deleteCharAt(ans2.length() - 1);
				}
			}
		} else if (s2.charAt(index) == '?') {
			for (int i = 0 ; i < 10; i++) {
				ans1.append(s1.charAt(index));
				ans2.append(i);
				tryAll(s1, s2, ans1, ans2, index+1);
				ans1.deleteCharAt(ans1.length() - 1);
				ans2.deleteCharAt(ans2.length() - 1);
			}
		} else {
			ans1.append(s1.charAt(index));
			ans2.append(s2.charAt(index));
			tryAll(s1, s2, ans1, ans2, index+1);
			ans1.deleteCharAt(ans1.length() - 1);
			ans2.deleteCharAt(ans2.length() - 1);
		}
	}
	
}
