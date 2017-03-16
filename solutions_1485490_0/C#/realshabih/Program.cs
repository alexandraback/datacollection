using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Round1C
{
    class Program
    {
        static int ReadInt(System.IO.StreamReader reader)
        {
            return int.Parse(reader.ReadLine());
        }

        static List<int> ReadIntList(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ').Select(x => int.Parse(x)).ToList();
        }

        static int[] ReadIntArray(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ').Select(x => int.Parse(x)).ToArray();
        }

        static int[] ReadCharArray(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            int[] dataInt = new int[data.Length];
            for (int i = 0; i < data.Length; i++)
                dataInt[i] = data[i] == '.' ? -1 : 1;

            return dataInt;
        }

        static int[] ReadIntData(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ').Select(x => int.Parse(x)).ToArray();
        }

        static Int64[] ReadInt64Array(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ').Select(x => Int64.Parse(x)).ToArray();
        }

        static List<string> ReadStringList(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ').ToList();
        }

        static void Main(string[] args)
        {
            System.IO.StreamReader reader = System.IO.File.OpenText("input.in");
            System.IO.StreamWriter writer = System.IO.File.CreateText("output.out");

            int T = ReadInt(reader);
            for (int i = 1; i <= T; i++)
            {
                int[] data = ReadIntArray(reader);
                int N = data[0];
                int M = data[1];

                Int64[] boxes = ReadInt64Array(reader);
                Int64[] toys = ReadInt64Array(reader);

                Int64 result = FindMaxCount(boxes, toys, 0, 0);

                Console.WriteLine("Case #" + i + ": " + result);
                writer.WriteLine("Case #" + i + ": " + result);
            }

            reader.Dispose();
            writer.Dispose();
        }

        static Int64 FindMaxCount(Int64[] boxes, Int64[] toys, int start1, int start2)
        {
            Int64 count = 0;
            Int64[] copyBoxes = new Int64[boxes.Length];
            Int64[] copyToys = new Int64[toys.Length];
            boxes.CopyTo(copyBoxes, 0);
            toys.CopyTo(copyToys, 0);

            if (boxes[start1 + 1] == toys[start2 + 1])
            {
                Int64 c = Math.Min(boxes[start1], toys[start2]);
                count += c;
                copyBoxes[start1] -= c;
                copyToys[start2] -= c;
                if (copyBoxes[start1] == 0)
                    start1 += 2;
                if (copyToys[start2] == 0)
                    start2 += 2;
                if (boxes.Length == start1 || toys.Length == start2)
                    return count;
                else
                    return count + FindMaxCount(copyBoxes, copyToys, start1, start2);
            }
            else
            {
                //throw toys;
                Int64 count1 = 0;
                if (start2 + 2 < toys.Length)
                    count1 = FindMaxCount(boxes, toys, start1, start2 + 2);
                //throw boxes
                Int64 count2 = 0;
                if (start1 + 2 < boxes.Length)
                    count2 = FindMaxCount(boxes, toys, start1 + 2, start2);
                return count + Math.Max(count1, count2);
            }
        }
    }
}
