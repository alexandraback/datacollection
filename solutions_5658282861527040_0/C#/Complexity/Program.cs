using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace NewLottery
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader s = new StreamReader(@"C:\Users\Tim\Desktop\input.in");
            StreamWriter w = new StreamWriter(@"C:\Users\Tim\Desktop\output.txt");
            int t = Convert.ToInt32(s.ReadLine());
            for (int i = 1; i < t + 1; i++)
            {
                string[] line = s.ReadLine().Split();
                int a = Convert.ToInt32(line[0]);
                int b = Convert.ToInt32(line[1]);
                int k = Convert.ToInt32(line[2]);

                int ways = 0;
                for (int x = 0; x < a; x++)
                {
                    for (int y = 0; y < b; y++)
                    {
                        if ((x&y) < k)
                            ways++;
                    }
                }
                w.WriteLine("Case #" + i + ": " + ways);
            }
            s.Close();
            w.Close();
        }
    }
}
