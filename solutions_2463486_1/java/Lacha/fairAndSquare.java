import java.util.*;

public class fairAndSquare {
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int numCase = in.nextInt();
		for (int testCase = 0; testCase < numCase; testCase++)
		{
			long low = in.nextLong();
			long lowSqrt = (long)Math.sqrt(low);
			if (lowSqrt*lowSqrt < low)
				lowSqrt++;
			long high = in.nextLong();
			long highSqrt = (long)Math.sqrt(high);
			if (highSqrt*highSqrt > high)
				highSqrt--;
			ArrayList<Long> store = new ArrayList<Long>();
			store = allPalindromic(lowSqrt, highSqrt);
			long count = 0;
			while(!store.isEmpty())
			{
				long number = store.remove(0);
				String numberSqrt = Long.toString(number * number);
				if (isPalindrome(numberSqrt))
				{
					count++;
				}
			}
			System.out.println("Case #" + (testCase+1)+": "+count);
		}
	}
	
	public static ArrayList<Long> allPalindromic(long low, long high) {

		ArrayList<Long> result = new ArrayList<Long>();

	    for (long i = low; i <= 9 && i <= high; i++)
	        result.add(i);

	    boolean cont = true;
	    for (int i = 1; cont; i++) {
	        StringBuffer rev = new StringBuffer("" + i).reverse();
	        cont = false;
	        for (String d : "0123456789".split("")) {
	            long n = Long.parseLong("" + i + d + rev);
	            if (n <= high) {
	                cont = true;
	                if (n >= low)
	                	result.add(n);
	            }
	        }
	    }

	    return result;
	}
	
	private static final boolean isPalindrome(final String str) { 
		return str.equals((new StringBuilder(str)).reverse().toString()); 
	} 
}
