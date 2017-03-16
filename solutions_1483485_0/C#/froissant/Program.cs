using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam1
{
	class Program
	{
		public static string alphabet = "abcdefghijklmnopqrstuvwxyz";
		static void Main(string[] args)
		{
			//string[] input = new string[caseNumber];
			//string[] output = new string[caseNumber];
			string[] input = 
			{
				"ejp mysljylc kd kxveddknmc re jsicpdrysi",
				"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
				"de kr kd eoya kw aej tysr re ujdr lkgc jv"
			};

			string[] output = 
			{
				"our language is impossible to understand",
				"there are twenty six factorial possibilities",
				"so it is okay if you want to just give up"
			};

			Dictionary<char, char> mapping = new Dictionary<char, char>();
			mapping.Add('y', 'a');
			mapping.Add('e', 'o');
			mapping.Add('z', 'q');
			mapping.Add('q', 'z');
			for (int i = 0; i < input.Length; i++)
			{
				for (int j = 0; j < input[i].Length; j++)
				{
					char c = input[i][j];
					if (!mapping.Keys.Contains(c))
					{
						mapping.Add(c, output[i][j]);
					}
				}
			}

			List<string> inputCases = new List<string>();
			try
			{
				using (StreamReader sr = new StreamReader(File.OpenRead("A-small-attempt2.in")))
				{
					using (StreamWriter sw = new StreamWriter(File.OpenWrite("A-small-attempt2.out")))
					{
						int caseNumber = int.Parse(sr.ReadLine());
						int i = 0;
						while (sr.Peek() > 0)
						{
							string t = "";
							string inputCase = sr.ReadLine();
							foreach (char c in inputCase)
							{
								t += mapping[c];
							}
							sw.WriteLine("Case #" + ++i + ": " + t);
						}
					}
				}
			}
			catch
			{
				Console.WriteLine("Check that input file (A-small-attempt2.in) is in the same directory.");
			}
		}
	}
}
