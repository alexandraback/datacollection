using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemA
{
    class InputOutput : IDisposable
    {
        const string input = "e:\\round1b\\A-large.in";
        const string output = "e:\\round1b\\A-large.out";

        List<string> lines;
        int currentLine;

        StreamWriter writer;

        public InputOutput()
        {
            using (StreamReader sr = new StreamReader(input))
            {
                String line = sr.ReadToEnd();
                lines = new List<string>(line.Split(new string[] { "\r\n", "\n" }, StringSplitOptions.RemoveEmptyEntries));
                currentLine = 0;
            }

            writer = new StreamWriter(output, false, Encoding.ASCII);
            writer.NewLine = "\n";
        }

        public string NextLine()
        {
            if (lines != null && currentLine >= 0 && currentLine < lines.Count)
            {
                return lines[currentLine++];
            }

            return null;
        }

        public static int AsInt(string line)
        {
            return Convert.ToInt32(line);
        }

        public static double AsDouble(string line)
        {
            return Convert.ToDouble(line, System.Globalization.CultureInfo.InvariantCulture);
        }

        public int Int()
        {
            return AsInt(NextLine());
        }

        public double Double()
        {
            return AsDouble(NextLine());
        }

        public List<int> Ints()
        {
            var line = NextLine();
            var list = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            var ret = new List<int>(list.Length);

            foreach (var item in list)
            {
                ret.Add(AsInt(item));
            }

            return ret;
        }

        public void Ints(out int i1, out int i2)
        {
            var line = NextLine();
            var list = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

            i1 = 0;
            i2 = 0;

            if (list.Length > 0)
            {
                i1 = AsInt(list[0]);
            }

            if (list.Length > 1)
            {
                i2 = AsInt(list[1]);
            }
        }

        public List<double> Doubles()
        {
            var line = NextLine();
            var list = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            var ret = new List<double>(list.Length);

            foreach (var item in list)
            {
                ret.Add(AsDouble(item));
            }

            return ret;
        }

        public List<string> Strings()
        {
            var line = NextLine();
            return new List<string>(line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries));
        }

        public void Dispose()
        {
            if (writer != null)
            {
                writer.Close();
                writer.Dispose();
                writer = null;
            }
        }

        public void WriteLine(string line)
        {
            writer.WriteLine(line);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            using (var io = new InputOutput())
            {
                int tc = io.Int();

                for (int t = 0; t < tc; t++)
                {
                    string line = io.NextLine();
                    string[] h = line.Split('/');

                    long p = Convert.ToInt64(h[0]);
                    long q = Convert.ToInt64(h[1]);
                    long startGen = 1;
                    long answer = 0;

                    while(startGen < 40)
                    {
                        long gen = startGen;
                        long affect = (long)Math.Pow(2, gen);
                        long P = p;
                        long Q = q;

                        long first = -1;

                        while (P > 0 && gen < 40)
                        {
                            long tmpQ = Q;
                            long tmpA = affect;

                            if(Q >= affect)
                            {
                                if(Q % affect == 0)
                                { 
                                    long factor = Q / affect;
                                    tmpA *= factor;

                                    if (first == -1)
                                    {
                                        if (factor <= P)
                                        {
                                            P -= factor;
                                            first = gen;
                                        }
                                    }
                                    else
                                    {
                                        while (factor <= P)
                                        {
                                            P -= factor;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                P *= 2;
                                Q *= 2;
                            }

                            affect *= 2;
                            ++gen;
                        }

                        if(P == 0)
                        {
                            answer = first;
                            break;
                        }

                        ++startGen;
                    }


                    string ans;

                    if(answer > 0)
                    {
                        ans = string.Format("Case #{0}: {1}", t + 1, answer);
                    }
                    else
                    {
                        ans = string.Format("Case #{0}: impossible", t + 1);
                    }

                    io.WriteLine(ans);
                    Console.WriteLine(ans);
                }
            }
        }
    }
}
