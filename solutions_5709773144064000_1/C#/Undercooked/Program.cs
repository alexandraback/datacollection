using System.Globalization;
using System.IO;
using System.Linq;

namespace CookieClickerAlpha
{
	class Program
	{
		static void Main(string[] args)
		{
			var inFile = @"C:\Repository\GoogleCodeJam\Qualification2014\CookieClickerAlpha\bin\Debug\B-large.in";
			var outFile = @"C:\Repository\GoogleCodeJam\Qualification2014\CookieClickerAlpha\bin\Debug\output.out";

			var reader = new StreamReader(inFile);
			var writer = new StreamWriter(outFile);

			var T = int.Parse(reader.ReadLine());
			for (int i = 1; i <= T; i++)
			{
				decimal[] CFX = reader.ReadLine().Split(new[] { ' ' }).Select(n => decimal.Parse(n, CultureInfo.InvariantCulture)).ToArray();
				decimal C = CFX[0];
				decimal F = CFX[1];
				decimal X = CFX[2];
				decimal R = 2;
				decimal time = 0;

				while (X / R > C / R + X / (R + F))
				{
					time += C / R;
					R += F;
				}
				time += X / R;
				writer.WriteLine("Case #" + i + ": " + time.ToString("F7", CultureInfo.InvariantCulture));
			}

			reader.Close();
			writer.Close();
		}
	}
}
