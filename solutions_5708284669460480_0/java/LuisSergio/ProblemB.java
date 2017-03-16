import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Locale;
import java.util.Random;
import java.util.Scanner;
import java.util.Set;
import java.util.regex.Pattern;

public class ProblemB {	

	private static BufferedWriter writer;
	private static Scanner scanner;
	

private static long k, l, s;
private static String keyboard;
private static String targetWord;
private static double bananasToKeep;

	private static void processCase(int i) throws IOException {
		readInput();
		solve();
		outputResults(i);
	}

	private static void outputResults(int testCase) throws IOException {
		String out = String.format("Case #%d: %f", testCase + 1, bananasToKeep);
		System.err.println(out);
		writer.write(out);
		writer.newLine();
	}

	private static void solve() {
		List<String> allPossibleSequences = findPossibleSequences(s, keyboard.toCharArray());
		long bestScore = 0;
		long sumScore = 0;
		for (String s : allPossibleSequences) {
			long seqScore = countTargets(s);
			if (seqScore > bestScore) {
				bestScore = seqScore;
			}
			sumScore += seqScore;
		}
		double qty = allPossibleSequences.size();
		double avgScore = sumScore/qty;
		bananasToKeep = bestScore - avgScore;
	}

	private static List<String> findPossibleSequences(long count, char[] keys) {
		if (keys.length == 0) {
			return Collections.emptyList();
		}
		if (count == 1) {
			List<String> result = new ArrayList<String>();
			for (char k : keys) {
				result.add(String.valueOf(k));
			}
			return result;
		}
//		if (keys.length == 1) {
//			StringBuilder sb = new StringBuilder();
//			for(int i =0 ; i < count; i++) sb.append(keys[0]);
//			return Collections.singletonList(sb.toString());
//		}
		List<String> result = new ArrayList<String>();
		for(int i = 0; i < keys.length; i++) {
			char selected = keys[i];
			List<String> subseqs = findPossibleSequences(count-1, keys);
			for (String subseq : subseqs) {
				String s = String.valueOf(selected) + subseq;
				result.add(s);
			}
		}
		return result;
	}

	private static long countTargets(String word) {
		long result = 0;
		int index = word.indexOf(targetWord, 0);
		while (index >= 0) {
			result++;
			index = word.indexOf(targetWord, index+1);
		}
		return result;
	}

	static Random random = new Random(System.currentTimeMillis());
	private static Pattern p;
	
	private static String simulate(char[] keys) {
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < s; i++) {
			int index = random.nextInt(keys.length);
			sb.append(keys[index]);
		}
		return sb.toString();
	}

	private static void readInput() {
		k = scanner.nextLong();
		l = scanner.nextLong();
		s = scanner.nextLong();
		keyboard = scanner.next();
		targetWord = scanner.next();
		p = Pattern.compile(targetWord);

	}

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		Path input = Paths.get("input.in");
		Path output = Paths.get("output.txt");
		scanner = new Scanner(input);
		writer = Files.newBufferedWriter(output);
		int testCases = scanner.nextInt();
		for (int i = 0; i < testCases; i++) {
			processCase(i);
		}
		writer.close();

	}

}
