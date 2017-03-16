using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Osmos
{
	class MainClass
	{
        static void Main(string[] args)
        {
            List<TestCase> cases = new List<TestCase>();

            using (StreamReader sr = new StreamReader("A-large.in"))
            {
                int numOfTestCases = int.Parse(sr.ReadLine());

                for (int i = 0; i < numOfTestCases; i++)
                {
					int[] nums = sr.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();

					int startingMoteSize = nums[0];
					int[] moteSizes = sr.ReadLine().Split(' ').Select(s => int.Parse(s)).OrderBy(m => m).ToArray();

                    cases.Add(new TestCase(startingMoteSize, moteSizes));
                }
            }

            using (StreamWriter sw = new StreamWriter("A-large.out"))
            {
                for (int i = 0; i < cases.Count; i++)
                {
					int minimum = cases[i].GetMinimum();

	                sw.Write("Case #" + (i + 1).ToString() + ": ");
                    sw.WriteLine(minimum);

					Console.WriteLine(minimum);
                }
            }
        }
    }

	class TestCase
	{
		private readonly int _StartingMoteSize;
		private readonly int[] _OtherMoteSizes;

		public TestCase (int startingMoteSize, int[] otherMoteSizes)
		{
			_StartingMoteSize = startingMoteSize;
			_OtherMoteSizes = otherMoteSizes;
		}

		public int GetMinimum ()
		{
			if(_StartingMoteSize == 1)
				return _OtherMoteSizes.Length;

			return GetMinimumNumberOfOperations(_StartingMoteSize, 0, new List<int>(_OtherMoteSizes));
		}

		private int GetMinimumNumberOfOperations (int currentMoteSize, int currentSmallest, List<int> motes)
		{
			while (currentMoteSize > motes[0]) {
				currentMoteSize += motes[0];
				motes.RemoveAt (0);

				if (motes.Count == 0)
					break;
			}

			if (motes.Count == 0) {
				return currentSmallest;
			}

			List<int> newMotes = new List<int>(motes);
			newMotes.Insert(0, currentMoteSize - 1);

			if(currentSmallest + motes.Count <= currentSmallest + 1)
				return currentSmallest + motes.Count;

			return Math.Min(currentSmallest + motes.Count, GetMinimumNumberOfOperations(currentMoteSize, currentSmallest + 1, newMotes));
		}
	}
}
