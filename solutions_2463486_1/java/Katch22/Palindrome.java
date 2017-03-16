import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class Palindrome {

	/* List from http://oeis.org/A002779, the first 485 palindromic squares.
	 * We use this as the basis for building a slightly-smaller list of those
	 * palindromes who's square root is also a palindrome
	 */
	public static String FIRST485 = "first-485-ps.txt";

	private static ArrayList<BigInteger> palindromes = new ArrayList<BigInteger>();

	public static void init(){
		Scanner s;
		try {
			s = new Scanner(new FileReader(new File(FIRST485)));
			
			while(s.hasNextLine()){
				String[] line = s.nextLine().split(" ");
				BigInteger num = new BigInteger(line[1]);
				
				BigInteger sqrt = sqrt(num);
				if(isPalindrome(sqrt.toString())){
					palindromes.add(num);
				}
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	/*From http://faruk.akgul.org/blog/javas-missing-algorithm-biginteger-sqrt/ 
	 * No BigInt.sqrt() method, this solves it*/
	private static BigInteger sqrt(BigInteger n) {
		BigInteger a = BigInteger.ONE;
		BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8"))
				.toString());
		while (b.compareTo(a) >= 0) {
			BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
			if (mid.multiply(mid).compareTo(n) > 0)
				b = mid.subtract(BigInteger.ONE);
			else
				a = mid.add(BigInteger.ONE);
		}
		return a.subtract(BigInteger.ONE);
	}
	
	private static boolean isPalindrome(String number){
		
		for(int i = 0; i < (number.length() / 2) + 1; i++){
			if(number.charAt(i) != number.charAt(number.length() - i - 1)){
				return false;
			}
		}
		
		return true;
	}

	/**
	 * @param args
	 * @throws FileNotFoundException
	 */
	public static void main(String[] args) throws FileNotFoundException {
		init();

		Scanner s = new Scanner(new FileReader(new File(args[0])));

		int problems = s.nextInt();
		s.nextLine();

		for (int prob = 0; prob < problems; prob++) {
			String[] line = s.nextLine().split(" ");

			BigInteger A = new BigInteger(line[0]);
			BigInteger B = new BigInteger(line[1]);

			int lowindex = 0;
			int highindex = 0;

			while (palindromes.get(lowindex).compareTo(A) < 0) {
				lowindex++;
			}

			//System.out.println(palindromes.get(lowindex) + " " + lowindex);

			while (palindromes.get(highindex).compareTo(B) <= 0) {
				highindex++;
			}

			//System.out.println(palindromes.get(highindex) + " " + highindex);

			System.out.println("Case #" + (prob + 1) + ": "
					+ (highindex - lowindex));
		}
	}

}
