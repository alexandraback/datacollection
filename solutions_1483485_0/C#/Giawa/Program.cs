using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace FindMappingCodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            char[] mappings = new char[128]  { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'y', 'h', 'e', 's', 'o', 'c', 'v', 'x',
'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm',
'a', 'q', ' ', ' ', ' ', ' ', ' ', };

            using (StreamReader stream = new StreamReader(@"C:\Users\Montana\Desktop\A-small-attempt0.in"))
            using (StreamWriter output = new StreamWriter(@"C:\Users\Montana\Desktop\output.txt"))
            {
                int count = int.Parse(stream.ReadLine());
                for (int i = 0; i < count; i++)
                {
                    output.Write("Case #{0}: ", i + 1);
                    string line = stream.ReadLine();
                    for (int j = 0; j < line.Length; j++) output.Write(mappings[line[j]]);
                    output.WriteLine();
                }
            }
        }
    }
}
