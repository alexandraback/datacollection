using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GoogleCodeJam._1C
{
    class A
    {
        static void Main(string[] args)
        {
            var input = @"..\..\1C\A-small-attempt1.in";

            var result = Solver.Solve(File.ReadAllLines(input));
            File.WriteAllLines(Path.ChangeExtension(input, "out"), result);

            Console.WriteLine("Press ENTER to finish");
            Console.ReadLine();
        }

        public class Solver
        {
            public static IEnumerable<string> Solve(IEnumerable<string> input)
            {
                var reader = new Reader(input);
                var testCount = int.Parse(reader.Next());

                for (var i = 0; i < testCount; i++)
                {
                    var value = reader.Next().Split(' ').Select(int.Parse).ToArray();
                    var r = value[0];
                    var c = value[1];
                    var w = value[2];

                    yield return string.Format("Case #{0}: {1}", i + 1, SolveCase(r, c, w));
                }
            }

            public static int SolveCase(int r, int c, int w)
            {
                var fires = 0;

                var e = c;

                while (e >= w * 2)
                {
                    e -= w;
                    fires += r;
                }

                fires += r - 1;

                if (e > w)
                    fires += w + 1;
                else
                    fires += w;

                return fires;
            }
        }

        private class Reader
        {
            private readonly IEnumerator<string> _enumerator;

            public Reader(IEnumerable<string> lines)
            {
                _enumerator = lines.GetEnumerator();
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
