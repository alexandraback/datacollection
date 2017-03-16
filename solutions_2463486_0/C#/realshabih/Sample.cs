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

        static bool isPalindrome(int num)
        {
            string n = num.ToString();
            for (int i = 0; i < n.Length / 2; i++)
                if (n[i] != n[n.Length - i - 1])
                    return false;

            return true;
        }

        static void FindFairAndSquare(int start, int end, List<int> fs)
        {
            int s = Convert.ToInt32(Math.Sqrt(start));
            int e = Convert.ToInt32(Math.Sqrt(end));

            for (int i = s; i <= e; i++)
            {
                if (isPalindrome(i))
                {
                    int square = Convert.ToInt32(Math.Pow(i, 2));
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

            List<int> fairAndSquare = new List<int>();
            FindFairAndSquare(1, 1000, fairAndSquare);

            for (int i = 1; i <= T; i++)
            {
                int[] AB = ReadIntArray(reader);
                int A = AB[0];
                int B = AB[1];

                int result = fairAndSquare.Count(e => e >= A && e <= B);
                
                writer.WriteLine("Case #" + i + ": " + result);
            }

            reader.Dispose();
            writer.Dispose();
        }

    }
}
