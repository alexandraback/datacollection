import java.io.*;

public class FairAndSquare {
	public static void main (String[] args) {
		try {
			BufferedReader br = new BufferedReader(new FileReader("C-small-attempt0.in"));
			// read T
			int T = Integer.parseInt(br.readLine());
			for (int i = 1; i <= T; i++) {
				// read A and B
				String temp = br.readLine();
				String[] split = temp.split("\\s+");
				int A = Integer.parseInt(split[0]);
				int B = Integer.parseInt(split[1]);
				// find fair and square
				System.out.println("Case #" + i + ": " + findFairSquare(A, B));
			}
			br.close();
		} catch (IOException ioe) {
			;
		}
	}
	
	public static int findFairSquare (int A, int B) {
		int count = 0;
		int i = 0;
		while (true) {
			if (i * i < A);
			else if (i * i > B)
				return count;
			else
				if (isPalindrome(i) && isPalindrome(i * i))
					count++;
			i++;
		}
	}
	
	public static boolean isPalindrome (int n) {
		if (n == reverse(n))
			return true;
		else
			return false;
	}
	
	public static int reverse (int n) {
		int result = 0;
		while (n != 0) {
			result = result * 10 + (n % 10);
			n /= 10;
		}
		return result;
	}
}
