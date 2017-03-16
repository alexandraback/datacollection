using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static int Get_gcd(int a, int b)
        {
            if (a < b) 
            {
                int tmp = a;
                a = b;
                b = tmp;
            }
            return b == 0 ? a : Get_gcd(b, a % b);
        }
        static void Main(string[] args)
        {
            string fin = //"B.txt";
               "B-small-attempt4.in";
            string fout = "B.output";
            int[] A = new int[1001];
            
            StreamReader sr = new StreamReader(fin);
            StreamWriter sw = new StreamWriter(fout);

            int T = Int32.Parse(sr.ReadLine());
            int D, ans;

            for (int i = 1; i <= T; i++)
            {
                for (int j = 1; j <= 1000; j++)
                    A[j] = 0;
                int max = 0;
                ans = 0;
                D = Int32.Parse(sr.ReadLine());
                int gcd = -1;
                foreach (string s in sr.ReadLine().Split(' '))
                {
                    int num = Int32.Parse(s);
                    if (gcd == -1) gcd = num;
                    else gcd = Get_gcd(gcd, num);
                    A[num]++;
                    if (max < num) max = num;
                }



                int k = max;
                int k2;

                int ans1 = 10;   // hack for small set
                if (max == 9)  
                {
                    k2 = 8;
                    while (A[k2] == 0 && k2>0) k2--;
                    if (k2 <= 3)
                        ans1 = 2 * A[9] + 3;
                    else
                        ans1 = 2 * A[9] + k2;
                }


                ans = max;
                while (k > 3)
                {
                    if (A[k] == 0) { k--; continue; }
                    k2 = k-1;
                    while (A[k2] == 0 && k2 > (k + 1) / 2) k2--;
                    if (k2 + A[k] <= k)
                    {
                        ans = ans - k + k2 + A[k];
                        A[k / 2] += A[k];
                        A[(k + 1) / 2] += A[k];
                        k = k2;
                    }
                    else
                        break;
                }


                /*
                if (gcd > 1)
                {
                    int step = 0;
                    int cnt = 0;
                    for (int j = gcd; j <= 1000; j += gcd)
                    {
                        step += (j / gcd - 1) * A[j];
                        cnt += j / gcd * A[j];
                    }
                    int ans1 = step + gcd;
                    for (int j = 2; j < gcd; j++)
                    {
                        if (gcd % j == 0)
                        {
                            if (ans1 > step + j + (gcd / j - 1) * cnt)
                                ans1 = step + j + (gcd / j - 1) * cnt;
                        }
                    }
                    if (ans > ans1) ans = ans1;
                }
                */
                if (ans > ans1) ans = ans1;
                sw.WriteLine(string.Format("Case #{0}: {1}", i, ans));
            }
            sr.Close();
            sw.Close();
        }
    }
}
