using System;
using System.Linq;
using System.IO;
using System.Text;
using System.Collections.Generic;
using System.Diagnostics;

public class CodeJamProblem : IDisposable
{

    static class ProblemB
    {
        static void Main(string[] args)
        {
            using (var prob = new CodeJamProblem('A', ProblemType.Large))
            {
                var test = prob.ReadLineInt32();
                for (int k = 0; k < test; k++)
                {
                    var arr = prob.ReadInt32Array();
                    int A = arr[0];
                    int N = arr[1];
                    var sizes = new List<int>(prob.ReadInt32Array());
                    sizes.Sort();
                    int MIN = Solve(sizes, 0, A, 0);
                    prob.OutputCase(MIN);
                }

            }
        }

        private static int Solve(List<int> sizes, int startPos, int A, int MIN)
        {
            for (int i = startPos; i < sizes.Count; i++)
            {
                if (A <= sizes[i])
                {
                    if (MIN >= sizes.Count) return sizes.Count;
                    // CASE 1: remove sizes[i]
                    int min1 = Solve(sizes, i + 1, A, MIN + 1);
                    // CASE 2: add A -1 moat
                    int newA;
                    int n = GetMinMoatsToAdd(A, sizes[i], sizes.Count, out newA);
                    int min2 = sizes.Count;
                    if (n + MIN < sizes.Count)
                    {
                        min2 = Solve(sizes, i, newA, MIN + n);
                    }
                    return Math.Min(Math.Min(min1, min2), sizes.Count);
                }
                else
                {
                    A += sizes[i]; // everything good
                }
            }
            return Math.Min(MIN, sizes.Count);
        }

        private static int GetMinMoatsToAdd(int A, int target, int maxN, out int newA)
        {
            int n = 0;
            while (A <= target && n < maxN)
            {
                ++n;
                A += A - 1;
            }
            newA = A;
            return n;
        }
    }

    private static readonly string BaseDirectory = Path.Combine(Directory.GetParent(Environment.GetFolderPath(
        Environment.SpecialFolder.MyDocuments)).FullName, @"Documents\CodeJam\Problems");

    private static string GetProblemTypeName(ProblemType problemType)
    {
        return problemType.ToString().ToLower();
    }

    private int caseNumber;

    private StreamReader textReader;
    private StreamWriter textWriter;

    private bool disposed = false;
    private ProblemType _problemType;

    public CodeJamProblem(char problem, ProblemType problemType, int attempt = 0)
        : this(
            char.ToUpper(problem).ToString() + "-" + GetProblemTypeName(problemType) +
            (problemType == ProblemType.Small ? "-attempt" + attempt.ToString() : string.Empty) + ".in"
        )
    {
        _problemType = problemType;
    }
    
    public CodeJamProblem(string practiceProblem, ProblemType problemType)
        : this(
            practiceProblem.ToUpper() + "-" + GetProblemTypeName(problemType) +
             "-practice" + ".in"
        )
    {
        _problemType = problemType;
    }

    public CodeJamProblem(string inputFileName)
    {
        if (!File.Exists(inputFileName))
        {
            inputFileName = Path.Combine(BaseDirectory, inputFileName);
        }

        this.InputFileName = inputFileName;
        this.OutputFileName = Path.ChangeExtension(this.InputFileName, ".out");

        this.textReader = new StreamReader(this.InputFileName);
        this.textWriter = new StreamWriter(this.OutputFileName);

        this.caseNumber = 1;
        this.StartTime = Environment.TickCount;
    }

    public int StartTime
    {
        get;
        private set;
    }

    public int ElapsedTime
    {
        get;
        private set;
    }

    public int CurrentCaseNumber
    {
        get { return this.caseNumber; }
    }

    public bool InputAvailable
    {
        get { return this.textReader.Peek() != -1; }
    }

    public string InputFileName
    {
        get;
        private set;
    }

    public string OutputFileName
    {
        get;
        private set;
    }

    public void Dispose()
    {
        Dispose(true);
        GC.SuppressFinalize(this);
    }

    protected void Dispose(bool disposing)
    {
        if (!disposed)
        {
            if (disposing)
            {
                this.ElapsedTime = Environment.TickCount - this.StartTime;

                textReader.Dispose();
                textWriter.Dispose();

                if (_problemType != ProblemType.Sample)
                {
                    Console.WriteLine("Elapsed time: {0:#,#0}ms", this.ElapsedTime);
                    Console.Beep();
                    Console.ReadKey(true);
                }
            }
        }

        disposed = true;
    }

