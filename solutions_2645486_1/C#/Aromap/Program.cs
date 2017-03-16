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
			long e,r,n;
			long.TryParse(splits[0],out e);
			long.TryParse(splits[1],out r);
			long.TryParse(splits[2],out n);

			line = inputstream.ReadLine();
			splits = line.Split(new char[1]{' '});
			long[] gains = new long[n];
			for(long p = 0; p < n; p++)
				long.TryParse(splits[p],out gains[p]);

			long score = 0;
			long eC = e;
			for(long p = 0; p < n; p++)
			{
				long usable = eC;
				long pDiff = 1;
				if(p < (n - 1))
				{
					bool isMax = false;
					for(long l = p+1; l < n; l++)
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
						long eDiff = eC + pDiff * r - e;
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
