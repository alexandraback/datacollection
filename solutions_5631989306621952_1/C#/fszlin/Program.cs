using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2016R1
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var input = File.ReadAllLines("../../in.txt");
            var T = int.Parse(input[0]);

            using (var writer = File.CreateText("../../out.txt"))
            {
                for (var i = 1; i <= T; ++i)
                {
                    writer.Write($"Case #{i}: ");
                    new Program().Solve(input[i], writer);
                }
            }
        }

        private void Solve(string input, StreamWriter o)
        {
            var str = "" + input[0];
            foreach (var c in input.Skip(1))
            {
                if (c >= str[0])
                {
                    str = c + str;
                }
                else
                {
                    str = str + c;
                }
            }

            o.WriteLine(str);
        }
    }
}
