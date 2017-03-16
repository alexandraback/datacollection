import java.io.*;
import java.util.*;

public class B
{
	static char[] c,j;
	static int mindiff;
	static String best;
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		int numRuns=in.nextInt();

		for (int run=1; run<=numRuns; run++){
		c=in.next().toCharArray();
		j=in.next().toCharArray();
		mindiff=100000000;
		best="";
//		System.out.println(new String(c)+" "+new String(j));
		System.out.println("Case #"+run+": "+min(0));}
	}

	static String min(int s)
	{
		for (int i=s; i<c.length; i++)
		{
			if (c[i]=='?')
			{
				for (int k=0; k<=9; k++)
				{
					c[i]=(char)('0'+k);
					if (j[i]=='?')
					{
						for (int u=0; u<=9; u++)
						{
							j[i]=(char)('0'+u);
							min(i+1);
							j[i]='?';
						}
					}
					else min(i+1);
					c[i]='?';
				}
			}
			else if (j[i]=='?')
			{
				for (int u=0; u<=9; u++)
				{
					j[i]=(char)('0'+u);
					min(i+1);
					j[i]='?';
				}
			}
			else
				continue;
			return best;
		}

		int diff=Math.abs(Integer.parseInt(new String(c))-Integer.parseInt(new String(j)));
		if (diff<mindiff)
		{
			mindiff=diff;
			best=new String(c)+" "+new String(j);
		}
		return best;
	}
}
