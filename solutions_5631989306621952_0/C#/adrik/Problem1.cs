using System.Collections.Generic;
using System.Linq;
using Utils;

namespace Round1A
{
    public class Problem1 : AbstractProblem<string, string>
    {
        protected override IEnumerable<string> ReadTestCases(IEnumerable<string> lines, int testCases)
        {
            return lines;
        }

        protected override IEnumerable<string> CreateOutput(string output, int index)
        {
            return Enumerable.Repeat($"Case #{index + 1}: {output}", 1);
        }

        protected override string Solve(string input)
        {
            var result = new LinkedList<char>();
            foreach (var c in input)
            {
                if (result.Count > 0 && c >= result.First.Value)
                    result.AddFirst(c);
                else
                    result.AddLast(c);
            }
            return new string(result.ToArray());
        }
    }
}
