using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Numerics;
using System.Threading.Tasks;

namespace google_code_jam
{
    class StandingOvation
    {
        public string solve(string s)
        {
            for (int i = 0; i <= 1000; i++)
            {
                int n = i;

                for (int j = 0; j < s.Length; j++)
                {
                    if (n >= j)
                    {
                        n += s[j] - '0';

                        if (j == s.Length - 1)
                        {
                            return i.ToString();
                        }
                    }
                    else
                    {
                        break;
                    }

                }
            }

            return null;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            string folder = @"D:\tmp\";
            string input = "input";

            StreamReader reader = new StreamReader(folder + input + ".in", Encoding.ASCII);
            StreamWriter writer = new StreamWriter(@"D:\TMP\out.txt");
            string s = reader.ReadLine();

            int T = int.Parse(s);

            for (int i = 0; i < T; i++)
            {
                var x = reader.ReadLine().Split(' ')[1];
                string r = "Case #" + (i + 1).ToString() + ":" + " " + new StandingOvation().solve(x);
                writer.WriteLine(r);
            }
            reader.Close();
            writer.Close();
        }
    }
}
