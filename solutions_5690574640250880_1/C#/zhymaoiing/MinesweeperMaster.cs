namespace ZTGCJ2014.Qualification_Round
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using ZTCommon;
    using ZTCommon.ContestCommon;

    internal class MinesweeperMaster : SolverBase
    {
        public MinesweeperMaster()
            : base(@"Qualification Round\C-large")
        {
        }

        public override void Solve(InputHelper input)
        {
            var R = input.ReadInt();
            var C = input.ReadInt();
            var M = input.ReadInt();
            var array = new char[R, C];

            array.Fill('.');
            PutMines(R, C, M, array);

            array[0, 0] = 'c';
            this.SetResult(string.Concat("\n", Verify(R, C, array) ? ToMap(array) : "Impossible"));
        }

        private const char MineChar = '*';

        private static void PutMines(int r, int c, int m, char[,] array)
        {
            if (m == 0) return;

            bool trans = r < c;
            int line = Math.Min(r, c);

            if (m > 1 && m + 1 == line)
            {
                for (int i = line - 1; i >= 0 && m > 1; --i, --m)
                    array[trans ? i : r - 1, trans ? c - 1 : i] = MineChar;
                array[trans ? line - 1 : r - 2, trans ? c - 2 : line - 1] = MineChar;
            }
            else
            {
                for (int i = line - 1; i >= 0 && m > 0; --i, --m)
                    array[trans ? i : r - 1, trans ? c - 1 : i] = MineChar;
                PutMines(trans ? r : r - 1, trans ? c - 1 : c, m, array);
            }
        }

        private static bool Verify(int r, int c, char[,] array)
        {
            var f = new int[r, c];
            GetArray(r, c).ForEach(s => f[s.Item1, s.Item2] = array[s.Item1, s.Item2] == MineChar ? int.MaxValue : GetAround(s, r, c).Where(d => array[d.Item1, d.Item2] == MineChar).Count());
            var noMine = GetArray(r, c).Where(s => array[s.Item1, s.Item2] != MineChar).ToArray();
            var except = noMine.Where(s => !GetAround(s, r, c).Any(d => f[d.Item1, d.Item2] == 0)).ToArray();
            return noMine.Count() == 1 || (except.Count() <= 1 && except.All(s => f[s.Item1, s.Item2] == 0));
        }

        private static string ToMap<T>(T[,] array)
        {
            var res = new StringBuilder();
            for (int i = 0; i < array.GetLength(0); ++i)
            {
                for (int j = 0; j < array.GetLength(1); ++j)
                    res.Append(array[i, j]);
                if (i + 1 < array.GetLength(0)) res.Append('\n');
            }
            return res.ToString();
        }

        private static IEnumerable<Tuple<int, int>> GetAround(Tuple<int, int> center, int r, int c)
        {
            return GetArray(3, 3).Where(d => 1 != d.Item1 || 1 != d.Item2).
                Select(d => Tuple.Create(center.Item1 + d.Item1 - 1, center.Item2 + d.Item2 - 1)).
                Where(d => 0 <= d.Item1 && d.Item1 < r && 0 <= d.Item2 && d.Item2 < c);
        }

        private static IEnumerable<Tuple<int, int>> GetArray(int r, int c)
        {
            for (int i = 0; i < r; ++i)
                for (int j = 0; j < c; ++j)
                    yield return Tuple.Create(i, j);
        }
    }
}
