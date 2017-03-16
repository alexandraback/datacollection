import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;

public class Consonants {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader(new File(
				"/Users/narok119/Desktop/A-small-attempt1.in")));
		int caseCount = 1;
		String txt = reader.readLine();
		while ((txt = reader.readLine()) != null) {
			int result = 0;
			String word = txt.split(" ")[0];
			int n = Integer.parseInt(txt.split(" ")[1]);
			for (int i = 0; i <= word.length(); i++) {
				for (int j = i + n; j <= word.length(); j++) {
					if (isConsec(word.substring(i, j), n)) {
						result++;
					}
				}
			}
			System.out.println("Case #" + caseCount++ + ": " + result);
		}

	}

	private static boolean isConsec(String substring, int n) {

		int count = 0;
		for (int i = 0; i < substring.length(); i++) {
			if (substring.charAt(i) != 'a' && substring.charAt(i) != 'e'
					&& substring.charAt(i) != 'i' && substring.charAt(i) != 'o'
					&& substring.charAt(i) != 'u') {
				count++;
			} else {
				count = 0;
			}
			if (count == n) {
				return true;
			}
		}
		return false;
	}
}
