using System.IO;
using System.Linq;

namespace B
{
    class SolverB
    {
        public string SolveOne(TextReader input)
        {
            string line = input.ReadLine();
            var nums = line.Split(' ').Select(double.Parse).ToArray();
            double cookiesPerSec = 2.0;
            double timeSpent = 0.0;
            double farmCost = nums[0];
            double farmCookiesPerSec = nums[1];
            double targetCookies = nums[2];

            while (true)
            {
                double noBuyTime = targetCookies / cookiesPerSec;
                double withBuyTime = farmCost / cookiesPerSec + targetCookies / (cookiesPerSec + farmCookiesPerSec);
                if (noBuyTime <= withBuyTime)
                    return (timeSpent + noBuyTime).ToString("F7");
                timeSpent += farmCost / cookiesPerSec;
                cookiesPerSec += farmCookiesPerSec;
            }
        }
    }
}