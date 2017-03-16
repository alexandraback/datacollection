using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

namespace _2012R1_B
{
    class Program
    {
        static void Main(string[] args)
        {
            var inputFileName = "B.in";

            if (args.Count() > 0)
                inputFileName = args[0];

            var sb = new StringBuilder();
            var input = new List<string>();

            using (var stream = new FileStream(inputFileName, FileMode.Open))
            {
                using (var reader = new StreamReader(stream))
                {
                    string line;
                    while ((line = reader.ReadLine()) != null)
                    {
                        input.Add(line);
                    }
                }
            }

            var caseCount = Convert.ToInt32(input[0]);
            var sw = new Stopwatch();
            sw.Start();

            var lineCnt = 1;
            for (int i = 0; i < caseCount; i++)
            {
                var towerCnt = Convert.ToInt32(input[lineCnt]);
                var towers = new List<Tower>();

                for (int j = 0; j < towerCnt; j++)
                {
                    var req = input[lineCnt + j + 1].Split(' ');

                    towers.Add(new Tower
                                   {
                                       RequredL = Convert.ToInt32(req[0]),
                                       RequredH = Convert.ToInt32(req[1]),
                                       Stars = 2,
                                   });
                }

                lineCnt += towerCnt + 1;

                towers = towers.OrderBy(v => v.RequredH).ToList();

                var stars = 0;
                var iters = 0;

                var unable = false;

                while (towers.Any() && !unable)
                {
                    while (true)
                    {
                        var canComplete = towers.Where(v => v.RequredH <= stars).ToList();

                        if (!canComplete.Any())
                            break;

                        towers = towers.Except(canComplete).ToList();

                        iters += canComplete.Count;
                        stars += canComplete.Sum(v => v.Stars);
                    }

                    if (!towers.Any())
                        break;
                    {
                        var canComplete = towers.Where(v => v.Stars > 1 && v.RequredL <= stars).OrderByDescending(v => v.RequredH).FirstOrDefault();

                        if (canComplete == null)
                        {
                            unable = true;
                            break;
                        }

                        --canComplete.Stars;

                        ++iters;
                        ++stars;
                    }
                }

                if (unable)
                    sb.AppendFormat("Case #{0}: {1}", i + 1, "Too Bad");
                else
                    sb.AppendFormat("Case #{0}: {1}", i + 1, iters);

                sb.AppendLine();
                Console.WriteLine("Case #{0}: time spent {1:0.00}, total predicted {2:0.0}",
                    i + 1, sw.Elapsed.TotalSeconds, sw.Elapsed.TotalSeconds / (i + 1) * caseCount);
            }

            using (var stream = new FileStream(inputFileName + ".out", FileMode.Create))
            {
                using (var writer = new StreamWriter(stream))
                {
                    writer.Write(sb.ToString());
                }
            }

            Console.WriteLine("press a key to exit");
            Console.ReadKey();

            
        }

        private class Tower
        {
            public int Stars { get; set; }
            public int RequredL { get; set; }
            public int RequredH { get; set; }
        }
    }
}
