using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Problem_1
{
    class Program
    {
        static void Main(string[] args)
        {
            int lCases = 0;
            lCases = int.Parse(Console.ReadLine());
            for (int i = 0; i < lCases; i++)
            {
                long lStart = 0;
                lStart = long.Parse(Console.ReadLine());
                Console.Write("Case #{0}: ", i+1);
                var lNumsSeen = new List<int>();
                foreach (char x in lStart.ToString())
                {
                    if (lNumsSeen.IndexOf((int)(x - '0')) < 0)
                    {
                        lNumsSeen.Add(x - '0');
                    }
                }
                long lCount = lStart;
                while (lNumsSeen.Count < 10) 
                {
                    lCount += lStart;
                    if (lCount - lStart > long.MaxValue - lStart * 2)
                        Console.WriteLine("OVERFLOW DETECTED");
                    if (lCount == 0)
                        break;
                    foreach (char x in lCount.ToString())
                    {
                        if (lNumsSeen.IndexOf((int)(x - '0')) < 0)
                        {
                            lNumsSeen.Add(x - '0');
                        }
                    }
                } 
                if (lStart == 0)
                {
                    Console.WriteLine("INSOMNIA");
                }
                else
                {
                    Console.WriteLine(lCount);
                }
            }
        }
    }
}
