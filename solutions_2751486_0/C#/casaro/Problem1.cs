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

                name = input[0];
                n = Convert.ToInt32(input[1]);

                int result = GetValue(0);

                Output.WriteLine("Case #{0}: {1}", tc, result);
            }

            Output.Close();
        }

        private static int GetValue(int start)
        {
            int cc = 0;
            for (int i = start; i < name.Length; i++)
            {
                if (IsConsonant(name[i]))
                    ++cc;
                else
                    cc = 0;

                if (cc == n)
                {
                    int result = (i - n - start + 2) * (name.Length - i);
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
    }
}
