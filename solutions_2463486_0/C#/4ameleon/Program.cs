using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace Test
{
    public class Program
    {
		private static void Main()
		{
			Solve(Console.In, Console.Out);
		}

		private static string Add(string x, string y)
		{
			const byte zero = (byte)'0';
			int len = Math.Max(x.Length, y.Length);
			var result = new StringBuilder(len);

			x = x.PadRight(len, '0');
			y = y.PadRight(len, '0');

			for (int i = 0; i < len; i++)
				result.Append((char)((byte)x[i] + (byte)y[i] - zero));

			return result.ToString();
		}

		private static void AddSquare(string format, string prefix, string postfix, List<string> results)
		{
			string fair = String.Format(format, prefix, postfix);
			string square = "0";

			for (int k = 0; k < fair.Length; k++)
				for (int i = 0; i < (byte)fair[k] - (byte)'0'; i++)
					square = Add(square, new String('0', k) + fair);

			results.Add(square.PadLeft(100, '0'));
		}

		private static void FindNumbers(string prefix, string postfix, int sum, int length, List<string> results)
		{
			if (length > 1)
			{
				if (!String.IsNullOrEmpty(prefix)) FindNumbers(prefix + '0', '0' + postfix, sum, length - 1, results);
				if (sum >= 2) FindNumbers(prefix + '1', '1' + postfix, sum - 2, length - 1, results);
				if (sum >= 8) FindNumbers(prefix + '2', '2' + postfix, sum - 8, length - 1, results);
			}
			else
			{
				if (!String.IsNullOrEmpty(prefix)) AddSquare("{0}0{1}", prefix, postfix, results);
				if (sum >= 1) AddSquare("{0}1{1}", prefix, postfix, results);
				if (sum >= 4) AddSquare("{0}2{1}", prefix, postfix, results);
				if (sum >= 9) AddSquare("{0}3{1}", prefix, postfix, results);
				if (!String.IsNullOrEmpty(prefix)) AddSquare("{0}00{1}", prefix, postfix, results);
				if (sum >= 2) AddSquare("{0}11{1}", prefix, postfix, results);
				if (sum >= 8) AddSquare("{0}22{1}", prefix, postfix, results);
			}
		}

		public static void Solve(TextReader input, TextWriter output)
		{
			int t = Convert.ToInt32(input.ReadLine());
			List<string> results = new List<string>(50000);

			for (int k = 1; k <= 25; k++)
				FindNumbers(String.Empty, String.Empty, 9, k, results);

			for (int z = 1; z <= t; z++)
			{
				string[] data = input.ReadLine().Split(' ');
				string a = data[0].PadLeft(100, '0');
				string b = data[1].PadLeft(100, '0');
				int count = 0;

				foreach (string s in results)
					if ((s.CompareTo(a) >= 0) && (s.CompareTo(b) <= 0)) count++;

				output.WriteLine("Case #{0}: {1}", z, count);
			}
		}
    }
}