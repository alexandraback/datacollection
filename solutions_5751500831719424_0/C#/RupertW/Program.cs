using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ141BQ1
{
  using System.IO;

  class Program
  {
    class Line
    {
      public char c;

      public int i;
    }

    class Foo
    {
      public char c;

      public int l;

      public List<Line> s;
    }

    static void Main(string[] args)
    {
      //args = new string[] {"..\\..\\A-small-attempt1.in"};
      using (var sr = new StreamReader(args[0]))
      {
        int nCases = int.Parse(sr.ReadLine());

        for (int nCase = 1; nCase <= nCases; ++nCase)
        {
          int nStrings = int.Parse(sr.ReadLine());

          var s = new List<String>();
          for (int i = 0; i < nStrings; ++i)
          {
            s.Add(sr.ReadLine());
          }

          string s0 = s[0];
          string s1 = s[1];

          int moves = 0;

          int index = 0;
          for (; ; )
          {
            var cs = s.Select((t, x) => new Line() { c = ((index < t.Length) ? t[index] : (char)0), i = x });
            var csc = cs.GroupBy(q => q.c).Select(g => new Foo() { c = g.Key, l = g.Count(), s = g.ToList() })
              .OrderBy(f => f.l).ToList();

            if (csc.Count == 1)
            {
              if (csc[0].c == 0) break;
              ++index;
              continue;
            }

            bool changed = false;
            Foo shortest = csc.First();
            foreach(Foo longest in csc.Skip(1).Reverse())
            {
              int lineI = shortest.s[0].i;
              string line = s[lineI];
              char sc = shortest.c;
              char target = longest.c;

              if (sc != 0)
              {
                if (target != 0)
                {
                  if ((index >= 1) && line[index - 1] == target)
                  {
                    // Double
                    s[lineI] = line.Substring(0, index) + target + line.Substring(index);
                    ++moves;
                    changed = true;
                    break;
                  }
                  if ((index >= 1) && (line[index - 1] == line[index]))
                  {
                    int maxDelete = 1;
                    while (((index + maxDelete) < line.Length) && (line[index+maxDelete] == line[index])) ++maxDelete;
                    if (((index + maxDelete) < line.Length) && (line[index + maxDelete] == target))
                    {
                      // Delete many!
                      s[lineI] = line.Substring(0, index)+ line.Substring(index + maxDelete);
                      moves += maxDelete;
                      changed = true;
                      break;
                    }
                  }
                }
                else
                {
                  if ((index >= 1) && line[index - 1] == line[index])
                  {
                    // Delete
                    s[lineI] = line.Substring(0, index);
                    ++moves;
                    changed = true;
                    break;
                  }
                }
              }
              else
              {
                if (target != 0)
                {
                  if ((index >= 1) && line[index - 1] == target)
                  {
                    // Double
                    s[lineI] = line + target;
                    ++moves;
                    changed = true;
                    break;
                  }
                }
              }
            }
            if (changed)
            {
              continue;
            }

            // Failed
            moves = -1;
            break;
          }

          if (moves >= 0)
          {
            Console.WriteLine("Case #{0}: {1}", nCase, moves);
          }
          else
          {
            Console.WriteLine("Case #{0}: Fegla Won", nCase);
          }
        }
      }
     }
  }
}
