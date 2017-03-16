import java.math.BigInteger;
import java.util.ArrayList;
import java.util.BitSet;
import java.util.Scanner;


public class nameSplit {

	/**
	 * @param args
	 */
	public static char[] vows = {'a','e','i','o','u'};
	public static ArrayList<Character> vowList = new ArrayList<Character>();
	
	private static Scanner sc = new Scanner(System.in);
	
	public static void main(String[] args) {
		for (int i = 0; i < vows.length; i++) {
			vowList.add(vows[i]);
		}		
		
		long samples = sc.nextLong();
		for (int j = 0; j <samples;j++)
		{
			String word = sc.next();
			int n = sc.nextInt();
			System.out.println("Case #"+(j+1)+": "+ncount(word,n));
		}

		;
	}

	private static BigInteger ncount(String word, int n) {
		char[] letters =  word.toCharArray();
		int lastBreak = 0;
		int constInARow = 0;
		BigInteger wordCount =BigInteger.ZERO;
		for (int i =1; i<=word.length();i++){
			if (isConst(letters[i-1]))
			{
				constInARow++;
				if (constInARow>=n)
				{	
					BigInteger countForward = BigInteger.valueOf(word.length()).subtract(BigInteger.valueOf(i)).add(BigInteger.ONE);
					BigInteger countBackward = BigInteger.valueOf(i).subtract( BigInteger.valueOf(n)).subtract( BigInteger.valueOf(lastBreak)).add(BigInteger.ONE);
					BigInteger countAdition = countBackward.multiply(countForward);
					wordCount = wordCount.add(countAdition);		
					lastBreak = i-(n-1);
				}
			}
			else{
				constInARow=0;
			}
		}
		return wordCount;
	}

	private static boolean isConst(char c) {
		
		return !isVow(c);
	}

	private static boolean isVow(Character c) {
		return vowList.contains(c);
	
	}

}
