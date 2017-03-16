/*
 * 
 * To compile: javac <filename>.java
 * To run: java <filename> <input_file> > <output_file>
 * 
 */
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class BullsEye
{

	private long r, t;

	public BullsEye(long r, long t)
	{
		this.r = r;
		this.t = t;
	}

	private long eq(long a)
	{
		return 2 * a * a + (2 * r - 1) * a - t;
	}

	public long solve()
	{
		long hi = (long) Math.min(Math.sqrt(t / 2), t / (2 * r - 1)) + 1;
		long lo = 1;

		while (hi > lo)
		{
			long mid = (lo + hi) / 2;
			long equ = eq(mid);
			if (equ < 0)
			{
				lo = mid;
			}
			else if (equ > 0)
			{
				hi = mid - 1;
			}
			else
				return mid;

			if (hi - lo == 1)
			{
				if(eq(hi) <= 0)
					return hi;
				if(eq(lo) <= 0)
					return lo;
			}
		}

		return hi;
		// double d = Math.sqrt((2 * r - 1) * (2 * r - 1) + 8 * t);
		//
		// long answer = (long) ((d - 2 * r + 1) / 4);
		//
		// if (eq(answer) <= 0)
		// {
		// if (eq(answer + 1) <= 0)
		// return answer + 1;
		// return answer;
		// }
		// return answer - 1;
		// long term = 2 * t + (r - 1) * r;
		// long answer = (long) Math.floor(Math.sqrt(term));
		//
		// if(answer * (answer + 1) <= term)
		// return answer;
		// else
		// return answer - 1;
		// long answer = 0;
		// long used = 0;
		//
		// while (used <= t)
		// {
		// used += (r + 2 * answer) + (r + 2 * answer + 1);
		// answer++;
		// }
		//
		// return answer - 1;
	}

	public static void main(String[] args)
	{
		if (args.length != 1)
		{
			System.err.println("Run it with 1 command line argument i.e. filename of input file");
		}
		File file = new File(args[0]);
		Scanner scan = null;
		try
		{
			scan = new Scanner(file);
		}
		catch (FileNotFoundException e)
		{
			System.err.println("File not found");
			e.printStackTrace();
		}

		int T = scan.nextInt();

		for (int i = 0; i < T; i++)
		{
			long r = scan.nextLong();
			long t = scan.nextLong();

			BullsEye be = new BullsEye(r, t);
			System.out.println("Case #" + (i + 1) + ": " + be.solve());
		}
	}
}
