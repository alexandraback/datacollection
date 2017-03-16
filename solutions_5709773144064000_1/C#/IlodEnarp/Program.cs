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
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");
            Scanner s = new Scanner(Console.ReadLine());
            int N = s.nextInt();
            for (int iTest = 0; iTest < N; ++iTest)
            {
                s = new Scanner(Console.ReadLine());
                double C = s.nextDouble();
                double F = s.nextDouble();
                double X = s.nextDouble();
                double bestTime;
                double nextTime = double.PositiveInfinity;
                int nbFarm = 0;
                do
                {
                    bestTime = nextTime;
                    nextTime = X / (2 + nbFarm * F);
                    for (int iFarm = 0; iFarm < nbFarm; ++iFarm)
                    {
                        nextTime += C / (2 + iFarm * F);
                    }
                    ++nbFarm;
                } while (nextTime < bestTime);
                Debug.WriteLine(string.Format("Case #{0}: {1}", iTest + 1, bestTime.ToString(".0000000")));
            }
        }
    }
}
