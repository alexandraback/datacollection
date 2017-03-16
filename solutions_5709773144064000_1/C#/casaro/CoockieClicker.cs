using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class CoockieClicker
    {
        static StreamReader Input;
        static StreamWriter Output;

        static int n;

        static void Main(string[] args)
        {
            string classname = MethodBase.GetCurrentMethod().DeclaringType.Name;
            string testcase = Console.ReadLine();

            Input = new StreamReader("input/" + classname + "-" + testcase + ".txt");
            Output = new StreamWriter("output/" + classname + "-" + testcase + ".txt");

            int testcases = Convert.ToInt32(Input.ReadLine());

            for (int tc = 1; tc <= testcases; tc++)
            {
                string[] input = Input.ReadLine().Split(' ');

                double c = Convert.ToDouble(input[0]);
                double f = Convert.ToDouble(input[1]);
                double x = Convert.ToDouble(input[2]);

                double cps = 2.0;
                double time = 0.0;
                while (true)
                {
                    double timeForFarm = c / cps;
                    double timeForWin = x / cps;
                    if (timeForWin < timeForFarm + (x / (cps + f)))
                    {
                        time += timeForWin;
                        break;
                    }

                    cps += f;
                    time += timeForFarm;
                }

                Output.WriteLine("Case #{0}: {1:F7}", tc, time);
            }

            Output.Close();
        }
    }
}
