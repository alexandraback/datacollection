using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace Round1
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var writer = new StreamWriter("output.txt", false)) {}

            using (var reader = new StreamReader(args[0]))
            using (var writer = new StreamWriter("output.txt", true))
            {
                int t = Convert.ToInt32(reader.ReadLine());
                for (int i = 0; i < t; i++)
                {
                    var line = Array.ConvertAll(reader.ReadLine().Split(new[] { ' ' }), Int32.Parse);
                    var program = new Program(i + 1, writer, line[0], line[1], line[2]);
                }
            }
        }

        public Program(int t, StreamWriter writer, int r, int c, int w)
        {

            //writer.WriteLine(String.Format("Case #{0}: {1}", t, c / w + c % w + w - 1));
            //writer.WriteLine(String.Format("Case #{0}: {1}", t, c / w + w));
            writer.WriteLine(String.Format("Case #{0}: {1}", t, c / w + (c % w > 0 ? w : w - 1)));
        }
    }
}
