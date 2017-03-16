package codejam.tongues;

import java.util.HashMap;
import java.util.Map;

public class TongueSolver {

	Map<String, String> dict = new HashMap<String, String>();

	public TongueSolver() {
		//translate sample
		String google = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jvqz";
		String englsh = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give upzq";

		char[] gChar = google.toCharArray();
		char[] eChar = englsh.toCharArray();
		int n = gChar.length;

		for (int i = 0; i < n; i++) {
			dict.put("" + gChar[i], "" + eChar[i]);
		}
	}

	public String translate(String s) {

		String ans = "";

		char[] chars = s.toCharArray();
		for (char c : chars) {
			ans += dict.get(Character.toString(c));
		}

		return ans;

	}
}
