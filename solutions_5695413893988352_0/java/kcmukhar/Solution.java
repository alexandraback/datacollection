import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.regex.Pattern;
import java.util.regex.PatternSyntaxException;

public class Solution {
	static ArrayList<String> allStrings = new ArrayList<>();

	public static void main(String[] args) {

		try (Scanner in = new Scanner(new FileInputStream(args[0] + ".in"));
				BufferedWriter out = new BufferedWriter(new FileWriter(args[0] + ".out"))) {

			int T = in.nextInt();
			in.nextLine();
			for (int t = 0; t < T; t++) {
				String S[] = in.nextLine().split(" ");
				String C = S[0].replace("?", ".");
				String J = S[1].replace("?", ".");
				int length = C.length();
				printAllKLength(new char[] { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' }, length);
				String answer = "";
				String c0 = "";
				String sc0 = "";
				String j0 = "";
				String sj0 = "";
				int c = -1;
				int j = -1;
				int diff = Integer.MAX_VALUE;
				for (String s : allStrings) {
					boolean cMatches = Pattern.matches(C, s);
					boolean jMatches = Pattern.matches(J, s);
					if (cMatches && jMatches) {
						answer = s + " " + s;
						break;
					}
					if (cMatches) {
						c = Integer.parseInt(s);
						sc0 = s;
					}
					if (jMatches) {
						j = Integer.parseInt(s);
						sj0 = s;
					}
					if (c != -1 && j != -1) {
						int delta = Math.abs(c - j);
						if (delta < diff) {
							diff = delta;
							c0 = sc0;
							j0 = sj0;
						}
					}
				}
				if (answer.equals("")) {
					answer = c0 + " " + j0;
				}

				String str = "Case #%d: %s\n";
				System.out.printf(str, t + 1, answer);
				out.write("Case #" + (t + 1) + ": " + answer);
				out.newLine();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	// http://www.geeksforgeeks.org/print-all-combinations-of-given-length/
	// The method that prints all possible strings of length k. It is
	// mainly a wrapper over recursive function printAllKLengthRec()
	static void printAllKLength(char set[], int k) {
		int n = set.length;
		printAllKLengthRec(set, "", n, k);
	}

	// http://www.geeksforgeeks.org/print-all-combinations-of-given-length/
	// The main recursive method to print all possible strings of length k
	static void printAllKLengthRec(char set[], String prefix, int n, int k) {

		// Base case: k is 0, print prefix
		if (k == 0) {
			allStrings.add(prefix);
			return;
		}

		// One by one add all characters from set and recursively
		// call for k equals to k-1
		for (int i = 0; i < n; ++i) {

			// Next character of input added
			String newPrefix = prefix + set[i];

			// k is decreased, because we have added a new character
			printAllKLengthRec(set, newPrefix, n, k - 1);
		}
	}
}
