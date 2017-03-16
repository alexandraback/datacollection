using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJamQualifications
{
    class Pattern
    {
        int[,] pattern;
        int[] rows;
        int[] columns;

        public Pattern(string[] pattern)
        {
            rows = new int[pattern.Length];
            columns = new int[pattern[0].Length / 2 + 1];

            this.pattern = new int[pattern.Length, pattern[0].Length];

            for (int r = 0; r < rows.Length; r++)
            {
                for (int c = 0; c < columns.Length; c++)
                {
                    Console.WriteLine(pattern[r].Substring(c, 1));
                    this.pattern[r, c] = int.Parse(pattern[r].Substring(c * 2, 1));
                }
            }
        }

        public void ComputeCuts()
        {
            for (int r = 0; r < rows.Length; r++)
            {
                int max = 0;
                for (int c = 0; c < columns.Length; c++)
                {
                    if (pattern[r, c] > max)
                        max = pattern[r, c];
                }
                rows[r] = max;
            }

            for (int r = 0; r < columns.Length; r++)
            {
                int max = 0;
                for (int c = 0; c < rows.Length; c++)
                {
                    if (pattern[c, r] > max)
                        max = pattern[c, r];
                }
                columns[r] = max;
            }
        }

        public bool IsPossible()
        {
            for (int r = 0; r < rows.Length; r++)
            {
                for (int c = 0; c < columns.Length; c++)
                {
                    if (pattern[r, c] != rows[r] && pattern[r, c] != columns[c])
                        return false;
                }
            }
            return true;
        }
    }
}
