using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace FallingDiamonds
{
	class MainClass
	{
		static void Main(string[] args)
        {
            List<TestCase> cases = new List<TestCase>();

            using (StreamReader sr = new StreamReader("B-small-attempt1.in"))
            {
                int numOfTestCases = int.Parse(sr.ReadLine());

                for (int i = 0; i < numOfTestCases; i++)
                {
					int[] nums = sr.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();

					int numberOfFallingDiamonds = nums[0];
					int posX = nums[1];
					int posY = nums[2];

                    cases.Add(new TestCase(numberOfFallingDiamonds, posX, posY));
                }
            }

            using (StreamWriter sw = new StreamWriter("B-small-attempt1.out"))
            {
                for (int i = 0; i < cases.Count; i++)
                {
					double minimum = cases[i].GetProbability();

	                sw.Write("Case #" + (i + 1) + ": ");
                    sw.WriteLine(minimum.ToString("F8"));

					Console.WriteLine(minimum);
                }
            }
        }
    }

	public class TestCase
	{
		private readonly int _NumberOfFallingDiamonds, _PosX, _PosY;

		public TestCase (int numberOfFallingDiamonds, int posX, int posY)
		{
			_NumberOfFallingDiamonds = numberOfFallingDiamonds;
			_PosX = posX;
			_PosY = posY;
		}

		public double GetProbability ()
		{
			if (_PosX == 0 && _PosY == 0)
				return 1.0;

			//Check for diamond tip
			if (_PosX == 0)
				return GetProbabilityForTip ();

			int diamondsUnder, nextLayer;
			int numberOfDiamondsInBase = GetNumberOfDiamondsInBase (out diamondsUnder, out nextLayer);

			if (numberOfDiamondsInBase >= _NumberOfFallingDiamonds)
				return 0.0;

			int diamondsLeftForOuterLayer = _NumberOfFallingDiamonds - numberOfDiamondsInBase;

			int oneFullSide = (nextLayer - 1) / 2;

			// Enough diamonds available to force it
			if (diamondsLeftForOuterLayer >= oneFullSide + diamondsUnder + 1)
				return 1.0;

			// Only enough for one side
			if (diamondsLeftForOuterLayer == diamondsUnder + 1)
				return Math.Pow (0.5, diamondsUnder + 1);

			while (diamondsLeftForOuterLayer > diamondsUnder + 1 && diamondsUnder > 0) {
				diamondsLeftForOuterLayer -= 2;
				diamondsUnder--;
			}

			// Only enough for one side
			if (diamondsLeftForOuterLayer == diamondsUnder + 1)
				return Math.Pow (0.5, diamondsUnder + 1);

			return 1.0 - Math.Pow (0.5, diamondsLeftForOuterLayer);
		}

		private double GetProbabilityForTip ()
		{
			int normalized = (_PosY / 2) + 1;
			int numberOfDiamondsRequired = normalized  * ((2 * normalized) - 1);

			if(_NumberOfFallingDiamonds >= numberOfDiamondsRequired)
				return 1.0;
			else
				return 0.0;
		}

		private int GetNumberOfDiamondsInBase (out int diamondsUnder, out int nextLayer)
		{
			diamondsUnder = 0;

			int posX = _PosX;
			int posY = _PosY;

			while (posY != 0) {
				if(posX > 0)
					posX += 1;
				else if (posX < 0)
					posX -= 1;
				else
					throw new InvalidOperationException();

				posY -= 1;

				diamondsUnder++;
			}

			int positivePosition = Math.Abs(posX);
			int normalized = positivePosition - 2;

			int returnValue = normalized * ((2 * normalized) - 1);

			int normalizedPlusOne = normalized + 1;

			// Outer layer count
			nextLayer = normalizedPlusOne * ((2 * normalizedPlusOne) - 1) - returnValue;

			return returnValue;
		}
	}
}
