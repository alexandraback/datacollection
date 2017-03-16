import java.util.*;

public class fairAndSquare {
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int numCase = in.nextInt();
		for (int testCase = 0; testCase < numCase; testCase++)
		{
			int low = in.nextInt();
			int lowSqrt = (int)Math.sqrt(low);
			if (lowSqrt*lowSqrt < low)
				lowSqrt++;
			int high = in.nextInt();
			int highSqrt = (int)Math.sqrt(high);
			if (highSqrt*highSqrt > high)
				highSqrt--;
			ArrayList<Integer> store = new ArrayList<Integer>();
			store = allPalindromic(lowSqrt, highSqrt);
			int count = 0;
			while(!store.isEmpty())
			{
				int number = store.remove(0);
				String numberSqrt = Integer.toString(number * number);
				if (isPalindrome(numberSqrt))
				{
					count++;
				}
			}
			System.out.println("Case #" + (testCase+1)+": "+count);
		}
	}
	
	public static ArrayList<Integer> allPalindromic(int low, int high) {

		ArrayList<Integer> result = new ArrayList<Integer>();

	    for (int i = low; i <= 9 && i <= high; i++)
	        result.add(i);

	    boolean cont = true;
	    for (int i = 1; cont; i++) {
	        StringBuffer rev = new StringBuffer("" + i).reverse();
	        cont = false;
	        for (String d : "0123456789".split("")) {
	            int n = Integer.parseInt("" + i + d + rev);
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
