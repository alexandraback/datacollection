using System;
using System.CodeDom;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2016
{
    class Program
    {

/*
        static int toBase(int num, int toBase)
        {
            for (int d = 0; d < 32; d++)
            {
                if ((start & (1 << d)) > 0)
                {
                    upper = BigInteger.Add(upper, BigInteger.Pow(baseN, d));
                }
            }
        }*/

        private static bool test = false;
        // c:\users\erickul\documents\visual studio 2015\Projects\GCJ2016\GCJ2016\Program.cs
        static void Main(string[] args)
        {
            string file = "a-small-attempt1.in";
            if (test) file = "test.txt";

            string[] lines = File.ReadAllLines(@"c:\Users\erickul\Documents\Visual Studio 2015\Projects\GCJ2016\GCJ2016\" + file );
            StringBuilder output = new StringBuilder();
            int t = int.Parse(lines[0]);
            int nextLine = 1;
            for (int i = 1; i <= t; i++)
            {
                output.Append($"CASE #{i}: ");
                string n = lines[nextLine];
                nextLine++;
                int f = n.ToCharArray().Count(c => c == 'U');
                for (int j = 0; j < f; j++)
                {
                    n = n.Remove(n.IndexOf('F'), 1);
                    n = n.Remove(n.IndexOf('O'), 1);
                    n = n.Remove(n.IndexOf('U'), 1);
                    n = n.Remove(n.IndexOf('R'), 1);
                }

                int two = n.ToCharArray().Count(c => c == 'W');
                for (int j = 0; j < two; j++)
                {
                    n = n.Remove(n.IndexOf('T'), 1);
                    n = n.Remove(n.IndexOf('W'), 1);
                    n = n.Remove(n.IndexOf('O'), 1);
                }

                int z = n.ToCharArray().Count(c => c == 'Z');
                for (int j = 0; j < z; j++)
                {
                    n = n.Remove(n.IndexOf('Z'), 1);
                    n = n.Remove(n.IndexOf('E'), 1);
                    n = n.Remove(n.IndexOf('R'), 1);
                    n = n.Remove(n.IndexOf('O'), 1);
                }

                int g = n.ToCharArray().Count(c => c == 'G');
                for (int j = 0; j < g; j++)
                {
                    n = n.Remove(n.IndexOf('E'), 1);
                    n = n.Remove(n.IndexOf('I'), 1);
                    n = n.Remove(n.IndexOf('G'), 1);
                    n = n.Remove(n.IndexOf('H'), 1);
                    n = n.Remove(n.IndexOf('T'), 1);
                }

                int x = n.ToCharArray().Count(c => c == 'X');
                for (int j = 0; j < x; j++)
                {
                    n = n.Remove(n.IndexOf('S'), 1);
                    n = n.Remove(n.IndexOf('I'), 1);
                    n = n.Remove(n.IndexOf('X'), 1);
                }

                int five = n.ToCharArray().Count(c => c == 'F');
                for (int j = 0; j < five; j++)
                {
                    n = n.Remove(n.IndexOf('F'), 1);
                    n = n.Remove(n.IndexOf('I'), 1);
                    n = n.Remove(n.IndexOf('V'), 1);
                    n = n.Remove(n.IndexOf('E'), 1);
                }

                int v = n.ToCharArray().Count(c => c == 'V');
                for (int j = 0; j < v; j++)
                {
                    n = n.Remove(n.IndexOf('S'), 1);
                    n = n.Remove(n.IndexOf('E'), 1);
                    n = n.Remove(n.IndexOf('V'), 1);
                    n = n.Remove(n.IndexOf('E'), 1);
                    n = n.Remove(n.IndexOf('N'), 1);
                }

                int o = n.ToCharArray().Count(c => c == 'O');
                for (int j = 0; j < o; j++)
                {
                    n = n.Remove(n.IndexOf('O'), 1);
                    n = n.Remove(n.IndexOf('N'), 1);
                    n = n.Remove(n.IndexOf('E'), 1);
                }


                int h = n.ToCharArray().Count(c => c == 'H');
                for (int j = 0; j < h; j++)
                {
                    n = n.Remove(n.IndexOf('T'), 1);
                    n = n.Remove(n.IndexOf('H'), 1);
                    n = n.Remove(n.IndexOf('R'), 1);
                    n = n.Remove(n.IndexOf('E'), 1);
                    n = n.Remove(n.IndexOf('E'), 1);
                }

                int ni = n.ToCharArray().Count(c => c == 'N')/2;
                for (int j = 0; j <ni; j++)
                {
                    n = n.Remove(n.IndexOf('N'), 1);
                    n = n.Remove(n.IndexOf('I'), 1);
                    n = n.Remove(n.IndexOf('N'), 1);
                    n = n.Remove(n.IndexOf('E'), 1);
                }

                for (int j = 0; j < z; j++)
                    output.Append("0");
                for (int j = 0; j < o; j++)
                    output.Append("1");
                for (int j = 0; j < two; j++)
                    output.Append("2");
                for (int j = 0; j <h; j++)
                    output.Append("3");
                for (int j = 0; j < f; j++)
                    output.Append("4");
                for (int j = 0; j < five; j++)
                    output.Append("5");
                for (int j = 0; j < x; j++)
                    output.Append("6");
                for (int j = 0; j < v; j++)
                    output.Append("7");
                for (int j = 0; j < g; j++)
                    output.Append("8");
                for (int j = 0; j < ni; j++)
                    output.Append("9");
                output.AppendLine();
            }
            Console.WriteLine(output.ToString());
            File.WriteAllText(@"c:\Users\erickul\Documents\Visual Studio 2015\Projects\GCJ2016\GCJ2016\a.out", output.ToString());
        }
    }
}
