using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace DancingWithTheGooglers
{
    class Program
    {
        static void Main(string[] args)
        {
            TextReader tr = new StreamReader("input.txt");
            TextWriter tw = new StreamWriter("output.txt");

            int T = int.Parse(tr.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                tw.WriteLine("Case #" + i + ": " + Solve(tr.ReadLine().Split(' ')));
            }

            tr.Close();
            tw.Close();
        }

        static int Solve(string[] data)
        {
            int N = int.Parse(data[0]);
            int S = int.Parse(data[1]);
            int p = int.Parse(data[2]);

            int passRegular = Math.Max(3 * p - 2, p);
            int passWeird = Math.Max(3 * p - 4, p);

            int count = 0;

            for (int i = 3; i < data.Length; i++)
            {
                if (int.Parse(data[i]) >= passRegular)
                {
                    count++;
                }
                else if (S > 0 && int.Parse(data[i]) >= passWeird)
                {
                    count++;
                    S--;
                }
            }

            return count;
        }
    }
}
