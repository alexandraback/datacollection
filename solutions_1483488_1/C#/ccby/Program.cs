using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ProblemC
{
	class Program
	{
		static void Main(string[] args)
		{
			string file = "C-large";
			StreamReader sr = new StreamReader(new FileStream(file + ".in", FileMode.Open, FileAccess.Read));
			StreamWriter sw = new StreamWriter(new FileStream(file + ".out", FileMode.OpenOrCreate, FileAccess.Write));

			int maxCase = Convert.ToInt32(sr.ReadLine());

			for (int i = 0; i < maxCase; i++)
			{
				string[] para = sr.ReadLine().Split(new Char[] { ' ' });
				int min = Convert.ToInt32(para[0]);
				int max = Convert.ToInt32(para[1]);
				
				int result = Solve(min,max);

				//output
				Console.WriteLine("Case #{0}: {1}", i + 1, result.ToString());
				sw.WriteLine("Case #{0}: {1}", i + 1, result.ToString());
			}


			//close
			sr.Close();
			sw.Close();
		}

		private static int Solve(int min, int max)
		{
			int count = 0;
			var table = new Dictionary<int,bool>();
			for( int i = min; i <= max; i++) {
				table.Add(i,false);
			}

			for( int i = min; i< max; i++) {
				if(table[i] == true) {
					continue;
				}
				
				table[i] = true;
				int numOfDigits = i.ToString().ToCharArray().Length;
				List<int> cycleList = new List<int>();
				cycleList.Add(i);
				for( int j = 0; j < numOfDigits - 1; j++ ) {
					int cycledValue = Convert.ToInt32(String.Format("{0}{1}",i.ToString().Substring(j + 1), i.ToString().Substring(0,j + 1)));
					if(cycledValue >= min && cycledValue <= max && (!cycleList.Contains(cycledValue))) {
						cycleList.Add(cycledValue);
						table[cycledValue] = true;
					}
				}

				if (cycleList.Count > 1)
				{
					count = count + (cycleList.Count) * (cycleList.Count - 1) / 2;
				}
			}
			return count;
		}
	}
}
