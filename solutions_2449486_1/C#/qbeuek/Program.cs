using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace b_Lawmower
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var inputStream = new StreamReader("..\\..\\input.txt"))
            using (var outputStream = new StreamWriter("..\\..\\output.txt.", false))
            {
                var totalCases = int.Parse(inputStream.ReadLine());

                for (var currentCase = 1; currentCase <= totalCases; currentCase++)
                {
                    var boardSizes = inputStream.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
                    var rows = boardSizes[0];
                    var columns = boardSizes[1];

                    var board = new List<int[]>();
                    for (var i = 0; i < rows; i++)
                        board.Add(inputStream.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray());

                    var rowMaximums = Enumerable.Range(0, rows).Select(row => Enumerable.Range(0, columns).Max(column => board[row][column])).ToArray();
                    var columnMaximums = Enumerable.Range(0, columns).Select(column => Enumerable.Range(0, rows).Max(row => board[row][column])).ToArray();

                    var validBoard = true;
                    for (var row = 0; row < rows; row++)
                    {
                        for (var column = 0; column < columns; column++)
                        {
                            var currentField = board[row][column];
                            if (rowMaximums[row] > currentField && columnMaximums[column] > currentField)
                                validBoard = false;

                            if (!validBoard)
                                break;
                        }
                        if (!validBoard)
                            break;
                    }

                    outputStream.WriteLine("Case #{0}: {1}", currentCase, validBoard ? "YES" : "NO");
                }
            }
        }
    }
}
