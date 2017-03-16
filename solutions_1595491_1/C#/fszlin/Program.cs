using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication6
{
    class Program
    {
        static Dictionary<char, char> mapping = new Dictionary<char, char>();

        static void Main(string[] args)
        {
            var inputs = File.ReadAllLines("../../in.txt");
            var buffer = new StringBuilder();
            var T = Int32.Parse(inputs[0]);
            for (int i = 1; i < inputs.Length; ++i)
            {
                if (!String.IsNullOrEmpty(inputs[i]))
                {
                    buffer.AppendFormat("Case #{0}: ", i);
                    new Program().Process(inputs[i], buffer);
                }
            }

            Console.Write(buffer);
            File.WriteAllText("../../out.txt", buffer.ToString());
        }

        private void Process(string text, StringBuilder output)
        {
            var nums = text.Split(' ').Select(str => Int32.Parse(str)).ToList();
            var n = nums[0];
            var s = nums[1];
            var p = nums[2];

            var scores = nums.Skip(3).ToList();
            var sup = Math.Max(p - 2, 0) + Math.Max(p - 2, 0) + p;
            var nor = Math.Max(p - 1, 0) * 2 + p;

            var total = 0;
            var possible = 0;
            foreach (var score in scores)
            {
                if (score >= nor)
                {
                    ++total;
                }
                else if (score >= sup)
                {
                    ++possible;
                }
            }

            total += Math.Min(possible, s);

            output.Append(total).AppendLine();
        }
    }
}
