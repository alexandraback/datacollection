import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

public class Elf
{

	public static long gcd(long p, long q)
	{
		if (q == 0)
			return p;
		else
			return gcd(q, p % q);
	}

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException
	{
		Scanner scan = new Scanner(new File("A-small-attempt0 (2).in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("q1.txt"));

		int t = scan.nextInt();

		for (int i = 1; i <= t; i++)
		{
			String frac = scan.next();

			long p = 0;
			long q = 0;
			int slashIndex = 0;
			long answer;
			for (int j = 0; j < frac.length(); j++)
			{
				if (0 <= frac.charAt(j) - '0' && frac.charAt(j) - '0' <= 9)
					{
					
					}
				else
					slashIndex = j;
			}
p = Long.parseLong(frac.substring(0, slashIndex));
			q = Long.parseLong(frac.substring(slashIndex + 1, frac.length()));
			
			System.out.println(p);
			System.out.println (q);

			long gcd = gcd(p, q);
			long qreduce = q / gcd;

			long preduce = p/gcd;
			int qfactor = 0;

			while (qreduce % 2 == 0)
			{
				qreduce /= 2;
				qfactor++;
			}
			
			long ptest = 1;
			int pfactor = -1;
			
			while (ptest <= preduce)
			{
				ptest *=2;
				pfactor++;
			}
			
			if (qreduce != 1)
				out.write("Case #" + i + ": impossible" + "\n");
			else
				out.write("Case #" + i + ": " + (qfactor - pfactor)+"\n");
			
			
			
		}

		out.close();
	}

}
