import java.util.*;
import java.awt.*;
import java.io.*;

public class ProblemA
{
    public static void main (String args[])
    {
	BufferedReader in;
	PrintWriter out;
	StringTokenizer a;
	String s, finalS;
	try
	{
	    in = new BufferedReader (new FileReader ("A-large.in"));
	    out = new PrintWriter (new FileWriter ("out.txt"));
	    int lines = Integer.parseInt(in.readLine());
	    for (int x = 1 ; x <= lines ; x++)
	    {
		s = in.readLine();
		finalS = "" + s.charAt(0);
		for (int y = 1; y < s.length(); y++)
		{
		    if (s.charAt(y) >= finalS.charAt(0))
			finalS = s.charAt(y) + finalS;
		    else
			finalS = finalS + s.charAt(y);
		}
		out.println ("Case #"+x+": "+finalS);
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
