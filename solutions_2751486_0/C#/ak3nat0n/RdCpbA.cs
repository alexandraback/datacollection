using System;
using System.IO;
using System.Text;
using System.Linq;
using System.Collections.Generic;

namespace CodeJam
{
    class RoundC_A
    {
        public string Solve(string name, int n)
        {
            List<char> vowels = new List<char>(new char[] { 'a', 'e', 'i', 'o', 'u' });

            int num = 0;
            
            for (int i = 0; i < name.Length; i++)
            {
                for (int j = n; j < (name.Length -i +1); j++)
                {
                    String subs = name.Substring(i,j);

                    //count length n consonants
                    int localCount = 0;

                    for (int k = 0; k < subs.Length; k++)
                    {
                        if (!vowels.Contains(subs[k]))
                        {
                            localCount += 1;
                        }
                        else
                        {
                            localCount = 0;
                        }

                        if (localCount == n)
                        {
                            num += 1;
                            break;
                        }
                    }
                }
            }

            return num.ToString();
        } 

        static void Main()
        {
            string filename = "A-small-attempt0";
            //string filename = "A-small-attempt0";
            //string filename = "A-large";

            StringBuilder builder = new StringBuilder();
            using (StreamReader reader = new StreamReader("..\\..\\data\\" + filename + ".in"))
            {
                long N = long.Parse(reader.ReadLine());
                RoundC_A solver = new RoundC_A();

                for (long i = 0; i < N; i++)
                {
                    string[] data = readStrArray(reader.ReadLine());
                    builder.AppendLine("Case #" + (i + 1) + ": " + solver.Solve(data[0], Int32.Parse(data[1])));
                }
            }

            using (StreamWriter writer = new StreamWriter("..\\..\\results\\" + filename + ".out"))
            {
                writer.Write(builder.ToString());
            }
        }

        public static long readInt(string line)
        {
            return Int32.Parse(line);
        }

        public static int[] readIntArray(string line)
        {
            string[] arr = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            return arr.Select(p => Int32.Parse(p)).ToArray();
        }

        public static string[] readStrArray(string line)
        {
            return line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        }

        public static long readLong(string line)
        {
            return long.Parse(line);
        }

        public static long[] readLongArray(string line)
        {
            string[] arr = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            return arr.Select(p => long.Parse(p)).ToArray();
        }

        public static double readDouble(string line)
        {
            return double.Parse(line);
        }

        public static double[] readDoubleArray(string line)
        {
            string[] arr = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            return arr.Select(p => double.Parse(p)).ToArray();
        }
    }
}
