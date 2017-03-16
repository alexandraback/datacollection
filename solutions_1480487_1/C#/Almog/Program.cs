using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace SafetyNumbers
{
    class Program
    {
        static void Main(string[] args)
        {
            FileStream fsInput = new FileStream(args[0], FileMode.Open, FileAccess.Read);
            StreamReader reader = new StreamReader(fsInput);
            FileStream fsOutput = new FileStream(args[0] + ".out", FileMode.Create, FileAccess.Write);
            StreamWriter writer = new StreamWriter(fsOutput);

            string sCases = reader.ReadLine();

            int iCases = int.Parse(sCases);

            for (int caseId = 1; caseId <= iCases; caseId++)
            {
                string itemsStr = reader.ReadLine();
                string[] itemsStrs = itemsStr.Split(' ');

                double[] items = Array.ConvertAll<string, double>(itemsStrs, double.Parse);
                double[] sourceItems = (double[])items.Clone();
                int count = (int)items[0];

                Array.Sort(items, 1, items.Length - 1);

                double x = 0;
                for (int i = 1; i < items.Length; i++)
                {
                    x += items[i];
                }

                double[] acc = new double[items.Length];
                double[] cost = new double[items.Length];
                acc[0] = x;
                cost[0] = 0;
                for (int i = 1; i < acc.Length; i++)
                {
                    double nextLevel = 2 * x;

                    if (i + 1 != acc.Length)
                    {
                        nextLevel = items[i + 1];
                    }

                    cost[i] = nextLevel - items[i];
                    if (i * cost[i] >= acc[i - 1])
                    {
                        cost[i] = acc[i - 1] / i;
                    }
                    acc[i] = acc[i - 1] - i * cost[i];
                }

                writer.Write("Case #{0}: ", caseId);
                for (int i = 1; i < sourceItems.Length; i++)
                {
                    double totalCost = 0;
                    for (int j = 1; j < items.Length; j++)
                    {
                        if (sourceItems[i] <= items[j])
                        {
                            totalCost += cost[j];
                        }
                    }

                    double percentage = 100.0 * totalCost / (double)x;
                    writer.Write("{0} ", percentage.ToString("0.000000"));
                }
                writer.WriteLine();

            }

            reader.Close();
            writer.Close();

        }
    }
}
