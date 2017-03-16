using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam
{
	class Program
	{
		static string solve121AB(IEnumerable<string> args)
		{
			//Console.WriteLine(">> {0}", args.ElementAt(0));
			var input = args.Select(x => x.Split(new char[] { ' ' }));
			
			var s = new List<int>();
			for (int i = 1; i < input.Count(); i++)
			{
				s.Add((int.Parse(input.ElementAt(i).ElementAt(1)) * 10000) + int.Parse(input.ElementAt(i).ElementAt(0)));
			}
			s.Sort();

			var star = 0;
			var count = 0;
			for (int i = 0; i < s.Count; i++)
			{
				var req = s[i] / 10000;
				while (req > star) {
					var ok = false;
					for (int j = s.Count - 1; j >= 0; j--)
					{
						var req1 = s[j] % 10000;
						if (req1 <= star)
						{
							ok = true;
							star++;
							count++;
							s[j] = (s[j] / 10000 * 10000) + 9999;
							break;
						}
					}
					if (!ok) return "Too Bad";
				}
				star += s[i] % 10000 == 9999 ? 1 : 2;
				count++;
				s[i] = 9999;
			}

			//Console.WriteLine("<< {0}", count);
			return count.ToString();
		}

		static void Main(string[] args)
		{
			var input = File.ReadAllLines("z.in");
			var prepare = new List<IEnumerable<string>>();
			for (int i = 1; i < input.Length; i++)
			{
				var size = int.Parse(input[i].Split(new char[] { ' ' }).First());
				prepare.Add(input.Skip(i).Take(size + 1)); // Extra var in first line
				i += size;
			}
			File.WriteAllLines("z.txt", prepare.AsParallel().AsOrdered().Select((x, i) => "Case #" + (i + 1) + ": " + solve121AB(x)));
			//Console.ReadKey();
		}
	}
}
