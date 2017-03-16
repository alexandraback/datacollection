using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace GoogleCodeJam2014Round1B
{
	internal class BSmall
	{
		private static void Main(string[] args)
		{
			string testsize = "small";

			TextReader tr = new StreamReader("B-" + testsize + ".in");
			TextWriter tw = new StreamWriter("B-" + testsize + ".out");

			int T = int.Parse(tr.ReadLine());

			for (int t = 0; t < T; t++)
			{
				int[] nums = tr.ReadLine().Split(' ').Select(int.Parse).ToArray();
				int a = Math.Min(nums[0], nums[1]);
				int b = Math.Max(nums[0], nums[1]);
				int k = nums[2];

				int s = 0;
				for (int i = 0; i < a; i++)
				{
					for (int j = 0; j < b; j++)
					{
						if ((i & j) < k)
						{
							s++;
						}
					}
				}

				tw.WriteLine("Case #" + (t + 1) + ": " + s);

			}
			tr.Close();
			tw.Close();
		}
	}
}
