using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;

namespace Solution {

    class Solver
    {
        #region hel
        int ReadInt()
        {
            return int.Parse(Console.ReadLine());
        }

        string ReadString()
        {
            return Console.ReadLine();
        }

        int[] ReadInts()
        {
            string s = ReadString();
            return s.Split(' ').ToList().Select(x => int.Parse(x)).ToArray();
        }
        #endregion


        internal void Solve()
        {
            int T = ReadInt();
            for (int i = 1; i <= T; i++)
            {
                var d = ReadInts();
                int a = d[0];
                int b = d[1];
                int k = d[2];
                int v = 0;
                for (int l = 0; l < a; l++)
                {
                    for (int j = 0; j < b; j++)
                    {
                        int t = l & j;
                        if (t < k)
                            v++;
                    }
                }
                Console.WriteLine("Case #{0}: {1}",i , v);
            }
        }
    }


    class Solution
    {
        static Regex catIdRegex = new Regex("(%\\d+)");
      
        static void Main(string[] args)
        {
            Solver s = new Solver();
            s.Solve();
        }
    }
}
