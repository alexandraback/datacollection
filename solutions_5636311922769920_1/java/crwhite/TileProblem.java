import java.util.*;
import java.awt.*;
import java.io.*;
import java.math.*;

public class TileProblem
{
    public static void main (String args[])
    {
	BufferedReader in;
	PrintWriter out;
	long k, c, s;
	BigInteger tile, coeff, poly;
	StringTokenizer a;
	try
	{
	    in = new BufferedReader (new FileReader ("D-large.in"));
	    out = new PrintWriter (new FileWriter ("out.txt"));
	    int lines = Integer.parseInt (in.readLine ());
	    for (int x = 1 ; x <= lines ; x++)
	    {
		a = new StringTokenizer (in.readLine ());
		k = Long.parseLong (a.nextToken ());
		c = Long.parseLong (a.nextToken ());
		s = Long.parseLong (a.nextToken ());
		if ((((k % c) == 0) && (s < (int) (k / c))) || (((k % c) != 0) && (s < ((int) (k / c) + 1))))
		    out.println ("Case #" + x + ": IMPOSSIBLE");
		else if (c <= k)
		{
		    if ((k % c) == 0)
		    {
			out.print ("Case #" + x + ":");
			for (long tileNum = 1 ; tileNum <= (k / c) ; tileNum++)
			{
			    tile = new BigInteger ("0");
			    for (long currPos = 0 ; currPos < c ; currPos++)
			    {
				coeff = new BigInteger (String.valueOf (((c * (tileNum - 1)) + currPos)));
				poly = new BigInteger (String.valueOf (power (k, c - (currPos + 1))));
				tile = tile.add (coeff.multiply (poly));
			    }
			    tile = tile.add (new BigInteger ("1"));
			    out.print (" " + tile);
			}
			out.println ();
		    }
		    else
		    {
			out.print ("Case #" + x + ":");
			for (long tileNum = 1 ; tileNum <= (k / c) ; tileNum++)
			{
			    tile = new BigInteger ("0");
			    for (long currPos = 0 ; currPos < c ; currPos++)
			    {
				coeff = new BigInteger (String.valueOf (((c * (tileNum - 1)) + currPos)));
				poly = new BigInteger (String.valueOf (power (k, c - (currPos + 1))));
				tile = tile.add (coeff.multiply (poly));
			    }
			    tile = tile.add (new BigInteger ("1"));
			    out.print (" " + tile);
			}
			tile = new BigInteger ("0");
			for (long currPos = 0 ; currPos < c ; currPos++)
			{
			    coeff = new BigInteger (String.valueOf ((k - c) + currPos));
			    poly = new BigInteger (String.valueOf (power (k, c - (currPos + 1))));
			    tile = tile.add (coeff.multiply (poly));
			}
			tile = tile.add (new BigInteger ("1"));
			out.println (" " + tile);
		    }
		}
		else
		{
		    tile = new BigInteger ("0");
		    for (long currPos = 0 ; currPos < k ; currPos++)
		    {
			coeff = new BigInteger (String.valueOf (currPos));
			poly = new BigInteger (String.valueOf (power (k, c - (currPos + 1))));
			tile = tile.add (coeff.multiply (poly));
		    }
		    tile = tile.add (new BigInteger ("1"));
		    out.println ("Case #" + x + ": " + tile);
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


    private static long power (long base, long exponent)
    {
	long pow = 1;
	for (int x = 0 ; x < exponent ; x++)
	{
	    pow *= base;
	}
	return pow;
    }
}


