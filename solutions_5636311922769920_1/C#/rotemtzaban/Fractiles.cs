using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2106
{
    class Fractiles
    {
        
        private const string NO_ANSWER = "IMPOSSIBLE";
        public static void SolveAll()
        {
            using (TextReader reader = File.OpenText("input.txt"))
            {
                using (TextWriter writer = File.CreateText("output.txt"))
                {
                    int T = int.Parse(reader.ReadLine());
                    for (int i = 0; i < T; i++)
                    {
                        string[] inputs = reader.ReadLine().Split(' ');
                        int length = int.Parse(inputs[0]);
                        int complexity = int.Parse(inputs[1]);
                        int students = int.Parse(inputs[2]);
                        ulong[] solution = SolveForStudentsNotEqualLength(length, complexity, students);
                        writer.Write(string.Format("case #{0}:", i + 1));
                        if (solution != null)
                        {

                            for (int j = 0; j < solution.Length; j++)
                            {
                                writer.Write(string.Format(" {0}", solution[j]));
                            }
                            writer.WriteLine();
                        }
                        else
                        {
                            writer.WriteLine(" " + NO_ANSWER);
                        }
                    }
                }
            }
        }

        private static ulong[] SolveForStudentsNotEqualLength(int length, int complexity, int students)
        {
            int size = length / complexity;
            if(length % complexity != 0)
            {
                size += 1;
            }
            if(size > students)
            {
                return null;
            }
            ulong[] solutions = new ulong[size];
            int i = 1, loc = 0;
            while(i <= length)
            {
                ulong sum = 1;
                for(int j = complexity - 1;j >= 0 && i<=length ;j--)
                {
                    sum += power((ulong)length, j) * (ulong)(i - 1);
                    i++;
                }
                solutions[loc] = sum;
                loc += 1;
            }
            return solutions;
        }

        private static ulong[] SolveForStudentsEqualLength(int length, int complexity)
        {
            ulong[] solution = new ulong[length];
            ulong blockSize = power((ulong)length, complexity - 1);
            for (int i = 0; i < length; i++)
            {
                solution[i] = blockSize * (ulong)i + 1;
            }
            return solution;
        }

        private static ulong power(ulong x, int y)
        {
            if (y == 0)
                return 1;
            ulong halfPow = power(x, y / 2);
            if (y % 2 == 0)
            {
                return halfPow * halfPow;
            }
            return (halfPow * halfPow) * x;
        }
    }
}
