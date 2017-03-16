using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Qualification
{
	class Googlerese
	{
		static void Main(string[] args)
		{
			var fileContent = File.ReadAllLines(@"C:\Z\Projects\CodeJam2012\Qualification\bin\Debug\A-small-attempt1.in");
			var numTests = int.Parse(fileContent[0]);

			var clueEnc = "qazour language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";
			var clueDec = "zyqejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
			var decoder = clueDec.Zip(clueEnc, (first, second) => new { From = first, To = second }).Distinct().ToDictionary(n => n.From, n => n.To);

			for (int i = 0; i < numTests; i++)
			{
				var encoded = fileContent[i + 1];
				Console.WriteLine(Solve(i+1, encoded, decoder));
			}
			//Console.ReadKey();
		}

		private static string Solve(int testNum, string ecoded, Dictionary<char, char> decoder)
		{
			var result = string.Concat(ecoded.Select(n => decoder[n]));
			return "Case #" + testNum + ": " + result;
		}
	}
}
