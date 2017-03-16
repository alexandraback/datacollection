#region using directives

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

#endregion

namespace ProblemB
{
    internal class Program
    {
        private static void Main()
        {
            string[] input = File.ReadAllLines("input.txt");
            int count = Int32.Parse(input[0]);

            var sb = new StringBuilder();

            for (int i = 1; i <= count; i++)
            {
                sb.Append("Case #" + i + ": ");

                string[] parts = input[i].Split(new[] {' '});

                int googlers = Int32.Parse(parts[0]);
                int suprisingResults = Int32.Parse(parts[1]);
                int bestResultAtLeast = Int32.Parse(parts[2]);
                List<int> scores = parts.Skip(3).Select(Int32.Parse).ToList();

                int result = 0;

                foreach (var score in scores)
                {
                    if (score >= bestResultAtLeast*3)
                    {
                        result++;
                        continue;
                    }

                    if (score >= Math.Max(bestResultAtLeast, bestResultAtLeast*3 - 2))
                    {
                        result++;
                        continue;
                    }

                    if (suprisingResults == 0) continue;

                    if (score >= Math.Max(bestResultAtLeast, bestResultAtLeast*3 - 4))
                    {
                        result++;
                        suprisingResults--;
                    }
                }

                sb.Append(result);
                sb.AppendLine();
            }

            Console.Write(sb.ToString());
            File.WriteAllText("ouput.txt", sb.ToString().Trim());
        }
    }
}