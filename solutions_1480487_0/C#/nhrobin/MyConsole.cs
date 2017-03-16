using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ProblemA
{
    public static class MyConsole
    {
        public static int ReadInt()
        {
            return Int32.Parse(Console.In.ReadLine());
        }

        public static int[] ReadIntArray(int count)
        {
            var arr = new int[count];
            var splits = Console.In.ReadLine().Split(' ');
            for (int i = 0; i < count; i++)
                arr[i] = Int32.Parse(splits[i]);
            return arr;
        }

        public static int GetNextInt()
        {
            TextReader reader = Console.In;
            string s = string.Empty;

            while (true)
            {
                char[] c = new char[1];
                var f = reader.Read(c, 0, 1);

                if (c[0] >= 48 && c[0] <= 57)
                {
                    s += c[0];
                }
                else
                {
                    if (!string.IsNullOrEmpty(s))
                        return Int32.Parse(s);
                    return 0;
                }
            }
        }

    }
}
