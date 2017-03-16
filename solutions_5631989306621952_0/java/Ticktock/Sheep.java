import java.util.Scanner;
import java.lang.StringBuilder;

public class Sheep {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		final int T = Integer.parseInt(sc.nextLine());
		for (int caseCount = 1; caseCount <= T; caseCount++) {
			System.out.print("Case #" + caseCount + ": ");
			String s = sc.nextLine();
			StringBuilder sb = new StringBuilder("" + s.charAt(0));
			for (int i = 1; i < s.length(); i++) {
				if (s.charAt(i) < sb.charAt(0)) {
					sb.append(s.charAt(i));
				} else {
					sb.insert(0, s.charAt(i));
				}
			}
			System.out.println(sb.toString());
		}
	}
}
