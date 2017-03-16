using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Threading.Tasks;

namespace JamPlayground
{

    class Program
    {
        static List<int> max<T>(T[] values, int from, int to)
            where T : IComparable<T>
        {
            if (to <= from) throw new ArgumentException();


            T max = values[from];
            for (int i = from + 1; i < to; i++)
            {
                if (values[i].CompareTo(max) > 0) max = values[i];
            }
         
            var maximums = new List<int>();
            for (int i = from; i < to; i++)
            {
                if (values[i].CompareTo(max) == 0) maximums.Add(i);
            }

            return maximums;
        }

        static bool v(char c)
        {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        }

        [DebuggerDisplay("Length = {Length}")]
        class Group
        {
            public int Length;
            public Group Next;
            public bool Cons;
        }

        static bool isN(string name, int n)
        {
            int g = 0;
            for (int i = 0; i < name.Length; i++)
            {
                bool isV = v(name[i]);
                if (isV)
                {
                    g = 0;
                }
                else
                {
                    g++;
                    if (g >= n) return true;
                }
            }
            return false;
        }

        static void Main(string[] args)
        {
            string input = "in.in";
            string output = "out.out";
            File.Delete(output);

            var lines = File.ReadAllLines(input);
            int t = int.Parse(lines[0]);
            for (int i = 0; i < t; i++)
            {

                var strings = lines[i+1].Split();
                string name = strings[0];
                int n = int.Parse(strings[1]);

                int value = 0;
                for (int j = 0; j < name.Length; j++)
                {
                    for (int k = j; k < name.Length; k++)
                    {
                        if (isN(name.Substring(j, k - j + 1), n)) value++;
                    }
                }

                var cs = string.Format("Case #{0}: ", (i + 1));
                File.AppendAllText(output, cs + value + Environment.NewLine);

            }
        }
    }
}
