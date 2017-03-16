import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class S2 {

	private static HashMap<String, Integer> solution = new HashMap<>();
	private static Pattern allPlus = Pattern.compile("^\\++$");
	private static Pattern allNegative = Pattern.compile("^\\-+$");
	private static Pattern beforePlus = Pattern.compile("(.*-)\\++$");
	private static Pattern startPlus = Pattern.compile("^(\\++)");

	static int solve(String s) {
		if (solution.containsKey(s)) {
			return solution.get(s);
		} else if (allPlus.matcher(s).find()){
			solution.put(s, 0);
			return 0;
		} else if (allNegative.matcher(s).find()){
			solution.put(s, 1);
			return 1;
		} else {
			Matcher matcher = beforePlus.matcher(s);
			if (matcher.find()) {
				int ans = solve(matcher.group(1));
				solution.put(s, ans);
				return ans;
			} else {
				Matcher startPlusM = startPlus.matcher(s);
				int countStartPlus = 0;
				if (startPlusM.find()) {
					countStartPlus = startPlusM.group(1).length();
					char[] chars = s.toCharArray();

					for (int i = 0; i < countStartPlus; i++) {
						chars[i] = '-';
					}
					int ans = solve(String.valueOf(chars));
					solution.put(s, ans + 1);
					return ans + 1;
				} else {
					char[] chars = new char[s.length()];
					for (int i = 0; i < s.length(); i++) {
						chars[i] = s.charAt(s.length() - 1 - i) == '+' ? '-' : '+';
					}
					int ans = solve(String.valueOf(chars));
					solution.put(s, ans + 1);
					return ans + 1;
				}
			}
		}
	}

	public static void main(String[] args) {
		try (Scanner sc = new Scanner(System.in)) {
			int t = sc.nextInt();
//			sc.next();
			for (int i = 1; i <= t; i++) {
				System.out.print("Case #");
				System.out.print(i);
				System.out.print(": ");
				System.out.println(solve(sc.next().trim()));
			}
		}

	}

}
