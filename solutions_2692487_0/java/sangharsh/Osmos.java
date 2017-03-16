/*
 * 
 * To compile: javac <filename>.java
 * To run: java <filename> <input_file> > <output_file>
 * 
 */
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Osmos
{

	private int A, N;

	private int[] motes;

	private int[] steps;

	int answer = 0;

	public Osmos(int A, int[] motes)
	{
		this.A = A;
		this.N = motes.length;
		this.motes = motes;
		Arrays.sort(this.motes);

		this.steps = new int[motes.length];
	}

	private int solve()
	{
		if (A == 1)
			return N;

		for (int i = 0; i < motes.length; i++)
		{
			if (A > motes[i])
			{
				A += motes[i];
				steps[i] = 0;
			}
			else
			{
				while (A <= motes[i])
				{
					steps[i]++;
					A += A - 1;
				}
				A += motes[i];
			}
		}

		int[] sums = new int[N];
		int totalSum = steps[0];
		sums[0] = steps[0];
		for (int i = 1; i < N; i++)
		{
			sums[i] = sums[i - 1] + steps[i];
			totalSum += steps[i];
		}

		int answer = N;
		for (int i = 0; i < N; i++)
		{
			answer = Math.min(answer, sums[i] + N - i - 1);
		}
		return answer;
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
			int A = scan.nextInt();
			int N = scan.nextInt();
			int[] motes = new int[N];

			for (int n = 0; n < N; n++)
				motes[n] = scan.nextInt();

			Osmos o = new Osmos(A, motes);
			System.out.println("Case #" + (i + 1) + ": " + o.solve());
		}
	}
}
