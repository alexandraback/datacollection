using System;
using System.Data;
using System.IO;
using System.Linq;

class Program
{
    private static StreamReader _reader;
    private static StreamWriter _writer;

    static Program()
    {
        _reader = new StreamReader(@"C:\CodeJam.Round1A\data\input.txt");
        _writer = new StreamWriter(@"C:\CodeJam.Round1A\data\output.txt", false);
        _writer.AutoFlush = true;
    }

    public static void Main()
    {
        var testCount = int.Parse(_reader.ReadLine());
        for (int testN = 1; testN <= testCount; testN++)
        {
            var pars = _reader.ReadLine().Split().Select(p => Convert.ToInt32(p)).ToArray();

            _writer.WriteLine("Case #{0}: {1}", testN, Solve(pars[0], pars[1], pars[2]));
        }
    }

    private static int Solve(int r, int c, int w)
    {
        var guesses = r*c/w + w - (c%w == 0 ? 1 : 0);
        return guesses;
    }
}