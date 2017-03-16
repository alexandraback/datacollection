using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Round1AB
{

	public class Level
	{
		public int StarCountFor1StarRating = 0;
		public int StarCountFor2StarRating = 0;
		public int StarsCompleted = 0;

		public Level(int a, int b)
		{
			StarCountFor1StarRating = a;
			StarCountFor2StarRating = b;
		}

		public static int CompareTo(Level l1, Level l2)
		{
			int retval = l1.StarCountFor2StarRating.CompareTo(l2.StarCountFor2StarRating);
			return retval == 0 ? l1.StarCountFor1StarRating.CompareTo(l2.StarCountFor1StarRating) : retval;
		}
	}

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
				int levelCount = int.Parse(Console.ReadLine());

				List<Level> levelList = new List<Level>();

				for (int levelIndex = 0; levelIndex < levelCount; levelIndex++)
				{
					int[] numbers = ReadNumbers(Console.ReadLine());
					levelList.Add(new Level(numbers[0], numbers[1]));
				}

				levelList.Sort(Level.CompareTo);

				int minTimes = 0;
				int totalStars = 0;
				int twoStarIndex = 0;
				int oneStarIndex = levelCount-1;

				while (totalStars < 2 * levelCount)
				{
					Level twoStarLevel = levelList[twoStarIndex];
					Level oneStarLevel = levelList[oneStarIndex];

					if (twoStarLevel.StarCountFor2StarRating <= totalStars)
					{
						int diff = 2 - twoStarLevel.StarsCompleted;
						totalStars += diff;
						twoStarLevel.StarsCompleted = 2;
						minTimes++;
						twoStarIndex++;
					}
					else if (oneStarLevel.StarsCompleted == 0 && oneStarLevel.StarCountFor1StarRating <= totalStars)
					{
						oneStarLevel.StarsCompleted = 1;
						totalStars += 1;
						minTimes++;
						oneStarIndex = levelCount - 1;
					}
					else
					{
						oneStarIndex--;
					}

					if (twoStarIndex > oneStarIndex)
					{
						break;
					}
				}

				// Output
				Console.WriteLine("Case #{0}: {1}", tcIndex, (totalStars != (2 * levelCount) ? "Too Bad" : minTimes.ToString()));
			}
		}
	}
}
