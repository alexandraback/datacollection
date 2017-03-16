#region using directives

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

#endregion

namespace ProblemC
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

                int result = 0;

                string[] parts = input[i].Split(new[] {' '});
                int a = Int32.Parse(parts[0]);
                int b = Int32.Parse(parts[1]);

                for (int n = a; n < b; n++)
                {
                    result += GetMCount(a, n, b);
                }

                sb.Append(result);

                sb.AppendLine();
            }

            Console.Write(sb.ToString());
            File.WriteAllText("ouput.txt", sb.ToString().Trim());
        }
        
        private static int GetMCount(int a, int n, int b)
        {
            var mResult = new List<int>();
            string nStr = n.ToString();

            for (int pos = nStr.Length - 1; pos > 0; pos--)
            {
                mResult.Add(Int32.Parse(nStr.Substring(pos, nStr.Length - pos) + nStr.Substring(0, pos)));
            }

            return mResult.Distinct().Count(m => a <= m && n < m && m <= b);
        }
    }
}