import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class FairAndSquareLarge1 {

	private static final String inputFilePath = "Input/C-large-1.in";
	private static final int UPPERLIMIT = 10000000;
	private static List<BigInteger> FAS = new ArrayList<BigInteger>();
	private static Set<BigInteger> FASSet = new HashSet<BigInteger>();
	
	private static int count(BigInteger X) {
		int ret = 0;
		for (BigInteger fas : FAS)
			if (fas.compareTo(X) > 0)
				break;
			else
				ret ++;
		return ret;
	}
	
	private static int countLess(BigInteger X) {
		int ret = 0;
		for (BigInteger fas : FAS)
			if (fas.compareTo(X) >= 0)
				break;
			else
				ret ++;
		return ret;
	}
	
	private static int solve(BigInteger A, BigInteger B) {
		int ret = 0;
		ret = count(B) - countLess(A);
		return ret;
	}
	
	private static boolean isPalindrome(int x) {
		char[] bits = String.valueOf(x).toCharArray();
		int len = bits.length;
		for (int i = 0; i < len / 2; i ++)
			if (bits[i] != bits[len - 1 - i])
				return false;
		return true;
	}
	
	private static boolean isPalindrome(BigInteger x) {
		char[] bits = String.valueOf(x).toCharArray();
		int len = bits.length;
		for (int i = 0; i < len / 2; i ++)
			if (bits[i] != bits[len - 1 - i])
				return false;
		return true;
	}
	
	private static void init() {
		for (int i = 1; i <= UPPERLIMIT; i ++) 
			if (isPalindrome(i)) {
				BigInteger num = BigInteger.valueOf((long) i);
				BigInteger square = num.multiply(num);
				if (isPalindrome(square)) {
					FAS.add(square);
					FASSet.add(square);
				}
			}
	}
	
	/**
	 * Good Luck, Wash!
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		init();		
		PrintWriter out = new PrintWriter(new FileWriter("Output/output.txt")); 
		BufferedReader br = new BufferedReader(new FileReader(inputFilePath)); 
		int T = Integer.parseInt(br.readLine());
		for (int i = 1; i <= T; i ++) {
			String[] parts = br.readLine().split(" ");
			BigInteger A = new BigInteger(parts[0]);
			BigInteger B = new BigInteger(parts[1]);
			out.println(String.format("Case #%d: %d", i, solve(A, B)));
		}
		br.close();
		out.close();
	}

}
