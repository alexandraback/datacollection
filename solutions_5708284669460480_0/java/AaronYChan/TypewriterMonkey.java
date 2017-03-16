import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class TypewriterMonkey {
	
	static ArrayList<String> possible;
	static HashSet<Character> unique;
	
	public static void main (String [] args) throws IOException {
		
		String root = "B-small-attempt4";
		String fileName = "C:\\Users\\Aaron\\Downloads\\" + root + ".in";
		BufferedReader reader = new BufferedReader (new FileReader(new File(fileName)));
		int nTestCases = Integer.parseInt(reader.readLine());
		ArrayList<String> out = new ArrayList<String>();
		
		
		
		
		for (int t = 0; t < nTestCases; t++) {
			
			int maxMatches = 0;
			String maxOcc = "NO MATCHES";
			
			possible = new ArrayList<String>();
			String[] bn = reader.readLine().split(" ");
			
			int len = Integer.parseInt(bn[2]);
			String keyboard = reader.readLine();
			String target = reader.readLine();
			
			HashMap<Character, Double> p = getProbabilities(keyboard);
			unique = new HashSet<Character>();
			for (char c : keyboard.toCharArray()) unique.add(c);
			
			// Generate all combinations of what the monkey could type
			solve("", len, target);
			
			double expected = 0;
			for (String s : possible) {
				int numMatches = findAll(s, target);
				if (numMatches == 0) continue;
				
				if (maxMatches < numMatches) {
					maxMatches = numMatches;
					maxOcc = s;
				}
				
				double probability = 1;
				for (char c : s.toCharArray()) {
					probability *= p.get(c);
				}
				//System.out.println(s + ":" + numMatches + ": p=" + probability);
				expected += probability * numMatches;
			}
			
			//Calculate worst case
			int worstCaseBananas = maxMatches;
			/*if (!isPossible(target)) worstCaseBananas = 0;
			else {
				StringBuilder worstCase = new StringBuilder(target);
				String suffix = "";
				for (int i = 0; i < target.length() / 2; i++) {
					if (target.charAt(i) == target.charAt(target.length() - i - 1)) {
						suffix += target.charAt(i);
					}
					else break;
				}
				String appendMe = null;
				if (suffix.length() == 0 || suffix.length() == target.length()) {
					appendMe = target;
				}
				else {
					System.out.println("USING NEW SYSTEM");
					appendMe = target.substring(suffix.length());
				}
				System.out.println("Suffix: " + suffix);
				System.out.println("Target: " + target);
				System.out.println("Append me: " + appendMe);
				System.out.println("Max length: " + len);
				System.out.println("Max matches: " + maxMatches);
				while (worstCase.length() <= len) {
					worstCase.append(appendMe);
				}
				String worst = worstCase.toString().substring(0, len);
				worstCaseBananas = findAll(worst, target);
				System.out.println("Worst case: " + worstCaseBananas + " for worst string: " + worst + " because of target " + target);
			}*/
			
			System.out.println("Maximum matches: " + maxMatches + " for string: " + maxOcc);
			double ans = worstCaseBananas - expected;
			
			System.out.println("CASE " + (t + 1) + ": " + ans);
			out.add("Case #" + (t+1) + ": " + ans);
			System.out.println("-----------------");
		}
		
		PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("C:\\Users\\Aaron\\Downloads\\"+ root + "-SOL.out")));
		for (String s : out) {
			writer.write(s + "\n");
		}
		
		writer.close();
		reader.close();
	}
	
	public static boolean isPossible (String t) {
		for (char c : t.toCharArray()) {
			if (!unique.contains(c)) return false;
		}
		return true;
	}
	
	public static int findAll (String s, String target) {
		int numMatches = 0;
		int start = 0;
		int lastIndex = -1;
		int ix = s.indexOf(target, start);
		while (ix != -1) {
			if (ix != lastIndex) numMatches++;
			start += 1;
			lastIndex = ix;
			ix = s.indexOf(target, start);
		}
		return numMatches;
	}
	
	public static void solve (String s, int L, String t) {
		if (s.length() == L) {
			possible.add(s); 
			return;
		}
		
		for (char c : unique) solve(s + c, L, t);
	}
	
	public static HashMap<Character, Double> getProbabilities (String s) {
		HashMap<Character, Double> numOccurrences = new HashMap<Character, Double>();
		for (char c : s.toCharArray()) {
			if (numOccurrences.containsKey(c)) {
				numOccurrences.put(c, numOccurrences.get(c) + 1);
			}
			else {
				numOccurrences.put(c, 1.0);
			}
		}
		
		for (Character key : numOccurrences.keySet()) {
			numOccurrences.put(key, numOccurrences.get(key) / (double) s.length());
		}
		return numOccurrences;
	}
}
