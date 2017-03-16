import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
import java.util.TreeSet;

public class FairSquare {

	private static TreeSet<Long> set;

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		generate();
		Scanner reader = new Scanner(System.in);
		FileWriter fstream = new FileWriter("clarge.txt");
		BufferedWriter out = new BufferedWriter(fstream);
		int T = reader.nextInt();
		for (int i = 1; i <= T; i++) {
			long a = reader.nextLong(), b = reader.nextLong();
			long result = 0;
			result += set.headSet(b, true).size();
			result -= set.headSet(a).size();
			System.out.println("Case #" + i + ": " + result);
			out.write("Case #" + i + ": " + result);
			out.newLine();
		}
		out.flush();
		out.close();

	}

	private static void generate() {
		set = new TreeSet<Long>();
		allPalindromic((long) Math.pow(10, 9));
	}

	public static boolean isPalindromic(String s) {
		for (int i = 0; i < s.length() / 2; i++) {
			if (s.charAt(i) != s.charAt(s.length() - 1 - i))
				return false;
		}
		return true;
	}

	public static void allPalindromic(long limit) {

		for (long i = 1; i <= 9 && i <= limit; i++) {
			tryAddFairAndSquare(i);
		}

		boolean cont = true;
		for (long i = 1; cont; i++) {
			StringBuffer rev = new StringBuffer("" + i).reverse();
			cont = false;
			for (String d : "0123456789".split("")) {
				long n = Long.parseLong("" + i + d + rev);
				if (n <= limit) {
					cont = true;
					tryAddFairAndSquare(n);
				}
			}
		}
	}

	private static void tryAddFairAndSquare(long i) {
		long sq = i * i;
		String s = "" + sq;
		if (isPalindromic(s)) {
			set.add(sq);
		}
	}
}
