using System;
using System.Linq;
using System.Text;
using System.IO;

namespace Round1AQ1
{
	class MainClass
	{
		public static string GetSolution(string line){

			var solution = string.Empty;

			foreach (var letter in line) {

				if (solution.Length == 0) {
					solution += letter;
				} else {
					var c = solution.First ();

					if (c <= letter) {
						solution = letter + solution;
					} else {
						solution = solution + letter;
					}
				}
			}

			return solution;
		}

		public static void Main (string[] args)
		{
			var lines = File.ReadLines (args [0]).ToArray();
			var output = new StringBuilder();

			for (int i = 1; i <= int.Parse (lines[0]); i++) {
				output.AppendLine (string.Format ("Case #{0}: {1}", i, GetSolution(lines[i])));
			}

			File.WriteAllText(args[0] + ".out", output.ToString());
			Console.Write(output.ToString());
		}
	}
}