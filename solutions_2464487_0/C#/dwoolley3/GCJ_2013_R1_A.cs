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
            TextReader reader = new StreamReader("../../input_A_sm.txt");
            TextWriter writer = new StreamWriter("../../output_A_sm.txt");

            int T = int.Parse(reader.ReadLine());

            for (int tc = 1; tc <= T; tc++)
            {

                string[] s = reader.ReadLine().Split();
                long r = long.Parse(s[0]);
                long t = long.Parse(s[1]);
               
                long i = r;
                long j = r+1;
                int cnt = 0;
                while (t > 0)
                {
                    t -= (j * j - i * i);
                    j += 2;
                    i += 2;
                    cnt++;
                }
                if (t < 0) cnt--;

                writer.WriteLine("Case #" + tc + ": " + cnt);
            }

            reader.Close();
            writer.Close();
        }

    }
}
