using System;
using System.Linq;
using System.IO;
using System.Text;
 
public class CodeJamProblem : IDisposable
{

    static class ProblemA
    {
        static void Main(string[] args)
        {
            using (var prob = new CodeJamProblem('A', ProblemType.Small, 0))
            {
                var t = prob.ReadLineInt32();
                for (int x = 0; x < t; x++)
                {
                    var abs = prob.ReadInt32Array();
                    var probs = prob.ReadDoubleArray();
                    int A = abs[0];
                    int B = abs[1];
                    int delta = B - A + 1;
                    int newKeys = B + 1;

                    double maxKeys = newKeys + 1; // press enter right away
                    double probAllCorrect = 1.0;
                    for (int i = 0; i < A; i++)
                    {
                        probAllCorrect *= probs[i];
                    }
                    double maxKeys2 = probAllCorrect * delta + (1.0 - probAllCorrect) * (delta + newKeys); // keep typing

                    maxKeys = Math.Min(maxKeys, maxKeys2);

                    // for i number of backspaces
                    // Note: no need to attempt more than A/2 backspaces and pressing enter right away will always better than that
                    for (int i = 1; i < (A/2 + 1); i++)
                    {
                        int nKeysRight = i * 2 + delta;
                        int nKeysWrong = nKeysRight + newKeys;
                        double probRight = 1.0;
                        for (int j = 0; j < (A - i); j++)
                        {
                            probRight *= probs[j];
                        }
                        double keys = probRight * nKeysRight + (1.0 - probRight) * nKeysWrong;
                        maxKeys = Math.Min(maxKeys, keys);
                    }

                    prob.OutputCase(string.Format("{0:N6}", maxKeys));
                }
            }
        }
    }
    
    private static readonly string BaseDirectory = @"C:\Temp\CodeJam\Problems"; // Path.Combine(Directory.GetParent(Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments)).FullName, @"My Documents\CodeJam\Problems");
 
    private static string GetProblemTypeName(ProblemType problemType)
    {
        return problemType.ToString().ToLower();
    }
 
    private int caseNumber;
 
    private StreamReader textReader;
    private StreamWriter textWriter;
 
    private bool disposed = false;
 
    public CodeJamProblem(char problem, ProblemType problemType, int attempt = 0)
        : this(
            Path.Combine(BaseDirectory, char.ToUpper(problem).ToString() + "-" + GetProblemTypeName(problemType) +
            (problemType == ProblemType.Small ? "-attempt" + attempt.ToString() : string.Empty) + ".in")
        )
    {
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
 
                Console.WriteLine("Elapsed time: {0:#,#0}ms", this.ElapsedTime);
                Console.Beep();
                Console.ReadKey(true);
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