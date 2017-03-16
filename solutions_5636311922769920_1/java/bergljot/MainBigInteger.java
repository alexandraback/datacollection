package fractiles;

import java.math.BigInteger;
import java.util.Scanner;

public class MainBigInteger {

	static public BigInteger getFinalTile(int k, int min, int max)
	{
		BigInteger sum = BigInteger.valueOf(0);
		// System.out.println("Min max " + min + " " + max);
		for (int i = min; i <= max; i++)
		{
			if (i >= k) sum = sum.add(BigInteger.valueOf(0)); // instead of k - 1
			else sum = sum.add(BigInteger.valueOf(i));
			if (i < max) sum = sum.multiply(BigInteger.valueOf(k)); //sum *= k;
		}
		return sum;
	}
	
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		in.nextLine();
		for(int i = 0; i < cases; i++)
		{
			int k = in.nextInt();
			int c = in.nextInt();
			int s = in.nextInt();
			if (k > c * s) System.out.println("Case #" + (i + 1) + ": " + "IMPOSSIBLE");
			else 
			{
				System.out.print("Case #" + (i + 1) + ":");
				// each final tile covers c original tiles
				int student = 1;
				while(true)
				{
					//System.out.println("student #" + student + " " + getFinalTile(k, (student - 1) * c, student * c - 1));
					System.out.print(" " + getFinalTile(k, (student - 1) * c, student * c - 1).add(BigInteger.valueOf(1)));
					// this student covers
					//System.out.println(((student - 1) * c) + " "  + (student * c - 1));
					if (student * c >= k) break;
					student += 1;
				}
				System.out.println();
			}
		}
		in.close();
	}
	
}
