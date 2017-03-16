package google.codejam;

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import com.google.common.base.Charsets;
import com.google.common.io.Closeables;
import com.google.common.io.Files;

public class SpeakingInTongues {

	public static final int LETTERS_IN_ALPHABET = 26;

	public static void main(String[] args) throws IOException {
		File cwd = new File("C:\\Users\\TaG\\workspace\\CodeJam\\");
		File inputFile = new File(cwd, "input.txt");
		File outputFile = new File(cwd, "output.txt");
		if (outputFile.exists())
			outputFile.delete();
		PrintStream out = null;
		try {
			out = new PrintStream(outputFile);

			Map<Character, Character> charMap = createCharMap();

			List<String> lines = Files.readLines(inputFile, Charsets.UTF_8);
			int cases = Integer.parseInt(lines.remove(0));
			int caseNo = 1;
			for (String line : lines) {
				line = line.toLowerCase();
				StringBuilder sb = new StringBuilder();
				for (int i = 0; i < line.length(); i++) {
					char c = line.charAt(i);
					assert charMap.containsKey(c);
					Character e = charMap.get(c);
					sb.append(e);
				}
				out.printf("Case #%d: %s\n", caseNo, sb);
				System.out.printf("Case #%d: %s\n", caseNo, sb);
				caseNo++;
			} // end for-each lines
		} finally {
			Closeables.closeQuietly(out);
		}
	}

	private static Map<Character, Character> createCharMap() {
		String[] googlerese = { "ejp mysljylc kd kxveddknmc re jsicpdrysi",
				"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
				"de kr kd eoya kw aej tysr re ujdr lkgc jv" };
		String[] english = { "our language is impossible to understand",
				"there are twenty six factorial possibilities",
				"so it is okay if you want to just give up" };
		Map<Character, Character> map = new HashMap<Character, Character>();
		map.put('y', 'a');
		map.put('e', 'o');
		map.put('z', 'q');
		map.put('q', 'z');
		for (int s = 0; s < googlerese.length; s++) {
			String s1 = googlerese[s].toLowerCase();
			String s2 = english[s].toLowerCase();
			assert s1.length() == s2.length();
			for (int i = 0; i < s1.length(); i++) {
				char c1 = s1.charAt(i);
				char c2 = s2.charAt(i);
				Character old = map.put(c1, c2);
				if (old != null) {
					assert old.equals(Character.valueOf(c2));
				}
			}
		}
		//assert map.size() == LETTERS_IN_ALPHABET;
		return map;
	}

}
