using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GCJ.Impl._2016_Qual
{
	public class ProblemA : ProblemBase
	{
		protected override bool SolveOne(StreamReader reader, StreamWriter writer, int testNumber)
		{
			var n = ReadInts(reader).First();
			if (n == 0)
				return Write(writer, testNumber, "INSOMNIA");
			int i;
			var c = new HashSet<char>();
			for (i = n; ; i += n)
			{
				foreach (var cc in $"{i}")
					c.Add(cc);
				if (c.Count == 10)
					return Write(writer, testNumber, i);
			}
		}
	}
}