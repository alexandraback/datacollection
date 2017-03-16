import java.util.*;

public class a {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int t = in.nextInt();

		for(int caseN = 1; caseN <= t; caseN++) {
			String str = in.next();
			System.out.println("Case #" + caseN + ": " + go(str));
		}

	}

	public static String go(String str) {
		if(str.length() == 0) return "";
		char c = str.charAt(str.length() - 1);
		int bestIndex = str.length() - 1;
		for(int i = str.length() - 1; i >= 0; i--) {
			if(str.charAt(i) > c) {
				c = str.charAt(i);
				bestIndex = i;
			}
		}

		return "" + str.charAt(bestIndex) + go(str.substring(0, bestIndex)) + str.substring(bestIndex + 1);
	}

}