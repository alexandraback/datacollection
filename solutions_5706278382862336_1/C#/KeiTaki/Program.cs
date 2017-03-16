using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class Program
    {
        static string _folderPath = Directory.GetCurrentDirectory() + @"/../../Questions/";
        static string _question = "PartElf";
        static string _dataSize = "L";   // T, S or L q

        static void Main(string[] args)
        {
            var data = File.ReadAllLines(_folderPath + _question + "_" + _dataSize + ".in");

            using (var outFile = File.CreateText(_folderPath + _question + "_" + _dataSize + ".out"))
            {
                Action<string> dualWriter = line =>
                {
                    Console.WriteLine(line);
                    outFile.WriteLine(line);
                };

                solve(data, dualWriter);
            }

            Console.WriteLine("Done!");
            Console.Read();
        }

        static void solve(IList<string> lines, Action<string> writeLine)
        {
            int numQs = int.Parse(lines[0]);

            int at = 1;

            for (int q = 0; q < numQs; q++)
            {
                // parse data here
                var data = lines[at++].Split(new[] { '/' }, StringSplitOptions.RemoveEmptyEntries).Select(s => long.Parse(s)).ToList();

                string answer = solve1(data[0], data[1]);
                writeLine(string.Format("Case #{0}: {1}", q + 1, answer));
            }
        }

        static string solve1(long top, long btm)
        {
            long bb = btm;

            while (bb > 1)
            {
                if (bb % 2 != 0)
                {
                    if (top % bb != 0)
                    {
                        return "impossible";
                    }
                    else
                    {
                        top /= bb;
                        btm /= bb;
                        break;
                    }
                }

                bb /= 2;
            }

            bb = btm;
            int ct = 0;

            while (bb > 1)
            {
                bb /= 2;
                ct++;
            }

            if (ct > 40)
            {
                return "impossible";
            }

            ct = 1;

            while (top < btm / 2)
            {
                btm /= 2;
                ct++;
            }

            return ct.ToString();
        }
    }

    #region Extensions

    public static class Ext
    {
        public static String ReplaceAt(this String s, int pos, char c)
        {
            var sb = new StringBuilder(s);
            sb[pos] = c;
            return sb.ToString();
        }
    }

    #endregion
}


// lines[at++].Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(s => double.Parse(s)).ToList();