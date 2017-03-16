using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader inFile = new StreamReader("b.in");
            StreamWriter outFile = new StreamWriter("b.out");

            int csCnt = Convert.ToInt32(inFile.ReadLine());
            for (int csId = 1; csId <= csCnt; csId++)
            {
                int n = Convert.ToInt32(inFile.ReadLine());
                List<int> L1 = new List<int>();
                List<int> L2 = new List<int>();
                for (int i = 0; i < n; i++)
                {
                    string[] spt = inFile.ReadLine().Split();
                    L1.Add(Convert.ToInt32(spt[0]));
                    L2.Add(Convert.ToInt32(spt[1]));
                }
                int ans = getAnswer(n, L1, L2);
                outFile.WriteLine("Case #{0}: {1}", csId, ((ans > 0) ? ans.ToString() : "Too Bad"));
            }

            inFile.Close();
            outFile.Close();
        }

        static int getAnswer(int n, List<int> L1, List<int> L2)
        {
            int comp = 0;
            int star = 0;
            int ans = 0;
            while (comp < n)
            {
                int s2 = getNext2(star, L1, L2);
                if (s2 >= 0)
                {
                    comp++;
                    star += ((L1[s2] < 0) ? 1 : 2);
                    L2[s2] = -1;
                    //L1[s2] = -1; //
                    ans++;
                }
                else
                {
                    bool flag = false;
                    for (int i = 0; i < n; i++)
                        if (L2[i] < 0 && L1[i] >= 0)
                        {
                            L1[i] = -1;
                            star += 2;
                            ans++;
                            flag = true;
                            break;
                        }
                    if (!flag)
                    {
                        int s1 = getNext1(star, L1, L2);
                        if (s1 >= 0)
                        {
                            star++;
                            L1[s1] = -1;
                            ans++;
                        }
                        else
                        {
                            break;
                        }

                    }
                }
            }
            if (comp < n) ans = -1;
            return ans;
        }

        static int getNext1(int star, List<int> L1, List<int> L2)
        {
            for (int i = 0; i < L1.Count; i++)
                if (L1[i] >= 0 && star >= L1[i] && L2[i] >= 0) return i;
            return -1;
        }

        static int getNext2(int star, List<int> L1, List<int> L2)
        {
            for (int i = 0; i < L2.Count; i++)
                if (L2[i] >= 0 && star >= L2[i]) return i;
            return -1;
        }
    }
}
