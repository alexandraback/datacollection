using System;
using System.Linq;
using System.IO;
using System.Text;
using System.Collections.Generic;
 
public class CodeJamProblem : IDisposable
{

    static class ProblemA
    {
        private static Dictionary<char, char> _mapping = new Dictionary<char, char>();

        static void Main(string[] args)
        {
            List<char> inputChars = new List<char>();
            inputChars.Add(' ');
            for (int i = 0; i < 26; i++)
            {
                inputChars.Add((char)((int)'a' + i));
            }

            List<char> outputChars = new List<char>(inputChars.ToArray());

            // Figure out the mapping
            using (var prob = new CodeJamProblem('A', ProblemType.Sample, 0))
            {
                // initial mapping provided
                _mapping = new Dictionary<char, char> { { 'q', 'z' }, { 'e', 'o' }, { 'y', 'a' } };

                new List<char>(_mapping.Keys).ForEach(c => inputChars.Remove(c));
                new List<char>(_mapping.Values).ForEach(c => outputChars.Remove(c));

                var t = prob.ReadLineInt32() * 2;
                var lines = prob.ReadLines(t);
                for (int i = 0; i < t; i += 2)
                {
                    string input = lines[i];
                    string output = lines[i + 1];
                    for (int j = 0; j < input.Length; j++)
                    {
                        if (!_mapping.ContainsKey(input[j]))
                        {
                            _mapping.Add(input[j], output[j]);
                            inputChars.Remove(input[j]);
                            outputChars.Remove(output[j]);
                        }
                    }
                }
            }

            if (inputChars.Count > 0)
            {
                if (inputChars.Count == 1 && outputChars.Count == 1)
                {
                    _mapping.Add(inputChars[0], outputChars[0]);
                }
                else
                {
                    throw new Exception("Not expected. Ambigious mapping.");
                }
            }

            List<char> outs = new List<char>(_mapping.Keys);
            outs.Sort();
            List<char> ins = new List<char>(_mapping.Values);
            ins.Sort();

            // Solve input with the mapping
            using (var prob = new CodeJamProblem('A', ProblemType.Small, 2))
            {
                var t = prob.ReadLineInt32();
                foreach (var cur in prob.ReadLines(t))
                {
                    var input = cur;
                    List<char> chars = new List<char>(input.ToArray()); // clone input
                    for (int j = 0; j < input.Length; j++)
                    {
                        char outchar;
                        if (_mapping.TryGetValue(input[j], out outchar))
                        {
                            chars[j] = outchar;
                        }
                        else
                        {
                            throw new Exception("Something is wrong.");
                        }
                    }
                    prob.OutputCase(new string(chars.ToArray()));
                }
            }
        }
    }

    private static readonly string BaseDirectory = Path.Combine(Directory.GetParent(Environment.GetFolderPath(
        Environment.SpecialFolder.MyDocuments)).FullName, @"My Documents\CodeJam\Problems");
 
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