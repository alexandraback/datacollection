package codejam.round1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

public class ProblemA {
	public static void main(String[] args) throws Exception {
		Map<String, String> m = new HashMap<String, String>();
		m.put("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
		m.put("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
		m.put("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");

		Map<String, String> mappings = new HashMap<String, String>();
		mappings.put("z", "q");
		mappings.put("q", "z");

		Set<Entry<String, String>> entrySet = m.entrySet();
		for (Entry<String, String> entry : entrySet) {
			String key = entry.getKey();
			String value = entry.getValue();

			int length = key.length();
			for (int i = 0; i < length; i++) {
				mappings.put("" + key.charAt(i), "" + value.charAt(i));
			}
		}

		BufferedReader reader = new BufferedReader(new FileReader(args[0]));
		PrintStream out = new PrintStream(args[1]);

		int testsCount = Integer.parseInt(reader.readLine());
		for(int test = 1; test<=testsCount;test++) {
			String googlerString = reader.readLine();
			int stringLength = googlerString.length();
			StringBuffer englishString = new StringBuffer();
			for(int i=0;i<stringLength;i++) {
				englishString.append(mappings.get("" + googlerString.charAt(i)));
			}

			out.println(String.format("Case #%s: %s", test, englishString));
		}

		out.close();
		reader.close();
	}

}
