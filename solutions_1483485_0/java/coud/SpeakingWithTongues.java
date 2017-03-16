import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Map;

import com.google.common.collect.ImmutableMap;
import com.google.common.collect.Maps;
import com.google.common.io.LineReader;

public class SpeakingWithTongues {

	static Map<String, String> sentences = ImmutableMap
			.<String, String> builder()
			.put("ejp mysljylc kd kxveddknmc re jsicpdrysi",
					"our language is impossible to understand")
			.put("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
					"there are twenty six factorial possibilities")
			.put("de kr kd eoya kw aej tysr re ujdr lkgc jv",
					"so it is okay if you want to just give up")
			.put("y qee", "a zoo").build();

	static Map<Character, Character> map = Maps.newHashMap();

	public static void main(String[] args) throws NumberFormatException,
			IOException {

		for (Map.Entry<String, String> entry : sentences.entrySet()) {
			for (int i = 0; i < entry.getKey().length(); i++) {
				map.put(entry.getKey().charAt(i), entry.getValue().charAt(i));
			}
		}

		// System.out.println(map.size());
		for (char c = 'a'; c <= 'z'; c++) {
			if (!map.containsKey(c)) {
				for (char r = 'a'; r <= 'z'; r++) {
					if (!map.values().contains(r)) {
						// System.out.println("adding: " + c + " -> " + r);
						map.put(c, r);
					}
				}
			}
		}

		LineReader lineReader = new LineReader(new FileReader(args[0]));
		FileWriter out = new FileWriter(args[0] + "-out.txt");

		int t = Integer.parseInt(lineReader.readLine());
		for (int counter = 1; counter <= t; counter++) {
			String result = compute(lineReader.readLine());
			out.write(String.format("Case #%d: %s\n", counter, result));
		}
		out.close();
	}

	 private static String compute(String input) {
		 StringBuffer sb = new StringBuffer();
		 for (int i = 0; i < input.length(); i++) {
			 sb.append(map.get(input.charAt(i)));
		 }
		 return sb.toString();
	 }

}
