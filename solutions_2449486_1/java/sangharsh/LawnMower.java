/*
 * 
 * To compile: javac <filename>.java
 * To run: java <filename> <input_file> > <output_file>
 * 
 */
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class LawnMower
{

	private static class Lawn
	{
		private int N, M;

		private int[][] array;

		private int[] maxRow, maxCol;

		public Lawn(int N, int M, int[][] array)
		{
			this.N = N;
			this.M = M;
			this.array = array;

			maxRow = new int[N];
			maxCol = new int[M];
			initMaxRowCols();
		}

		private void initMaxRowCols()
		{
			for (int j = 0; j < N; j++)
			{
				maxRow[j] = 0;

				for (int k = 0; k < M; k++)
				{
					if (maxRow[j] < array[j][k])
						maxRow[j] = array[j][k];
				}
			}

			for (int k = 0; k < M; k++)
			{
				maxCol[k] = 0;

				for (int j = 0; j < N; j++)
				{
					if (maxCol[k] < array[j][k])
						maxCol[k] = array[j][k];
				}
			}

		}

		private void print()
		{
			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < M; k++)
				{
					System.out.print(array[j][k] + " ");
				}
				System.out.println();
			}
		}

		public boolean isPossible()
		{

			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < M; k++)
				{
					if (array[j][k] < maxRow[j] && array[j][k] < maxCol[k])
						return false;
				}
			}
			return true;
		}
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
			int N = scan.nextInt();
			int M = scan.nextInt();

			int[][] array = new int[N][M];

			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < M; k++)
				{
					array[j][k] = scan.nextInt();
				}
			}

			Lawn lawn = new Lawn(N, M, array);
			System.out.println("Case #" + (i + 1) + ": " + (lawn.isPossible() ? "YES" : "NO"));
			// lawn.print();
		}
	}
}
