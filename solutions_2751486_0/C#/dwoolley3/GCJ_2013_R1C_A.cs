using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO; //for StreamReader & Writer

namespace GoogleCodeJam
{
    class GoogleCodeJam_2013_R1C_A
    {
        static string vow = "aeoiu";
        static int[] consec;
        static int n;
        static void Main(string[] args)
        {
            TextReader reader = new StreamReader("../../input_A_sm.txt");
            TextWriter writer = new StreamWriter("../../output_A_sm.txt");

            int T = int.Parse(reader.ReadLine());

            for (int tc = 1; tc <= T; tc++)
            {
                string[] s = reader.ReadLine().Split();
                string w = s[0];
                n = int.Parse(s[1]);

                int wLen = w.Length;
                int conNum = 0;
                consec = new int[wLen];
                for (int i = 0; i < wLen; i++)
                {
                    if (vow.Contains(w[i]))
                        conNum = 0;
                    else
                        conNum++;
                    consec[i] = conNum;
                }

                int cnt = 0;
                for (int i = 0; i < wLen - n + 1; i++)
                {
                    for (int j = n; j <= wLen - i; j++)
                    {
                        string ss = w.Substring(i, j);
                        if (IsConst(ss))
                        {
                            //Console.WriteLine(ss);
                            cnt++;
                        }
                    }
                }

                Console.WriteLine("Case #" + tc + ": " + cnt);
                writer.WriteLine("Case #" + tc + ": " + cnt);
            }

            reader.Close();
            writer.Close();
        }

        static bool IsConst(string w)
        {
            int wLen = w.Length;
            int conNum = 0;
            for (int i = 0; i < wLen; i++)
            {
                if (vow.Contains(w[i]))
                    conNum = 0;
                else
                    conNum++;
                if (conNum >= n) return true;
            }
            return false;

            //for (int i = 0; i < s.Length; i++)
            //    if (vow.Contains(s[i]))
            //        return false;
            //return true;
        }

    }
}
