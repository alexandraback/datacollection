import java.io.*;
import java.util.*;

public class Fractiles {
	public static void main(String[]args)
	{
		try
		{
			Scanner sc = new Scanner(new FileReader("D-large.in"));
			FileWriter fw = new FileWriter(new File("Output.txt"));
			PrintWriter pw = new PrintWriter(fw);
			
			int t = sc.nextInt();
			
			for(int r = 1; r <= t; r++)
			{
				int k = sc.nextInt();
				int c = sc.nextInt();
				int s = sc.nextInt();
				long [] ans = new long[k];
				int count = 0;

				if(c > 1)
				{
					for(int i = 0; i < (int)(k/2); i++)
					{
						ans[i] =  ((2*(long)Math.pow(k, c-1))+2)*i+2;
						count++;
					}
					if(k % 2 == 1)
					{
						ans[count] = (long) Math.pow(k, c);
						count++;
					}
				}
				else
				{
					for(int i = 1; i <= k;i++)
					{
							ans[i-1]=i;
							count++;
					}
				}

				pw.print("Case #" + r + ":");
				if (count>s)
				{
					pw.print(" IMPOSSIBLE");
				}
				else
				{
					for(int i = 0; i < count; i++)
					{
						pw.print(" " + ans[i]);
					}
				}
				if (r != t)
					pw.println();
			}
			pw.flush();	
		}
		catch(IOException ioe)
		{
			System.out.print(ioe);
		}

	}
}
