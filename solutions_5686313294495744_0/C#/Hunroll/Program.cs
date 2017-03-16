using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace Sheeps
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("a.in");
            StreamWriter sw = new StreamWriter("a.out");
            int tryCnt = Convert.ToInt32(sr.ReadLine());
            //string[] N = new string[tryCnt];
            for (int Tr = 0; Tr < tryCnt; Tr++)
            {
                int topCnt = Convert.ToInt32(sr.ReadLine());
                List<string> p1s = new List<string>();
                List<int> p1cnts = new List<int>();
                List<string> p2s = new List<string>();
                List<int> p2cnts = new List<int>();
                string[,] topics = new string[topCnt, 2];
                #region readAndFill
                for (int top = 0; top < topCnt; top++)
                {
                    string N = sr.ReadLine();
                    string p1 = N.Substring(0, N.IndexOf(' '));
                    string p2 = N.Substring(N.IndexOf(' ') + 1);
                    topics[top, 0] = p1;topics[top, 1] = p2;
                    int index = p1s.IndexOf(p1);
                    if (index==-1)
                    {
                        p1s.Add(p1);
                        p1cnts.Add(1);
                    }
                    else
                        p1cnts[index]++;
                    index = p2s.IndexOf(p2);
                    if (index == -1)
                    {
                        p2s.Add(p2);
                        p2cnts.Add(1);
                    }
                    else
                        p2cnts[index]++;
                }
                #endregion

                List<string> definiteP1s = new List<string>();
                List<string> definiteP2s = new List<string>();
                int numberOfUnique = 0;
                for (int i = 0; i < topCnt; i++)
                    if (p1cnts[p1s.IndexOf(topics[i, 0])] == 1 || p2cnts[p2s.IndexOf(topics[i, 1])] == 1)
                    {
                        definiteP1s.Add(topics[i, 0]);definiteP2s.Add(topics[i, 1]);
                        numberOfUnique++;
                    }
                for (int i = 0; i < topCnt; i++)
                    if (definiteP1s.IndexOf(topics[i,0])==-1 && definiteP2s.IndexOf(topics[i, 1]) == -1)
                    {
                        definiteP1s.Add(topics[i, 0]); definiteP2s.Add(topics[i, 1]);
                        numberOfUnique++;
                    }
                for (int i = 0; i < topCnt; i++)
                    if (definiteP1s.IndexOf(topics[i, 0]) == -1 || definiteP2s.IndexOf(topics[i, 1]) == -1)
                    {
                        definiteP1s.Add(topics[i, 0]); definiteP2s.Add(topics[i, 1]);
                        numberOfUnique++;
                    }
                sw.WriteLine("Case #" + (Tr + 1) + ": "+(topCnt-numberOfUnique));
            }

            sr.Close();
            sw.Close();
        }


    }
}
