using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ.A
{
    class Program
    {
        static void Main(string[] args)
        {
            var worker = new Worker();

            using (var reader = new StreamReader("d:/A-small-attempt2.in"))
            {
                using (var writer = new StreamWriter("d:/aout.txt"))
                {
                    int cases = int.Parse(reader.ReadLine());
                    for (int c = 1; c <= cases; c++)
                    {
                        var input = reader.ReadLine();
                        var result = worker.Convert(input);
                        writer.WriteLine(string.Format("Case #{0}: {1}", c, result));
                        Console.WriteLine(string.Format("Case #{0}: {1}", c, result));
                    }
                }
            }

            Console.ReadKey();
        }
    }

    class Worker
    {
        static string original = "abcdefghijklmnopqrstuvwxyz ";
        static string mappings = "ynficwlbkuomxsevzpdrjgthaq ";

        public string Convert(string input)
        {
            var chars = input.ToCharArray().Select(c => original[mappings.IndexOf(c)]);
            var output = string.Join("", chars);
            return output;
        }
    }
}
