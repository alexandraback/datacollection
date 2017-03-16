using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class GarbledEmail : GCJBase
    {
        HashSet<string> dic = new HashSet<string>();

        public override void Solve()
        {
            System.IO.FileInfo f = new System.IO.FileInfo("garbled_email_dictionary.txt");
            var reader = f.OpenText();
            int longest = 0;
            while (!reader.EndOfStream)
            {
                string word = reader.ReadLine();
                longest = Math.Max(longest, word.Length);
                dic.Add(word);
            }


            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                string s = Console.ReadLine();
                long ret = minChanges(s);

                Console.WriteLine("Case #{0}: {1}", iCase, ret);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private int minChanges(string s)
        {
            // Next index written , safe #
            int[,] min = new int[s.Length + 1, 5];
            for (int i = 0; i < s.Length + 1; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    min[i, j] = 9999;
                }
            }

            min[0, 0] = 0;

            for (int nextidx = 0; nextidx < s.Length; nextidx++)
            {
                for (int safe = 0; safe < 5; safe++)
                {
                    if (min[nextidx, safe] == 9999) continue;

                    for (int nextwordlen = 1; nextwordlen <= 10; nextwordlen++)
                    {
                        if (nextidx + nextwordlen > s.Length) continue;

                        char[] c = new char[nextwordlen];
                        for (int i = 0; i < nextwordlen; i++)
                        {
                            c[i] = s[nextidx + i];
                        }

                        if (dic.Contains(new string(c)))
                        {
                            int newsafe = Math.Max(0, safe - nextwordlen);
                            min[nextidx + nextwordlen, newsafe] = Math.Min(min[nextidx+nextwordlen,newsafe], min[nextidx, safe]);
                        }
                        else
                        {
                            // Change 2 letters
                            for (int a1 = safe; a1 < nextwordlen; a1++)
                            {
                                int a2min = a1 + 5;
                                if (a2min > nextwordlen) a2min = nextwordlen;
                                for (int a2 = a2min; a2 < nextwordlen + 1; a2++)
                                {
                                    int nextsafe = 5 + a2 - nextwordlen;
                                    if (nextsafe >= 5) nextsafe = 5 + a1 - nextwordlen;
                                    if (nextsafe >= 5) nextsafe = 4;
                                    if (nextsafe < 0) nextsafe = 0;

                                    char c1min = 'a';
                                    char c1max = 'z';
                                    char c2min = 'a';
                                    char c2max = 'z';
                                    int changed = 2;
                                    if (a2 == nextwordlen)
                                    {
                                        c2max = 'a';
                                        changed = 1;
                                    }

                                    char oldc2 = 'a';
                                    if (a2 < nextwordlen)
                                    {
                                        oldc2 = c[a2];
                                    }
                                    for (char c2 = c2min; c2 <= c2max; c2++)
                                    {
                                        if (a2 < nextwordlen)
                                        {
                                            c[a2] = c2;
                                        }
                                        char oldc1 = c[a1];
                                        for (char c1 = c1min; c1 <= c1max; c1++)
                                        {
                                            c[a1] = c1;

                                            if (dic.Contains(new string(c)))
                                            {
                                                min[nextidx + nextwordlen, nextsafe] = Math.Min(min[nextidx + nextwordlen, nextsafe], min[nextidx, safe] + changed);
                                            }

                                        }
                                        c[a1] = oldc1;
                                    }
                                    if (a2 < nextwordlen) c[a2] = oldc2;
                                }
                            }
                        }
                    }
                }
            }

            int minret = 9999;
            for (int safe = 0; safe < 5; safe++)
            {
                minret = Math.Min(minret, min[s.Length, safe]);
            }
            return minret;
        }

    }
}
