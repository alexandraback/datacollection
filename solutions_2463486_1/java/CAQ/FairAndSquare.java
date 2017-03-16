package gcj2013;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class FairAndSquare {
	static String PATH = "/home/caq/Desktop/gcj2013/qual/", PROBLEM = "C",
			SIZE = "large-1", ATTEMPT = "0";
	static ArrayList<Long> PALINDROMES;

	static boolean isPalindrome(String s) {
		int l = s.length();
		for (int i = 0; i < l / 2; i++) {
			if (s.charAt(i) != s.charAt(l - i - 1))
				return false;
		}
		return true;
	}

	static void generatePalindromes() {
		// long upperbound = new Double(Math.sqrt(Long.MAX_VALUE)).longValue();
		long upperbound = 10000000;
		long num = 1;
		PALINDROMES = new ArrayList<Long>();
		while (num <= upperbound) {
			if (isPalindrome(num + ""))
				PALINDROMES.add(num);
			num++;
		}
		System.out.println(PALINDROMES.size());
		// System.out.println(PALINDROMES);

		PALINDROMES = new ArrayList<Long>();
		MyNumber mynum = new MyNumber(1);
		while (mynum.length() <= 7) {
			PALINDROMES.add(new Long(mynum.toString()));
			mynum = mynum.nextPalindrome();
		}
		System.out.println(PALINDROMES.size());
		// System.out.println(PALINDROMES);
	}

	public static void main(String[] args) throws IOException {
		String filename = PATH + PROBLEM + "-" + SIZE;
		if (SIZE.equals("small"))
			filename += "-attempt" + ATTEMPT;
		BufferedReader br = new BufferedReader(new FileReader(filename + ".in"));
		BufferedWriter bw = new BufferedWriter(
				new FileWriter(filename + ".out"));
		int total = new Integer(br.readLine());
		for (int i = 0; i < total; i++) {
			// each case
			String[] AB = br.readLine().trim().split(" ");
			MyNumber A = new MyNumber(AB[0]), B = new MyNumber(AB[1]);

			MyNumber rootA = A.sqrtCeil(), rootB = B.sqrtFloor();

			long result = 0;

			MyNumber rootNum = new MyNumber(rootA.toString());
			if (!rootNum.isPalindrome())
				rootNum = rootNum.nextPalindrome();
			while (rootNum.less(rootB, true)) {
				MyNumber sq = rootNum.square();
				if (sq.isPalindrome()) {
					// System.out.print(rootNum + "\t" + sq);
					// System.out.print("\tPalindrome!");
					// System.out.println();
					result++;
				}
				rootNum = rootNum.nextPalindrome();
			}

			bw.write("Case #" + (i + 1) + ": " + result);
			bw.newLine();
		}

		bw.close();
		br.close();
		System.out.println("Finished.");

		// generatePalindromes();
	}

}
