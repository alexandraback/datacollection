using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2014_MagicTrick
{
    class Program
    {
        static TextReader input = Console.In;
        static TextWriter output = Console.Out;
        static void Main(string[] args)
        {
            if (args.Any())
            {
                var path = args[0];
                if (File.Exists(path))
                {
                    input = File.OpenText(path);
                }
                path = path.Remove(path.LastIndexOf('.'));
                path += ".out";
                output = File.CreateText(path);
            }

            int totalCases = int.Parse(input.ReadLine());
            for (int currentCase = 1; currentCase <= totalCases; currentCase++)
            {
                string caseOutput = HandleCase(input);
                output.WriteLine(string.Format("Case #{0}:", currentCase));
                output.WriteLine(caseOutput);
            }
            output.Flush();
        }

        private static string HandleCase(TextReader input)
        {
            string[] lineSplit = input.ReadLine().Split(' ');
            int rows = int.Parse(lineSplit[0]);
            int columns = int.Parse(lineSplit[1]);
            int mines = int.Parse(lineSplit[2]);

            return new Field(rows, columns, mines).Answer();
        }
    }

    public class Field
    {
        private bool[][] _field;

        public int Rows { get; private set; }
        public int Columns { get; private set; }
        private int _mines;

        private bool _isFillingRow;
        private bool _hasMadeSquare;

        private int _currentRowFilling;
        private int _currentColumnFilling;
        private int _currentMines;

        public Field(int rows, int columns, int mines)
        {
            Rows = rows;
            Columns = columns;
            _mines = mines;

            _field = new bool[rows][];
            for (int row = 0; row < rows; row++)
            {
                _field[row] = new bool[columns];
            }
        }

        public string Answer()
        {
            // if we make a square of free cells to the bottom right of the grid,
            // it's impossible to reveal all if there is
            // - 2 cells left: both are numbered cells, not revealing the other cell
            // - 3 cells left: all 3 are numbered cells, not revealing the other cells
            // - 5 cells left: one cell is _always_ only connected to numbered cells
            // - 7 cells left: one cell is _always_ only connected to numbered cells
            // AND columns and row != 1
            int totalCells = Rows * Columns;
            int freeCells = totalCells - _mines;
            if ((freeCells == 2 || freeCells == 3 || freeCells == 5 || freeCells == 7)
                && Columns != 1 && Rows != 1)
            {
                return "Impossible";
            }

            // otherwise we take the biggest square that doesn't leave only 1 remaining cell
            // 1 remaining gives us an impossible to place cell
            int squareSide = (int)Math.Sqrt(freeCells);
            if (freeCells - squareSide * squareSide == 1 && Rows != 1 && Columns != 1)
            {
                squareSide--;
            }

            // bound the square also by Min(Rows, Columns), so we don't go out of bounds
            squareSide = Math.Min(squareSide, Math.Min(Rows, Columns));

            // mark the squares as free cells
            for (int row = 0; row < squareSide; row++)
            {
                for (int column = 0; column < squareSide; column++)
                {
                    _field[row][column] = true;
                }
            }

            int remainingCells = freeCells - squareSide * squareSide;

            bool canPlaceRow = squareSide < Rows;
            int rowToPlace = squareSide;
            bool canPlaceColumn = squareSide < Columns;
            int columnToPlace = squareSide;

            // now keep placing the biggest Nx1 (or 1xN) rectangle that doesn't leave only 1 cell remaining
            int side = squareSide;
            while (remainingCells > 0)
            {
                // make sure we don't free too many cells
                while (remainingCells - side < 0)
                {
                    side--;
                }
                // make sure we don't leave only 1 cell remaining
                if (remainingCells - side == 1 && Rows != 1 && Columns != 1)
                {
                    side--;
                }
                if (canPlaceRow)
                {
                    for (int column = 0; column < side; column++)
                    {
                        _field[rowToPlace][column] = true;
                    }
                    rowToPlace++;
                    canPlaceRow = rowToPlace < Rows;
                }
                else if (canPlaceColumn)
                {
                    for (int row = 0; row < side; row++)
                    {
                        _field[row][columnToPlace] = true;
                    }
                    columnToPlace++;
                    canPlaceColumn = columnToPlace < Columns;
                }
                else
                {
                    // can't place enough free cells
                    return "Impossible";
                }

                remainingCells -= side;
            }

            // compute grid string, click is top left
            StringBuilder sb = new StringBuilder();
            for (int row = 0; row < Rows; row++)
            {
                for (int column = 0; column < Columns; column++)
                {
                    sb.Append(_field[row][column] ? "." : "*");
                }
                sb.AppendLine();
            }
            // place click top left
            sb[0] = 'c';

            return sb.ToString();
        }
    }
}
