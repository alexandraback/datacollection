using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Xml.Schema;

namespace CloseMatch
{
  class Program
  {
    static void Main(string[] args)
    {
      string inputFile = (args.Length > 0) ? args[0] : @"..\..\test.in";
      var input = File.ReadAllLines(inputFile);
      int ncase = 1;

      foreach (string scoresLine in input.Skip(1))
      {
        var s = scoresLine.Split();
        string pc = s[0];
        string pj = s[1];
        string c = "", j = "";

        int l = pc.Length;
        int m = 10;
        for (int i = 1; i < l; ++i)
        {
          m *= 10;
        }

        var rc = new Regex(pc.Replace("?", "."));
        var rj = new Regex(pj.Replace("?", "."));

        var sc = new List<int>();
        var sj = new List<int>();

        for (int i = 0; i < m; ++i)
        {
          var ii = i.ToString("D" + l.ToString());
          if (rc.IsMatch(ii))
          {
            sc.Add(i);
          }
          if (rj.IsMatch(ii))
          {
            sj.Add(i);
          }
        }

        int xxc = 0, xxj = 0, bd = 1000;

        foreach(int xj in sj)
        {
          foreach (int xc in sc)
          {
            int d = Math.Abs(xj - xc);
            if (d < bd)
            {
              bd = d;
              xxj = xj;
              xxc = xc;
            }
          }
        }

        c = xxc.ToString("D" + l.ToString());
        j = xxj.ToString("D" + l.ToString());

        /*
        for (int i = 0; i < pc.Length; ++i)
        {
          if (pc[i] == '?')
          {
            if (pj[i] == '?')
            {
              if (i == 0)
              {
                c += '0';
                j += '0';
              }
              else
              {
                int nc = int.Parse(c);
                int nj = int.Parse(j);
                if (nc < nj)
                {
                  c += '9';
                  j += '0';
                }
                else if (nc > nj)
                {
                  c += '0';
                  j += '9';
                }
                else
                {
                  c += '0';
                  j += '0';
                }
              }
            }
            else
            {
              c += pj[i];
              j += pj[i];
            }
          }
          else
          {
            if (pj[i] == '?')
            {
              c += pc[i];
              j += pc[i];
            }
            else
            {
              c += pc[i];
              j += pj[i];
            }
          }
        }
        */

        Console.WriteLine("Case #{0}: {1} {2}", ncase, c, j);
        ++ncase;
      }
    }
  }
}
