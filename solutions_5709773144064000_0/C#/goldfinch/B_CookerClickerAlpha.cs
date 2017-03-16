using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ14
{
    using System.Globalization;

    class B_CookerClickerAlpha
    {
        public string[] Solve(string[] lines)
        {
            int cases = int.Parse(lines[0]);
            string[] res = new string[cases];

            for (int i = 0; i < cases; i++)
            {
                var li = lines[i + 1].Split(' ').Select(d => double.Parse(d, CultureInfo.InvariantCulture)).ToList();
                double c = li[0];
                double f = li[1];
                double x = li[2];

                double curSpeed = 2.0;
                double totalTime = 0.0;
                for (;;)
                {
                    double timeToFarm = c / curSpeed;

                    bool shouldBuy = x / (f + curSpeed) < (x - c) / curSpeed;

                    if (shouldBuy)
                    {
                        totalTime += timeToFarm;
                        curSpeed += f;
                    }
                    else
                    {
                        totalTime += x / curSpeed;
                        break;
                    }
                }
                res[i] = string.Format(
                    "Case #{0}: {1}",
                    (i + 1).ToString(CultureInfo.InvariantCulture),
                    totalTime.ToString("0.00000000", CultureInfo.InvariantCulture));
            }

            return res;
        }
    }
}
