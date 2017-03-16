using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Round1CQ1
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine().Trim());

            for (int i = 0; i < t; i++)
                SolveProblem(i + 1);
        }

        private static void SolveProblem(int testNum)
        {
            string[] parts = Console.ReadLine().Trim().Split(' ');
            long B = long.Parse(parts[0]);
            long M = long.Parse(parts[1]);

            double maxPossibleWayCount = Math.Pow(2, (B - 2));
            if (M > maxPossibleWayCount)
            {
                Console.WriteLine("Case #{0}: {1}", testNum, "IMPOSSIBLE");
                return;
            }

            Console.WriteLine("Case #{0}: {1}", testNum, "POSSIBLE");

            long mOriginal = M;



            StringBuilder sb = new StringBuilder();
            sb.Append("0");

            List<int> firstLine = new List<int>();
            firstLine.Add(0);

            double comparator = maxPossibleWayCount / 2;

            while (comparator > 0.9)
            {
                //17
                if (M >= comparator)
                {
                    sb.Append(" 1");
                    firstLine.Add(1);

                    M -= (long)comparator;
                }
                else
                {
                    sb.Append(" 0");
                    firstLine.Add(0);
                }

                comparator /= 2;
            }

            if (M == 1)
            {
                sb.Append(" 1");
                firstLine.Add(1);
            }
            else
            {
                sb.Append(" 0");
                firstLine.Add(0);
            }


            //Console.WriteLine(sb.ToString());
            Console.WriteLine(string.Join(" ", firstLine));
            bool flag = false;

            for (int i = 1; i < B; i++)
            {
                string[] arr = new string[B];

                if (firstLine[i] == 0 && !flag)
                {
                    for (int k = 0; k < B; k++)
                        arr[k] = "0";

                    Console.WriteLine(string.Join(" ", arr));
                    continue;
                }
                else
                    flag = true;


                for (int j = 0; j < B; j++)
                {
                    if (j > i)
                        arr[j] = "1";
                    else
                        arr[j] = "0";
                }
                Console.WriteLine(string.Join(" ", arr));
            }
        }
    }
}
