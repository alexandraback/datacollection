using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Collections.Immutable;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam
{
    public class B
    {
        static void Main(string[] args)
        {
            //Console.WriteLine(B.Solver.EatAll(Enumerable.Repeat(200, 30).ToImmutableList()));

            var input = @"C:\Users\kaspir\Downloads\B-small-attempt3.in";

            File.WriteAllLines(Path.ChangeExtension(input, "out"), Solver.Solve(File.ReadAllLines(input)));

            Console.WriteLine("Press ENTER to finish");
            Console.ReadLine();
        }

        public class Solver
        {
            public static IEnumerable<string> Solve(IEnumerable<string> input)
            {
                var reader = new Reader(input);

                var testCount = Int32.Parse(reader.Next());

                for (var i = 0; i < testCount; i++)
                {
                    reader.Next();
                    var p = reader.Next().Split(' ').Select(int.Parse).ToImmutableList();
                    var message = String.Format("Case #{0}: {1}", i + 1, new Solver().EatAll(p));
                    Console.WriteLine(message);
                    yield return message;
                }
            }

            readonly Dictionary<string, int> Cache = new Dictionary<string, int>(); 

            public int EatAll(ImmutableList<int> p)
            {
                if (!p.Any())
                    return 0;

                int cached;

                var key = string.Join("_", p);
                if (Cache.TryGetValue(key, out cached))
                    return cached;

                var max = p.Max();

                var min = max;

                if (max > 1)
                {
                    var split = 1 + EatAll(p.Remove(max).Add(max / 2).Add(max - max / 2));
                    if (split < min)
                        min = split;
                }

                return Cache[key] = min;
            }
        }

        class Reader
        {
            readonly IEnumerator<string> _enumerator;

            public Reader(IEnumerable<string> lines)
            {
                _enumerator = lines.GetEnumerator();
            }

            public string NextOrNull()
            {
                if (!_enumerator.MoveNext())
                    return null;

                return _enumerator.Current;
            }

            public string Next()
            {
                if (!_enumerator.MoveNext())
                    throw new ApplicationException("End of input");

                return _enumerator.Current;
            }
        }
    }
}
