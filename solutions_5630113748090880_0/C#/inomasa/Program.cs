using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2016
{
    class Program
    {
        static void Main(string[] args)
        {
            var filename = new[] { "test.in", "B-small-attempt0.in", "B-large.in" }[1];
            using (var output = new StreamWriter(Path.ChangeExtension(filename, ".out")))
            using (var input = new StreamReader(filename))
            {
                Round0C(input, output);
            }
        }

        static void Round0C(StreamReader fileInput, StreamWriter fileOutput)
        {
            var T = int.Parse(fileInput.ReadLine());
            for (int t = 0; t < T; t++)
            {
                var N = int.Parse(fileInput.ReadLine());
                var list = new int[N*2-1][];
                for (int j = 0; j < list.Length; j++)
                    list[j] = fileInput.ReadLine().Split(' ').Select(i => int.Parse(i)).ToArray();

                var count = new int[2501];
                foreach (var line in list)
                {
                    foreach (var cell in line)
                        count[cell]++;
                }
                var missing = new List<int>();
                for (int i = 0; i < count.Length; i++)
                    if (count[i] % 2 == 1) missing.Add(i);

                var result = string.Format("Case #{0}: {1}", t + 1, string.Join(" ", missing));
                Console.WriteLine(result);
                fileOutput.WriteLine(result);
            }
        }

    }
}
