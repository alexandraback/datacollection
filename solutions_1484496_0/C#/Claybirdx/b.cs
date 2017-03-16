using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace R1B
{
    class Program
    {
        static string strIn = "C:\\Users\\hp\\Downloads\\input.txt";
        static string strOut = "C:\\Users\\hp\\Downloads\\output.txt";
        static StreamReader sr = new StreamReader(strIn, System.Text.Encoding.ASCII);
        static StreamWriter sw = new StreamWriter(strOut, false, System.Text.Encoding.ASCII);

        static Dictionary<long, string> dicSum = new Dictionary<long, string>();

        static void Main(string[] args)
        {
            int n = ReadLineInt();
            for (int i = 1; i <= n; i++)
            {
                dicSum.Clear();
                sw.WriteLine("Case #{0}:", i );
                solve();
            }
            sr.Close();
            sw.Close();
        }

        static void solve()
        {
            dicSum.Clear();
            string[] ss = ReadLine().Split(' ');
            
            int N = int.Parse(ss[0]);

            int[] num = new int[N];
            for (int i = 0; i <= N - 1; i++)
            {
                num[i] = int.Parse(ss[i + 1]);
            }
            for (long i = 1; i <= Math.Pow(2,N); i++)
            {
                long x = long.Parse((i + Math.Pow(2, N)).ToString());
                string n = Convert.ToString(x, 2);
                long sum = 0;
                for (int j = 1; j <= N; j++)
                {
                    if (n.Substring(j, 1) == "1") { sum += num[j-1]; }
                }
                if (dicSum.ContainsKey(sum))
                {
                    if (n != dicSum[sum])
                    {
                        sw.WriteLine(CreateArray(num, n));
                        sw.WriteLine(CreateArray(num, dicSum[sum]));
                        return;
                    }
                }
                else
                {
                    dicSum[sum] = n;
                }
            }
            sw.WriteLine("Impossible");
            return;
        }
        static string CreateArray(int[] aryInt, string n)
        {
            string result = "";
            for (int i = 1; i < n.Length; i++)
            {
                if (n.Substring(i,1) == "1")
                {
                    if (result != "") { result += " "; }
                    result += aryInt[i-1].ToString();
                }
            }
            return result;
        }

        static string ReadLine()
        {
            return sr.ReadLine();
        }

        static double ReadLineDouble()
        {
            return double.Parse(sr.ReadLine());
        }

        static int ReadLineInt()
        {
            return int.Parse(sr.ReadLine());
        }

        static string[] ReadLineArray(int count)
        {
            var lines = new string[count];
            for (int i = 0; i < lines.Length; i++)
                lines[i] = ReadLine();
            return lines;
        }

        static string[] ReadLinePart()
        {
            return ReadLine().Split(' ');
        }
    }
}
