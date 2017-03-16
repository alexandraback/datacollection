using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace R1A
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = int.Parse( Console.ReadLine());
            for (int t = 0; t < T; t++)
            {
                string result = "";
                string str = Console.ReadLine();
                result += str[0];
                for (int i = 1; i < str.Length; i++)
                {
                    if (str[i] < result[0])
                        result += str[i];
                    else
                        result = str[i] + result;
                }

                Console.WriteLine("Case #"+(t+1)+": "+result);
            }
        }
    }
}
