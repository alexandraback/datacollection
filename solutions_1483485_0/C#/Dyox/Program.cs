using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace GoogleCodeJam2012
{
    public class Program
    {
        static void Main(string[] args)
        {
            string[] input = File.ReadAllLines("C:\\CodeJam2012\\A\\A-small-attempt0.in");
            string output = "";
            string normal;
            int testCases = int.Parse(input[0]);
            for (int i = 1; i <= testCases; i++)
            {
                normal = input[i].ToUpper();
                normal = normal.Replace("A", "y");
                normal = normal.Replace("B", "h");
                normal = normal.Replace("C", "e");
                normal = normal.Replace("D", "s");
                normal = normal.Replace("E", "o");
                normal = normal.Replace("F", "c");
                normal = normal.Replace("G", "v");
                normal = normal.Replace("H", "x");
                normal = normal.Replace("I", "d");
                normal = normal.Replace("J", "u");
                normal = normal.Replace("K", "i");
                normal = normal.Replace("L", "g");
                normal = normal.Replace("M", "l");
                normal = normal.Replace("N", "b");
                normal = normal.Replace("O", "k");
                normal = normal.Replace("P", "r");
                normal = normal.Replace("Q", "z");
                normal = normal.Replace("R", "t");
                normal = normal.Replace("S", "n");
                normal = normal.Replace("T", "w");
                normal = normal.Replace("U", "j");
                normal = normal.Replace("V", "p");
                normal = normal.Replace("W", "f");
                normal = normal.Replace("X", "m");
                normal = normal.Replace("Y", "a");
                normal = normal.Replace("Z", "q");
                output += "Case #" + (i) + ": " + normal + Environment.NewLine;
            }
            File.WriteAllText("C:\\CodeJam2012\\A\\A-small-attempt0.out", output);
        }

    }
}
