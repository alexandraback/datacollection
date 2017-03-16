using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Round1B
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

        static void Main(string[] args)
        {
            System.IO.StreamReader reader = System.IO.File.OpenText("input.in");
            System.IO.StreamWriter writer = System.IO.File.CreateText("output.out");

            int T = ReadInt(reader);

            for (int i = 1; i <= T; i++)
            {
                int result = 0;

                string[] data = ReadStringArray(reader);
                string name = data[0];
                int n = Convert.ToInt32(data[1]);

                char[] vowels = { 'a', 'e', 'i', 'o', 'u' };

                for (int j = 0; j <= name.Length - n; j++)
                {
                    for (int k = n; k <= name.Length - j; k++)
                    {
                        string s = name.Substring(j, k);
                        int temp = 0;
                        foreach (char ch in s)
                        {
                            if (vowels.Contains(ch))
                                temp = 0;
                            else
                                temp++;

                            if (temp == n)
                            {
                                result++;
                                break;
                            }
                        }
                    }
                }
                

                writer.WriteLine("Case #" + i + ": " + result.ToString());
            }

            reader.Dispose();
            writer.Dispose();
        }
    }

}
