using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJamQualifications
{
    class Program
    {
        static void Main(string[] args)
        {
            File.WriteAllText(@"C:\Users\Arch\Documents\CodeJam\Output\Lawnmower.out", "");
            string[] lines = File.ReadAllLines(args[0]);
            int count = int.Parse(lines[0]);
            int line = 1;

            for (int i = 0; i < count; i++)
            {
                int height = int.Parse(lines[line].Split(new char[] { ' ' })[0]);
                ++line;
                string[] pattern = new string[height];
                for (int h = 0; h < height; h++)
                {
                    pattern[h] = lines[line++];
                }
                Pattern p = new Pattern(pattern);
                p.ComputeCuts();
                File.AppendAllText(@"C:\Users\Arch\Documents\CodeJam\Output\Lawnmower.out", "Case #" + (i + 1) + ": " + (p.IsPossible() ? "YES" : "NO") + "\n");
            }
        }
    }
}
