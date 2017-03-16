using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Numerics;

public class CodeJamProblem : IDisposable
{

    static class ProblemD
    {

        internal static int TestCaseNum = 0;

        static void Main(string[] args)
        {
            using (var prob = new CodeJamProblem('D', ProblemType.Large, 0))
            {
                var t = prob.ReadLineInt32();
                for (int k = 0; k < t; k++)
                {
                    var arrX = prob.ReadInt32Array();
                    int K = arrX[0];
                    int C = arrX[1];
                    int S = arrX[2];
                    string output = "IMPOSSIBLE";
                    int n = 1;
                    var tiles = GetMinTiles(K, C);
                    int minS = tiles.Count;
                    //Console.WriteLine("K = " + K + ", C = " + C + ", n = " + n + " => " + minS + " {" + PrintList(tiles, " ") + "}");
                    if (S >= minS)
                    {
                        output = PrintList(tiles, " ");
                    }
                    prob.OutputCase(output);
                }
            }
        }

        private static List<string> GetMinTiles(int K, int C)
        {
            int minS;
            int n = 1;
            BigInteger all = K;
            BigInteger numGs = n;
            for (int i = 1; i < C; i++)
            {
                numGs = K * numGs + (all - numGs) * n;
                all *= K;
            }
            minS = (int) ((numGs) * K / all);
            double percentage = 100.0 * (double)numGs / (double)all;
            if (minS * all == K * numGs && minS < K) ++minS;
            minS = Math.Max(minS, K - 1);
            //minS = Math.Min(Math.Max(minS, K - 1), Math.Max(minS, K / 2 + 1));
            //Console.WriteLine("K = " + K + ", C = " + C + ", n = " + 1 + " => " + minS + " [" + numGs + " => " + percentage.ToString("0.00") + "%]");

            List<string> selections = new List<string>();
            int init = K - minS;
            for (int i = 1; i <= minS; i++)
            {
                var pos = init + i;
                selections.Add(pos.ToString());
            }

            return selections;
        }

     
    }

    public static string PrintList(List<string> list, string separator)
    {
        string output = string.Empty;

        for (int i = 0; i < list.Count; i++)
        {
            output += list[i];
            if (i < list.Count - 1)
            {
                output += separator;
            }
        }

        return output;
    }

    private static readonly string BaseDirectory = Path.Combine(Directory.GetParent(Environment.GetFolderPath(
        Environment.SpecialFolder.MyDocuments)).FullName, @"Documents\CodeJam\CodeJam2016\Qual\Input");

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
            Path.Combine(BaseDirectory, char.ToUpper(problem).ToString() + "-" + GetProblemTypeName(problemType) +
            (problemType == ProblemType.Small ? "-attempt" + attempt.ToString() : string.Empty) + ".in")
        )
    {
        _problemType = problemType;
    }

    public CodeJamProblem(string inputFileName)
    {
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

    public string[] ReadStringArray()
    {
        return ReadParts();
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

    public ulong[] ReadUInt64Array()
    {
        var parts = ReadParts();
        var values = new ulong[parts.Length];
        for (int i = 0; i < values.Length; i++)
            values[i] = ulong.Parse(parts[i]);
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