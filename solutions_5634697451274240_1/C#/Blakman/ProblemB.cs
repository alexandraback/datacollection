using System.IO;
using System.Linq;

namespace GCJ.Impl._2016_Qual
{
	public class ProblemB : ProblemBase
	{
		protected override bool SolveOne(StreamReader reader, StreamWriter writer, int testNumber)
		{
			var s = reader.ReadLine() + '+';
			var res = Enumerable.Range(0, s.Length - 1).Count(i => s[i] != s[i + 1]);
			Write(writer, testNumber, res);
			return true;
		}
	}
}