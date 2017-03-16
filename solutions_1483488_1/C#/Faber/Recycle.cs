using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Scratch
{
  public class Recycle
  {

    public static void Main()
    {
      var reader = File.OpenText(@"C:\Users\raf.CRYPTOMATHIC\Downloads\C-large (1).in");
      var writer = File.CreateText(@"c:\temp\C-large-output.txt");
      int num = int.Parse(reader.ReadLine());
      for (int caseno = 0; caseno < num; caseno++)
      {
        string line = reader.ReadLine();
        string[] split = line.Split(' ');
        int length = split[0].Length;
        int mod = 1;
        for(int i=0;i<length;i++) mod *= 10;
        int a = int.Parse(split[0]);
        int b = int.Parse(split[1]);
        int res = 0;
        int[] memo = new int[length];
        for (int n = a; n < b; n++)
        {
          int m = n;
          int v = 0;
          for(int i=0;i<length-1;i++)
          {
            int t = m*10;
            m = t%mod + t/mod;
            if (m > n && m > a && m <= b)
            {
              int j;
              for (j = 0; j < v;j++)
              {
                if (memo[j] == m)
                  break;
              }
              if (j == v)
              {
                res++;
                memo[v] = m;
                v++;
              }
            }
          }
        }

        writer.WriteLine("Case #{0}: {1}", caseno + 1, res);
      }
      reader.Close();
      writer.Close();
    }
  }
}
