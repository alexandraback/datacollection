using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CJ_Test
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("in.txt");
            StreamWriter sw = new StreamWriter("out.txt");

            int T = int.Parse(sr.ReadLine());

            for (int t = 0; t < T; t++)
            {
                string[] temp = sr.ReadLine().Split(' ');
                int R = int.Parse(temp[0]);
                int C = int.Parse(temp[1]);
                int W = int.Parse(temp[2]);

                int result = R * (C / W) + W - 1;
                if (C % W > 0)
                    result++;

                sw.WriteLine("Case #" + (t + 1) + ": " + result);
                Console.WriteLine(t);
            }

            sr.Close();
            sw.Close();

            Console.WriteLine("End!");
            Console.ReadLine();
        }

        static int[] StringToIntArray(string[] str)
        {
            int[] result = new int[str.Length];
            for (int i = 0; i < str.Length; i++)
                result[i] = int.Parse(str[i]);
            return result;
        }
        static float[] StringToFloatArray(string[] str)
        {
            float[] result = new float[str.Length];
            for (int i = 0; i < str.Length; i++)
                result[i] = float.Parse(str[i]);
            return result;
        }
    }
}
