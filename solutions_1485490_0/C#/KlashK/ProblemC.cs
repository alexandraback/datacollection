using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class ProblemC
    {
        static void Main(string[] args)
        {
            var stream = new FileStream(args[0], FileMode.Open, FileAccess.Read);
            var reader = new StreamReader(stream);

            var writeStream = new FileStream(args[1], FileMode.Create, FileAccess.Write);
            var writer = new StreamWriter(writeStream);

            var cases = Convert.ToInt32(reader.ReadLine());

            for (var i = 0; i < cases; i++)
            {
                var line = reader.ReadLine().Split(' ');
                var n = Convert.ToInt32(line[0]);
                var m = Convert.ToInt32(line[1]);

                var boxes = new List<Batch>();

                line = reader.ReadLine().Split(' ');
                for (var j = 0; j < 2 * n; j += 2)
                {
                    boxes.Add(new Batch()
                    {
                        Amount = Convert.ToInt64(line[j]),
                        TypeId = Convert.ToInt32(line[j + 1])
                    });
                }

                var toys = new List<Batch>();

                line = reader.ReadLine().Split(' ');
                for (var j = 0; j < 2 * m; j += 2)
                {
                    toys.Add(new Batch()
                    {
                        Amount = Convert.ToInt64(line[j]),
                        TypeId = Convert.ToInt32(line[j + 1])
                    });
                }

                var sequences = new long[boxes.Count, toys.Count];
                for (var j = 0; j < boxes.Count; j++)
                {
                    for (var k = 0; k < toys.Count; k++)
                    {
                        if(boxes[j].TypeId == toys[k].TypeId)
                            sequences[j,k] = Math.Min(boxes[j].Amount, toys[k].Amount);
                    }
                }

                var best = GetBest(sequences, 0, 0, 0);

                writer.WriteLine(string.Format("Case #{0}: {1}", i + 1, best));

            }

            writer.Flush();
            writer.Close();
        }

        private static long GetBest(long[,] sequences, int startBox, int startToy, long val)
        { 
            var maxBox = sequences.GetLength(0);
            var maxToy = sequences.GetLength(1);

            long best = 0;

            for (var i = startBox; i < maxBox; i++)
            {
                for (var j = startToy; j < maxToy; j++)
                {
                    var curr = sequences[i,j];
                    if (curr > 0)
                    {
                        var newBest = GetBest(sequences, i + 1, j + 1, curr);
                        if (newBest > best)
                            best = newBest;

                        //maxBox = i + 1;
                    }
                }

            }

            return val + best;
        }

    }

    public class Batch
    {
        public long Amount;
        public int TypeId;
    }
}
