using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Dynamic;

namespace CodeJam
{
	public class RecycledNumbers
	{
		public static void DoJob(string inputfile, string outputfile)
		{
			TextReader reader = new StreamReader(inputfile);
			TextWriter writer = new StreamWriter(outputfile);
			int TestCases = int.Parse(reader.ReadLine());

			for (int line = 0; line < TestCases; line++)
			{
				string text = reader.ReadLine();
				string[] words = text.Split(' ');
				int smallNumber = int.Parse(words[0]);
				int bigNumber = int.Parse(words[1]);
				int pairs = 0;
				Dictionary<int, ICollection<int>> pairset = new Dictionary<int, ICollection<int>>();

				for (int counter = smallNumber; counter < bigNumber; counter++)
				{
					string digitstring = counter.ToString();
					pairset.Add(counter, new LinkedList<int>());
					for (int cut = 1; cut < counter.ToString().Length; cut++)
					{
						int recyclednumber = int.Parse(digitstring.Substring(cut) + digitstring.Substring(0, cut));
						if (recyclednumber > counter && recyclednumber <= bigNumber && !pairset[counter].Contains(recyclednumber))
						{
							
							pairs++;
							pairset[counter].Add(recyclednumber);
						}
					}
				}

				//output:
				string sout = "Case #" + (line + 1) + ": " + pairs;
				writer.WriteLine(sout);
				Console.WriteLine(sout);
				writer.Flush();

			}

			Console.ReadKey();
		}
		class Pair
		{
			public int Small { get; set; }
			public int Big { get; set; }
			public override bool Equals(object obj)
			{
				Pair pair = obj as Pair;
				if (pair == null)
					return false;
				else
					if (pair.Big == Big && pair.Small == Small)
						return true;
				return false;
			}
			public override int GetHashCode()
			{
				return Big * Small + Small;
			}
		}
	}
}
