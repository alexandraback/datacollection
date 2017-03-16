using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace C
{
    class Program
    {
        static void Main(string[] args)
        {
            var dir = "d:\\";
            var inputFileName = "C-small-attempt1";
            var inputFile = inputFileName + ".txt";
            var outputFile = inputFile.Replace(".txt", "_out.txt");

            using (var reader = new StreamReader(dir + inputFile))
            {
                using (var writer = new StreamWriter(dir + outputFile))
                {
                    var cases = int.Parse(reader.ReadLine());
                    for (int c = 1; c <= cases; c++)
                    {
                        var parts = reader.ReadLine().Split(new[] { " " }, StringSplitOptions.RemoveEmptyEntries);
                        var array = parts.Skip(1).Select(v => int.Parse(v)).ToArray();

                        var tuple = FindSets(array.ToList());
                        string line = string.Format("Case #{0}:\n{1}", c, "Impossible");

                        if (tuple != null)
                            line = string.Format("Case #{0}:\n{1}\n{2}", c, string.Join(" ", tuple.Item1), string.Join(" ", tuple.Item2));

                        Console.WriteLine(line);
                        writer.WriteLine(line);
                    }
                }
            }

            Console.ReadKey();
        }

        private static Tuple<int[], int[]> FindSets(List<int> array)
        {
            var s = array.Sum();
            var n = array.Count();
            var SEP_SUM = ";"; var SEP_SUM_ARR = new[] { SEP_SUM };
            var SEP_NUM = ","; var SEP_NUM_ARR = new[] { SEP_NUM };

            Dictionary<int, int> indexes = array.ToDictionary(v => v, v => array.IndexOf(v));
            Dictionary<int, string> memo = new Dictionary<int, string>();

            for (int i = 1; i <= s; i++)
            {
                if (indexes.ContainsKey(i)) memo.Add(i, i.ToString());
                foreach (var number in array)
                {
                    if (i - number > 0 && memo.ContainsKey(i - number))
                    {
                        var prevsum = memo[i - number];
                        var sums = prevsum.Split(SEP_SUM_ARR, StringSplitOptions.RemoveEmptyEntries);
                        foreach (var sum in sums)
                        {
                            var nums = sum.Split(SEP_NUM_ARR, StringSplitOptions.RemoveEmptyEntries);
                            if (nums.Contains(number.ToString())) continue;

                            if (!memo.ContainsKey(i))
                                memo.Add(i, sum + SEP_NUM + number.ToString());
                            else
                            {
                                var xo = memo[i].Split(SEP_NUM_ARR, StringSplitOptions.RemoveEmptyEntries).Select(x => int.Parse(x)).OrderBy(x => x).ToArray();
                                var xn = (sum + SEP_NUM + number.ToString()).Split(SEP_NUM_ARR, StringSplitOptions.RemoveEmptyEntries).Select(x => int.Parse(x)).OrderBy(x => x).ToArray();

                                if (xo.Length != xn.Length)
                                    return new Tuple<int[], int[]>(xo, xn);

                                if(xo.ToList().Intersect(xn).Count() != xo.Length)
                                    return new Tuple<int[], int[]>(xo, xn);
                            }
                        }
                    }
                }
            }

            return null;
        }
    }
}
