using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Diagnostics;

namespace _13_2A
{
    class A_B
    {
        static void Main(string[] args)
        {
            int T;

            string str;
            string[] strs;

            int[] s = new int[200];
            for (int i = 0; i < s.Length; i++)
            {
                s[i] = 2 * i * i + 3 * i;

            }

            str = Console.ReadLine();
            T = int.Parse(str);

            for (int caseNumber = 1; caseNumber <= T; caseNumber++)
            {
                int N, X, Y;
                str = Console.ReadLine();
                strs = str.Split(' ');
                N = int.Parse(strs[0]);
                X = int.Parse(strs[1]);
                Y = int.Parse(strs[2]);

                int dan;
                for (dan = 0; dan < s.Length; dan++)
                {
                    if (N < s[dan])
                    {
                        break;
                    }
                }

                int hopeDan = (X + Y) / 2;
                double result = 0;

                if (hopeDan < dan)
                {
                    int amari = N - s[dan-1] - 1;
                    if ((amari == -1) && (X == 0) && (hopeDan + 1 == dan))
                    {
                        result = 0;
                    }
                    else
                    {
                        result = 1.0;
                    }
                }
                else if (hopeDan > dan)
                {
                    result = 0;
                }
                else
                {
                    int amari = N - s[dan-1] - 1;
                    if (X == 0) { result = 0; }
                    else if (amari == -1)
                    {
                        result = 0;
                    }
                    else if (2 * dan + Y + 1 <= amari)
                    {
                        result = 1;
                    }
                    else
                    {

                        for (int j = 0; j <= Y; j++)
                        {
                            int mm = 1, nn = 1, oo = 1;
                            for (int i = 1; i <= amari; i++)
                            {
                                mm *= i;
                            }
                            for (int i = 1; i <= j; i++)
                            {
                                nn *= i;
                            }
                            for (int i = 1; i <= (amari - j); i++)
                            {
                                oo *= i;
                            }
                            int ans = (mm / (nn * oo));
                            result += (double)ans / Math.Pow(2, amari);
                        }
                        result = 1 - result;

                    }

                }

                Console.WriteLine("Case #" + caseNumber + ": " + result);
            }

            Debug.WriteLine("fin");

            //Console.ReadLine();

        }
    }
}
