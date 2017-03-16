using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace War
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            int T = Convert.ToInt32(Console.ReadLine());
            for (int t = 1; t <= T; ++t)
            {
                int N = Convert.ToInt32(Console.ReadLine());
                var Naomi = Console.ReadLine().Split(' ').Select(token => Convert.ToDouble(token)).OrderBy(n => n).ToArray();
                var Ken = Console.ReadLine().Split(' ').Select(token => Convert.ToDouble(token)).OrderBy(n => n).ToArray();
                Console.WriteLine("Case #{0}: {1} {2}", t, PlayDeceitful(N, Naomi, Ken), PlayClassic(N, Naomi, Ken));
            }
        }

        static int PlayClassic(int N, double[] Naomi, double[] Ken)
        {
            int KenL = 0, KenR = N - 1;
            int score = 0;
            for (int NaomiR = N - 1; NaomiR >= 0; --NaomiR)
            {
                if (Naomi[NaomiR] > Ken[KenR])
                {
                    ++score;
                    ++KenL;
                }
                else
                    --KenR;
            }
            return score;
        }

        static int PlayDeceitful(int N, double[] Naomi, double[] Ken)
        {
            int NaomiL = 0, NaomiR = N - 1;
            int score = 0;
            for (int KenR = N - 1; KenR >= 0; --KenR)
            {
                if (Naomi[NaomiR] > Ken[KenR])
                {
                    ++score;
                    --NaomiR;
                }
                else
                    ++NaomiL;
            }
            return score;
        }
    }
}
