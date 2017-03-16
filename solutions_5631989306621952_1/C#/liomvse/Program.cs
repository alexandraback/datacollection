using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication3
{
    class Program
    {
        static void Main(string[] args)
        {
            int testCaseCount = int.Parse(Console.ReadLine());
            for (int i = 0; i < testCaseCount; ++i)
            {
                DoWork(i);
            }
        }

        static void DoWork(int testCaseNumber)
        {
            string S = Console.ReadLine();

            string result = S[0].ToString();
            for (int i = 1; i < S.Length; ++i)
            {
                if (S[i] >= result[0])
                {
                    result = S[i].ToString() + result;
                }
                else
                {
                    result += S[i].ToString();
                }
            }
            
            Console.WriteLine("Case #{0}: {1}", testCaseNumber + 1, result);
        }
    }
}
