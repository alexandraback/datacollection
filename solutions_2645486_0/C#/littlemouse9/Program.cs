using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestB
{
    class Program
    {
        static List<int> wlist;
        static int E;
        static int R;
        static int N;
        static int[] xlist;

        static long recur(int beginIdx, int endIdx, int startE, int endE)
        {
            if (endIdx < beginIdx)
                return 0;
            else if (endIdx == beginIdx)
            {
                int x = Math.Min(startE, startE + R - endE) ;
                xlist[endIdx] = x;
                return x * wlist[endIdx];
            }
            else
            {
                int max = 0;
                int idx = -1;
                for (int i = beginIdx; i <= endIdx; i++)
                {
                    if (wlist[i] > max)
                    {
                        max = wlist[i];
                        idx = i;
                    }
                }
                int len = endIdx - beginIdx + 1;
                int ub = Math.Min(startE + R * (idx - beginIdx), E);
                int lb = Math.Max(endE - (endIdx - idx) * R, R);
                int x = ub - lb + R;
                if (x == 0)
                {
                    for (int i = beginIdx; i <= endIdx; i++)
                        xlist[i] = 0;
                    return 0;
                }
                else
                {
                    xlist[idx] = x;
                    return x * wlist[idx] + recur(beginIdx, idx - 1, startE, x + lb - R) + recur(idx + 1, endIdx, lb, endE);
                }
            }
        }

        static void Main(string[] args)
        {
            StreamReader reader = new StreamReader(@"H:\Program\Test\GoogleTest\roundA\TestA\TestB\B-small-attempt3.in");
            StreamWriter writer = new StreamWriter(@"H:\Program\Test\GoogleTest\roundA\TestA\TestB\B-small-attempt3.out");
//            StreamReader reader = new StreamReader(@"H:\Program\Test\GoogleTest\roundA\TestA\TestB\B1.in");
//            StreamWriter writer = new StreamWriter(@"H:\Program\Test\GoogleTest\roundA\TestA\TestB\B1.out");
//            StreamReader reader = new StreamReader(@"H:\Program\Test\GoogleTest\roundA\TestA\TestB\test.in");
//            StreamWriter writer = new StreamWriter(@"H:\Program\Test\GoogleTest\roundA\TestA\TestB\test.out");
            StreamWriter writerd = new StreamWriter(@"H:\Program\Test\GoogleTest\roundA\TestA\TestB\t.dump");

            int nTest = int.Parse(reader.ReadLine());
            for (int idxTest = 0; idxTest < nTest; idxTest++)
            {
                String str = reader.ReadLine();
                String[] words = str.Split();
                E = int.Parse(words[0]);
                R = int.Parse(words[1]);
                N = int.Parse(words[2]);
                wlist = new List<int>(N);
                xlist = new int[N];
                str = reader.ReadLine();
                words = str.Split();
                for (int j = 0; j < N; j++)
                    wlist.Add(int.Parse(words[j]));
                long result = recur(0, N - 1, E, R);
                writer.WriteLine("Case #{0}: {1}", idxTest + 1, result);
                writerd.WriteLine("Case #{0}: ", idxTest + 1);
                for (int j = 0; j < N; j++)
                    writerd.Write("{0} ", xlist[j]);
                writerd.WriteLine();
            }
            reader.Close();
            writer.Close();
            writerd.Close();
        }
    }
}
