using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Marius.CodeJam
{
    public class Program
    {
        public static void Main(string[] args)
        {
            using (var input = new StreamReader(@"..\..\input.txt"))
            using (var output = new StreamWriter(@"..\..\output.txt"))
            {
                var caseCount = int.Parse(input.ReadLine());
                for (var currentCase = 1; currentCase <= caseCount; currentCase++)
                {
                    input.ReadLine();
                    var plates = input.ReadLine().Split().Select(s => int.Parse(s)).ToArray();
                    var max = plates.Max();
                    var data = new int[max + 1];
                    for (var i = 0; i < plates.Length; i++)
                    {
                        data[plates[i]]++;
                    }

                    var sorted = new SortedDictionary<int, int>(new ReverseComparer());
                    for (int i = 0; i < data.Length; i++)
                    {
                        if (data[i] != 0)
                            sorted.Add(i, data[i]);
                    }

                    var result = max;
                    var spent = 0;
                    while (true)
                    {
                        var it = sorted.GetEnumerator();
                        if (!it.MoveNext())
                            break;

                        var current = it.Current;
                        var next = 0;
                        if (it.MoveNext())
                            next = it.Current.Key;

                        sorted.Remove(current.Key);

                        var index = current.Key;
                        var value = current.Value;
                        if (index <= 2)
                            break;

                        var left = index >> 1;
                        var right = left;
                        if ((index & 1) == 1)
                            right++;

                        if (next < right)
                            next = right;

                        var test = spent + value + next;
                        if (test < result)
                            result = test;
                        spent += value;

                        var update = 0;
                        sorted.TryGetValue(left, out update);
                        update += value;
                        sorted[left] = update;

                        sorted.TryGetValue(right, out update);
                        update += value;
                        sorted[right] = update;
                    }

                    output.WriteLine("Case #{0}: {1}", currentCase, result);
                }
            }
        }

        public class ReverseComparer : IComparer<int>
        {
            public int Compare(int x, int y)
            {
                return y - x;
            }
        }
    }
}
