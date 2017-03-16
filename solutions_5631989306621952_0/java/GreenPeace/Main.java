import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Comparator;
import java.util.Iterator;
import java.util.Locale;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.TreeMap;

public class Main {

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(new FileInputStream("input.txt"))){
			scanner.useLocale(Locale.ENGLISH);
			BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
			int tests = scanner.nextInt();
			for (int i = 0; i < tests; i++) {
				String word = scanner.next();
				Map<Character, Integer> letters = new TreeMap<>(
						new Comparator<Character>() {
							@Override
							public int compare(Character o1, Character o2) {
								return Character.compare(o2, o1);
							}
							
						}
				);
				for (int j = 0; j < word.length(); j++) {
					if (!letters.containsKey(word.charAt(j))) {
						letters.put(word.charAt(j), j);
					}
				}
				int[] usedLetters = new int[word.length()];
				Iterator<Entry<Character, Integer>> iter = letters.entrySet().iterator();
				Entry<Character, Integer> entry = iter.next();
				Character topChar = entry.getKey();
				int position = entry.getValue();
				StringBuilder prefix = new StringBuilder();
				StringBuilder suffix = new StringBuilder();
				for (int j = word.length() -1; j >= 0; j--) {
					char currentChar = word.charAt(j);
					if (word.charAt(j) == topChar.charValue()) {
						prefix.append(currentChar);
					}
					else {
						suffix.insert(0, currentChar);
					}
					if (j == position) {
						while(iter.hasNext()) {
							entry = iter.next();
							topChar = entry.getKey();
							position = entry.getValue();
							if (position < j) {
								break;
							}
						}
					}
				}
				out.write("Case #" + (i + 1) + ": " + prefix.toString() + suffix.toString() + "\n");
			}
			out.close();
		} catch (FileNotFoundException e) {
			// ????
		} catch (IOException e) {
			// ????
		}
	}
}