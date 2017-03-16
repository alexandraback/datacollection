import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;

public class Pogo {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader(new File(
				"/Users/narok119/Desktop/B-small-attempt2.in")));
		int caseCount = 1;
		String txt = reader.readLine();
		while ((txt = reader.readLine()) != null) {
			String result = "";
			int x = Integer.parseInt(txt.split(" ")[0]);
			int y = Integer.parseInt(txt.split(" ")[1]);
			if (x > 0) {
				result += repeat("EW", x);
			} else if (x < 0) {
				result += repeat("WE", x);
			}
			if (y > 0) {
				result += repeat("SN", y);
			} else if (y < 0) {
				result += repeat("NS", y);
			}
			System.out.println("Case #" + caseCount++ + ": " + result);
		}

	}

	private static String repeat(String string, int x) {
		if (x < 0) {
			x = x * -1;
		}
		StringBuilder sBuilder = new StringBuilder();
		for (int i = 0; i < x; i++) {
			sBuilder.append(string);
		}
		if (string.startsWith("S") || string.startsWith("N")) {
			return sBuilder.toString();
		}
		return sBuilder.substring(0, sBuilder.length() - 1);
	}
}
