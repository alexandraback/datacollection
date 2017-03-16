using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Scratch
{
  public class Dance
  {

    public static void Main()
    {
      var reader = File.OpenText(@"C:\Users\raf.CRYPTOMATHIC\Downloads\B-small-attempt0 (1).in");
      var writer = File.CreateText(@"c:\temp\B-small-output.txt");
      int num = int.Parse(reader.ReadLine());
      for (int caseno = 0; caseno < num; caseno++)
      {
        string line = reader.ReadLine();
        string[] split = line.Split(' ');
        int n = int.Parse(split[0]);
        int s = int.Parse(split[1]);
        int p = int.Parse(split[2]);
        int res = 0;
        for(int i=0;i<n;i++)
        {
          int score = int.Parse(split[3+i]);
          if (score >= p * 3-2)
          {
            res++;
          }
          else if(score >= p*3-4 && s>0 && p>1)
          {
            res++;
            s--;
          }
        }

        writer.WriteLine("Case #{0}: {1}", caseno + 1, res);
      }
      reader.Close();
      writer.Close();
    }
  }
}
