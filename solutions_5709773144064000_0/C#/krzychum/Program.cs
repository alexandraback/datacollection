using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CookieFarm
{
    class Program
    {
        static void Main(string[] args)
        {
            var data = File.ReadAllLines("data_in.txt");
            int nCases = int.Parse(data[0]);
            List<String> result = new List<string>();
            for (int c=0;c<nCases;++c)
            {
                var decimals = data[c+1].Split(' ').Select(l=>decimal.Parse(l, CultureInfo.InvariantCulture)).ToList();
                decimal farmCost = decimals[0];
                decimal farmEfficiency = decimals[1];
                decimal expectedAmount = decimals[2];
                decimal solution = Solve(farmCost, farmEfficiency, expectedAmount);
                result.Add("Case #" + (c + 1) + ": " +  solution.ToString(CultureInfo.InvariantCulture));
                Console.WriteLine(result[result.Count - 1]);
            }
            File.WriteAllLines("data_out.txt", result);
        }

        private static decimal Solve(decimal farmCost, decimal farmEfficiency, decimal expectedCookiesAmount)
        {
            decimal timePassed = 0;
            decimal bestTime = decimal.MaxValue ;
            decimal prevBestTime = decimal.MaxValue-1;
            decimal nFarms = 0;
            while (true)
            {
                decimal cookiesPerSecond = 2 + farmEfficiency * nFarms; // dokładne
                decimal thisBuyTime = farmCost / cookiesPerSecond;
                decimal timeToFinishNow = timePassed + (expectedCookiesAmount / cookiesPerSecond);
                prevBestTime = bestTime;
                bestTime = Math.Min(timeToFinishNow, bestTime);
                if (bestTime == prevBestTime)
                    return bestTime;
                if (timePassed+thisBuyTime >= timeToFinishNow)
                    return bestTime;
                timePassed += thisBuyTime;
                ++nFarms;
            }
        }

        /*
        public static string WriteLong(decimal val)
        {
            string res = val.ToString();
            while (res.Length < 7)
                res = "0" + res;
            res = res.Insert(res.Length - 7, ".");
            return res;
        }

        /// <summary>
        /// return decimal containig a value*10^7
        /// </summary>
        /// <param name="val"></param>
        /// <returns></returns>
        public static decimal ReadLong(string val)
        {
            int periodIdx = val.IndexOf('.');
            if (periodIdx == -1)
                return decimal.Parse(val) * 10000000;
            decimal valBeforePeriod = decimal.Parse(val.Substring(0, periodIdx));
            string strAfterPeriod = val.Substring(periodIdx + 1);
            decimal valAfterPeriod = decimal.Parse(strAfterPeriod);
            decimal[] powVals = new decimal[] { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
            valAfterPeriod *= powVals[7 - strAfterPeriod.Length];
            return valBeforePeriod * 10000000 + valAfterPeriod;
        }*/
    }
}
