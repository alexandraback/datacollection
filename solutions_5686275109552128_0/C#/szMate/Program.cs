using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Pancakes2
{
    class Program
    {
        static int getmax(int[] p, int length)
        {
            int max = 0;
            int num = 0;
            for (int i = 0; i < length; i++)
            {
                if (p[i] == max)
                {
                    num++;
                }
                else if (p[i] > max)
                {
                    max = p[i];
                    num = 1;
                }
            } return max;
           /* int threshold = (max + 1) / 2;
            // int max2 = 0;
            for (int i = 0; i < length; i++)
            {
                if (p[i] > threshold && p[i] < max)
                {
                    // max2 = p[i];
                    num++;
                }
            }
            return new int[] { max, num, threshold };*/
        }

        static int[] gain(int[] p, int length, int max, int threshold)
        {
            int[] ret = new int[(max-threshold)];
            for (int j = 0; j < ret.Length; j++)
            {
                for (int i = 0; i < length; i++)
                {
                    if (p[i] > threshold + j)
                    {
                        ret[j]++;
                    }
                }
            }
            return ret;
        }

        static void half(int[] p, ref int length, int n)
        {
            for (int i = 0; i < length; i++)
            {
                if (p[i] > n)
                {
                    p[length] = p[i] / 2;
                    length++;
                    p[i] = (p[i] + 1) / 2;
                }
            }
        }

        static void eat(int[] p, int length)
        {
            for (int i = 0; i < length; i++)
            {
                if (p[i] > 0) p[i]--;
            }
        }


        static void eat2(int[] p, int length)
        {
            for (int i = 0; i < length; i++)
            {
                p[i]--;
            }
        }

        static void uneat(int[] p, int length)
        {
            for (int i = 0; i < length; i++)
            {
                p[i]++;
            }
        }

        static void halfat(int[] p, int length, int at)
        {
            p[length] = p[at] / 2;
            p[at] = (p[at] + 1) / 2;
        }

        static int rechowmany(int[] p, int length, int max)
        {
            if (max==-1) max = getmax(p, length);
            if (max == 1) return 1;
            else if (max == 2) return 2;
            else if (max == 3) return 3;
            else
            {
                int best = 1000000;

                eat2(p,length);
                int cand = 1+ rechowmany(p, length, max-1);
                if (cand < best) best = cand;
                uneat(p, length);
                HashSet<int> hs = new HashSet<int>();
                for (int i = 0; i < length; i++)
                {
                    if (p[i] < 3) continue;
                    if (hs.Contains(p[i])) continue;
                    if (p[i] != max) continue;
                    hs.Add(p[i]);
                    int save = p[i];
                    halfat(p, length, i);
                    max = getmax(p, length);
                    cand = 1+ rechowmany(p, length + 1, max);
                    if (cand < best) best = cand;
                    p[i] = save;
                    //length--;
                }
                return best;
            }
        }

        static int howmany(int[] p, int length)
        {
            //int[] p, int length = new int[](P);

            int time = 0;

            int max = getmax(p, length);
            int threshold = (max + 1) / 2;
            int[] got = gain(p, length, max, threshold);
            while (max > 1)
            {
                int maxdiff=-1;
                int index=-1;
                for (int i = 0; i < got.Length; i++)
		        {
                    if ((max - (threshold + i)) - got[i] >= maxdiff)
                    {
                        maxdiff = (max - (threshold + i)) - got[i];
                        index = i;
                    }
		        }
                //int diff = (max / 2);
                if (maxdiff >= 0)
                {
                    time += got[index];
                    half(p, ref length, threshold+index);
                }
                else
                {
                    time++;
                    eat(p, length);
                }

                max = getmax(p, length);
                threshold = (max + 1) / 2;
                got = gain(p, length, max, threshold);
            }
            return time+1;
        }

        static void Main(string[] args)
        {
            StreamWriter sw = new StreamWriter("B-small-attempt5.out");
            StreamReader sr = new StreamReader("B-small-attempt5.in");
            int T = Int32.Parse(sr.ReadLine());
            for (int i = 0; i < T; i++)
            {
                int D = Int32.Parse(sr.ReadLine());
                string[] line = sr.ReadLine().Split(' ');
                int[] line2 = new int[1000000];
                for (int j = 0; j < line.Length; j++)
                {
                    line2[j] = Int32.Parse(line[j]);
                }
                int time = rechowmany(line2, line.Length, -1);
                sw.WriteLine("Case #{0}: {1}", i + 1, time);
                sw.Flush();
            }
            sr.Close();
            sw.Flush();
            sw.Close();
        }
    }
}
