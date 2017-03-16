using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Code_Jam.Round1B
{
    class Osmos_PA
    {
        static public void Main()
        {
            int T = int.Parse(Console.ReadLine());
            for (int i = 0; i < T; i++)
            {
                string[] s = Console.ReadLine().Split(' ');
                int A = int.Parse(s[0]);
                int N = int.Parse(s[1]);
                int[] n = new int[N];
                string[] s1 = Console.ReadLine().Split(' ');
                if (A == 1)
                {
                    Console.WriteLine("Case #" + (i + 1) + ": " + N); break;
                }
                for (int j = 0; j < N; j++)
                {
                    n[j] = int.Parse(s1[j]);
                }
                Array.Sort(n);
                int AddCount = 0, DelCount = N;
                int min = 0;
                for (int j = 0; j < N; j++)
                {
                    int v = n[j];
                    if (A > v)
                    {
                        A += v;
                    }
                    else
                    {
                        while (A <= v)
                        {
                            A = 2 * A - 1;
                            AddCount++;
                        }
                        A += v;
                    }
                    DelCount--;
                    if (min > AddCount + DelCount || min == 0)
                    {
                        min = AddCount + DelCount;
                    }
                }
                Console.WriteLine("Case #" + (i + 1) + ": " + min);
            }
        }
    }
}
