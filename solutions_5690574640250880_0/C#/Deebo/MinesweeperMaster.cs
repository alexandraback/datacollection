using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dfs.GoogleCodeJam.CodeJam2014.QualificationRound
{
    [ProblemInfo(ContestNames.CodeJam2014, RoundNames.QualificationRound, ProblemIdentifiers.C)]
    internal class MinesweeperMaster : ProblemBase
    {
        protected override ProblemCaseBase ParseCase(TextReader reader)
        {
            return new MinesweeperMasterCase(reader);
        }

        private class MinesweeperMasterCase : ProblemCaseBase
        {
            public MinesweeperMasterCase(TextReader reader)
            {
                int[] numbers = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();
                r = numbers[0];
                c = numbers[1];
                m = numbers[2];
            }

            public override string Solve()
            {
                Square[,] board = SolveForBoard();
                if (board == null) return "\nImpossible";

                StringBuilder sb = new StringBuilder();
                foreach (int i in Enumerable.Range(0, r))
                {
                    sb.Append('\n');
                    foreach (int j in Enumerable.Range(0, c))
                        sb.Append(SquareToChar(board[i, j]));
                }
                return sb.ToString();
            }

            private Square[,] SolveForBoard()
            {
                if (r == 1) return OneRow();
                if (c == 1) return OneColumn();
                if (m == r * c - 1) return AllButOne();
                if (m == r * c - 4) return AllButFour();
                if (m == r * c - 6) return AllButSix();
                if (m >= r * c - 7) return null;
                if (r == 2) return TwoRows();
                if (c == 2) return TwoColumns();
                if (m <= (r - 2) * (c - 2)) return GeneralCaseSparse();
                return GeneralCaseDense();
            }

            private Square[,] OneRow()
            {
                Square[,] result = AllButOne();
                foreach (int j in Enumerable.Range(1, c - m - 1))
                    result[0, j] = Square.Empty;
                return result;
            }

            private Square[,] OneColumn()
            {
                Square[,] result = AllButOne();
                foreach (int i in Enumerable.Range(1, r - m - 1))
                    result[i, 0] = Square.Empty;
                return result;
            }

            private Square[,] TwoRows()
            {
                if (m % 2 != 0) return null;
                Square[,] result = Fill(Square.Empty);
                result[0, 0] = Square.Click;
                foreach (int i in Enumerable.Range(0, 2))
                    foreach (int j in Enumerable.Range(c - m / 2, m / 2))
                        result[i, j] = Square.Mine;
                return result;
            }

            private Square[,] TwoColumns()
            {
                if (m % 2 != 0) return null;
                Square[,] result = Fill(Square.Empty);
                result[0, 0] = Square.Click;
                foreach (int i in Enumerable.Range(r - m / 2, m / 2))
                    foreach (int j in Enumerable.Range(0, 2))
                        result[i, j] = Square.Mine;
                return result;
            }

            private Square[,] AllButOne()
            {
                Square[,] result = Fill(Square.Mine);
                result[0, 0] = Square.Click;
                return result;
            }

            private Square[,] AllButFour()
            {
                Square[,] result = Fill(Square.Mine);
                foreach (int i in Enumerable.Range(0, 2))
                    foreach (int j in Enumerable.Range(0, 2))
                        result[i, j] = Square.Empty;
                result[0, 0] = Square.Click;
                return result;
            }

            private Square[,] AllButSix()
            {
                Square[,] result = Fill(Square.Mine);
                foreach (int i in Enumerable.Range(0, r == 2 ? 2 : 3))
                    foreach (int j in Enumerable.Range(0, r == 2 ? 3 : 2))
                        result[i, j] = Square.Empty;
                result[0, 0] = Square.Click;
                return result;
            }
            
            private Square[,] GeneralCaseSparse()
            {
                Square[,] result = Fill(Square.Empty);
                result[r - 1, c - 1] = Square.Click;
                int fullColumns = m / (r - 2);
                foreach (int i in Enumerable.Range(0, r - 2))
                    foreach (int j in Enumerable.Range(0, fullColumns))
                        result[i, j] = Square.Mine;
                int left = m - fullColumns * (r - 2);
                foreach (int i in Enumerable.Range(0, left))
                    result[i, fullColumns] = Square.Mine;
                return result;
            }

            private Square[,] GeneralCaseDense()
            {
                Square[,] result = Fill(Square.Empty);
                result[r - 1, c - 1] = Square.Click;
                foreach (int i in Enumerable.Range(0, r - 2))
                    foreach (int j in Enumerable.Range(0, c - 2))
                        result[i, j] = Square.Mine;
                int left = m - (r - 2) * (c - 2);
                if (left % 2 == 1)
                {
                    result[r - 3, c - 3] = Square.Empty;
                    left++;
                }
                foreach (int i in Enumerable.Range(0, Math.Min(left / 2, r - 3)))
                    foreach (int j in Enumerable.Range(c - 2, 2))
                        result[i, j] = Square.Mine;
                left -= 2 * Math.Min(left / 2, r - 3);
                foreach (int i in Enumerable.Range(r - 2, 2))
                    foreach (int j in Enumerable.Range(0, Math.Min(left / 2, c - 3)))
                        result[i, j] = Square.Mine;
                return result;
            }
                       
            private Square[,] Fill(Square square)
            {
                Square[,] result = new Square[r, c];
                foreach (int i in Enumerable.Range(0, r))
                    foreach (int j in Enumerable.Range(0, c))
                        result[i, j] = square;
                return result;
            }

            private static char SquareToChar(Square square)
            {
                switch (square)
                {
                    case Square.Click: return 'c';
                    case Square.Empty: return '.';
                    case Square.Mine: return '*';
                    default: throw new InvalidEnumArgumentException();
                }
            }

            private readonly int r;
            private readonly int c;
            private readonly int m;

            private enum Square { Empty, Click, Mine }
        }
    }
}
