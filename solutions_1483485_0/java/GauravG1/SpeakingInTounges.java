/*  
    Author: Gaurav Gupta
    Date:   14 Apr 2012
 */
import java.util.Scanner;

public class SpeakingInTounges {

	/**
	 * TODO Put here a description of what this method does.
	 * 
	 * @param args
	 */

	static char table[] = { 'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u',
			'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f',
			'm', 'a', 'q' };

	public static void main(String[] args) {
		// TODO Auto-generated method stub.

		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		sc.nextLine();
		String G, S;
		for (int i = 0; i < T; i++) {
			G = sc.nextLine();
			// System.out.println(G);
			G = G.trim();
			S = convert(G);
			System.out.println("Case #" + (i + 1) + ": " + S);

		}

	}

	public static String convert(String g) {
		String s = "";

		for (int i = 0; i < g.length(); i++) {
			char ch = g.charAt(i);
			// System.out.println(ch);
			if ((int) ch >= 97 && (int) ch <= 122)
				s = s + table[ch - 97];
			else
				s = s + ch;
		}

		return s;
	}

}
