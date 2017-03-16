import java.util.*;
import java.awt.*;
import java.io.*;

public class ProblemC
{
    public static void main (String args[])
    {
	BufferedReader in;
	PrintWriter out;
	StringTokenizer a;
	int [] bff;
	boolean [] stuTaken;
	int finalCircle;
	int numStu, count, currStu,currMax,prevStu;
	try
	{
	    in = new BufferedReader (new FileReader ("C-small-attempt1.in"));
	    out = new PrintWriter (new FileWriter ("out.txt"));
	    int lines = Integer.parseInt(in.readLine());
	    for (int x = 1 ; x <= lines ; x++)
	    {
		numStu = Integer.parseInt (in.readLine());
		a = new StringTokenizer (in.readLine());
		bff = new int [numStu];
		stuTaken = new boolean [numStu];
		for (int y = 0; y < numStu; y++)
		    bff [y] = Integer.parseInt (a.nextToken())-1;

		currMax = 0;
		for (int y = 0; y < numStu; y++)
		{
		    prevStu = y;
		    count = 0;
		    Arrays.fill(stuTaken,false);
		    currStu = y;
		    do
		    {
			count ++;
			stuTaken[currStu] = true;
			if ((stuTaken[bff[currStu]] == true)||(stuTaken[bff[bff[currStu]]]==true && bff[bff[currStu]]!=y && bff[bff[currStu]]!= currStu))
			    break;
			prevStu = currStu;
			currStu = bff[currStu];
		    }while (stuTaken[currStu]== false);
		    for (int z = 0; z < numStu; z++)
		    {
			if ((bff [z] == currStu) && (stuTaken[z]==false) && (bff[currStu]==prevStu || bff[currStu]==z))
			{
			    count ++;
			    currStu = z;
			    break;
			}
		    }
		    if (count > currMax)
			currMax = count;
		}
		out.println("Case #"+x+": "+currMax);
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
