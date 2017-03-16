using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ConsoleApplication2
{
    class Program
    {
        static bool fits(string real, string pattern)
        {
            if (real.Length != pattern.Length) return false;
            int length = real.Length;
            for (int i = 0; i < length; i++)
            {
                if (pattern[i] == '?' || real[i] == pattern[i]) continue;
                return false;
            }
            return true;
        }
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("input.txt");
            StreamWriter sw = new StreamWriter("output.txt");
            int t = int.Parse(sr.ReadLine());
            for (int tt = 1; tt <= t; tt++)
            {
                sw.Write("Case #" + tt.ToString() + ": ");
                string[] spl = sr.ReadLine().Split();
                string a = spl[0];
                string b = spl[1];
                int best = 3000;
                string abest = "", bbest = "";
                for(int i=0;i<1000;i++)
                {
                    for (int j = 0; j < 1000; j++)
                    {
                        string apat = i.ToString();
                        while (apat.Length < a.Length) apat = "0" + apat;
                        string bpat = j.ToString();
                        while (bpat.Length < b.Length) bpat = "0" + bpat;
                        if (fits(apat, a) && fits(bpat, b))
                        {
                            int diff = Math.Abs(i - j);
                            if (diff < best)
                            {
                                best = diff;
                                abest = apat;
                                bbest = bpat;
                            }
                        }
                    }
                }
                sw.WriteLine(abest + " " + bbest);
            }
            sw.Close();
        }
    }
}
