using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
  class Program
  {
    static void Main(string[] args)
    {
      var instream = new StreamReader("B-large.in.txt");
      var outstream = new StreamWriter("output-large.txt");

      int n = Int32.Parse(instream.ReadLine());

      for (int x = 1; x <= n; ++x)
      {
        outstream.Write("Case #{0}:", x);

        string line = instream.ReadLine();

        int blocks = 1;
        char face = line[0];
        for(int i=1; i<line.Length; i++)
        {
          if (face != line[i])
            blocks++;
          face = line[i];
        }
        if (face == '+') blocks--;

        outstream.WriteLine(" {0}", blocks);
      }

      instream.Close();
      outstream.Close();
    }
  }
}
