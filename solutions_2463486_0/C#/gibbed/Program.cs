using System;
using System.IO;
using System.Linq;

namespace Gibbed.GoogleCodeJam2013.Qualification.ProblemC
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            var fairAndSquare = Enumerable.Range(1, 10000000)
                                          .Where(i => IsFairAndSquare(i) == true)
                                          .Select(i => (long)i * (long)i)
                                          .OrderBy(i => i)
                                          .ToArray();

            var data = Console.In;
            //var data = new StreamReader("C-sample.in");

            string input;
            string[] parts;

            input = data.ReadLine();
            if (input == null)
            {
                throw new EndOfStreamException();
            }

            var count = byte.Parse(input);
            for (byte i = 1; i <= count; i++)
            {
                input = data.ReadLine();
                if (input == null)
                {
                    throw new EndOfStreamException();
                }

                parts = input.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                var start = long.Parse(parts[0]);
                var stop = long.Parse(parts[1]);

                var results = fairAndSquare.Where(v => v >= start && v <= stop).ToArray();
                //Console.WriteLine("Case #{0}: {1} ; {2}", i, results.Length, string.Join(", ", results.Select(r => r.ToString())));
                Console.WriteLine("Case #{0}: {1}", i, results.Length);
            }
        }

        public static string Reverse(string s)
        {
            var c = s.ToCharArray();
            Array.Reverse(c);
            return new string(c);
        }

        private static bool IsFairAndSquare(long value)
        {
            var a = value.ToString();
            if (a != Reverse(a))
            {
                return false;
            }

            var b = (value * value).ToString();
            return b == Reverse(b);
        }
    }
}
