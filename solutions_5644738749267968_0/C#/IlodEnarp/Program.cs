using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using System.Threading;
using System.Globalization;

namespace ConsoleApplication1
{
    class Program
    {
        static int LoyalScore(double[] Naomi, double[] Ken)
        {
            int endNaomi = Naomi.Length - 1;
            int endKen = Ken.Length - 1;
            int score = 0;
            for (int i = 0; i < Naomi.Length; ++i)
            {
                if (Naomi[endNaomi] > Ken[endKen])
                {
                    ++score;
                    --endNaomi;
                }
                else
                {
                    --endNaomi;
                    --endKen;
                }
            }
            return score;
        }
        static int UnloyalScore(double[] Naomi, double[] Ken)
        {
            int endNaomi = Naomi.Length - 1;
            int endKen = Ken.Length - 1;
            int startKen = 0;
            int startNaomi = 0;
            int score = 0;
            for (int i = 0; i < Naomi.Length; ++i)
            {
                if (Naomi[startNaomi] > Ken[startKen])
                {
                    ++score;
                    ++startNaomi;
                    ++startKen;
                }
                else
                {
                    ++startNaomi;
                    --endKen;
                }
            }
            return score;
        }

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");
            Scanner s = new Scanner(Console.ReadLine());
            int N = s.nextInt();
            for (int iTest = 0; iTest < N; ++iTest)
            {
                s = new Scanner(Console.ReadLine());
                int SIZE = s.nextInt();
                double[] Naomi = new double[SIZE];
                s = new Scanner(Console.ReadLine());
                for (int i = 0; i < SIZE; ++i)
                {
                    Naomi[i] = s.nextDouble();
                }
                s = new Scanner(Console.ReadLine());
                double[] Ken = new double[SIZE];
                for (int i = 0; i < SIZE; ++i)
                {
                    Ken[i] = s.nextDouble();
                }
                Array.Sort(Naomi);
                Array.Sort(Ken);
                Debug.WriteLine(string.Format("Case #{0}: {1} {2}", iTest + 1, UnloyalScore(Naomi, Ken), LoyalScore(Naomi, Ken)));
            }
        }
    }
}
