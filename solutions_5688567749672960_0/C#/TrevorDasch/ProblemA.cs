using System;
using System.IO;
using System.Linq;

namespace CodeJam.Round1B
{
	public class ProblemA
	{
		public static void Main(string[] args)
		{
			using (var input = new StreamReader(File.OpenRead("../../Input.txt")))
			{
				using (var output = new StreamWriter(File.OpenWrite("../../Output.txt")))
				{
					int cases = int.Parse(input.ReadLine());

					for (int i = 0; i < cases; i++)
					{
						var result = GetResult(input);

						Console.WriteLine("Case #" + (i + 1) + ": " + result);
						output.WriteLine("Case #" + (i + 1) + ": " + result);
					}
				}
			}
		}

		public static string GetResult(StreamReader input)
		{
			string line = input.ReadLine();
			int num = int.Parse(line);

			if (num <= 20)
			{
				return num.ToString();
			}

			int count = 0;

			//all numbers end in not 0 now
			if (line[line.Length - 1] == '0')
			{
				count++;
				num--;
			}

			line = num.ToString();

			var digits = line.ToCharArray().Select(x => int.Parse(x.ToString())).ToArray();

			//first step, aquire correct umber of digits

			int size = 10;
			for (int i = 1; i <= digits.Length; i++)
			{
				var initial = Enumerable.Repeat(0, i).ToArray();
				var desired = i == digits.Length ? digits : Enumerable.Repeat(9, i).ToArray();

				initial[0] = 1;

				count += 1 + CountToDigit(initial, desired);
			}

				
			return count.ToString();
		}

		public static int CountToDigit(int[] initial, int [] desired)
		{
			bool swapped = false;
			for (int i = 0; i < initial.Length / 2; i++)
			{
				if (initial[i] != desired[i])
				{
					swapped = true;
					break;
				}
			}

			int count = swapped ? 1 : 0;

			for (int i = 0; i < initial.Length; i++)
			{
				int j = swapped ? initial.Length - i - 1 : i;

				int size = (int)Math.Pow(10, Math.Min(i, initial.Length - i - 1));

				count += size * (desired[j] - initial[i]);
			}
			return count;
		}
	}
}

