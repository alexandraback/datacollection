using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;

namespace C
{
    class SolverC
    {
        private int _rows;
        private int _cols;
        private int _mines;
        private int _minesLeft;

        public string SolveOne(TextReader input)
        {
            string line = input.ReadLine();
            var args = line.Split(' ').Select(int.Parse).ToArray();
            _rows = args[0];
            _cols = args[1];
            _mines = _minesLeft = args[2];

            string res = GetSolution();
            //VerifySolution(res);
            return res;
        }

        private string GetSolution()
        {
            if (_rows*_cols == _minesLeft + 1)
            {
                return GetFullTable();
            }

            if (_rows == 1)
            {
                return "\n" + GetOneRowSolution(_cols);
            }

            if (_cols == 1)
            {
                return GetOneRowSolution(_rows).Aggregate(string.Empty, (s, c) => s + "\n" + c);
            }

            try
            {
                return GetTopLines() + GetBottom2Lines();
            }
            catch (InvalidDataException)
            {
                return "\nImpossible";
            }
        }

        private string GetOneRowSolution(int num)
        {
            return new string('*', _minesLeft) + new string('.', num - _minesLeft - 1) + "c";
        }

        private string GetTopLines()
        {
            string res = string.Empty;
            for (int i = 1; i <= _rows - 2; ++i)
            {
                int minesHere = Math.Min(_minesLeft, (i < _rows - 1) ? _cols : (_cols - 2));
                if (minesHere == _cols - 1)
                {
                    -- minesHere;
                }
                if (i == _rows - 2)
                {
                    if ((_minesLeft - minesHere) % 2 == 1)
                    {
                        if (--minesHere == _cols - 1)
                        {
                            minesHere -= 2;
                        }
                    }
                    if (minesHere < 0 || (_minesLeft > 0 && minesHere < (_minesLeft - minesHere) / 2))
                    {
                        throw new InvalidDataException();
                    }
                }
                string outLine = "\n" + new string('*', minesHere) + new string('.', _cols - minesHere);
                _minesLeft -= minesHere;
                res += outLine;
            }
            return res;
        }

        private string GetBottom2Lines()
        {
            if (_minesLeft % 2 == 1 || 2 * _cols - 4 < _minesLeft)
            {
                throw new InvalidDataException();
            }

            string line1 = "\n" + new string('*', _minesLeft/2) + new string('.', _cols - _minesLeft/2);
            string line2 = line1.Substring(0, _cols) + "c";
            return line1 + line2;
        }

        private string GetFullTable()
        {
            string res = string.Empty;
            for (int i = 1; i <= _rows; ++i)
            {
                string outLine = "\n" + new string('*', _cols);
                if (i == _rows)
                    outLine = outLine.Substring(0, _cols) + "c";
                res += outLine;
            }
            return res;
        }

        private void VerifySolution(string res)
        {
            if (res == "\nImpossible")
            {
                char[][] solution = CheckForSolution(new Stack<Coord>());
                if (solution != null)
                {
                    throw new InvalidOperationException();
                }
            }
            else
            {
                char[][] rows = res.Substring(1).Split('\n').Select(s => s.ToCharArray()).ToArray();
                if (!IsValidSolution(rows))
                {
                    throw new InvalidOperationException();
                }
            }
        }

        private bool IsValidSolution(char[][] rows)
        {
            int r, c;
            SetCellValue(rows, _rows - 1, _cols - 1);
            while (FindZeroCell(rows, out r, out c))
            {
                ExpandCell(rows, r, c);
            }
            bool valid = !rows.Any(row => row.Any(ch => ch == '.'));
            return valid;
        }

        private bool FindZeroCell(char[][] rows, out int r, out int c)
        {
            for (int i = 0; i < rows.Length; ++i)
            {
                char[] row = rows[i];
                for (int j = 0; j < row.Length; ++j)
                {
                    if (row[j] == '0')
                    {
                        r = i;
                        c = j;
                        return true;
                    }
                }
            }
            r = c = 0;
            return false;
        }

        private void ExpandCell(char[][] rows, int r, int c)
        {
            rows[r][c] = ' ';
            for (int i = Math.Max(0, r - 1); i <= Math.Min(_rows - 1, r + 1); ++i)
            {
                for (int j = Math.Max(0, c - 1); j <= Math.Min(_cols - 1, c + 1); ++j)
                {
                    if (i == r && j == c)
                        continue;
                    SetCellValue(rows, i, j);
                }
            }
        }

        private void SetCellValue(char[][] rows, int r, int c)
        {
            if (rows[r][c] != '.' && rows[r][c] != 'c')
                return;

            int cnt = 0;
            for (int i = Math.Max(0, r-1); i <= Math.Min(_rows-1, r+1); ++i)
            {
                for (int j= Math.Max(0, c - 1); j <= Math.Min(_cols - 1, c + 1); ++j)
                {
                    if (rows[i][j] == '*')
                        ++cnt;
                }
            }
            rows[r][c] = cnt.ToString(CultureInfo.InvariantCulture)[0];
        }

        class Coord
        {
            public int row;
            public int col;
            public Coord(int r, int c)
            {
                row = r;
                col = c;
            }
        }

        private char[][] CheckForSolution(Stack<Coord> mines)
        {
            if (mines.Count == _mines)
            {
                char[][] rows = new char[_rows][];
                for (int i = 0; i < _rows; ++i)
                {
                    rows[i] = new string('.', _cols).ToCharArray();
                }
                foreach (var mine in mines)
                {
                    rows[mine.row][mine.col] = '*';
                }
                rows[_rows - 1][_cols - 1] = 'c';

                bool valid = IsValidSolution(rows);
                return valid ? rows : null;
            }

            int lastRow = mines.Any() ? mines.Peek().row : 0;
            int lastCol = mines.Any() ? mines.Peek().col : -1;
            var mineCoord = new Coord(lastRow, lastCol);
            mines.Push(mineCoord);
            while (ForwardCoord(mineCoord))
            {
                char[][] solution = CheckForSolution(mines);
                if (solution != null)
                    return solution;
            }
            mines.Pop();
            return null;
        }

        private bool ForwardCoord(Coord coord)
        {
            if (++coord.col < _cols)
            {
                bool isLast = coord.row == _rows - 1 && coord.col == _cols - 1;
                return !isLast;
            }
            if (++coord.row == _rows)
                return false;
            coord.col = 0;
            return true;
        }
    }
}