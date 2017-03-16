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
            string[] nums = pattern[0].Split(new char[] { ' ' });
            columns = new int[nums.Length];

            this.pattern = new int[pattern.Length, pattern[0].Length];

            for (int r = 0; r < rows.Length; r++)
            {
                nums = pattern[r].Split(new char[] { ' ' });
                for (int c = 0; c < columns.Length; c++)
                {
                    this.pattern[r, c] = int.Parse(nums[c]);
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
