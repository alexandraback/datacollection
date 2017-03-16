using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    public class Round1CProblemA : Problem
    {
        protected override string SolveCase()
        {
            int[] parameters = ReadNextLineAsInt32Array();
            int rows = parameters[0];
            int columns = parameters[1];
            int width = parameters[2];

            int guesses = Math.Max((columns - (width + 1)) / width, 0) + width + (columns > width ? 1 : 0);
            if (rows > 1)
            {
                guesses += (columns / width) * (rows - 1);
            }
            return guesses.ToString();
        }
    }
}
