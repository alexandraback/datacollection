using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _2013QualifyB
{
	class Program
	{
		public static int[] ReadNumbers(string line)
		{
			string[] strNumbers = line.Split(new char[] { ' ' });
			int[] numbers = new int[strNumbers.Length];

			for (int i = 0; i < strNumbers.Length; i++)
			{
				numbers[i] = int.Parse(strNumbers[i]);
			}

			return numbers;
		}


		static void Main(string[] args)
		{
			int tcCount = int.Parse(Console.ReadLine());
			for (int tcIndex = 1; tcIndex <= tcCount; tcIndex++)
			{
				int[] numbers = ReadNumbers(Console.ReadLine());

				int rows = numbers[0];
				int cols = numbers[1];

				int[,] lawn = new int[rows, cols];
				int[] rowMaxs = new int[rows];
				int[] colMaxs = new int[cols];

				for (int r = 0; r < rows; r++)
				{
					numbers = ReadNumbers(Console.ReadLine());
					for (int c = 0; c < cols; c++)
					{
						lawn[r, c] = numbers[c];

						if (rowMaxs[r] < lawn[r, c])
							rowMaxs[r] = lawn[r, c];

						if (colMaxs[c] < lawn[r, c])
							colMaxs[c] = lawn[r, c];
					}
				}

				int[,] mowedLawn = new int[rows, cols];
				for (int r = 0; r < rows; r++)
				{
					for (int c = 0; c < cols; c++)
					{
						mowedLawn[r, c] = Min(rowMaxs[r], colMaxs[c]);
					}
				}

				// Output
				Console.WriteLine("Case #{0}: {1}", tcIndex, Same(lawn, mowedLawn, rows, cols));
			}
		}

		static int Min(int n1, int n2)
		{
			return n1 < n2 ? n1 : n2;
		}

		static string Same(int[,] orgLawn, int[,] mowedLawn, int rows, int cols)
		{
			for (int r = 0; r < rows; r++)
			{
				for (int c = 0; c < cols; c++)
				{
					if (orgLawn[r, c] != mowedLawn[r, c])
						return "NO";
				}
			}
			return "YES";
		}
	}
}
