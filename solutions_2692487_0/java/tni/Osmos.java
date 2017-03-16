import java.io.*;
import java.util.*;

public class Osmos
{
	public static void main(String[] args) throws Exception
	{
		Scanner in = new Scanner(new File(args[0]));

		int T = in.nextInt();
		for (int i = 0; i < T; i++)
		{
			int A = in.nextInt();
			int N = in.nextInt();

			List<Integer> motes = new ArrayList<Integer>();
			for (int j = 0; j < N; j++)
			{
				motes.add(in.nextInt());
			}

			Collections.sort(motes);
			int moves;
			if (A == 1)
			{
				moves = motes.size();
			}
			else
			{
				moves = numMovesRemaining(A, motes);
			}

			System.out.format("Case #%d: %d\n", i+1, moves);
		}
	}

	private static int numMovesRemaining(int A, List<Integer> motes)
	{
		int index = 0;
		for (int m : motes)
		{
			if (A <= m)
			{
				break;
			}

			A += m;
			index++;
		}

		if (index == motes.size())
		{
			return 0;
		}

		int size = motes.size();
		motes.add(index, A - 1);
		return Math.min(size - index, 1 + numMovesRemaining(A, motes.subList(index, motes.size())));
	}
}