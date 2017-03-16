import java.lang.Character.Subset;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.Scanner;
import java.util.regex.MatchResult;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Consonants {

	static HashMap<Integer, HashMap<Integer, Object>> substrings = new HashMap<Integer, HashMap<Integer, Object>>();

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int _ = 1; _ <= t; _++) {
			System.out.println("Case #" + _ + ": " + solve(sc.next("[a-z]*"), sc.nextInt()));
		}

	}

	private static int solve(String name, int n) {
		substrings.clear();
		String regex = "[bcdfghjklmnpqrstvwxyz]{" + n + "}";
		Pattern pattern = Pattern.compile(regex);
		Matcher matcher = pattern.matcher(name);
		int nValue = 0;
		int start = 0;
		while (matcher.find(start)) {
			MatchResult mr = matcher.toMatchResult();
			start = mr.start() + 1;
			for (int i = 0; i <= mr.start(); i++) {
				for (int j = mr.end() - 1; j < name.length(); j++) {
					if (!substrings.containsKey(i)) {
						substrings.put(i, new HashMap<Integer, Object>());
					}
					if (!substrings.get(i).containsKey(j)) {
						substrings.get(i).put(j, null);
						nValue++;
					}
				}
			}
		}
		return nValue;
	}

}
