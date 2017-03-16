using System;
using System.Globalization;
using System.IO;
using System.Linq;

namespace DeceitfulWar
{
	class Program
	{
		static void Main(string[] args)
		{
			var inFile = @"C:\Repository\GoogleCodeJam\Qualification2014\DeceitfulWar\bin\Debug\D-small-attempt1.in";
			var outFile = @"C:\Repository\GoogleCodeJam\Qualification2014\DeceitfulWar\bin\Debug\output.out";

			var reader = new StreamReader(inFile);
			var writer = new StreamWriter(outFile);

			var T = int.Parse(reader.ReadLine());
			for (int i = 1; i <= T; i++)
			{
				int N = int.Parse(reader.ReadLine());
				decimal[] bN = reader.ReadLine().Split(new[] { ' ' }).Select(d => decimal.Parse(d, CultureInfo.InvariantCulture)).ToArray();
				decimal[] bK = reader.ReadLine().Split(new[] { ' ' }).Select(d => decimal.Parse(d, CultureInfo.InvariantCulture)).ToArray();
				Array.Sort(bN);
				Array.Sort(bK);
				
				int dWar = 0, j = 0, k = 0;
				while (j < N)
				{
					if (bN[j] > bK[k])
					{
						dWar++;
						j++;
						k++;
					}
					else
						j++;
				}
				
				int war = 0;
				for (j = 0; j < N; j++)
				{
					war++;
					for (k = j; k < N; k++)
						if (bK[k] > bN[j])
						{
							bK[k] = bK[j];
							war--;
							break;
						}
				}

				writer.WriteLine(string.Format("Case #{0}: {1} {2}", i, dWar, war));
			}

			reader.Close();
			writer.Close();
		}
	}
}
