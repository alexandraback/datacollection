using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;

namespace GoogleJam1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = System.IO.File.ReadAllLines(@"D:\GoogleJam\1\test.txt");

            string[] lines2 = System.IO.File.ReadAllLines(@"D:\GoogleJam\1\test2.txt");

            string[] lines3 = System.IO.File.ReadAllLines(@"D:\GoogleJam\1\test3.txt");

            Dictionary<Char, Char> dict = new Dictionary<Char, Char>();

            for (int i = 1; i < lines.Count(); i++)
            {
                
                for(int j = 0; j < lines[i].Count(); j++)
                {
                    if (!dict.Keys.Contains(lines[i][j]))
                    {
                        dict[lines[i][j]] = lines2[i][j];
                    }
                }
            }
            dict['z'] = 'q';
            dict['q'] = 'z';
            using (System.IO.StreamWriter file = new System.IO.StreamWriter(@"D:\GoogleJam\1\output.txt"))
            {



                for (int i = 1; i < lines3.Count(); i++)
                {
                    string result = "";
                    for (int j = 0; j < lines3[i].Count(); j++)
                    {
                        result += dict[lines3[i][j]];
                    }
                    Console.WriteLine("Case #{0}: {1}", i, result);
                    file.WriteLine("Case #{0}: {1}", i, result);
                }
            }
            

            System.Console.ReadKey();
        }
    }
}
