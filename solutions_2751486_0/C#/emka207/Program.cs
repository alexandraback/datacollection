using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ13_1C_A1
{
    class Program
    {
        static void Main(string[] args)
        {
            char[] v = new char[]{'a','i','u','e','o'};
            int T = int.Parse(Console.ReadLine());
            for (int nc = 1; nc <= T; nc++)
            {
                string[] ss = Console.ReadLine().Split(' ');
                string s = ss[0];
                int n = int.Parse(ss[1]);
                int ret = 0;
                for (int i = 0; i < s.Length; i++)
                {
                    for (int j = i + n - 1; j < s.Length; j++)
                    {
                        int nnc = 0;
                        for (int k = i; k <= j; k++)
                            if (Array.IndexOf(v, s[k]) < 0)
                            {
                                nnc++;
                                if (nnc == n)
                                {
                                    ret++;
                                    break;
                                }
                            }
                            else
                            {
                                nnc = 0;
                            }
                    }
                }
                Console.WriteLine("Case #{0}: {1}", nc, ret);
            }
        }
    }
}
