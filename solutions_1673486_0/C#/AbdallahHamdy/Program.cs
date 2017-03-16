using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
namespace lang
{
    class Levels
    {
        public int oneStar;
        public int twoStar;
        public bool oneStare=false;
        public bool TwoStare=false;
        public Levels(int o, int t)
        {
            oneStar = o;
            twoStar = t;
        }
    }
    class Program
    {
        static StreamReader read;
        static StreamWriter write;

        static void Main(string[] args)
        {
            read = new StreamReader("input.txt");
            write = new StreamWriter("output.txt");
            int T = Convert.ToInt32(read.ReadLine());
            Dictionary<string, char> hist = new Dictionary<string, char>();
            for (int i = 0; i < T; i++)
            {
                double itr = 00;
                string AB = read.ReadLine();
                string[] ab = AB.Split(' ');
                int A = Convert.ToInt32(ab[0]);
                int B = Convert.ToInt32(ab[1]);
                double[] correct = new double[A];
                string[] c = read.ReadLine().Split(' ');
                double correctence = 1;
                for (int j = 0; j < A; j++)
                {
                    correct[j] = Convert.ToDouble(c[j]);
                    correctence *= correct[j];
                }
                double[][] table = new double[5][];
                for (int j = 0; j < 5; j++)
                    table[j] = new double[8];
                double sol = double.MaxValue;
                //case continue
                double s = (B - A + 1) * correctence + (1 - correctence) * (2 * B - A + 2);
                if (s < sol)
                    sol = s;
                //case enter
                s = (2 + B);
                if (s < sol)
                    sol = s;
                //case BakeSPace
                for (int j = 1; j < A; j++)
                {
                    correctence = correctence / correct[A - j];
                    s = (2 * j + (B - A) + 1) * correctence + (2 * j + (2 * B - A) + 2) * (1 - correctence);
                    if (s < sol)
                        sol = s;
                }
                write.WriteLine("Case #" + (i + 1) + ": " + sol);
                Console.WriteLine("Case #" + (i + 1) + ": " + sol);

            }
            write.Close();
        }
        static string Rotate(string A)
        {
            return A.Substring(A.Length - 1, 1) + A.Substring(0, A.Length - 1);
            
        }
    }
}
/*
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv
our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up
 *  if (A == 1)
                {
                    table[0][0] = correct[0];
                    table[0][1] = 1.0d - correct[0];
                }
                else if (A == 2)
                {
                    table[0][0] = correct[0]*correct[1];
                    table[0][1] = (1.0d - correct[0])*correct[1];
                    table[0][2] = (1.0d - correct[1]) * correct[0];
                    table[0][3] = (1.0d - correct[0]) * (1.000000d - correct[1]);
                }
                else if (A == 3)
                {
                    table[0][0] = correct[0] * correct[1] * correct[2];
                    table[0][1] = (1.0d - correct[0]) * correct[1] * correct[2];
                    table[0][2] = (1.0d - correct[1]) * correct[0] * correct[2];
                    table[0][3] = (1.0d - correct[2]) * correct[0] * correct[1];
                    table[0][4] = (1.0d - correct[0]) * (1.000000d - correct[1]) * correct[2];
                    table[0][5] = correct[0] * (1.000000d - correct[1]) * (1.0d - correct[2]);
                    table[0][6] = (1.0d - correct[0]) * correct[1] * (1.000000d - correct[2]);
                    table[0][7] = (1.0d - correct[0]) * (1.000000d - correct[1]) * (1.000000d - correct[2]);
                }
*/