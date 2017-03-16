using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ.RN
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var sr = new StreamReader(new FileStream("file.in", FileMode.Open)))
            {
                var testCases = Convert.ToInt32(sr.ReadLine());

                var output = new List<string>();

                var powLookup = new Dictionary<int, int>();
                powLookup.Add(1, 10);
                powLookup.Add(2, 100);
                powLookup.Add(3, 1000);
                powLookup.Add(4, 10000);
                powLookup.Add(5, 100000);
                powLookup.Add(6, 1000000);
                powLookup.Add(7, 10000000);
                powLookup.Add(8, 100000000);

                var i = 0;
                while (!sr.EndOfStream)
                {
                    var line = sr.ReadLine().Split(' ');
                    var min = Convert.ToInt32(line[0]);
                    var max = Convert.ToInt32(line[1]);

                    var count = 0;

                    if (max >= 10)
                    {
                        for (int n = min; n < max; ++n)
                        {
                            var numbers = -1;
                            if (n >= 10 && n < 100)
                                numbers = 2;
                            else if (n >= 100 && n < 1000)
                                numbers = 3;
                            else if (n >= 1000 && n < 10000)
                                numbers = 4;
                            else if (n >= 10000 && n < 100000)
                                numbers = 5;
                            else if (n >= 100000 && n < 1000000)
                                numbers = 6;
                            else if (n >= 1000000 && n < 10000000)
                                numbers = 7;
                            else
                                numbers = 1;

                            var seen = new List<int>();

                            for (int s = 1; s < numbers; ++s)
                            {
                                int t = powLookup[s];
                                int t2 = powLookup[numbers - s];
                                int t3 = powLookup[numbers - 1];
                                int m = n / t + (n % t) * t2;

                                if (m > n && m <= max && m >= t3 && !seen.Any(x => x == m))
                                {
                                    seen.Add(m);
                                    ++count;
                                }
                            }
                        }
                    }

                    Console.WriteLine(i);
                    output.Add("Case #" + ++i + ": " + count);
                }

                File.WriteAllLines("file.out", output);
            }
        }
    }
}
