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
			long r,t;
			long.TryParse(splits[0],out r);
			long.TryParse(splits[1],out t);
			long n = 0;
			long c = 0;
			while(t>0)
			{
				t -= 2*r + 2*n + 1;
				if(t>=0)
					c++;
				n+=2;
			}
			return c.ToString();
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
