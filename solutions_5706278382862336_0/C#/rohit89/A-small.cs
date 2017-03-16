using System;
using System.Collections.Generic;
using System.IO;
using System.Numerics;
using System.Diagnostics;
using System.Linq;

public enum ProblemType
{
    Sample,
    Small,
    Large
}

public class CodeJamProblem : IDisposable
{
    private static readonly string filepath = Path.Combine(Directory.GetParent(Environment.GetFolderPath(Environment.SpecialFolder.Personal)).FullName, "Desktop\\devp\\gcj\\");

    private static string ProblemTypeName(ProblemType problemtype)
    {
        switch (problemtype)
        { 
            case ProblemType.Sample:
                return "sample";
            case ProblemType.Small:
                return "small";
            case ProblemType.Large:
                return "large";
        }
        throw new ArgumentException("Invalid problem type", "problemtype");
    }

    private StreamReader reader;
    private StreamWriter writer;

    private string inputfile;
    private string outputfile;

    public CodeJamProblem(string filename, ProblemType problemtype)
    { 
        string problemname = Path.Combine(filepath, filename + "-" + ProblemTypeName(problemtype));
        this.inputfile = problemname + ".in";
        this.outputfile = problemname + ".out";
        this.reader = new StreamReader(this.inputfile);
        this.writer = new StreamWriter(this.outputfile);
    }

    public void WriteLine(string line)
    {
        this.writer.WriteLine(line);
        Console.WriteLine(line);
    }

    public void WriteLine(string format, params object[] args)
    {
        this.writer.WriteLine(format, args);
        Console.WriteLine(format, args);
    }

    public void Write(string line)
    {
        this.writer.Write(line);
        Console.Write(line);
    }

    public void Write(string format, params object[] args)
    {
        this.writer.Write(format, args);
        Console.Write(format, args);
    }

    public string ReadLine()
    {
        return this.reader.ReadLine();
    }

    public void Dispose()
    {
        Dispose(true);
        GC.SuppressFinalize(this);
    }

    protected void Dispose(bool disposing)
    {
        if (disposing)
        {
            reader.Close();
            writer.Close();
        }
    }
}

class Helper
{
    public static void dump<T>(T[] arr)
    {
        Console.WriteLine("[" + String.Join(", ", arr) + "]");
    }

    public static void dump<T, K>(Dictionary<T, K> dict)
    {
        foreach (T key in dict.Keys)
            Console.WriteLine("{0} => {1}", key, dict[key]);
    }

    public static void dump<T>(List<T> list)
    {
        Console.WriteLine(String.Join(" ", list));
    }

    public static void update<T, K>(Dictionary<T, K> dict, T key, K value)
    {
        if (!dict.ContainsKey(key))
            dict.Add(key, value);
    }
}

class Program
{
    static void Main(string[] args)
    {
        using (var prob = new CodeJamProblem("A", ProblemType.Small))
        {
            int t = int.Parse(prob.ReadLine());
            for (int tcase = 0; tcase < t; tcase++)
            {
                var param = prob.ReadLine().Split('/');
                var p = decimal.Parse(param[0]);
                var q = decimal.Parse(param[1]);
                var divisor = gcd(p, q);
                if (divisor != 1)
                {
                    p /= divisor;
                    q /= divisor;
                }
                if (!pow_of_two(q))
                {
                    prob.WriteLine("Case #{0}: impossible", tcase + 1);
                    prob.ReadLine();
                    continue;
                }

                var res = solve(p, q);
                if (res == -1)
                    prob.WriteLine("Case #{0}: impossible", tcase + 1);
                else
                    prob.WriteLine("Case #{0}: {1}", tcase + 1, res);
            }
        }     
        Console.ReadLine();
    }

    private static int solve(decimal p, decimal q)
    {
        int gen = 0;
        while (gen <= 40)
        {
            if (q == 1)
            {
                if (p == 1) return gen;
                else return -1;
            }
            if (p > q)
                return gen;
            
            q /= 2;
            gen++;
        }
        return -1;
    }

    private static bool pow_of_two(decimal q)
    {
        for (double i = 0; i <= 40; i++)
            if ((decimal)Math.Pow(2, i) == q) return true;
        return false;
    }

    private static decimal gcd(decimal p, decimal q)
    {
        if (q == 0) return p;
        else return gcd(q, p % q);
    }
}
