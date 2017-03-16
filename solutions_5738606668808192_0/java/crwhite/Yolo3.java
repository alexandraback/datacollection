import java.util.*;
import java.awt.*;
import java.io.*;

public class Yolo3
{
    public static void main (String args[])
    {
	findPotentialNumbers ();
	BufferedReader in;
	PrintWriter out;
	String currNum = "";
	long[] nums = new long [9], divisors = new long [9];
	boolean isPrime = false;
	try
	{
	    ArrayList potentialNums = findPotentialNumbers ();
	    in = new BufferedReader (new FileReader ("C-small-attempt2.in"));
	    out = new PrintWriter (new FileWriter ("out.txt"));
	    int outLine = Integer.parseInt (in.readLine ());
	    for (int m = 1 ; m <= outLine ; m++)
	    {
		String newLine = in.readLine ();
		int count = 0;
		StringTokenizer str = new StringTokenizer (newLine);
		int digits = Integer.parseInt (str.nextToken ());
		int coins = Integer.parseInt (str.nextToken ());
		out.println ("Case #"+m+":");
		for (int x = 0 ; x < potentialNums.size () ; x++)
		{
		    currNum = potentialNums.get (x).toString ();
		    for (int base = 2 ; base < 10 ; base++)
		    {
			nums [base - 2] = Long.parseLong (currNum, base);
		    }
		    nums [8] = Long.parseLong (currNum);
		    isPrime = false;

		    for (int z = 0 ; z < 9 ; z++)
		    {
			for (int y = 3 ; y <= (int) Math.sqrt (nums [z]) + 1 ; y++)
			{
			    if (nums [z] % y == 0)
			    {
				divisors [z] = y;
				break;
			    }
			    else
			    {
				if (y == (int) Math.sqrt (nums [z]) + 1)
				    isPrime = true;
			    }
			}
			if (isPrime == true)
			    break;
		    }
		    if (isPrime == false)
		    {
			count++;
			out.print (nums[8]);
			for (int q = 2 ; q <= 10 ; q++)
			{
			    out.print (" " + divisors [q - 2]);
			}
			out.println ();
			if (count == coins)
			    break;
		    }
		}
	    }
	    in.close ();
	    out.close ();
	}
	catch (FileNotFoundException e)
	{
	}
	catch (IOException i)
	{
	}
    }


    public static ArrayList findPotentialNumbers ()
    {
	ArrayList potentials = new ArrayList ();
	String num;
	boolean isBinary = false;
	for (long x = 1000000000000001L ; x <= 1000000011111111L ; x += 10L)
	    {
		num = Long.toString (x);
		isBinary = false;
		if (num.indexOf ("2") == -1 && num.indexOf ("3") == -1 && num.indexOf ("4") == -1 && num.indexOf ("5") == -1 && num.indexOf ("6") == -1 && num.indexOf ("7") == -1 && num.indexOf ("8") == -1 && num.indexOf ("9") == -1)
		{
		    isBinary = true;
		}
		if (isBinary)
		    potentials.add (potentials.size(), num);
	    }
	return potentials;
    }
}
