using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication6
{
    class Program
    {
        static List<int> shifts;

        static void Main(string[] args)
        {
            shifts = new List<int>() { 0, 1 };
            for (int i = 2; i < 10; ++i)
            {
                shifts.Add(shifts[i - 1] * 10);
            }

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
            var a = nums[0];
            var b = nums[1];

            var total = 0;
            for (var i = a; i < b; ++i)
            {
                var check = new HashSet<int>();
                var len = i.ToString().Length;
                var cur = i;
                for (var j = 1; j < len; ++j)
                {
                    cur = cur / 10 + (cur % 10) * shifts[len];
                    if (cur > i && cur <= b)
                    {
                        if (!check.Contains(cur))
                        {
                            check.Add(cur);
                            ++total;
                        }
                    }
                }
            }

            output.Append(total).AppendLine();
        }
    }
}
