using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using Mono.Math;
using System.Linq;

namespace Round1BProblemA
{
    class MainClass
    {
        public static void Solve(StringBuilder sb, string[] lines, ref int index) {

            var S = lines[index].ToList();
            index++;


            int[] counts = new int[10];

            while(S.Count > 0) {

                if (S.Contains('Z'))
                {
                    counts[0]++;
                    S.Remove('Z');
                    S.Remove('E');
                    S.Remove('R');
                    S.Remove('O');
                }
                else if (S.Contains('X'))
                {
                    counts[6]++;
                    S.Remove('S');
                    S.Remove('I');
                    S.Remove('X');
                }
                else if (S.Contains('W'))
                {
                    counts[2]++;
                    S.Remove('T');
                    S.Remove('W');
                    S.Remove('O');
                }
                else if (S.Contains('G'))
                {
                    counts[8]++;
                    S.Remove('E');
                    S.Remove('I');
                    S.Remove('G');
                    S.Remove('H');
                    S.Remove('T');
                }
                else if (S.Contains('U'))
                {
                    counts[4]++;
                    S.Remove('F');
                    S.Remove('O');
                    S.Remove('U');
                    S.Remove('R');
                }
                else if (S.Contains('R'))
                {
                    counts[3]++;
                    S.Remove('T');
                    S.Remove('H');
                    S.Remove('R');
                    S.Remove('E');
                    S.Remove('E');
                }
                else if (S.Contains('S'))
                {
                    counts[7]++;
                    S.Remove('S');
                    S.Remove('E');
                    S.Remove('V');
                    S.Remove('E');
                    S.Remove('N');
                }
                else if (S.Contains('O'))
                {
                    counts[1]++;
                    S.Remove('O');
                    S.Remove('N');
                    S.Remove('E');
                }
                else if (S.Contains('F'))
                {
                    counts[5]++;
                    S.Remove('F');
                    S.Remove('I');
                    S.Remove('V');
                    S.Remove('E');
                }
                else
                {
                    counts[9]++;
                    S.Remove('N');
                    S.Remove('I');
                    S.Remove('N');
                    S.Remove('E');
                }
            }

            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < counts[i]; j++)
                {
                    sb.Append(i.ToString());
                }
            }

            sb.AppendLine();
        }

        public static void Main(string[] args)
        {
            var ifname = args[0];
            var ofname = args[1];

            var lines = File.ReadAllLines(ifname);

            var lineCount = long.Parse(lines[0]);

            var sb = new StringBuilder();
            int index = 1;
            for (long i = 1; i <= lineCount; i++)
            {
                sb.Append("Case #" + i + ": ");



                Solve(sb, lines, ref index);
            }

            File.WriteAllText(ofname, sb.ToString());
        }
    }
}
