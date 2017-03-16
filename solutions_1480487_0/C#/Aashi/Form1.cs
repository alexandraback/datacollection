using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Collections;

namespace COdeJam2012
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
           // Solve();
           // Solve2();
           // Solve3();
            Solve1B();
        }
        private void Solve1B()
        {
            StreamReader reader = new StreamReader("inp.txt");
            StreamWriter writer = new StreamWriter("out.txt");
            string line = reader.ReadLine();
            int cas = 1;
            while (!reader.EndOfStream)
            {
                line = reader.ReadLine();
                string[] toks = line.Split(new char[1] { ' ' });
                int c = int.Parse(toks[0]);
                ArrayList arr = new ArrayList();
                int totalSum = 0;
                for (int i = 1; i < toks.Length; i++)
                {
                    int vv = int.Parse(toks[i]);
                    arr.Add(vv);
                    totalSum += vv;
                }
                writer.Write("Case #" + cas + ":");
                ArrayList ar = new ArrayList();
                for (int i = 0; i < arr.Count; i++)
                {
                    double val = DoBinary(i, arr, totalSum);
                    writer.Write(" " + formathis(val.ToString()));
                }
                cas++;
                writer.WriteLine("");
                
            }
            reader.Close();
            writer.Close();
        }
        private string formathis(string s)
        {
            int idx = s.IndexOf('.');
            if (idx == -1)
                return s;
            string[] toks = s.Split(new char[1] { '.' });
            if (toks[1].Length < 6)
                return s;
            return toks[0] +"."+ toks[1].Substring(0, 5);
        }
        private double DoBinary(int idx, ArrayList arr, int totalSum)
        {
            double diff = (double)1/100000;
            double st = 0;
            double en = 100.0;
            while (en - st >= diff)
            {
                double mid = (en + st) / 200;
                double votes = ((double)((int)arr[idx]))+ mid * totalSum;
                double rem = (1 - mid) * (double)totalSum;
                bool result = true;
                for (int i = 0; i < arr.Count; i++)
                {
                    if (idx == i)
                        continue;
                    if ((double)(int)arr[i] > votes)
                        continue;
                    double needed = votes - (double)(int)arr[i];
                    rem -= needed;
                    if (rem < 0)
                    {
                        en = mid * 100;
                        continue;
                    }
                }
                if (rem > 0)
                    result = false;

                if (!result)
                {
                    st = mid * 100;
                }
                else
                {
                    en = mid * 100;
                }
            }
            return st;
        }

        /* private void Solve3()
         {
             StreamReader reader = new StreamReader("inp.txt");
             StreamWriter writer = new StreamWriter("out.txt");
             string line = reader.ReadLine();
             int cas = 1;
             while (!reader.EndOfStream)
             {
                 int answer = 0;
                 line = reader.ReadLine();
                 string[] toks = line.Split(new char[1] { ' ' });
                 int googlers = int.Parse(toks[0]);
                 int unwanted = int.Parse(toks[1]);
                 int p = int.Parse(toks[2]);
                 int canBeSuprise = 0;
                 int canBeUnsurprise = 0;
                 int surprised = 0;
                 int unsurprised = 0;
                 int maxcnt = 0;
                 for (int i = 0; i < googlers; i++)
                 {
                     int score = int.Parse(toks[3 + i]);
                     int v1 = p;
                     int v2 = (score - p) / 2;
                     int v3 = score - v1 - v2;
                     bool diff1 = (int)Math.Abs(v1 - v2) > 2;
                     bool diff2 = (int)Math.Abs(v1 - v3) > 2;
                     bool diff3 = (int)Math.Abs(v2 - v3) > 2;
                     if (v2 < 0 || v2 > 10 || v3 < 0 || v3 > 10 || diff1 || diff2 || diff3)
                     {
                         v1 = score / 3;
                         if (score % 3 == 0)
                         {
                             v1 = v2 = v3 = score / 3;
                             if (v1 >= p) 
                             {
                                 maxcnt++;                            
                                 canBeUnsurprise++;
                                 if ((v3 + 1) <= 10 && (v1 - 1) >= 0)
                                     canBeSuprise++;
                             }
                         }
                         else if (score % 3 == 1)
                         {
                             v1 = v2 = score / 3;
                             v3 = v1 + 1;
                             if (v1 >= p || v2 >= p || v3 >= p)
                             {   
                                 maxcnt++;
                                 canBeUnsurprise++;
                                 if (v3 + 1 <= 10 || (v1 - 1) >= 0)
                                     canBeSuprise++;
                             }
                         }
                         else
                         {
                             v1 = score / 3;
                             v2 = v1 + 1;
                             v3 = v1 + 1;
                             if (v1 >= p || v2 >= p || v3 >= p)
                             {
                                 maxcnt++;                            
                                 canBeUnsurprise++;
                                 if (v3 + 1 <= 10 || (v1 - 1) >= 0)
                                     canBeSuprise++;                                
                             }
                         }
                     }
                     else
                     {
                         maxcnt++;
                         if ((Math.Abs(v1 - v2) == 2)
                             || (Math.Abs(v1 - v3) == 2)
                             || Math.Abs(v2 - v3) == 2)
                         {
                             surprised++;
                         }
                         else
                         {
                             unsurprised++;
                         }
                     }
                 }
                 if (unwanted == surprised + canBeSuprise)
                 {
                     answer = maxcnt;
                 }
                 else
                     if (unwanted <= surprised)
                     {
                         answer = maxcnt - (surprised - unwanted);
                     }
                     else
                     {
                         answer = ;
                     }
            
                 writer.WriteLine("Case #" + cas + ": " + answer);
                 cas++;
             }
             writer.Close();
             reader.Close();
         }*/

        char[] encrypted = new char[26 ] { 'y', 'n', 'f', 'i', 'c', 'w', 'l', 'b', 'k', 'u', 'o', 'm', 'x', 's', 'e', 'v', 'z', 'p', 'd', 'r', 'j', 'g', 't','h','a','q' };
        private void Solve2()
        {
            StreamReader reader = new StreamReader("inp.txt");
            StreamWriter writer = new StreamWriter("out.txt");
            string line = reader.ReadLine();
            int cas = 1;
            while (!reader.EndOfStream)
            {
                line = reader.ReadLine();
                StringBuilder bb = new StringBuilder();
                foreach (char c in line)
                {
                    if (c == ' ')
                        bb.Append(" ");
                    else
                    {
                        int i;
                        for (i = 0; i < 26; i++)
                        {
                            if (encrypted[i] == c)
                                break;
                        }
                        bb.Append((char)((int)('a') + i));
                    }
                }
                writer.WriteLine("Case #" + cas.ToString() + ": " + bb);
                cas++;
            }
            reader.Close();
            writer.Close();
        }

        public void Solve()
        {
            StreamReader reader = new StreamReader("inp.txt");
            StreamWriter writer = new StreamWriter("out.txt");
            string line = reader.ReadLine();
            int cas = 1;
            while (!reader.EndOfStream)
            {
                line = reader.ReadLine();
                string[] toks = line.Split(new char[1] { ' ' });
                int A = int.Parse(toks[0]);
                int B = int.Parse(toks[1]);
                writer.WriteLine("Case #" + cas.ToString() + ": " + SolveCase(A, B));
                cas++;
            }
            reader.Close();
            writer.Close();
        }
        public int SolveCase(int A, int B)
        {
            int ret = 0;
            int maxDigit = A.ToString().Length;
            for (int i = A; i < B; i++)
            {
                int cc = 0;
                int pp = 10;
                int cnt = 1;
                int start = 1;
                Dictionary<int, bool> dd = new Dictionary<int, bool>();
                while (start <= maxDigit)
                {
                    int val = i % pp;                    
                    int nn = (i / pp) + (val * (int)Math.Pow(10, maxDigit - cnt));
                    if (nn > i && nn <= B && !dd.ContainsKey(nn))
                    {
                        dd.Add(nn, true);
                        cc++;
                    }
                    pp *= 10;
                    cnt++;
                    start++;
                }
                ret += cc;
            }
            return ret;
        }
    }
}