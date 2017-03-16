using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam2012
{
    class Program
    {
        static void Main(string[] args)
        {
            string fileName = "input.in";
            using (var reader = new StreamReader(fileName))
            {
                int cases = int.Parse(reader.ReadLine().Trim());
                using (var writer = new StreamWriter("output.out"))
                {
                    for (int i = 0; i < cases; i++)
                    {
                        var line = reader.ReadLine();
                        var lineValues = line.Split(' ');

                        int height = int.Parse(lineValues[0]);
                        int width = int.Parse(lineValues[1]);

                        var lawn = new KurkaRurka(width, height);

                        for (int y = 0; y < height; y++)
                        {
                            line = reader.ReadLine();
                            lineValues = line.Split(' ');
                            lawn.AddRow(lineValues.Select(lv => int.Parse(lv)).ToArray());
                        }

                        writer.WriteLine(string.Format("Case #{0}: {1}", i + 1, lawn.IsValid() ? "YES" : "NO"));
                    }
                }
            }
        }


        class KurkaRurka
        {
            List<int[]> lawn = new List<int[]>();
            int w;
            int h;
            List<int> maxes = new List<int>();

            public KurkaRurka(int width, int height)
            {
                w = width;
                h = height;
            }

            public void AddRow(int[] row)
            {
                lawn.Add(row);
            }

            public bool IsValid()
            {
                foreach (var l in lawn)
                    maxes.Add(l.Max());
                for (int c = 0; c < w; c++)
                {
                    maxes.Add(lawn.Select(l => l[c]).Max());
                }
                //przejechać całość: dla każdej wartości sprawdzić czy jest równa przynajmniej jednemu lokalnemu maximum
                for (int x = 0; x < w; x++)
                {
                    for (int y = 0; y < h; y++)
                    {
                        if ((lawn[y][x] != maxes[y]) && (lawn[y][x] != maxes[h + x]))
                            return false;
                    }
                }

                return true;
            }
        }

    }
}
