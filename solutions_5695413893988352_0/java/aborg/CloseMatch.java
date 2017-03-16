/*
 * 
 */
package codejam2016.round1b.b;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Collection;
import java.util.HashSet;
import java.util.Set;

/**
 *
 * @author Gabor Bakos
 */
public class CloseMatch {
	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		String lineSep = System.getProperty("line.separator");
		try (BufferedReader br = new BufferedReader(
				args.length > 0 ? new FileReader(args[0]) : new InputStreamReader(System.in));
				Writer out = new BufferedWriter(
						args.length > 1 ? new FileWriter(args[1]) : new OutputStreamWriter(System.out))) {
			int numCases = Integer.parseInt(br.readLine().trim());
			for (int i = 1; i <= numCases; ++i) {
				String[] parts = br.readLine().split(" ");
				out.write("Case #" + i + ": " + result(parts[0], parts[1]) + lineSep);
			}
		}
	}
	private static String result(String c, String j) {
		int minDiff = Integer.MAX_VALUE;
		String minOptC = Integer.toString(Integer.MAX_VALUE), minOptJ = Integer.toString(Integer.MAX_VALUE);
		Collection<String> optionsC = options(c);
		Collection<String> optionsJ = options(j);
		for (final String optC : optionsC) {
			for (final String optJ: optionsJ) {
				int diff = Math.abs(Integer.parseInt(optC) - Integer.parseInt(optJ));
				if (diff < minDiff) {
					minOptC = optC;
					minOptJ = optJ;
					minDiff = diff;
				} else if (diff == minDiff) {
					if (minOptC.compareTo(optC) > 0) {
						minOptC = optC;
						minOptJ = optJ;
					}
					if (minOptC.equals(optC) && minOptJ.compareTo(optJ) > 0) {
						minOptJ = optJ;
						minOptC = optC;
					}
				}
			}
		}
		return minOptC + " " + minOptJ;
	}

	private static Collection<String> options(String c) {
		Set<String> ret = new HashSet<>();
		options(c, ret);
		return ret;
	}
	private static void options(String c, Set<String> ret) {
		if (c.contains("?")) {
			for (char ch = '0'; ch <= '9'; ++ch) {
				options(c.replaceFirst("\\?", String.valueOf(ch)), ret);
			}
		} else {
			ret.add(c);
		}
	}
	private static String resultWrong(String c, String j) {
		if (c.equals(j) || isAllQ(j)) {
			String res = c.replace('?', '0');
			return res + " " + res;
		}
		if (isAllQ(c)) {
			String res = j.replace('?', '0');
			return res + " " + res;
		}
		c = '0' + c + '0';
		j = '0' + j + '0';
//		StringBuilder cb = new StringBuilder(c), jb = new StringBuilder(j);
//		fixAlternating(cb, jb);
//		c = cb.toString();
//		j = jb.toString();
		for (int i = 1; i < c.length() - 1; ++i) {
			int cMinusJSign = (int) Math.signum(c.charAt(i - 1) - j.charAt(i - 1)); 
			char nextJ = j.charAt(i + 1);
			char nextC = c.charAt(i + 1);
			int nextSign = (int) Math.signum(nextC - nextJ);
			int q = 1;
			while (nextJ == '?' && nextC == '?') {
				nextJ = j.charAt(i + q);
				nextC = j.charAt(i +q);
				++q;
			}
			if (nextC == '?' || nextJ == '?') {
				nextSign = 0;
			}
			if (nextSign != 0 && Math.abs(nextC - nextJ) < 5) {
				nextSign = 0;
			}
			if (c.charAt(i) == '?') {
				if (j.charAt(i) == '?') {
					switch (cMinusJSign) {
					case -1:
						c = c.replaceFirst("\\?", "9");
						j = j.replaceFirst("\\?", "0");
						break;
					case 0:
						c = c.replaceFirst("\\?", nextSign == 0 || nextJ <= '5' ?"0" : "1");
						j = j.replaceFirst("\\?", nextSign == 0 || nextC <= '5' ?"0" : "1");
						break;
					case 1:
						j = j.replaceFirst("\\?", "9");
						c = c.replaceFirst("\\?", "0");
						break;
					}
				} else {
					c = c.replaceFirst("\\?", String.valueOf(j.charAt(i)));
				}
			} else if (j.charAt(i) == '?'){
				j = j.replaceFirst("\\?", String.valueOf(c.charAt(i)));
			}
		}
		return c.substring(1, c.length() - 1) + " " + j.substring(1, j.length() - 1);
	}

//	private static void fixAlternating(StringBuilder cb, StringBuilder jb) {
//		for (int i = 1; i < cb.length() - 1; ++i) {
//			if (cb.charAt(i) != '?' && jb.charAt(i) == '?' && cb.charAt(i + 1) == '?' && jb.charAt(i + 1) != '?') {
//				cb.setCharAt(i, jb.charAt(i + 1) < );
//			}
//			if (cb.charAt(i) == '?' && jb.charAt(i) != '?' && cb.charAt(i + 1) != '?' && jb.charAt(i + 1) == '?') {
//				cb.setChar(i, '0');
//				jb.setCharAt(i, cb.charAt(i + 1) > 5 ? '1');
//			}
//		}
//	}

	private static boolean isAllQ(String c) {
		boolean hasOther = false;
		for (int i = c.length(); i -->0;) {
			hasOther |= c.charAt(i) != '?';
		}
		return !hasOther;
	}


}
