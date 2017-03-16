import java.io.File;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

public class FairAndSquare {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new File("C-large1.in"));

		ArrayList<Long> fasArray = new ArrayList<Long>();
		FairAndSquare.makeFairAndSquareArray(fasArray);
		//System.out.println(fasArray.size());
		//System.out.println(fasArray);

		int caseNum = s.nextInt();
		for (int t = 1; t <= caseNum; ++t) {
			long A = s.nextLong();
			long B = s.nextLong();

			System.out.println("Case #" + t + ": " + FairAndSquare.count(A, B, fasArray));
		}
	}

	public static long count(long A, long B, ArrayList<Long> array) {
		long countNum = 0;

		Iterator<Long> it = array.iterator();
		while (it.hasNext()) {
			long n = it.next();
			if (A <= n && n <= B) {
				countNum++;
			}
		}

		return countNum;
	}

	public static boolean isPalindrome(String str) {
		for (int i = 0; i <= str.length() / 2; ++i) {
			if (str.charAt(i) != str.charAt(str.length() - 1 - i)) {
				return false;
			}
		}

		return true;
	}

	public static void makeFairAndSquareArray(ArrayList<Long> array) {
		for (long i = 1; i * i <= Long.valueOf("100000000000000"); ++i) {
			if (FairAndSquare.isPalindrome(String.valueOf(i))
					&& FairAndSquare.isPalindrome(String.valueOf(i * i))) {
				//System.out.println(i + "," + i*i);
				array.add(i * i);
			}
		}
	}
}
