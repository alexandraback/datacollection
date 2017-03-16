using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2008_1a
{
    class CookieClickerAlpha
    {
        static void Main(string[] args)
        {
            var me = new Numbers();
            using (var helper = new CodeJamHelper('B', ProblemType.Small, 0))
            {
                var numTestCases = helper.ReadLineInt32();
                foreach (var caseNum in Enumerable.Range(1, numTestCases))
                {
                    var temp = helper.ReadDoubleArray();
                    var C = temp[0];
                    var F = temp[1];
                    var X = temp[2];

                    double time = 0;
                    double currentCookies = 0;
                    double payoffTime = C / F;
                    int numFarms = 0;
                    while (true)
                    {
                        double cookiesPerSecond = 2 + (F * numFarms);
                        double timeToNextFarm = C / cookiesPerSecond;
                        double timeToCompletion = X / cookiesPerSecond;

                        //If we should just wait to finish our cookies (buying the next farm isn't going to pay off in time
                        if (timeToCompletion <= timeToNextFarm + payoffTime)
                        {
                            helper.OutputCase(string.Format("{0:0.0000000}", time + timeToCompletion));
                            break;
                        }

                        time += timeToNextFarm;
                        numFarms += 1;
                    }
                }
            }
        }
    }
}
