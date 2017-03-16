using System;
using System.IO;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(new FileStream("A-small-attempt0.in", FileMode.Open));
            StreamWriter sw = new StreamWriter(new FileStream("A-small.out", FileMode.Create));
            string temp = sr.ReadLine();

            int test_num = int.Parse(temp);

            for (int i = 1; i < test_num + 1; i++)
            {
                temp = sr.ReadLine();
                string[] words = temp.Split(' ');
                int R = int.Parse(words[0]);
                int C = int.Parse(words[1]);
                int W = int.Parse(words[2]);

                int max_score = 0;
                if (C == W)
                    max_score = W;
                else if (C % W == 0)
                    max_score = C / W + W - 1;
                else
                    max_score = C / W + W;

                sw.WriteLine("Case #{0}: {1}", i, max_score);
            }

            sr.Close();
            sw.Close();
        }
    }
}
