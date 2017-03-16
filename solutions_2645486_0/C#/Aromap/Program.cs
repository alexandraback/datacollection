using System;
using System.IO;
using System.Collections.Generic;

namespace Round1A
{
	class MainClass
	{
		static string InputFileName = "./Input";
		static string OutputFileName = "./Output";

		public static void Main (string[] args)
		{
			StreamReader inputstream = File.OpenText(InputFileName);
			string line = inputstream.ReadLine();
			int nbCases = 0;
			int.TryParse(line, out nbCases);
			List<string> results = new List<string>();

			int currentCase = 0;
			while(nbCases > currentCase++)
				results.Add(ResolveCase(ref inputstream));

			WriteCasesResults(ref results);

		}

		public static string ResolveCase(ref StreamReader inputstream)
		{
			string line = inputstream.ReadLine();
			string[] splits = line.Split(new char[1]{' '});
			int e,r,n;
			int.TryParse(splits[0],out e);
			int.TryParse(splits[1],out r);
			int.TryParse(splits[2],out n);

			line = inputstream.ReadLine();
			splits = line.Split(new char[1]{' '});
			int[] gains = new int[n];
			for(int p = 0; p < n; p++)
				int.TryParse(splits[p],out gains[p]);

			int score = 0;
			int eC = e;
			for(int p = 0; p < n; p++)
			{
				int usable = eC;
				int pDiff = 1;
				if(p < (n - 1))
				{
					bool isMax = false;
					for(int l = p+1; l < n; l++)
					{
						if(gains[p] < gains[l])
							break;
						if(l < n - 1)
							pDiff++;
						else
							isMax = true;
					}
					if(!isMax)
					{
						int eDiff = eC + pDiff * r - e;
						usable = eDiff > 0 ? eDiff : 0;
						usable = usable > e ? e : usable;
					}
				}
				score += usable * gains[p];
				eC += r - usable;
			}

			return score.ToString();
		}

		public static void WriteCasesResults(ref List<string> results)
		{
			StreamWriter writer = new StreamWriter(OutputFileName);
			
			int countWrite = 1;
			foreach(string result in results)
			{
				writer.WriteLine("Case #" + countWrite.ToString() + ": " + result);
				countWrite++;
			}

			writer.Close();
		}
	}
}
