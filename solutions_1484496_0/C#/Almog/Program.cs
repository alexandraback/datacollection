using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace EqualSubsets
{
    class Program
    {
        static FileStream fsInput;
        static StreamReader reader;
        static FileStream fsOutput;
        static StreamWriter writer;

        static void Main(string[] args)
        {
            fsInput = new FileStream(args[0], FileMode.Open, FileAccess.Read);
            reader = new StreamReader(fsInput);
            fsOutput = new FileStream(args[0] + ".out", FileMode.Create, FileAccess.Write);
            writer = new StreamWriter(fsOutput);

            string sCases = reader.ReadLine();

            int iCases = int.Parse(sCases);

            for (int caseId = 1; caseId <= iCases; caseId++)
            {
                writer.WriteLine("Case #{0}:", caseId);
                bool success = false;

                string itemsStr = reader.ReadLine();
                string[] itemsStrs = itemsStr.Split(' ');

                int[] items = Array.ConvertAll<string, int>(itemsStrs, int.Parse);
                int count = (int)items[0];

                Int64 setsCount = (int)Math.Pow(2, count);
                for (int i = 1; i < setsCount; i++)
                {
                    for (int j = 1; j < setsCount; j++)
                    {
                        if (i != j)
                        {
                            int iSum = 0;
                            int jSum = 0;
                            for (int k = 0; k < count; k++)
                            {
                                int iIsExist = (1 << k) & i;
                                if (iIsExist != 0)
                                {
                                    iSum += items[k + 1];
                                }

                                int jIsExist = (1 << k) & j;
                                if (jIsExist != 0)
                                {
                                    jSum += items[k + 1];
                                }
                            }
                            if (iSum == jSum)
                            {
                                success = true;
                                PrintSet(i, items);
                                PrintSet(j, items);
                                break;
                            }
                        }
                    }
                    if (success)
                    {
                        break;
                    }
                }

                if (!success)
                {
                    writer.WriteLine("Impossible");
                }
            }

            reader.Close();
            writer.Close();
        }

        private static void PrintSet(int iSum, int[] items)
        {
            for (int k = 1; k < items.Length; k++)
            {
                int iIsExist = (1 << (k - 1)) & iSum;
                if (iIsExist != 0)
                {
                    writer.Write("{0} ", items[k]);
                }
            }
            writer.WriteLine();
        }
    }
}
