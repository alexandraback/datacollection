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

            string input = null;

            for (int caseno = 1; caseno <= T; caseno++)
            {
                input = tr.ReadLine();
                string[] arr = input.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                int A = int.Parse(arr[0]);
                int B = int.Parse(arr[1]);
                int totalPair = 0;
                for (int n = A; n <= B; n++)
                {

                    string nstr = n.ToString();
                    int len = nstr.Length;
                    bool[] visited = new bool[B + 1];
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
                                    totalPair++;
                                    visited[m] = true;
                                }
                            }
                        }
                    }
                }

                tw.WriteLine("Case #{0}: {1}", caseno, totalPair);
            }

            tr.Close();
            tw.Close();
        }
    }
}