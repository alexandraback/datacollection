using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamWriter writer = new StreamWriter(@"D:\output.txt"))
            {
                using (StreamReader reader = new StreamReader(File.OpenRead(@"D:\input.txt")))
                {
                    int cases = int.Parse(reader.ReadLine());
                    for (int i = 0; i < cases; i++)
                    {
                        Process(i, reader, writer);
                    }
                }
            }
        }

        private static void Process(int num, StreamReader reader, StreamWriter writer)
        {
            int caseId = num + 1;

            var row = reader.ReadLine().Split(' ');
            var N = int.Parse(row[0]);
            var numbers = new List<int>();
            for (var i = 0; i < N; i++)
            {
                var val = int.Parse(row[i + 1]);
                numbers.Add(val);
            }

            var ordered = numbers.OrderBy(x => x).ToList();
            var sum = numbers.Sum();
            var max = sum / 2;

            var dict = new Dictionary<int, HashSet<int>>();
            var flag = false;
            HashSet<int> set = new HashSet<int>();
            HashSet<int> set1 = new HashSet<int>();
            for (var i = 0; i < Math.Pow(2, N); i++)
            {
                var total = 0;
                set = new HashSet<int>();
                for (var j = 0; j < N; j++)
                {
                    if ((i & (int)Math.Pow(2, j)) > 0)
                    {
                        total += numbers[j];
                        set.Add(numbers[j]);
                    }
                }
                if (dict.ContainsKey(total))
                {
                    flag = true;
                    set1 = dict[total];
                    break;
                }
                else
                {
                    dict.Add(total, set);
                }
            }

            writer.WriteLine("Case #{0}:", caseId);

            if (flag)
            {
                writer.WriteLine(string.Join(" ", set));
                writer.WriteLine(string.Join(" ", set1));
            }
            else
            {
                writer.WriteLine("Case #{0}: Impossible");
            }
        }
    }
}
