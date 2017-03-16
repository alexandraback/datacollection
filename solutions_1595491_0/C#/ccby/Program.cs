using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ProblemB
{
	class Program
	{
		static void Main(string[] args)
		{
			string file = "B-small-attempt4";
			StreamReader sr = new StreamReader(new FileStream(file + ".in", FileMode.Open, FileAccess.Read));
			StreamWriter sw = new StreamWriter(new FileStream(file + ".out", FileMode.OpenOrCreate, FileAccess.Write));

			int maxCase = Convert.ToInt32(sr.ReadLine());

			for (int i = 0; i < maxCase; i++)
			{
				string[] para = sr.ReadLine().Split(new Char[] { ' ' });
				int numOfGoogler = Convert.ToInt32(para[0]);
				int numOfSurprise = Convert.ToInt32(para[1]);
				int leasePoint = Convert.ToInt32(para[2]);
				List<int> points = new List<int>();
				for (int j = 0; j < numOfGoogler; j++)
				{
					points.Add(Convert.ToInt32(para[j + 3]));
				}
				int result = Solve(numOfGoogler, numOfSurprise, leasePoint, points);

				//output
				Console.WriteLine("Case #{0}: {1}", i + 1, result.ToString());
				sw.WriteLine("Case #{0}: {1}", i + 1, result.ToString());
			}


			//close
			sr.Close();
			sw.Close();
		}

		private static int Solve1(int numOfGoogler, int numOfSurprise, int leasePoint, List<int> points)
		{
			int count = 0;
			foreach (int point in points)
			{
				int baseP = point / 3;
				switch (point % 3)
				{
					case 0:
						if (baseP >= leasePoint)
						{
							count++;
						}
						else if (numOfSurprise > 0 && (baseP + 1 == leasePoint))
						{
							count++;
							numOfSurprise--;
						}
						break;
					case 1:
						if(baseP + 1 >= leasePoint) {
							count++;
						}
						break;
					case 2:
						if(baseP + 1 >= leasePoint) {
							count++;
						}else if(numOfSurprise > 0 && (baseP + 2 == leasePoint)) {
							count++;
							numOfSurprise--;							
						}
						break;
				}
			}
			return count;
		}


		private static int Solve(int numOfGoogler, int numOfSurprise, int leasePoint, List<int> points)
		{
			int count = 0;
			int surpriseCount = 0;
			//int optionalSurprise = 0;
			foreach (int point in points)
			{
				int remain = point - leasePoint;
				if (remain >= 0)
				{
					int p1 = remain / 2;
					int p2 = remain - p1;

					if (p1 + 1 >= leasePoint)
					{
						count++;
						//if(remain - leasePoint * 2 >= 2) {
						//    optionalSurprise++;
						//}
					}
					else if (p1 + 2 >= leasePoint)
					{
						surpriseCount++;
					}
					//else if( point >= 2 ) {
					//    optionalSurprise++;
					//}


				}
			}

			if (surpriseCount > numOfSurprise)
			{
				count = count + numOfSurprise;
			}
			else
			{
				count = count + surpriseCount;
			}

			return count;
		}
	}
}
