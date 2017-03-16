using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    public class Question1 : Problem
    {
        protected override string SolveCase()
        {
            var input = this.ReadNextLineAsString().ToCharArray();

            int[] numberCounts = new int[10];

            numberCounts[8] = input.Count(c => c == 'G');
            numberCounts[0] = input.Count(c => c == 'Z');
            numberCounts[2] = input.Count(c => c == 'W');
            numberCounts[6] = input.Count(c => c == 'X');
            numberCounts[7] = input.Count(c => c == 'S') - numberCounts[6];
            numberCounts[5] = input.Count(c => c == 'V') - numberCounts[7];
            numberCounts[9] = input.Count(c => c == 'I') - numberCounts[5] - numberCounts[6] - numberCounts[8];
            numberCounts[4] = input.Count(c => c == 'F') - numberCounts[5];
            numberCounts[1] = input.Count(c => c == 'O') - numberCounts[0] - numberCounts[2] - numberCounts[4];
            numberCounts[3] = input.Count(c => c == 'T') - numberCounts[2] - numberCounts[8];

            var number = string.Empty;

            for (int i = 0; i <= 9; i++)
            {
                number += new string(i.ToString().ToCharArray().First(), numberCounts[i]);
            }

            return number;
        }
    }
}
