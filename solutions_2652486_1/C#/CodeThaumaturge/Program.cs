using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Threading.Tasks;

namespace GoodLuck
{
    class Program
    {
        static void Main(string[] args)
        {
            Random random = new Random();

            string[] outputs;
            using (StreamReader reader = new StreamReader(args[0]))
            {
                reader.ReadLine(); // Discard known 1 in first row.

                string[] tokens = reader.ReadLine().Split(' ');

                int games = Int32.Parse(tokens[0]);
                int numbers = Int32.Parse(tokens[1]);
                int max = Int32.Parse(tokens[2]);
                int draws = Int32.Parse(tokens[3]);

                outputs = new string[games];

                for (int i = 0; i < games; i++)
                {
                    tokens = reader.ReadLine().Split(' ');

                    long[] products = tokens.Select(lToken => Int64.Parse(lToken)).ToArray();

                    List<int> candidates = new List<int>();
                    for (int j = 0; j < draws; j++)
                    {
                        long product = products[j];

                        int candidate = max;
                        while (product > 1 && candidate >= 2)
                        {
                            if (product % candidate == 0)
                            {
                                candidates.Add(candidate);
                                product /= candidate;
                            }
                            else
                                candidate--;
                        }
                    }

                    Dictionary<int, double> countMap = new Dictionary<int, double>();
                    foreach (var pair in candidates.GroupBy(lCandidate => lCandidate))
                        countMap.Add(pair.Key, ((double)pair.Count()) / candidates.Count);

                    double weightIncrement = ((double)numbers) / candidates.Count;

                    int[] selections = new int[numbers];
                    for (int k = 0; k < numbers; k++)
                    {
                        int selection = countMap
                            .Where(lPair => lPair.Value > 0)
                            .OrderByDescending(lPair => lPair.Value)
                            .Select(lPair => lPair.Key)
                            .FirstOrDefault();

                        if (selection > 1)
                        {
                            selections[k] = selection;

                            countMap[selection] -= weightIncrement;
                            if (countMap[selection] < 0)
                                countMap[selection] = 0;
                        }
                        else
                            selections[k] = random.Next(2, max / 2);
                    }

                    outputs[i] = String.Join(String.Empty, selections);
                }
            }

            using (StreamWriter writer = new StreamWriter(args[0].Replace(".in", ".out")))
            {
                writer.WriteLine("Case #1:");
                writer.Write(String.Join(Environment.NewLine, outputs));
            }
        }
    }
}
