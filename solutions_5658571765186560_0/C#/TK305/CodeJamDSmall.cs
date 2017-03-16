using System;
using System.IO;

namespace CodeJamDSmall
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(new FileStream("D-small-attempt0.in", FileMode.Open));
            StreamWriter sw = new StreamWriter(new FileStream("D_small.out", FileMode.Create));
            string temp = sr.ReadLine();

            int test_num = int.Parse(temp);

            for (int i = 1; i < test_num + 1; i++)
            {
                temp = sr.ReadLine();
                string[] words = temp.Split(' ');

                int X = int.Parse(words[0]);
                int R = int.Parse(words[1]);
                int C = int.Parse(words[2]);

                if (X > R && X > C)
                    sw.WriteLine("Case #{0}: RICHARD", i);
                else if ((R * C) % X != 0)
                    sw.WriteLine("Case #{0}: RICHARD", i);
                else if (X == 4 && (R < 3 || C < 3))
                    sw.WriteLine("Case #{0}: RICHARD", i);
                else if (X == 3 && (R < 2 || C < 2))
                    sw.WriteLine("Case #{0}: RICHARD", i);
                else
                    sw.WriteLine("Case #{0}: GABRIEL", i);                    
            }
            sr.Close();
            sw.Close();
        }
    }
}
