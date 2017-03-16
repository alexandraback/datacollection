using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
namespace Codejam_2012_1A_1
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("input.txt");
            StreamWriter sw = new StreamWriter("output.txt");
            int t = int.Parse(sr.ReadLine());
            for (int i = 1; i <= t; i++)
            {
                int k1=0;
                int n = int.Parse(sr.ReadLine());
                int score = 0;
                int[][] a = new int[n][];
                for (int j = 0; j <n; j++)
                {
                    a[j] = new int[3];
                    string[] tmp = sr.ReadLine().Split();
                    a[j][0] = int.Parse(tmp[0]);
                    a[j][1] = int.Parse(tmp[1]);
                    a[j][2] = 0;
                }
               
                for (int j = 0; j < n; j++)
                {
                    for (int k = j + 1; k < n; k++)
                    {
                        if (a[j][1] > a[k][1])
                        {
                            int[] tmp=new int[3];
                            tmp = a[j];
                            a[j] = a[k];
                            a[k] = tmp;
                        }
                    }
                }
                for (int j = 0; j < n; j++)
                {
                    if (i == 4)
                        i = 4;
                    if (score < a[j][1])
                    {
                        bool tr = true;
                        while (tr)
                        {
                            int flag = 0;
                            for (int k = n-1; k >=0; k--)
                            {
                                if (a[k][2] == 0&&a[k][0]<=score)
                                {
                                    k1++;
                                    flag = 1;
                                    a[k][2] = 1;
                                    score = score + 1;
                                    if (score == a[j][1])
                                    {
                                        tr = false;
                                        break;
                                    }
                                }

                            }
                            if (flag == 0)
                                break;
                        }
                    }
                        if (score >= a[j][1])
                        {
                            if (a[j][2] == 0)
                            {
                                score = score + 2;
                                a[j][2] = 1;
                            }
                            else
                                score = score + 1;
                        }
                        if (score < a[j][1])

                            score = -1;
                    
                }
                if (score == -1)
                    sw.WriteLine("Case #" + i + ": " + "Too Bad");
                else
                {
                    int f = k1 + n;
                    sw.WriteLine("Case #" + i + ": " + f);
                }
                Console.WriteLine(k1 + n);
            }
            sw.Close();
    }
    }
}
