import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		char[] translateTable = getTranslateTable();
		Scanner sc = new Scanner(System.in);
		int t = Integer.parseInt(sc.nextLine());
		for (int ti = 0; ti < t; ti++) {
			String s = sc.nextLine();
			StringBuffer sb = new StringBuffer();
			for (int i = 0; i < s.length(); i++) {
				if (Character.isWhitespace(s.charAt(i)))
					sb.append(s.charAt(i));
				else
					sb.append(translateTable[s.charAt(i) - 'a']);
			}
			System.out.printf("Case #%d: %s%n", ti + 1, sb.toString());
		}
	}

	private static char[] getTranslateTable() {
		char[] table = new char[26];
		String[] ins = { "ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
				"de kr kd eoya kw aej tysr re ujdr lkgc jv" };
		String[] outs = { "our language is impossible to understand", "there are twenty six factorial possibilities",
				"so it is okay if you want to just give up" };
		for (int i = 0; i < ins.length; i++) {
			String s = ins[i];
			String t = outs[i];
			for (int j = 0; j < s.length(); j++) {
				if (Character.isWhitespace(s.charAt(j)))
					continue;
				if (table[s.charAt(j) - 'a'] != 0) {
					assert t.charAt(j) == table[s.charAt(j) - 'a'];
				} else {
					table[s.charAt(j) - 'a'] = t.charAt(j);
				}
			}
		}
		table['z' - 'a'] = 'q';
		table['q' - 'a'] = 'z';
		return table;
	}
}
