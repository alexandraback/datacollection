using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Round1.A.CS
{
    class Program
    {
        static void Main(string[] args)
        {
            var reader = new StreamReader("input.txt");
            var writer = new StreamWriter("output.txt");
            var testCaseCount = int.Parse(reader.ReadLine());

            for (int i = 0; i < testCaseCount; i++)
            {
                var heightCount = new Dictionary<int, int>();
                var N = int.Parse(reader.ReadLine());
                for (int j = 0; j < 2 * N - 1; j++)
                {
                    foreach (var height in reader.ReadLine().Split(' ').Select(int.Parse))
                    {
                        if (!heightCount.ContainsKey(height))
                            heightCount[height] = 0;
                        heightCount[height]++;
                    }
                }
                var missingHeights = heightCount.Where(kvp => kvp.Value % 2 != 0).Select(kvp => kvp.Key).ToArray();
                Array.Sort(missingHeights);

                writer.Write("Case #{0}: ", i+1);
                for (int k = 0; k < missingHeights.Length - 1; k++)
                    writer.Write(missingHeights[k] + " ");
                writer.Write(missingHeights[missingHeights.Length - 1]);
                writer.WriteLine();
            }

            reader.Close();
            writer.Flush();
            writer.Close();
        }
    }
}