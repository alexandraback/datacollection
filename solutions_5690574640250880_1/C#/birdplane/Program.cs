using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// Program written by Teun van Gils
// All rights reserved (c) 2014
namespace _C__Minesweeper_Master
{
    class Program
    {
        static void Main(string[] args)
        {
            // Fix globalization
            System.Threading.Thread.CurrentThread.CurrentCulture = System.Globalization.CultureInfo.CreateSpecificCulture("en-US");
            // Number of games
            int T = Int32.Parse(Console.ReadLine());
            // Set up output file
            TextWriter writer = new StreamWriter("out.txt", false);
            for (int t = 1; t <= T; t++)
            {
                // Output case number
                writer.WriteLine("Case #" + t + ": ");
                // Read the data
                String[] line = Console.ReadLine().Split(' ');
                int R = Int32.Parse(line[0]);
                int C = Int32.Parse(line[1]);
                int M = Int32.Parse(line[2]);
                // Set variables
                MinesweeperBoard board = new MinesweeperBoard(R, C);
                // Calculate and output the result
                MinesweeperBoard result;
                if ((C == 2 || R == 2) && M % 2 == 1)
                    result = null;
                else if (M == R * C - 1)
                    result = board;
                else
                    result = removeMines(board.ClearSpace(0, 0), M);

                if (result == null)
                    writer.WriteLine("Impossible");
                else
                    writer.WriteLine(result);
            }
            // EOF
            writer.Close();
        }

        // Recursive function for emptying the board
        static MinesweeperBoard removeMines(MinesweeperBoard board, int M)
        {
            if (board.Mines == M)
                return board;
            
            if (board.Mines < M)
                return null;

            foreach (Tuple<int, int> border in board.Borders)
            {
                MinesweeperBoard newBoard = removeMines(board.ClearSpace(border.Item1, border.Item2), M);
                if (newBoard != null)
                    return newBoard;
            }

            return null;
        }
    }

    class MinesweeperBoard
    {
        public int Mines { get; private set; }
        public IEnumerable<Tuple<int, int>> Borders
        {
            get
            {
                return borders;
            }
        }

        private int R, C;
        private char[,] map;
        private HashSet<Tuple<int, int>> borders;

        public char this[int r, int c]
        {
            get { return map[r, c]; }
            set { map[r, c] = value; }
        }

        public MinesweeperBoard(int R, int C)
        {
            this.Mines = R * C;
            this.borders = new HashSet<Tuple<int, int>>();
            this.R = R;
            this.C = C;
            map = new char[R, C];
            SetEach((_, __) => '*');
        }

        public MinesweeperBoard(MinesweeperBoard board)
        {
            this.Mines = board.Mines;
            this.borders = new HashSet<Tuple<int, int>>(board.borders);
            this.R = board.R;
            this.C = board.C;
            map = new char[R, C];
            SetEach((r, c) => board[r,c]);
        }

        public override string ToString()
        {
            TextWriter writer = new StringWriter();
            for (int r = 0; r < R; r++)
            {
                for (int c = 0; c < C; c++)
                {
                    writer.Write(r == 0 && c == 0 ? 'c' : this[r, c]);
                }
                if (r < R - 1)
                    writer.WriteLine();
            }
            return writer.ToString();
        }

        public void ForEach(Action<int, int> lambda)
        {
            for (int r = 0; r < R; r++)
                for (int c = 0; c < C; c++)
                    lambda(r, c);
        }

        public void SetEach(Func<int, int, char> lambda)
        {
            ForEach((r, c) => { map[r, c] = lambda(r, c); });
        }
        
        public void ForEachNeighbour(int r, int c, Action<int, int> lambda)
        {
            for (int dr = -1; dr <= 1; dr++)
                for (int dc = -1; dc <= 1; dc++)
                    if (r + dr >= 0 && r + dr < R && c + dc >= 0 && c + dc < C)
                        lambda(r + dr, c + dc);
        }

        public void SetEachNeighbour(int r, int c, Func<int, int, char> lambda)
        {
            ForEachNeighbour(r, c, (nr, nc) => { map[nr, nc] = lambda(nr, nc); });
        }

        public bool ForAnyNeighbour(int r, int c, Func<int, int, bool> lambda)
        {
            for (int dr = -1; dr <= 1; dr++)
                for (int dc = -1; dc <= 1; dc++)
                    if (r + dr >= 0 && r + dr < R && c + dc >= 0 && c + dc < C)
                        if (lambda(r + dr, c + dc))
                            return true;
            return false;
        }

        public MinesweeperBoard ClearSpace(int r, int c)
        {
             MinesweeperBoard board = new MinesweeperBoard(this);
             board.ForEachNeighbour(r, c, (nr, nc) => {
                 if (board.map[nr, nc] == '*')
                 {
                     board.Mines--;
                     board.map[nr, nc] = '.';
                     board.borders.Add(new Tuple<int, int>(nr, nc));
                 }
             });
             board.borders.RemoveWhere(t => !board.ForAnyNeighbour(t.Item1, t.Item2, (nr, nc) => board[nr,nc] == '*'));
             return board;
        }
    }
}
