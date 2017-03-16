using System;
using System.Collections.Generic;
using System.Text;
using System.Collections;
using System.IO;

/* Yoel Grodentzik
 * thed0okie
 * C#
 * Kingdom Rush  (B)
 */

namespace goroGCjam
{
    class GCJ2012R1B
    {
        static void Main(string[] args)
        {

            StreamReader sr = new StreamReader(@"C:\B-large.in");
            StreamWriter sw = new StreamWriter(@"C:\B-large.out");

            int numCases = 0;
            numCases = Convert.ToInt32(sr.ReadLine());

            for (int i = 0; i < numCases; i++)
            {
                string theLine = sr.ReadLine();
                int numLvl = Convert.ToInt32(theLine);

                int[] A = new int[numLvl];
                int[] B = new int[numLvl];

                int[] A2 = new int[numLvl];
                int[] B2 = new int[numLvl];

                List<Level> lvlLst = new List<Level>();
                List<Level> lvlLst2 = new List<Level>();

                for (int j = 0; j < numLvl; j++)
                {
                    theLine = sr.ReadLine();
                    string[] tmp = new string[2];
                    tmp = theLine.Split(' ');
                    A[j] = Convert.ToInt32(tmp[0]);
                    B[j] = Convert.ToInt32(tmp[1]);

                    Level lev = new Level(A[j], B[j], j);
                    lvlLst.Add(lev);
                }

                lvlLst.Sort(delegate(Level l1, Level l2) { return l1.a.CompareTo(l2.a); } );
                for(int j = 0; j < numLvl; j++)
                    lvlLst[j].idx1 = j;

                lvlLst.Sort(delegate(Level l1, Level l2) { return l1.b.CompareTo(l2.b); } );
                
                for(int j = 0; j < numLvl; j++)
                    lvlLst[j].idx2 = j;

                for(int j = 0; j < numLvl; j++)
                    lvlLst2.Add(lvlLst[j]);
                
                lvlLst.Sort(delegate(Level l1, Level l2) { return l1.a.CompareTo(l2.a); } );
                for (int k = 0; k < lvlLst.Count; k++)
                {
                    for (int l = k+1; l < lvlLst.Count; l++)
                    {
                        if (lvlLst[k].a == lvlLst[l].a)
                        {
                            if (lvlLst[k].b < lvlLst[l].b)
                            {
                                Level lvlTmp = lvlLst[k];
                                lvlLst[k] = lvlLst[l];
                                lvlLst[l] = lvlTmp;
                            }
                        }
                    }
                }
                lvlLst2.Sort(delegate(Level l1, Level l2) {  return l1.b.CompareTo(l2.b); } );
                for (int k = 0; k < lvlLst2.Count; k++)
                {
                    for (int l = k + 1; l < lvlLst2.Count; l++)
                    {
                        if (lvlLst2[k].b == lvlLst2[l].b)
                        {
                            if (lvlLst2[k].a > lvlLst2[l].a)
                            {
                                Level lvlTmp = lvlLst2[k];
                                lvlLst2[k] = lvlLst2[l];
                                lvlLst2[l] = lvlTmp;
                            }
                        }
                    }
                }

                int numStar = 0;
                int numTry = 0;
                
                
                bool canSolve = true;

                while(canSolve && lvlLst2.Count > 0)
                {
                    canSolve = false;
                    if(lvlLst2[0].b <= numStar)
                    {
                        if(lvlLst.Contains(lvlLst2[0]))
                        {
                            lvlLst.Remove(lvlLst2[0]);
                            numStar++;
                        }

                        lvlLst2.RemoveAt(0);
                        numStar++;
                        numTry++;
                        canSolve = true;
                    }
                    else if(lvlLst.Count > 0 && lvlLst[0].a <= numStar)
                    {
                        lvlLst.Remove(lvlLst[0]);
                        numStar++;
                        numTry++;
                        canSolve = true;
                    }
                }
                //small dataset

                if(!canSolve)
                    sw.WriteLine("Case #" + (i + 1) + ": " + "Too Bad");
                else
                    sw.WriteLine("Case #" + (i + 1) + ": " + numTry);

                lvlLst = null;
                lvlLst2 = null;
            }

            sr.Close();
            sw.Close();
        }

        class Level
        {
            public int lvNum;
            public int a;
            public int b;
            public int idx1;
            public int idx2;

            public Level(int x, int y, int lv)
            {
                a = x;
                b = y;
                idx1 = -1;
                idx2 = -1;
                lvNum = lv;
            }
        }

        
    }


}
