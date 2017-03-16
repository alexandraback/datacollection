using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            TextReader tr = new StreamReader("C:\\Users\\Avinash\\Desktop\\input.txt");
            TextWriter tw = new StreamWriter("C:\\Users\\Avinash\\Desktop\\output.txt");

            int T;
            T = int.Parse(tr.ReadLine());
            //int start = Environment.TickCount;
            string input = null;

            for (int caseno = 1; caseno <= T; caseno++)
            {
                input = tr.ReadLine();
                string[] arr = input.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                int A = int.Parse(arr[0]);
                int B = int.Parse(arr[1]);
                int totalPair = 0;
                bool[] visited = new bool[B + 1];
                for (int n = A; n <= B; n++)
                {
                    if (visited[n] == false)
                    {
                        string nstr = n.ToString();
                        int len = nstr.Length;
                        int tempPair = 0;
                        for (int j = 1; j <= len; j++)
                        {
                            string S1 = nstr.Substring(0, j);
                            string S2 = nstr.Substring(j);
                            string mstr = S2 + S1;
                            int m = int.Parse(mstr);
                            if (m <= B)
                            {
                                if (visited[m] == false)
                                {
                                    if (A <= n && n < m && m <= B)
                                    {
                                        tempPair++;
                                        visited[m] = true;
                                    }
                                }
                            }
                        }
                        totalPair = totalPair + (tempPair * (tempPair + 1) / 2);
                    }
                    visited[n] = true;
                }

                tw.WriteLine("Case #{0}: {1}", caseno, totalPair);
            }
            //int end = Environment.TickCount;
            //int time = end - start;
            tr.Close();
            tw.Close();
        }
    }
}