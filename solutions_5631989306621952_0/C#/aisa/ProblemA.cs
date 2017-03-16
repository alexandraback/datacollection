using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace A
{
	class ProblemA
	{
		static void Main(string[] args)
		{
			var inputfile = new FileStream("A-small-attempt0.in", FileMode.Open);
			var input = new StreamReader(inputfile);
			var outputFile = new FileStream("A-small-attempt0.out", FileMode.Create);
			var output = new StreamWriter(outputFile);
			char[] sep = { ' ' };

			var str = input.ReadLine();
			string[] temp = str.Split(sep);

			int testCase = int.Parse(temp[0]);
			for (int tc = 1; tc <= testCase; tc++)
			{
				str = input.ReadLine();
				var result = str[0].ToString();
				for (int i = 1; i < str.Length; i++)
				{
					if (str[i] < result[0])
					{
						result += str[i];
					}
					else
					{
						result = str[i] + result;
					}
				}


				output.WriteLine("Case #{0}: {1}", tc, result);


			}

			inputfile.Close();
			output.Close();
			outputFile.Close();

		}
	}
}
