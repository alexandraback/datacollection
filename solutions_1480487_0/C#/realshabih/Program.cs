using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Round_1B
{
    class Program1
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
                List<int> data = ReadIntList(reader);
                int N = data[0];
                data.RemoveAt(0);
                
                int sum = data.Sum();

                double[] result = new double[N];

                int count = N;
                int s = sum;
                for (int j = N - 1; j >= 0; j--)
                {
                    result[j] = -1;
                }

                for (int j = N - 1; j >= 0; j--)
                {
                    if (data[j] >= (double)sum * 2 / (double)N)
                    {
                        result[j] = 0;
                        count--;
                        s -= data[j];
                    }
                }
                
                for (int j = N - 1; j >= 0; j--)
                {
                    if (result[j] == -1)
                    {
                        if (s == 0)
                            result[j] = (double)100 / (double)count;
                        else
                            result[j] = ((double)(s + sum) / (double)count - data[j]) / (double)sum * 100;
                    }
                }

                string resultTotal = String.Empty;
                for (int j = 0; j < N; j++)
                    resultTotal += " " + Math.Round(result[j], 6).ToString("0.000000");

                Console.WriteLine("Case #" + i + ":" + resultTotal);
                writer.WriteLine("Case #" + i + ":" + resultTotal);
           }

            reader.Dispose();
            writer.Dispose();
        }

    }
}
