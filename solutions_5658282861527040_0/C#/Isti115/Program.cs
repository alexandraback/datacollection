using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CJ2014_New_Lottery_Game
{
    class Program
    {
        static void Main(string[] args)
        {
            string fileName = "B-small-attempt0";

            StreamReader sr = new StreamReader(fileName + ".in");
            int T = Convert.ToInt32(sr.ReadLine());

            StreamWriter sw = new StreamWriter(fileName + ".out");

            for (int t = 0; t < T; t++)
            {
                string[] splittedInput = sr.ReadLine().Split(' ');
                int A = Convert.ToInt32(splittedInput[0]);
                int B = Convert.ToInt32(splittedInput[1]);
                int K = Convert.ToInt32(splittedInput[2]);

                int goodCount = 0;

                for (int i = 0; i < A; i++)
                {
                    for (int j = 0; j < B; j++)
                    {
                        if ((i&j) < K)
                        {
                            goodCount++;
                        }
                    }
                }

                string output = goodCount.ToString();

                sw.WriteLine("Case #{0}: {1}", t + 1, output);
            }

            sw.Close();
        }
    }
}
