using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace B
{
	class ProblemB
	{
		static void Main(string[] args)
		{
			var inputfile = new FileStream("B-small-attempt0.in", FileMode.Open);
			var input = new StreamReader(inputfile);
			var outputFile = new FileStream("B-small-attempt0.out", FileMode.Create);
			var output = new StreamWriter(outputFile);
			char[] sep = { ' ' };

			var str = input.ReadLine();
			string[] temp = str.Split(sep);

			int testCase = int.Parse(temp[0]);
			for (int tc = 1; tc <= testCase; tc++)
			{
				str = input.ReadLine();
				var n = int.Parse(str);
				var list = new List<int>();				
				
				for (int i = 0; i < 2*n-1; i++)
				{
					str = input.ReadLine();
					temp = str.Split(sep);
					for (int j = 0; j < n; j++)
					{
						var z = int.Parse(temp[j]);
						if (list.Contains(z))
						{
							list.Remove(z);
						}
						else
						{
							list.Add(z);
						}
					}
				}

				list.Sort();
				output.Write("Case #{0}:", tc);
				for (int i = 0; i < n; i++)
				{
					output.Write(" {0}",list[i]);
				}
				output.WriteLine();


			}

			inputfile.Close();
			output.Close();
			outputFile.Close();

		}
	}
}
