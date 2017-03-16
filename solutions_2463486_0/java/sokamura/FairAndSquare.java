import java.io.File;
import java.util.Scanner;


public class FairAndSquare {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new File("C-small.in"));

		int caseNum = s.nextInt();
		for (int t = 1; t <= caseNum; ++t) {
			long A = s.nextLong();
			long B = s.nextLong();

			System.out.println("Case #" + t + ": " + FairAndSquare.count(A, B));
		}
	}

	public static long count(long A, long B) {
		long countNum = 0;

		for(long i=1; i*i<=B; ++i) {
			if(i*i < A) {
				continue;
			}
			if(FairAndSquare.isPalindrome(String.valueOf(i))
					&& FairAndSquare.isPalindrome(String.valueOf(i*i))){
				//System.out.println(i + "," + i*i);
				countNum++;
			}
		}

		return countNum;
	}

	public static boolean isPalindrome(String str) {
		for(int i=0;i<=str.length()/2; ++i) {
			if(str.charAt(i) != str.charAt(str.length()-1-i)) {
				return false;
			}
		}

		return true;
	}
}
