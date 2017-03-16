import java.util.*;
import java.awt.*;
import java.io.*;

public class Yolo
{
    public static void main (String args[])
    {
	BufferedReader in;
	PrintWriter out;
	boolean[] digits = new boolean [10];
	boolean allFound = false;
	try
	{
	    in = new BufferedReader (new FileReader ("A-large.in"));
	    out = new PrintWriter (new FileWriter ("out.txt"));
	    int lines = Integer.parseInt (in.readLine ());
	    for (int x = 0 ; x < lines ; x++)
	    {
		String num = in.readLine ();
		allFound = false;
		int count = 0, num2 = Integer.parseInt(num);
		for (int y = 0; y < 10; y++)
		{
		    digits[y] = false;
		}
		if (num.equals ("0"))
		    out.println ("Case #"+(x+1)+": INSOMNIA");
		else
		{
		    while (!allFound && count < 201)
		    {
			count++;
			num = String.valueOf (num2*count);
			for (int y = 0 ; y < 10 ; y++)
			{
			    if (num.indexOf(String.valueOf (y))!= -1)
			    {
				digits [y] = true;
			    }
			}
			allFound = true;
			for (int y = 0; y < 10; y++)
			{
			    if (digits[y]==false)
				allFound = false;
			}
		    }
		    out.println ("Case #"+(x+1)+": "+num);
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
}
