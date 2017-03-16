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

        static void Main(string[] args)
        {
            int n = ReadLineInt();
            for (int i = 1; i <= n; i++)
            {
                sw.WriteLine("Case #{0}: {1}", i, solve());
            }
            sw.Close();
            sr.Close();
        }

        static string solve()
        {
            string[] ss = ReadLine().Split(' ');
            string result = "";
            int N = int.Parse(ss[0]);
            double sum = 0;
            double sumX = 0;
            int numX = 0;
            for (int i = 1; i <= N; i++)
            {
                sum += double.Parse(ss[i]);
            }
            for (int i = 1; i <= N; i++)
            {
                if (double.Parse(ss[i]) >= 2 * sum / N) { sumX += double.Parse(ss[i]); numX++; }
            }
            for (int i = 1; i <= N; i++)
            {
                if (result != "") { result += " "; }
                double a = ((2.0 * sum - sumX) / (sum * (N - numX)) - double.Parse(ss[i]) / sum) * 100;
                if (a <= 0) { a = 0; }
                result += a.ToString();
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
