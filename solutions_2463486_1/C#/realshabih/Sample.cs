using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;

namespace GCJ.Round1
{
    class Program
    {
        static int ReadInt(System.IO.StreamReader reader)
        {
            return int.Parse(reader.ReadLine());
        }

        static int[] ReadIntArray(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ').Select(x => int.Parse(x)).ToArray();
        }

        static Int64[] ReadInt64Array(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ').Select(x => Int64.Parse(x)).ToArray();
        }

        static string[] ReadStringArray(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ');
        }

        static bool isPalindrome(Int64 num)
        {
            string n = num.ToString();
            for (int i = 0; i < n.Length / 2; i++)
                if (n[i] != n[n.Length - i - 1])
                    return false;

            return true;
        }

        static void FindFairAndSquare(Int64 start, Int64 end, List<Int64> fs)
        {
            Int64 s = Convert.ToInt64(Math.Sqrt(start));
            Int64 e = Convert.ToInt64(Math.Sqrt(end));

            for (Int64 i = s; i <= e; i++)
            {
                if (isPalindrome(i))
                {
                    Int64 square = Convert.ToInt64(Math.Pow(i, 2));
                    if (isPalindrome(square))
                        fs.Add(square);
                }
            }
        }

        static void Main(string[] args)
        {
            System.IO.StreamReader reader = System.IO.File.OpenText("input.in");
            System.IO.StreamWriter writer = System.IO.File.CreateText("output.out");

            int T = ReadInt(reader);

            List<Int64> fairAndSquare = new List<Int64>();
            FindFairAndSquare(1, Convert.ToInt64(Math.Pow(10, 14)), fairAndSquare);

            for (int i = 1; i <= T; i++)
            {
                Int64[] AB = ReadInt64Array(reader);
                Int64 A = AB[0];
                Int64 B = AB[1];

                int result = fairAndSquare.Count(e => e >= A && e <= B);
                
                writer.WriteLine("Case #" + i + ": " + result);
            }

            reader.Dispose();
            writer.Dispose();
        }

    }
}
