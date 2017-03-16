using System.IO;
using System.Linq;

namespace TicTacToeTonk
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var reader = new StreamReader("in.txt"))
            using (var writer = new StreamWriter("out.txt"))
            {
                reader.ReadLine();

                int caseID = 1;
                while (!reader.EndOfStream)
                {
                    var lawn = ReadLawn(reader);
                    var result = CanMow(lawn);
                    writer.WriteLine("Case #{0}: {1}", caseID, result ? "YES" : "NO");
                    caseID++;
                }
            }
        }

        private static bool CanMow(int[,] lawn)
        {
            // each cell must be longer than the longest cell in its row or column

            var height = lawn.GetLength(0);
            var width = lawn.GetLength(1);

            var rowMax = Enumerable.Range(0, height).Select(y => Enumerable.Range(0, width).Max(x => lawn[y, x])).ToArray();
            var colMax = Enumerable.Range(0, width).Select(x => Enumerable.Range(0, height).Max(y => lawn[y, x])).ToArray();

            for (int y = 0; y < height; y++)
            {
                for (int x = 0; x < width; x++)
                {
                    if (lawn[y, x] < rowMax[y] && lawn[y, x] < colMax[x]) return false;
                }
            }

            return true;
        }

        private static int[,] ReadLawn(StreamReader reader)
        {
            var dimensions = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var height = dimensions[0];
            var width = dimensions[1];
            var grid = new int[height, width];
            for (var i = 0; i < height; i++)
            {
                var line = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();
                for (var j = 0; j < width; j++)
                {
                    grid[i, j] = line[j];
                }
            }
            return grid;
        }
    }
}
