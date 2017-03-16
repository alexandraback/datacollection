using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Qualification
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

        static List<Int64> ReadInt64List(System.IO.StreamReader reader)
        {
            string data = reader.ReadLine();
            return data.Split(' ').Select(x => Int64.Parse(x)).ToList();
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

        public static int GetCount(int N, int start)
        {
            if (start.ToString().Length == N.ToString().Length)
            {
                return N - start;
            }
            else
            {
                int tCount = 0;
                while (start % 10 != 9)
                {
                    tCount++;
                    start++;
                }

                string t = String.Empty;
                for (int i = 0; i < start.ToString().Length; i++)
                {
                    t = t + start.ToString()[start.ToString().Length - i - 1].ToString();
                }

                start = Convert.ToInt32(t);
                tCount++;

                int iLength = start.ToString().Length;
                while (start.ToString().Length <= iLength)
                {
                    tCount++;
                    start++;
                }
                return tCount + GetCount(N, start);
            }
        }

        static void Main(string[] args)
        {
            System.IO.StreamReader reader = System.IO.File.OpenText("input.in");
            System.IO.StreamWriter writer = System.IO.File.CreateText("output.out");

            int T = ReadInt(reader);

            for (int i = 1; i <= T; i++)
            {
                int N = ReadInt(reader);
                int count = GetCount(N, 1);


                writer.WriteLine("Case #" + i + ": " + count);
            }

            reader.Dispose();
            writer.Dispose();
        }

    }
}
