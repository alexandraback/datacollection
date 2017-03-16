import java.io.*;
import java.util.*;

public class Fractiles {
	public static void main(String[]args)
	{
		try
		{
			Scanner sc = new Scanner(new FileReader("D-small-attempt2.in"));
			FileWriter fw = new FileWriter(new File("Output.txt"));
			PrintWriter pw = new PrintWriter(fw);
			
			int t = sc.nextInt();
			
			for(int r = 1; r <= t; r++)
			{
				int k = sc.nextInt();
				int c = sc.nextInt();
				int s = sc.nextInt();
				long [] ans = new long[k];

				for(int i = 1; i <= k;i++)
				{
						ans[i-1]=i;
				}
				pw.print("Case #" + r + ":");
				if (ans.length>s)
				{
					pw.print(" IMPOSSIBLE");
				}
				else
				{
					for(int i = 0; i < ans.length; i++)
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
