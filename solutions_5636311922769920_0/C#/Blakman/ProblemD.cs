using System.IO;
using System.Linq;
using MoreLinq;

namespace GCJ.Impl._2016_Qual
{
	public class ProblemD : ProblemBase
	{
		protected override bool SolveOne(StreamReader reader, StreamWriter writer, int testNumber)
		{
			int k, c, s;
			ReadInts(reader, out k, out c, out s);
			var res = Enumerable.Repeat(0, (c - k%c)%c).Concat(Enumerable.Range(0, k)).Batch(c).Select(a => a.Aggregate<int, long>(0, (r, i) => r*k + i)).Select(r => r + 1).ToArray();
			if (res.Length > s)
				Write(writer, testNumber, "IMPOSSIBLE");
			else
				Write(writer, testNumber, res);
			return true;
		}
	}
}