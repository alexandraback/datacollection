using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace DancingWiththeGooglers
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader reader = new StreamReader(args[0]);
            int count = int.Parse(reader.ReadLine());
            for (int i = 0; i < count; i++)
            {
                List<int> parameters = reader.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => Int32.Parse(x)).ToList();
                int N = parameters[0];
                int S = parameters[1];
                int p = parameters[2];
                List<int> scores = parameters.Skip(3).ToList();

                int result = 0;
                for (int j = 0; j < scores.Count; j++)
                {
                    if (BestNotSuprising(scores[j]) >= p)
                    {
                        result++;
                    }
                    else if (S > 0 && BestSuprising(scores[j]) >= p)
                    {
                        result++;
                        S--;
                    }
                }

                Console.WriteLine("Case #{0}: {1}", i + 1, result);
            }
        }

        private static int BestNotSuprising(int score)
        {
            int div = score / 3;
            int mod = score % 3;

            if (mod == 0)
            {
                return div;
            }
            else
            {
                return div + 1;
            }
        }

        private static int BestSuprising(int score)
        {
            int div = score / 3;
            int mod = score % 3;

            if (mod == 2)
            {
                return div + 2;
            }
            else if (div > 0)
            {
                return div + 1;
            }
            else
            {
                return 0;
            }
        }
    }
}
