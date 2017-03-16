using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

//może się uda?

namespace sets
{
    class Program
    {
        class Sum
        {
            public int sum;
            public string key;
        }

        class ByKeyComparer : IEqualityComparer<Sum>
        {
            public bool Equals(Sum x, Sum y)
            {
                return x.key.Equals(y.key);
            }

            public int GetHashCode(Sum obj)
            {
                return obj.key.GetHashCode();
            }
        }

        static void Main(string[] args)
        {
            using (var inputStream = new StreamReader("..\\..\\input.txt"))
            using (var outputStream = new StreamWriter("..\\..\\output.txt.", false))
            {
                var totalCases = int.Parse(inputStream.ReadLine());

                for (var currentCase = 1; currentCase <= totalCases; currentCase++)
                {
                    var set = inputStream.ReadLine().Split().Select(s => int.Parse(s)).Skip(1).ToArray();
                    var combinationCount = 1 << set.Length;
                    var sums = new Sum[combinationCount];
                    for (var i = 0; i < combinationCount; i++)
                    {
                        var j = 0;
                        var current = i;
                        var key = new List<int>();
                        var sum = new Sum();
                        while (current > 0)
                        {
                            if (current % 2 == 1)
                            {
                                sum.sum += set[j];
                                key.Add(set[j]);
                            }
                            current = current >> 1;
                            j++;
                        }
                        key.Sort();
                        sum.key = string.Join(" ", key.ToArray());
                        sums[i] = sum;
                    }

                    var sameKeysAndSums = sums.GroupBy(s => s.sum).Where(g => g.Distinct(new ByKeyComparer()).Count() > 1).ToLookup(g => g.Key);

                    outputStream.WriteLine("Case #{0}:", currentCase);
                    if (sameKeysAndSums.Any())
                    {
                        var suma = sameKeysAndSums.First().Key;
                        var keys = sameKeysAndSums.First().First().Distinct(new ByKeyComparer()).Select(s => s.key).ToArray();
                        outputStream.WriteLine(keys[0]);
                        outputStream.WriteLine(keys[1]);
                    }
                    else
                    {
                        outputStream.WriteLine("Impossible");
                    }
                }
            }
        }
    }
}
