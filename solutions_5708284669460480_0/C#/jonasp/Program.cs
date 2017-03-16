using System;
using System.Collections.Generic;
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

            var k = pars[0];
            var l = pars[1];
            var s = pars[2];

            var keys = _reader.ReadLine().ToCharArray().GroupBy(c => c).ToDictionary(g => g.Key, g => g.Count() * 1d / k);
            var word = _reader.ReadLine();

            var state = new double[l];
            for (var i = 0; i < l; i++) state[i] = 0;

            var ev = 0d;

            for (var i = 0; i < s; i++)
            {
                for (var j = l-1; j > 0; j--)
                {
                    state[j] = Prob(keys, word[j]) * state[j-1];
                }
                state[0] = Prob(keys, word[0]);
                ev += state[l-1];
            }

            var period = l;
            for (var i = l - 1; i > 0; i--)
            {
                if (!word.EndsWith(word.Substring(0, i))) continue;
                period = l - i;
                break;
            }

            var max = 0;
            if (l <= s && word.ToCharArray().All(keys.ContainsKey))
            {
                max++;
                max += (s - l) / period;
            } 
            
            _writer.WriteLine("Case #{0}: {1}", testN, max - ev);
        }
    }

    private static double Prob(Dictionary<char, double> keys, char c)
    {
        double prob = 0;
        keys.TryGetValue(c, out prob);
        return prob;
    }
}