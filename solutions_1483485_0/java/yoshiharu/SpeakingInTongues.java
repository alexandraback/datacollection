package qual;

import java.util.Scanner;

public class SpeakingInTongues {

	public static void main(String[] args) {
		new SpeakingInTongues().run();

	}

	private void run() {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		String nl = sc.nextLine();
		for (int t = 0; t < T; t++) {
			String result = solve(sc.nextLine());
			System.out.printf("Case #%d: %s\n", t + 1, result);
		}

	}

	public String solve(String str) {
		char[] map = new char[] {
				'y', /* a */	
				'h', /* b */
				'e', /* c */
				's', /* d */
				'o', /* e */
				'c', /* f */
				'v', /* g */
				'x', /* h */
				'd', /* i */
				'u', /* j */
				'i', /* k */
				'g', /* l */
				'l', /* m */
				'b', /* n */
				'k', /* o */
				'r', /* p */
				'z', /* q */  /**/
				't', /* r */
				'n', /* s */
				'w', /* t */
				'j', /* u */
				'p', /* v */
				'f', /* w */
				'm', /* x */
				'a', /* y */
				'q', /* z */  /**/
		};
		char[] s = str.toCharArray();
		for (int i = 0; i < s.length; i++) {
			if (s[i] != ' ') {
				s[i] = map[s[i] - 'a'];
			}
		}
		return new String(s);
	}

}
