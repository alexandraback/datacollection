using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO; //for StreamReader & Writer

namespace GoogleCodeJam
{
    class GoogleCodeJam_2013_QR_C
    {
        static void Main(string[] args)
        {
            TextReader reader = new StreamReader("../../input_C_la.txt");
            TextWriter writer = new StreamWriter("../../output_C_la.txt");

            int T = int.Parse(reader.ReadLine());

            //Generated numbers
            //1 - 1 - 1
            //2 - 4 - 2
            //3 - 9 - 3
            //4 - 121 - 11
            //5 - 484 - 22
            //6 - 10201 - 101
            //7 - 12321 - 111
            //8 - 14641 - 121
            //9 - 40804 - 202
            //10 - 44944 - 212
            //11 - 1002001 - 1001
            //12 - 1234321 - 1111
            //13 - 4008004 - 2002
            //14 - 100020001 - 10001
            //15 - 102030201 - 10101
            //16 - 104060401 - 10201
            //17 - 121242121 - 11011
            //18 - 123454321 - 11111
            //19 - 125686521 - 11211
            //20 - 400080004 - 20002
            //21 - 404090404 - 20102
            //22 - 10000200001 - 100001
            //23 - 10221412201 - 101101
            //24 - 12102420121 - 110011
            //25 - 12345654321 - 111111
            //26 - 40000800004 - 200002
            //27 - 1000002000001 - 1000001
            //28 - 1002003002001 - 1001001
            //29 - 1004006004001 - 1002001
            //30 - 1020304030201 - 1010101
            //31 - 1022325232201 - 1011101
            //32 - 1024348434201 - 1012101
            //33 - 1210024200121 - 1100011
            //34 - 1212225222121 - 1101011
            //35 - 1214428244121 - 1102011
            //36 - 1232346432321 - 1110111
            //37 - 1234567654321 - 1111111
            //38 - 4000008000004 - 2000002
            //39 - 4004009004004 - 2001002

            List<long> sq = new List<long>();
            List<long> sqrt = new List<long>();

            int cnt2 = 0;
            for (long i = 1; i <= 1e7; i++)
            {
                if (IsPal(i.ToString()) && IsPal((i * i).ToString()))
                {
                    sqrt.Add(i);
                    sq.Add(i * i);
                    cnt2++;
                    //writer.WriteLine(cnt2 + " - " + i*i + " - " + i);
                    //Console.WriteLine(cnt2 + " - " + i*i + " - " + i);
                }
            }

            for (int tc = 1; tc <= T; tc++)
            {
                string[] s = reader.ReadLine().Split();
                long a = long.Parse(s[0]);
                long b = long.Parse(s[1]);

                int cnt = 0;
                for (int i = 0; i < sq.Count; i++)
                    if (sq[i] >= a && sq[i] <= b) cnt++;

                writer.WriteLine("Case #" + tc + ": " + cnt);
            }

            reader.Close();
            writer.Close();
        }

        static private bool IsPal(string word)
        {
            int n = word.Length;
            for (int i = 0; i < n / 2; i++)
                if (word[i] != word[n - i - 1]) return false;
            return true;
        }

        static private bool IsSquareOfPal(long num)
        {
            double d = Math.Sqrt(num);
            long x = (long)(d + 1e-9);
            return (x * x == num && IsPal(x.ToString() ));
        }
    }
}
