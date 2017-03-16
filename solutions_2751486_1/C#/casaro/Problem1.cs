using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class Problem1
    {
        static StreamReader Input;
        static StreamWriter Output;

        static string name;
        static long n;

        static Random rnd = new Random();

        static void Main(string[] args)
        {
            string classname = MethodBase.GetCurrentMethod().DeclaringType.Name;
            string testcase = Console.ReadLine();

            Input = new StreamReader("input/" + classname + "-" + testcase + ".txt");
            Output = new StreamWriter("output/" + classname + "-" + testcase + ".txt");

            long testcases = Convert.ToInt32(Input.ReadLine());
            //long testcases = 100;

            for (long tc = 1; tc <= testcases; tc++)
            {
                string[] input = Input.ReadLine().Split(' ');

                name = input[0];
                n = Convert.ToInt32(input[1]);

                //name = GenerateRandom(1000000);
                //n = rnd.Next(1000000);

                long result = GetValue(0);

                Output.WriteLine("Case #{0}: {1}", tc, result);
            }

            Output.Close();
        }

        private static long GetValue(long start)
        {
            long cc = 0;
            for (int i = Convert.ToInt32(start); i < name.Length; i++)
            {
                if (IsConsonant(name[i]))
                    ++cc;
                else
                    cc = 0;

                if (cc == n)
                {
                    long result = (i - n - start + 2) * (name.Length - i);
                    result += GetValue(i - n + 2);
                    
                    return result;
                }
            }

            return 0;
        }

        private static bool IsConsonant(char c)
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                return false;
            else
                return true;
        }

        private static string GenerateRandom(long length)
        {
            StringBuilder sb = new StringBuilder();
            
            long r = rnd.Next(3);
            if (r == 0)
            {
                for (long i = 0; i < length; i++)
                {
                    sb.Append(Convert.ToChar(rnd.Next(26) + 97));
                }
            }
            else if (r == 1)
            {
                for (long i = 0; i < length; i++)
                {
                    sb.Append('a');
                }
            }
            else if (r == 2)
            {
                for (long i = 0; i < length; i++)
                {
                    sb.Append('b');
                }
            }

            return sb.ToString();
        }
    }
}
