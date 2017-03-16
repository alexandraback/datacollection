import java.util.*;
import java.math.*;

class CodeJamC
{
	private static long[] fairAndSquares;
	
	public static void main(String[] args)
	{
		fairAndSquares = preCompute();
		
		Scanner in = new Scanner(System.in);
		int tt = in.nextInt();
		int trial = 0;
		while(trial < tt)
		{
			int A = in.nextInt();
			int B = in.nextInt();
			int min = 0;
			int max = 0;
			while(fairAndSquares[min] < A)
			{
				++min;
			}
			max = min;
			while(fairAndSquares[max] <= B)
			{
				++max;
			}
		
			int ret = max - min;
			System.out.println("Case #" + ++trial + ": " + ret);
		}
			
	}
	
	public static long[] preCompute()
	{
		ArrayList<Long> squares = new ArrayList<Long>();
		long i = 1;
		long z = 0;
		do
		{
			z = i * i;
			if(isPalindrome("" + i) && isPalindrome("" + z))
			{
				squares.add(new Long(z));
				//System.err.println(i + " " + z);
			}
			++i;
		}while(z < 10000000000000000l);
		
		long[] ret = new long[squares.size()];
		
		int k=0;
		
		for(Long val : squares)
		{
			ret[k++] = val.longValue();
		}
		return ret;
	}
	
	public static boolean isPalindrome(String str)
	{
		int len = str.length();
		for(int i=0; i<len/2; ++i)
		{
			if(str.charAt(i) != str.charAt(len-1-i))
			{
				return false;
			}
		}
		return true;
	}
}