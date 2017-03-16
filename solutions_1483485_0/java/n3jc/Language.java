import java.io.IOException;
import java.io.OutputStreamWriter;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Formatter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Language {

	private static Map<Character, Character> reverseMappingDic = new HashMap<>();

	static {
		reverseMappingDic.put('y', 'a');
		reverseMappingDic.put('e', 'o');
		reverseMappingDic.put('q', 'z');
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Path path = Paths.get(args[0]);
		Path file = Paths.get("language.txt");
		train("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
		train("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
		train("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");
		posttrain();
		int numberOfCases;
		try (Scanner scanner = new Scanner(Files.newInputStream(path), "UTF-8");
				OutputStreamWriter output = new OutputStreamWriter(Files.newOutputStream(file), "UTF-8")) {
			Formatter f = new Formatter(output);
			numberOfCases = scanner.nextInt();
			scanner.nextLine();
			for (int i = 1; i <= numberOfCases; i++) {
				String googlerese = scanner.nextLine();
				String result = solve(googlerese);
				f.format("Case #%d: %s\n", i, result);
			}
			f.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private static void train(String googlerese, String clearText) {
		for (int i = 0; i < googlerese.length(); i++) {
			char g = googlerese.charAt(i);
			char c = clearText.charAt(i);
			if (g != ' ') {
				if (reverseMappingDic.containsKey(g) && reverseMappingDic.get(g) != c) {
					throw new IllegalArgumentException("Inconsistency detected");
				}
				if (!reverseMappingDic.containsKey(g)) {
					reverseMappingDic.put(g, c);
				}
			} else if (g != c) {
				throw new IllegalArgumentException("Inconsistency detected");
			}
		}
	}
	
	private static void posttrain() {
		char missingKey = '\0';
		char missingValue = '\0';
		Set<Character> characters = new HashSet<>(reverseMappingDic.values());
		for (int i = 97; i <=122; i++) {
			if (!reverseMappingDic.containsKey((char)i)) {
				missingKey = (char)i;
			}
			if (!characters.contains((char)i)) {
				missingValue = (char)i;
			}
		}
		if (missingKey != '\0') {
			reverseMappingDic.put(missingKey, missingValue);
		}
	}

	private static String solve(String googlerese) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < googlerese.length(); i++) {
			char g = googlerese.charAt(i);
			if (g == ' ') {
				sb.append(' ');
			} else {
				if (!reverseMappingDic.containsKey(g)) {
					throw new IllegalArgumentException("No mapping present");
				}
				sb.append(reverseMappingDic.get(g));
			}
		}
		return sb.toString();
	}
}
