import java.io.*;
import java.math.*;
import java.util.*;

public class FairAndSquare {
	public static void main (String[] args) {
		// pre-process: find all fair and square and store in an array
		ArrayList<BigInteger> allFairSquare = new ArrayList<BigInteger>();
		findAllFairSquare(allFairSquare);
		try {
			BufferedReader br = new BufferedReader(new FileReader("C-large-1.in"));
			// read T
			int T = Integer.parseInt(br.readLine());
			for (int i = 1; i <= T; i++) {
				// read A and B
				String temp = br.readLine();
				String[] split = temp.split("\\s+");
				BigInteger A = new BigInteger(split[0]);
				BigInteger B = new BigInteger(split[1]);
				// find all fair and square between A and B
				int s = 0;
				while (allFairSquare.get(s).compareTo(A) < 0)
					s++;
				int f = s;
				while (allFairSquare.get(f).compareTo(B) <= 0) {
					f++;
					if(allFairSquare.size() == f)
						break;
				}
				int nFairSquare = f - s;
				System.out.println("Case #" + i + ": " + nFairSquare);
			}
			br.close();
		} catch (IOException ioe) {
			;
		}
	}
	
	public static void findAllFairSquare (ArrayList<BigInteger> allFairSquare) {
		int i = 0;
		BigInteger i2 = new BigInteger("0");
		while (i2.compareTo(new BigInteger("100000000000000")) <= 0) {
			// check if fair and square
			if (isPalindrome(i) && isPalindrome(i2)) {
					allFairSquare.add(i2);
			}
			// increment
			i++;
			i2 = new BigInteger(Integer.toString(i)).multiply(new BigInteger(Integer.toString(i)));
		}
	}
	
	public static boolean isPalindrome (int n) {
		if (n == reverse(n))
			return true;
		else
			return false;
	}
	
	public static boolean isPalindrome (BigInteger n) {
		if (n.compareTo(reverse(n)) == 0)
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
	
	public static BigInteger reverse (BigInteger n) {
		String temp = n.toString();
		String result = new String();
		for (int i = 0; i < temp.length(); i++) {
			result += temp.charAt(temp.length() - i - 1);
		}
		return new BigInteger(result);
	}
}
