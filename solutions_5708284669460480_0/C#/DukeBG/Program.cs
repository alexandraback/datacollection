using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Globalization;

namespace codejam_1c_2
{
    public static class StreamWriterExtensions
    {
        public static void WriteAnswer(this StreamWriter sw, float f)
        {
            sw.WriteLine(f.ToString("g6", CultureInfo.InvariantCulture));
        }
    }

    class Program
    {
        class le
        {
            public char ch;
            public int count;
        }

        class lccx
        {
            public int lc;
            public bool dead;
        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(args.Length > 0 ? args[0] : "in");
            FileStream fsOut = new FileStream("out.txt", FileMode.Create);
            StreamWriter sw = new StreamWriter(fsOut);
            sw.AutoFlush = true;
            int testCount = int.Parse(sr.ReadLine());
            for (int ii = 0; ii < testCount; ii++)
            {
                sw.Write(string.Format("Case #{0}: ", ii + 1));
                string[] data = sr.ReadLine().Split(' ');
                int k = int.Parse(data[0]);
                int l = int.Parse(data[1]);
                int s = int.Parse(data[2]);
                string kk = sr.ReadLine(); Debug.Assert(kk.Length == k);
                string ll = sr.ReadLine(); Debug.Assert(ll.Length == l);

                List<char> dict = new List<char>(kk.ToCharArray());
                dict.Sort();
                dict = dict.Distinct().ToList();
                List<char> targetDict = new List<char>(ll.ToCharArray());
                targetDict.Sort();
                targetDict = targetDict.Distinct().ToList();

                if (targetDict.Except(dict).Count() > 0) { sw.WriteLine("0.0"); continue; }

                List<le> dict1 = new List<le>();
                foreach (char c in kk.ToCharArray())
                {
                    le f = dict1.FirstOrDefault(lle => lle.ch == c);
                    if (f == null)
                        f = new le { ch = c, count = 0 };
                    else
                        dict1.Remove(f);
                    f.count++;
                    dict1.Add(f);
                }

                float d = 1.0f;
                for (int i = 0; i < l; i++)
                {
                    //int desiredChar;
                    //int wordNum = Math.DivRem(i, l, out desiredChar);

                    //le f = dict1.FirstOrDefault(lle => lle.ch == ll[desiredChar]);
                    le f = dict1.FirstOrDefault(lle => lle.ch == ll[i]);
                    d = d * ((float)f.count / (float)k);
                }

                int tmp_wordNum;
                int wordNum = Math.DivRem(s, l, out tmp_wordNum);

                if ( 1 - Math.Pow(1 - d, wordNum) < 1e-7)
                {
                    sw.WriteAnswer(wordNum);
                    continue;
                }

                int maxWordsWritten = 0;
                long sum = 0;
                for (int i = 0; i < (int)Math.Pow(k, s); i++)
                {
                    int[] pressed = new int[s];
                    int ix = i;
                    for (int j = 0; j < s; j++)
                    {
                        ix = Math.DivRem(ix, k, out pressed[j]);
                    }

                    int wordsWritten = 0;
                    //int lc = 0;
                    List<lccx> lcx = new List<lccx>(); // { 0 };
                    for (int j = 0; j < s; j++)
                    {
                        lcx.Add(new lccx { lc = 0, dead = false });
                        foreach (lccx lc in lcx)
                        {
                            if (kk[pressed[j]] == ll[lc.lc])
                            {
                                lc.lc++;
                                if (lc.lc == l)
                                {
                                    wordsWritten++;
                                    lc.dead = true;
                                }
                            }
                            else
                                lc.dead = true;
                        }
                        lcx.RemoveAll(lc => lc.dead);
                    }

                    if (wordsWritten > maxWordsWritten)
                        maxWordsWritten = wordsWritten;

                    sum += wordsWritten;
                }
                float avgBananas = (float)sum / (float)Math.Pow(k, s);
                sw.WriteAnswer(maxWordsWritten - avgBananas);
            }
            fsOut.Close();
        }
    }
}
