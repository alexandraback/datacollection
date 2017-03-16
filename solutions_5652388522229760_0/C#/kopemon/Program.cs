using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = "../../A-small-attempt1.in";

            using (TextReader tr = new StreamReader(input))
            using (TextWriter tw = new StreamWriter(input.Replace(".in", ".out.txt")))
            {
                int T = int.Parse(tr.ReadLine());
                for (int c = 1; c <= T; c++)
                {
                    int ans = 0;

                    int N = int.Parse(tr.ReadLine());

                    if (N == 0)
                    {
                        ans = -1;
                    }
                    else {

                        HashSet<char> st = new HashSet<char>();
                        HashSet<char> all = new HashSet<char> { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };


                        int i = 1;
                        long ni = (long)N * (long)(i);
                        do
                        {
                            ans = (int) ni;
                            if (ni > int.MaxValue)
                            {
                                ans = -1;
                                break;
                            }

                            foreach (var ch in ni.ToString().ToCharArray())
                            {
                                st.Add(ch);
                            }
                            ni = (long)N * (long)(++i);
                        } while (!st.SetEquals(all));
                    }

                    Console.WriteLine($"Case #{c}: {(ans == -1 ? "INSOMNIA" : ans.ToString())}");
                    tw.WriteLine($"Case #{c}: {(ans == -1 ? "INSOMNIA" : ans.ToString())}");
                }
            }
        }
    }
}
