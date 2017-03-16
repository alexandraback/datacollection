using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using CodeJamTools;

namespace Round1ProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            new ProblemA().Run("in.txt");
        }
    }

    class ProblemA : CodeJamBase {
        protected override string RunTest(int index) {
            var p = Lines[index*2].Split(' ').Select(int.Parse).ToArray();
            var a = p[0];
            var b = p[1];

            var prob = Lines[index*2 + 1].Split(' ').Select(float.Parse).ToArray();

            var enter = b + 2;

            float[] possibilities = new float[a];
            float partial = 1;

            for (int i = 0; i < possibilities.Length; i++) {
                int pos = i + 1;

                partial *= prob[i];

                int backspace = (a - pos) * 2 + b - a + 1;
                float expected = partial * backspace + (1 - partial) * (backspace + b + 1);
                possibilities[i] = expected;
            }

            float min = possibilities.Min();

            if (min < enter) {
                return min.ToString();
            }
            return enter.ToString();
        }
    }
}