    public void OutputCase(params object[] values)
    {
        var parts = new string[values.Length];
        for (int i = 0; i < parts.Length; i++)
            parts[i] = values[i].ToString();
        OutputCase(string.Join(" ", parts));
    }

    public void OutputCase()
    {
        OutputCase((string)null);
    }

    public void OutputCase(string value)
    {
        WriteLine("Case #{0:#0}: {1}", this.caseNumber, value);
        this.caseNumber++;
    }

    public void WriteArrays<T>(T[][] entries)
    {
        for (int i = 0; i < entries.Length; i++)
            WriteArray(entries[i]);
    }

    public void WriteArray<T>(T[] values)
    {
        var parts = new string[values.Length];
        for (int i = 0; i < parts.Length; i++)
            parts[i] = values[i].ToString();
        WriteLine(string.Join(" ", parts));
    }

    public void WriteLines(string[] lines)
    {
        for (int i = 0; i < lines.Length; i++)
            WriteLine(lines[i]);
    }

    public void WriteLine(string format, params object[] arg)
    {
        Console.WriteLine(format, arg);
        this.textWriter.WriteLine(format, arg);
    }

    public void WriteLine(string line)
    {
        Console.WriteLine(line);
        this.textWriter.WriteLine(line);
    }

    public T[][] ReadArrays<T>(int count, Func<string, T> converter)
    {
        var entries = new T[count][];
        for (int i = 0; i < entries.Length; i++)
            entries[i] = ReadArray(converter);
        return entries;
    }

    public T[] ReadArray<T>(Func<string, T> converter)
    {
        var parts = ReadParts();
        var values = new T[parts.Length];
        for (int i = 0; i < values.Length; i++)
            values[i] = converter(parts[i]);
        return values;
    }

    public short[][] ReadInt16Arrays(int count)
    {
        var entries = new short[count][];
        for (int i = 0; i < entries.Length; i++)
            entries[i] = ReadInt16Array();
        return entries;
    }

    public short[] ReadInt16Array()
    {
        var parts = ReadParts();
        var values = new short[parts.Length];
        for (int i = 0; i < values.Length; i++)
            values[i] = short.Parse(parts[i]);
        return values;
    }

    public int[][] ReadInt32Arrays(int count)
    {
        var entries = new int[count][];
        for (int i = 0; i < entries.Length; i++)
            entries[i] = ReadInt32Array();
        return entries;
    }

    public int[] ReadInt32Array()
    {
        var parts = ReadParts();
        var values = new int[parts.Length];
        for (int i = 0; i < values.Length; i++)
            values[i] = int.Parse(parts[i]);
        return values;
    }

    public long[][] ReadInt64Arrays(int count)
    {
        var entries = new long[count][];
        for (int i = 0; i < entries.Length; i++)
            entries[i] = ReadInt64Array();
        return entries;
    }

    public long[] ReadInt64Array()
    {
        var parts = ReadParts();
        var values = new long[parts.Length];
        for (int i = 0; i < values.Length; i++)
            values[i] = long.Parse(parts[i]);
        return values;
    }

    public double[][] ReadDoubleArrays(int count)
    {
        var entries = new double[count][];
        for (int i = 0; i < entries.Length; i++)
            entries[i] = ReadDoubleArray();
        return entries;
    }

    public double[] ReadDoubleArray()
    {
        var parts = ReadParts();
        var values = new double[parts.Length];
        for (int i = 0; i < values.Length; i++)
            values[i] = double.Parse(parts[i]);
        return values;
    }

    public string[] ReadParts()
    {
        return ReadLine().Split(' ');
    }

    public string[] ReadLines(int count)
    {
        var lines = new string[count];
        for (int i = 0; i < lines.Length; i++)
            lines[i] = ReadLine();
        return lines;
    }

    public short ReadLineInt16()
    {
        return short.Parse(ReadLine());
    }

    public int ReadLineInt32()
    {
        return int.Parse(ReadLine());
    }

    public long ReadLineInt64()
    {
        return long.Parse(ReadLine());
    }

    public double ReadLineDouble()
    {
        return double.Parse(ReadLine());
    }

    public string ReadLine()
    {
        return this.textReader.ReadLine();
    }
}

public enum ProblemType
{
    Sample,
    Small,
    Large,
}