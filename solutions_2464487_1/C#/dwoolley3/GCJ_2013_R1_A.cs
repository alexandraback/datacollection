using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO; //for StreamReader & Writer

namespace GoogleCodeJam
{
    class GoogleCodeJam_2013_R1_A
    {
        static void Main(string[] args)
        {
            TextReader reader = new StreamReader("../../input_A_la.txt");
            TextWriter writer = new StreamWriter("../../output_A_la.txt");

            int T = int.Parse(reader.ReadLine());

            for (int tc = 1; tc <= T; tc++)
            {

                string[] s = reader.ReadLine().Split();
                long r = long.Parse(s[0]);
                long t = long.Parse(s[1]);

                long inc = r * 2 - 3;
                long sum = 0;
                long left = 0;
                long right = t / r; // 1000000000;
                if (right > 1000000000) right = 1000000000;
                //if (right < 1000) right = 1000;
                
                long n = 0;
                long cnt = 0;

                while (left < right && cnt < 1000)
                {
                    cnt++;
                    n = left + ((right - left) >> 1);
                    sum = n * (n + 1) * 2 + n * inc;
                    if (sum > t)
                    {
                        right = n;
                    }
                    else
                    {
                        left = n + 1;
                    }
                }
                if (n * (n + 1) * 2 + n * inc > t) n--;
                //1000000000000000000

                writer.WriteLine("Case #" + tc + ": " + n);
            }

            reader.Close();
            writer.Close();
        }

    }
}
