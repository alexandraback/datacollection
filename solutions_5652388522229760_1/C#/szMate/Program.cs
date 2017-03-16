using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static bool full(int[] arr)
        {
            for (int i = 0; i < arr.Length; i++)
            {
                if (arr[i] == 0) return false;
            }
            return true;
        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("A-large(3).in");
            StreamWriter sw = new StreamWriter("outlarge.txt");
            long T = Int64.Parse(sr.ReadLine());
            for (int i = 0; i < T; i++)
            {
                int[] set = new int[] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                long N = Int64.Parse(sr.ReadLine());
                if (N == 0) sw.WriteLine("Case #{0}: INSOMNIA", i + 1);
                else
                {
                    long NK = N;
                    while (!full(set))
                    {
                        long saveNK = NK;
                        while (NK > 0)
                        {
                            set[NK % 10] = 1;
                            NK /= 10;
                        }
                        NK = saveNK + N;
                    }
                    sw.WriteLine("Case #{0}: {1}", i + 1, NK - N);
                }
            }
            sw.Close();
        }
    }
}
