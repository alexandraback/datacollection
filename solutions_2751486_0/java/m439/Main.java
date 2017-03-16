import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		String fileName = "A-small-attempt3";
//		 String fileName = "a_sample";

		BufferedReader br = new BufferedReader(new FileReader(fileName + ".in"));
		BufferedWriter bw = new BufferedWriter(
				new FileWriter(fileName + ".out"));

		String line;

		line = br.readLine();
		int T = Integer.parseInt(line);

		for (int i = 1; i <= T; i++) {
			line = br.readLine();
			processLine(line, i, bw);
		}

		br.close();
		bw.close();
	}

	private static void processLine(String line, int tcNumber, BufferedWriter bw)
			throws IOException {
		Scanner sc = new Scanner(line);

		String name = sc.next();
		char nameChars[] = name.toCharArray();
		int n = sc.nextInt();

		ArrayList<Integer> consecutiveConsonants = new ArrayList<Integer>();
		ArrayList<Integer> precedingChars = new ArrayList<Integer>();
		ArrayList<Integer> remainingChars = new ArrayList<Integer>();

		ArrayList<Integer> consecutiveVowels = new ArrayList<Integer>();

		boolean startsWithCons = isConsonant(nameChars[0]);

		int j = 0;
		while (j < nameChars.length) {
			int consonants = 0;
			int curPrecedingChars = j;
			while (j < nameChars.length && isConsonant(nameChars[j])) {
				consonants++;
				j++;
			}

			if (consonants >= n) {
				consecutiveConsonants.add(consonants);
				precedingChars.add(curPrecedingChars);
				remainingChars.add(nameChars.length - j);
			}

			int vowels = 0;
			while (j < nameChars.length && !isConsonant(nameChars[j])) {
				vowels++;
				j++;
			}

			if (vowels > 0) {
				consecutiveVowels.add(vowels);
			}
		}

		System.out.println(n + " " + consecutiveConsonants + ", "
				+ precedingChars + ", " + remainingChars);

		int nValue = 0;

		if (consecutiveConsonants.size() > 0) {
			for (int i = 0; i < nameChars.length; i++) {
				int k;
				for (k = 0; k < consecutiveConsonants.size(); k++) {
					if (precedingChars.get(k) >= i) {
						nValue += nameChars.length - n + 1 - precedingChars.get(k);
						break;
					} else if (precedingChars.get(k) + consecutiveConsonants.get(k) - n >= i) {
						nValue += precedingChars.get(k) + consecutiveConsonants.get(k) - i - n + 1 + remainingChars.get(k); 
						break;
					}
				}
			}

	/*		if (consecutiveConsonants.get(consecutiveConsonants.size() - 1) > n) {
				nValue += consecutiveConsonants.get(consecutiveConsonants
						.size() - 1)
						- n
						+ remainingChars.get(consecutiveConsonants.size() - 1);
			}*/
		}

		/*
		 * for (int i = 0; i < consecutiveConsonants.size(); i++) { int
		 * consConsonants = consecutiveConsonants.get(i); int precChars =
		 * precedingChars.get(i); int remChars = remainingChars.get(i);
		 * 
		 * // #1: substrings that end or start with this string of consecutive
		 * // consonants nValue += (consConsonants - n + 1) * precChars +
		 * remChars;
		 * 
		 * // #2: substrings that start before and end after this string of ccs
		 * nValue += precChars * remChars;
		 * 
		 * // #3: substrings of the current string of ccs while (consConsonants
		 * >= n) { nValue += consConsonants - n + 1; consConsonants--; } }
		 * 
		 * // overlappings for #1 nValue -= (consecutiveConsonants.size() *
		 * (consecutiveConsonants.size() - 1)) / 2;
		 * 
		 * // overlappings for #2 for(int i = 0; i <
		 * consecutiveConsonants.size() - 1; i++) { // for(int ii = i; ii <
		 * consecutiveConsonants.size(); ii++) { int ii = i + 1; int prec1 =
		 * precedingChars.get(i); // ! int prec2 = precedingChars.get(ii); int
		 * rem1 = remainingChars.get(i); int rem2 = remainingChars.get(ii); // !
		 * 
		 * nValue -= (prec1) * (rem2); // } }
		 */

		System.out.println("Case #" + tcNumber + ": " + nValue);
		bw.write("Case #" + tcNumber + ": " + nValue + "\n");

		sc.close();
	}

	private static boolean isConsonant(char c) {
		return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
	}

	/*
	 * private static StarData[] processInput(String line, String fileName)
	 * throws Exception { Scanner sc = new Scanner(line);
	 * 
	 * // BufferedWriter bw = new BufferedWriter( // new FileWriter(fileName +
	 * ".out"));
	 * 
	 * int m; String name; int n;
	 * 
	 * m = sc.nextInt();
	 * 
	 * StarData starData[] = new StarData[m];
	 * 
	 * for (int i = 0; i < m; i++) { name = sc.next(); n = sc.nextInt();
	 * 
	 * starData[i] = new StarData(name, n);
	 * 
	 * for (int j = 0; j < n; j++) { starData[i].appendVal(sc.nextInt()); }
	 * 
	 * // output // bw.write(starData[i].name + " ");
	 * 
	 * // bw.write(starData[i].vals[0] + " "); int prevValue =
	 * starData[i].vals[0]; starData[i].consVal.add(starData[i].vals[0]);
	 * 
	 * int valCount = 1;
	 * 
	 * for (int j = 1; j < n; j++) { if (starData[i].vals[j] == prevValue) {
	 * valCount++; } else { // bw.write(valCount + " " + starData[i].vals[j] +
	 * " "); starData[i].consValNo.add(valCount);
	 * starData[i].consVal.add(starData[i].vals[j]); valCount = 1; prevValue =
	 * starData[i].vals[j]; } } // bw.write(valCount + " ");
	 * starData[i].consValNo.add(valCount); }
	 * 
	 * // bw.close(); sc.close();
	 * 
	 * return starData; }
	 */
}
