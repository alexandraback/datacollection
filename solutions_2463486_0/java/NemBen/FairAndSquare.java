import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;

public class FairAndSquare {

	private static boolean isPalindrome(BigInteger number) {
		String asString = number + "";
		for (int i = 0; i <= asString.length() / 2; ++i) {
			if (asString.charAt(i) != asString
					.charAt(asString.length() - 1 - i)) {
				return false;
			}
		}
		return true;
	}

	public static void solve(String file) throws Exception {
		ArrayList<BigInteger> palindromeSquare = new ArrayList<BigInteger>();
		for (int i = 1; i < 100; ++i) {
			String forward = i + "";
			String reverse = new StringBuilder(forward).reverse().toString();

			BigInteger p1 = new BigInteger(forward + reverse);
			BigInteger p1Square = p1.multiply(p1);
			if (isPalindrome(p1Square)) {
				palindromeSquare.add(p1Square);
			}

			BigInteger p2 = new BigInteger(forward + reverse.substring(1));
			BigInteger p2Square = p2.multiply(p2);
			if (isPalindrome(p2Square)) {
				palindromeSquare.add(p2Square);
			}
		}

		Collections.sort(palindromeSquare);
		for (BigInteger i : palindromeSquare) {
			System.out.println(i);
		}

		BufferedReader reader = new BufferedReader(new FileReader(new File("./"
				+ file + ".in")));
		BufferedWriter writer = new BufferedWriter(new FileWriter(new File("./"
				+ file + ".out"), false));

		try {
			int num = Integer.parseInt(reader.readLine());

			String[] cols;
			for (int n = 1; n <= num; ++n) {
				cols = reader.readLine().split("\\s");
				BigInteger A = new BigInteger(cols[0]);
				BigInteger B = new BigInteger(cols[1]);

				int posA = Collections.binarySearch(palindromeSquare, A);
				if (posA < 0) {
					posA = -(++posA);
				}

				int posB = Collections.binarySearch(palindromeSquare, B);
				if (posB < 0) {
					posB = -(++posB);
				} else {
					++posB;
				}

				writer.write("Case #" + n + ": " + (posB - posA));
				writer.newLine();
			}
		} finally {
			writer.close();
			reader.close();
		}
	}

	public static void main(String[] args) throws Exception {
		solve("small");
	}

}
