using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;
using System.Diagnostics;
using System.Numerics;

class Problem
{
    const string inFile = "..\\..\\asmall.in";
    const string outFile = "..\\..\\asmall.out";

    public void Process()
    {
        using (StreamReader sr = new StreamReader(inFile))
        {
            using (StreamWriter sw = new StreamWriter(outFile))
            {
                int numCases = int.Parse(sr.ReadLine());
                Console.WriteLine("There are {0} test cases.", numCases);
                for (int @case = 1; @case <= numCases; @case++)
                {
                    int[] ss = Array.ConvertAll<string, int>(sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries), int.Parse);
                    int A = ss[0];
                    int B = ss[1];
                    double[] a = Array.ConvertAll<string, double>(sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries), double.Parse);

                    string res = Solve(A, B, a);
                    sw.WriteLine("Case #{0}: {1}", @case, res);
                    Console.WriteLine("Done test case {0}...", @case);
                }
            }
        }
    }

    private string Solve(int n, int B, double[] a)
    {
        double[] f = new double[n];
        double correct = 1;
        for (int i = 0; i < n; i++)
        {
            f[i] = correct;
            correct *= a[i];
        }

        double first = calc1(n, B, a, correct);
        double second = calc2(n, B, a, f);

        double min = Math.Min(first, second);
        min = Math.Min(min, B + 2);

        return min.ToString();
    }

    private double calc2(int n, int B, double[] a, double[] f)
    {
        double res = double.MaxValue;
        for (int i = n - 1; i >= 0; --i)
        {
            int left = n - i + B - i + 1;
            double val = f[i]*(left) + (1 - f[i])*(left + B + 1);
            res = Math.Min(res, val);
        }

        return res;
    }

    private double calc1(int n, int B, double[] a, double correct)
    {
        int left = B - n + 1;
        return correct*left + (1 - correct)*(left + B + 1);
    }

    public static void Main()
    {
        Problem p = new Problem();
        p.Process();
    }
}