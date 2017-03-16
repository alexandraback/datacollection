import java.io.*;
import java.util.*;
//import java.math.*;

public class b {

	public static void main(String[] args) throws IOException
	{
		Scanner qwe = new Scanner(new File("b.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("b.out"));
		int t = qwe.nextInt();
		for(int i = 1; i <= t; i++)
		{
			int n = qwe.nextInt();
			int s = qwe.nextInt();
			int p = qwe.nextInt();
			
			int[] totals = new int [n];
			for(int j= 0; j < n; j++)
			{
				totals[j] = qwe.nextInt();
			}
			
			Arrays.sort(totals);
			
			int count = 0;
			for(int j = n-1; j >= 0; j--)
			{
				if(p == 0)
					count++;
				else if(totals[j] == 0)
					break;
				else if(p + 2*(p-1) <= totals[j])
					count++;
				else if(s > 0 && p >=2 && p + 2*(p-2) <= totals[j] )
				{
					count ++; 
					s --;
				}
				else
					break;
			}
			
			out.write("Case #" + i + ": " + count +  "\n");
		}
		out.close();
	}
}

