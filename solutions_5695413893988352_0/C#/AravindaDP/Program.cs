using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace _2016Round1B
{
    class Program
    {
        static void Main(string[] args)
        {
            B();
        }

        //static void A()
        //{
        //    StreamReader sr = new StreamReader("C:\\CodeJam\\2016\\Round1B\\A-large.in");
        //    StreamWriter sw = new StreamWriter("C:\\CodeJam\\2016\\Round1B\\A-large.out");

        //    int T;
        //    string S;
        //    T = int.Parse(sr.ReadLine());
        //    for (int i = 0; i < T; i++)
        //    {
        //        S = sr.ReadLine();
        //        int[] count = new int[26];
        //        for(int c = 0; c<26; c++)
        //        {
        //            count[c] = 0;
        //        }
        //        for(int c = 0; c < S.Length; c++)
        //        {
        //            count[S[c] - 'A']++;
        //        }
        //        int[] dcount = new int[10];
        //        for (int c = 0; c < 10; c++)
        //        {
        //            dcount[c] = 0;
        //        }
        //        dcount[0] = count['Z'-'A'];
        //        count['E' - 'A'] -= dcount[0];
        //        count['R' - 'A'] -= dcount[0];
        //        count['O' - 'A'] -= dcount[0];
        //        dcount[6] = count['X' - 'A'];
        //        count['S' - 'A'] -= dcount[6];
        //        count['I' - 'A'] -= dcount[6];
        //        dcount[7] = count['S' - 'A'];
        //        count['E' - 'A'] -= dcount[7];
        //        count['V' - 'A'] -= dcount[7];
        //        count['E' - 'A'] -= dcount[7];
        //        count['N' - 'A'] -= dcount[7];
        //        dcount[8] = count['G' - 'A'];
        //        count['E' - 'A'] -= dcount[8];
        //        count['I' - 'A'] -= dcount[8];
        //        count['H' - 'A'] -= dcount[8];
        //        count['T' - 'A'] -= dcount[8];
        //        dcount[5] = count['V' - 'A'];
        //        count['F' - 'A'] -= dcount[5];
        //        count['I' - 'A'] -= dcount[5];
        //        count['E' - 'A'] -= dcount[5];
        //        dcount[4] = count['F' - 'A'];
        //        count['O' - 'A'] -= dcount[4];
        //        count['U' - 'A'] -= dcount[4];
        //        count['R' - 'A'] -= dcount[4];
        //        dcount[2] = count['W' - 'A'];
        //        count['T' - 'A'] -= dcount[2];
        //        count['O' - 'A'] -= dcount[2];
        //        dcount[1] = count['O' - 'A'];
        //        count['N' - 'A'] -= dcount[1];
        //        count['E' - 'A'] -= dcount[1];
        //        dcount[3] = count['T' - 'A'];
        //        count['H' - 'A'] -= dcount[3];
        //        count['R' - 'A'] -= dcount[3];
        //        count['E' - 'A'] -= dcount[3];
        //        count['E' - 'A'] -= dcount[3];
        //        dcount[9] = count['I' - 'A'];
        //        count['N' - 'A'] -= dcount[9];
        //        count['N' - 'A'] -= dcount[9];
        //        count['E' - 'A'] -= dcount[9];

        //        sw.Write("Case #");
        //        sw.Write((i + 1).ToString());
        //        sw.Write(": ");
        //        for (int d= 0; d<10; d++)
        //        {
        //            for(int c =0; c<dcount[d];c++ )
        //            {
        //                sw.Write(d.ToString());
        //            }
        //        }
        //        sw.WriteLine();
        //    }
        //    sw.Close();
        //    sr.Close();
        //}

        //static void C()
        //{
        //    StreamReader sr = new StreamReader("C:\\CodeJam\\2016\\Round1B\\C-small-attempt0.in");
        //    StreamWriter sw = new StreamWriter("C:\\CodeJam\\2016\\Round1B\\C-small-attempt0.out");

        //    int T,N;
        //    string S;

        //    T = int.Parse(sr.ReadLine());
        //    for (int i = 0; i < T; i++)
        //    {
        //        Dictionary<string, int> firstDic = new Dictionary<string, int>();
        //        Dictionary<string, int> secondDic = new Dictionary<string, int>();
        //        List<string> topics = new List<string>();
        //        N = int.Parse(sr.ReadLine());
        //        for (int j = 0; j < N; j++)
        //        {
        //            S = sr.ReadLine();
        //            topics.Add(S);
        //            string[] toks = S.Split(' ');
        //            if(firstDic.ContainsKey(toks[0]))
        //            {
        //                firstDic[toks[0]]++;
        //            }
        //            else
        //            {
        //                firstDic.Add(toks[0], 1);
        //            }
        //            if (secondDic.ContainsKey(toks[1]))
        //            {
        //                secondDic[toks[1]]++;
        //            }
        //            else
        //            {
        //                secondDic.Add(toks[1], 1);
        //            }
        //        }
        //        bool removed = false;
        //        int y = 0;
        //        do
        //        {
        //            removed = false;
        //            string removedTopic = "";
        //            foreach (string s in topics)
        //            {
        //                string[] toks = s.Split(' ');
        //                if (firstDic[toks[0]] > 1 && secondDic[toks[1]] > 1)
        //                {
        //                    removed = true;
        //                    removedTopic = s;
        //                    firstDic[toks[0]]--;
        //                    secondDic[toks[1]]--;
        //                    y++;
        //                    break;
        //                }
        //            }
        //            if (removed)
        //            {
        //                topics.Remove(removedTopic);
        //            }
        //        } while (removed);
        //        sw.Write("Case #");
        //        sw.Write((i + 1).ToString());
        //        sw.Write(": ");
        //        sw.Write(y.ToString());
        //        sw.WriteLine();
        //    }
        //    sw.Close();
        //    sr.Close();
        //}

        static void B()
        {
            StreamReader sr = new StreamReader("C:\\CodeJam\\2016\\Round1B\\B-small-attempt0.in");
            StreamWriter sw = new StreamWriter("C:\\CodeJam\\2016\\Round1B\\B-small-attempt0.out");

            int T;
            string C,J;

            T = int.Parse(sr.ReadLine());
            for (int i = 0; i < T; i++)
            {
                string s = sr.ReadLine();
                
                    string[] toks = s.Split(' ');
                C = toks[0];
                J = toks[1];

                int c = 0;
                int j = 0;

                int d = 1000;//for small

                for(int ci = 0; ci <1000; ci++)
                {
                    if(ci.ToString().Length>C.Length)
                    {
                        break;
                    }
                    string cs = ci.ToString().PadLeft(C.Length, '0');
                    if (!IsValid(cs, C))
                        continue;
                    for(int  cj = 0; cj<1000;cj++)
                    {
                        if(cj.ToString().Length>J.Length)
                        {
                            break;
                        }
                        string js = cj.ToString().PadLeft(J.Length, '0');
                        if(IsValid(js,J))
                        {
                            int ad = Math.Abs(ci - cj);
                            if(ad<d)
                            {
                                d = ad;
                                c = ci;
                                j = cj;
                            }
                        }
                    }
                }
                sw.Write("Case #");
                sw.Write((i + 1).ToString());
                sw.Write(": ");
               sw.Write(c.ToString().PadLeft(C.Length, '0') + " "+j.ToString().PadLeft(J.Length, '0'));
                sw.WriteLine();
            }
            sw.Close();
            sr.Close();
        }

        static bool IsValid(string s, string mask)
        {
            for(int i = 0; i <s.Length;i++)
            {
                if ((mask[i] != '?') && (s[i] != mask[i]))
                    return false;
            }
            return true;
        }
    }
}
