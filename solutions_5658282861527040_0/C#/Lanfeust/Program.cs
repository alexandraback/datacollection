using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJamCS
{
    class Program
    {
        const string _downloadDir = @"C:\Users\Jean-Jacques\Downloads\";
        const string _workingDir = @"C:\Users\Jean-Jacques\Documents\Visual Studio 2013\Projects\CodeJamCS\";

        static string[] GetInputRaw(string file)
        {
            file = file + ".in";
            var fileName = _workingDir + file;
            if (!File.Exists(fileName))
                File.Move(_downloadDir + file, fileName);
            return File.ReadAllLines(fileName);
        }

        static IEnumerable<T> GetInputVar<T>(string file, Func<string[], Tuple<T, int>> f)
        {
            var allLines = GetInputRaw(file);
            int nbInput = int.Parse(allLines[0]);
            int curLine = 1;
            for (int i = 0; i < nbInput; i++)
            {
                string[] tmp = new string[allLines.Length - curLine];
                Array.Copy(allLines, curLine, tmp, 0, allLines.Length - curLine);
                var read = f(tmp);
                curLine += read.Item2;
                yield return read.Item1;
            }
        }

        static IEnumerable<T> GetInput<T>(string file, int nbLines, Func<string[], T> f)
        {
            return GetInputVar(file, a => Tuple.Create(f(a), nbLines));
        }

        static void GenOutput(string file, IEnumerable<string> results)
        {
            string fileName = _workingDir + file + ".out";
            if (File.Exists(fileName))
                File.Delete(fileName);
            int i = 0;
            using (var stream = new StreamWriter(File.OpenWrite(fileName)))
            {
                foreach (string s in results)
                    stream.WriteLine("Case #" + (++i) + ": " + s);
            }
        }

        static Tuple<int, int, int> Parse(string[] input)
        {
            var parts = input[0].Split(' ');
            return Tuple.Create(int.Parse(parts[0]), int.Parse(parts[1]), int.Parse(parts[2]));
        }

        static string SolveBrute(Tuple<int, int, int> pb)
        {
            int A = pb.Item1, B = pb.Item2, K = pb.Item3;
            int total = 0;
            for (int a = 0; a < A; a++)
                for (int b = 0; b < B; b++)
                    if ((a & b) < K)
                        total++;

            return string.Format("{0}", total);
        }

        static string Solve(Tuple<int, int, int> pb)
        {
            int A = pb.Item1, B = pb.Item2, K = pb.Item3;
            int total = 0;
            for (int a = 0; a < A; a++)
                for (int b = 0; b < B; b++)
                    if ((a & b) < K)
                        total++;

            return string.Format("{0}", total);
        }

        static void Main(string[] args)
        {
            var file = "B-small-attempt0";
            GenOutput(file, GetInput(file, 1, Parse).Select(p => Solve(p)));
        }
    }
}
