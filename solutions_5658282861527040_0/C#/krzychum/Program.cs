using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NewLotteryGame
{
    class Program
    {
        static void Main(string[] args)
        {
            var strL = File.ReadAllLines("data_in.txt");
            List<string> res = new List<string>();
            int nCases = int.Parse(strL[0]);
            ///int cLines = 1;
            for (int cCases = 0; cCases < nCases; ++cCases)
            {
                
                int[] vals = strL[cCases + 1].Split(' ').Select(int.Parse).ToArray();
                int limitVal1 = vals[0];
                int limitVal2 = vals[1];
                int limitCatalina = vals[2];
                int resu = new Calc(limitVal1, limitVal2, limitCatalina).Calculate();
                string answer = "Case #" + (cCases + 1) + ": " + resu.ToString();
                res.Add(answer);
                Console.WriteLine(answer);
            }
            File.WriteAllLines("data_out.txt", res);

        }
    }
}
