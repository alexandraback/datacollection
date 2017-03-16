using System;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

namespace C
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            string inputFilename = "C-large.in"; //args[0];
            string outputFilename = Path.ChangeExtension(inputFilename, "out");

            using (var input = new StreamReader(File.OpenRead(inputFilename)))
            using (var output = new StreamWriter(File.Open(outputFilename, FileMode.Create)))
            {
                int T = int.Parse(input.ReadLine());

                var bombs = new string(Enumerable.Repeat('*', 50).ToArray());
                var unknown = new string(Enumerable.Repeat('.', 50).ToArray());

                for (int tc = 1; tc <= T; ++tc)
                {
                    var a = input.ReadLine().Split(' ').Select(int.Parse).ToArray();
                    var r = a[0];
                    var c = a[1];
                    var m = a[2];

                    var free = r*c - m;
                    var side = (int)Math.Ceiling(Math.Sqrt(free));

                    var nr = Math.Min(r, side);
                    int nc = free/nr + (free%nr > 0 ? 1 : 0);

                    if (nc > c)
                    {
                        nc = Math.Min(c, side);
                        nr = free/nc + (free%nc > 0 ? 1 : 0);
                    }

                    if (nr > r) Debugger.Break(); // wtf?!

                    var nm = m - (r*c - nr*nc);

                    output.WriteLine("Case #{0}:", tc);
                    if (r == 1 || c == 1 || (nr > 1 && nc > 1 && nm == 0) || (nr > 2 && nc > 2 && nr + nc - 5 >= nm) || free == 1)
                    {
                        var row = new StringBuilder(r*c);

                        for (int i = 0; i < r; ++i)
                        {
                            int dots = 0;
                            if (i < nr) dots += nc;
                            if (i == nr - 2 && nc > 2 && dots - nm < 2)
                            {
                                dots--; // add extra mine
                                nm--; // .. less to put on last mine
                            }
                            if (i == nr - 1) dots -= nm;

                            row.Append(unknown.Substring(0, dots));
                            row.Append(bombs.Substring(0, c - dots));
                            row.AppendLine();
                        }

                        row[0] = 'c';

                        output.Write(row.ToString());
                    }
                    else output.WriteLine("Impossible");
                }
            }
        }
    }
}