using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace GoogleCodeJamV2
{
	public class CodeJam_2015_Round1C_C : ITestCase
	{
		public string GetTitle()
		{
			return "C. Less Money, More Problems";
		}

		public Func<string, int> LinesPerTestCase()
		{
			return x => 2;
		}

		public string Run(List<string> lines)
		{
			int C = int.Parse (lines [0].Split (' ') [0]);

			if (C > 1) {
				return "Not implemented";
			}

			int nrOfCoins = int.Parse (lines [0].Split (' ') [1]);
			int value = int.Parse (lines [0].Split (' ') [2]);
			List<int> amounts = lines [1].Split (' ').Select (x => int.Parse (x)).ToList ();

			List<int> coins = new List<int>();
		
			for (int i=1; i <= value; i++) 
			{
				List<int> result = new List<int> ();
				Change (coins, amounts, 0, 0, i, ref result);

				if (result.Count () == 0) {
					amounts.Add (i);
				}
			}

			return (amounts.Count() - nrOfCoins).ToString();
		}

		static void Change(List<int> coins, List<int> amounts, int highest, int sum, int goal, ref List<int> result)
		{
			if (sum == goal)
			{
				GetResult(coins, amounts, ref result);
				return;
			}

			if (sum > goal)
			{
				return;
			}

			foreach (int value in amounts)
			{
				if (value >= highest)
				{
					List<int> copy = new List<int>(coins);
					copy.Add(value);
					Change(copy, amounts, value, sum + value, goal, ref result);
				}
			}
		}

		static void GetResult(List<int> coins, List<int> amounts, ref List<int> result)
		{
			bool f = true;
			List<int> list = new List<int> ();
			
			foreach (int amount in amounts)
			{
				int count = coins.Count(value => value == amount);

				if (count > 1) {
					f = false;
				} else if (count == 1) {
					list.Add (amount);
				}
			}

			if (f == true) {
				result = list;
			}
		}

	}
}

