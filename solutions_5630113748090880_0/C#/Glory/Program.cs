using System;
using System.Text;
using System.Linq;
using System.IO;
using System.Collections.Generic ;

namespace Round1AQ2
{
	class MainClass
	{
		public static string GetSolution(string[] lines, ref int pos){

		
			var c =int.Parse (lines [pos]);
			var r = c * 2 - 1;

			var array = new int[r,c]; 

			for (int i = 0; i < r; i++) {

				var line = lines [pos + i+1].Split (' ');
				for (int j = 0; j < c; j++) {

					array[i,j] = int.Parse (line [j]);
				}
			}

			pos += r+1;

			int[] qq = new int[2500];
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++) {
					qq [array [i,j]]++;
				}
			
			var missing = new List<int> ();
			for (int i = 0; i < qq.Length; i++) {

				if (qq [i] % 2 != 0) {
					missing.Add (i);
				}
			}
			missing.Sort ();
			return string.Join(" ", missing);
		}

		public static void Main (string[] args)
		{
			var lines = File.ReadLines (args [0]).ToArray();
			var output = new StringBuilder();

			int pos = 1;
			for (int i = 1; i <= int.Parse (lines[0]); i++) {
				output.AppendLine (string.Format ("Case #{0}: {1}", i, GetSolution(lines, ref pos)));
			}

			File.WriteAllText(args[0] + ".out", output.ToString());
			Console.WriteLine(output.ToString());
		}
	}
}