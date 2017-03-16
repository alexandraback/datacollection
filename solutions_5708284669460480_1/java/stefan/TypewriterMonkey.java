import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class TypewriterMonkey {
	public static final String FILENAME = "B-large";

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("src/" + FILENAME
				+ ".in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("src/"
				+ FILENAME + ".out"));
		Scanner sc = new Scanner(in);
		int t = sc.nextInt();
		for (int tt = 1; tt <= t; tt++) {
			int k = sc.nextInt();
			int l = sc.nextInt();
			int s = sc.nextInt();
			char[] keys = sc.next().toCharArray();
			char[] word = sc.next().toCharArray();
			int prefix = minPrefix(word);
			int needed = 1 + (s - l) / prefix;
			Map<Character, Integer> amount = new HashMap<Character, Integer>();
			for (char c : keys) {
				if (!amount.containsKey(c)) {
					amount.put(c, 1);
				} else {
					amount.put(c, amount.get(c) + 1);
				}
			}
			double prob = 1;
			for (int i = 0; i < word.length; i++) {
				if (!amount.containsKey(word[i])) {
					prob = 0;
					needed = 0;
				} else {
					prob *= (double) amount.get(word[i]) / k;
				}
			}
			double exp = (s - l + 1) * prob;
			out.write("Case #" + tt + ": " + (needed - exp) + "\n");
		}
		in.close();
		out.close();
	}

	private static int minPrefix(char[] word) {
		for (int i = 1; i < word.length; i++) {
			boolean ok = true;
			for (int j = 0; ok && j + i < word.length; j++) {
				if (word[j] != word[j + i]) {
					ok = false;
				}
			}
			if (ok) {
				return i;
			}
		}
		return word.length;
	}
}
