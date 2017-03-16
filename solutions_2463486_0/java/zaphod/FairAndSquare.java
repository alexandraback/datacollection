import java.io.*;
import java.util.Scanner;

public class FairAndSquare
{

    public static boolean isPalindrome(long n)
    {
    	if (n %10 == 0)
    		return false;
    	long front = 0;
    	while (n > front)
    	{
    		front = 10*front + n% 10;
    		if (n== front)
    			return true;
    		n/=10;
    	}
     	return n== front;
    }

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException
	{
		String fileName = "C-small0";
        Scanner in = new Scanner(new File (fileName +".in"));
		PrintWriter out = new PrintWriter(new FileWriter(
				fileName +".out"));
		
	
		int noOfCases = in.nextInt();
		for (int caseNo =1 ; caseNo <=noOfCases; caseNo++)
		{
			long A = in.nextLong();
			long B = in.nextLong();
			long count = 0;
			
			long lower = Math.round(Math.sqrt(A));
			long upper = Math.round(Math.sqrt(B));
			
			for (long check = lower; check <= upper; check++)
			{
				if (isPalindrome(check))
				{
					long number = check*check;
					if (number >= A && number <= B && isPalindrome(number))
					{
						count++;
						//System.out.println("Pal: " + number);
					}
				}
			}
			
			System.out.println("Case #" + caseNo + ": " + count);
			out.println("Case #" + caseNo + ": " + count);
		}
		in.close();
		out.close();

	}

}
