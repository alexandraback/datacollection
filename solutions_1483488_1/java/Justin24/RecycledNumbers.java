package googleJam;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Scanner;

public class RecycledNumbers 
{

	public static void main(String[] args) 
	{
		Scanner scan = null;
		try
		{
			scan = new Scanner(new File(args[0]));
		}
		catch (FileNotFoundException e)
		{
			System.err.println("File not found!");
			return;
		}
		if (!scan.hasNext())
		{
			System.err.println("Nothing in File!");
			return;
		}
		int testCases = Integer.parseInt(scan.nextLine());
		int lower;
		int upper;
		int move;
		int d;
		int total;
		int zeroes;
		int num = 1;
		int first;
		HashSet<Integer> set;
		while(scan.hasNext())
		{
			System.out.print("Case #" + num + ": ");
			total = 0;
			lower = scan.nextInt();
			upper = scan.nextInt();
			for (int x = lower; x <= (upper); x++)
			{
				set = new HashSet<Integer>();
				zeroes = 1;
				move = x;
				while (move > 9)
				{
					move = move/10;
					zeroes = zeroes * 10;
				}
				int limit = zeroes;
				for(int n = 10; n < (limit*10); n = n * 10)
				{

					move = x/n;
					d = x % n;
					d = d * zeroes;
					d = d + move;
					zeroes = zeroes / 10;
					if (d < x && d >= lower && !set.contains(d) && d > 9)
					{
						total++;
						//System.out.println(d + " , " + x);
						set.add(d);
					}
				}
			}
			num++;
			System.out.print(total);
			if (scan.hasNext())
			{
				System.out.println();				
			}
		}
	}

}
