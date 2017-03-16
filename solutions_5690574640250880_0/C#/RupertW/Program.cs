using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ14Q3
{
  internal class Program
  {
    private static void Main(string[] args)
    {
      // args = new string[] {"..\\..\\sample.in"};
      using (var sr = new StreamReader(args[0]))
      {
        int nCases = int.Parse(sr.ReadLine());

        for (int nCase = 1; nCase <= nCases; ++nCase)
        {
          var vals = sr.ReadLine().Split(' ').Select(s => int.Parse(s)).ToList();
          Console.WriteLine("Case #{0}:", nCase);
          Play(vals[0], vals[1], vals[2]);
        }
      }
    }

    private static void Play(int r, int c, int m)
    {
      // -1 = mine
      int[,] counts = new int[r,c];

      for (int i = 0; i < m; ++i)
      {
        int max_x = 0;
        int max_y = 0;


        // First, try the corners
        if ((r>=5) && (c>=5) && counts[0, 0] >= 0)
        {
          max_x = 0;
          max_y = 0;
        }
        else if ((r >= 5) && (c >= 5) && counts[r - 1, c - 1] >= 0)
        {
          max_x = c-1;
          max_y = r-1;
        }
        else if ((r >= 5) && (c >= 5) && counts[0, c - 1] >= 0)
        {
          max_x = c - 1;
          max_y = 0;
        }
        else if ((r >= 5) && (c >= 5) && counts[r - 1, 0] >= 0)
        {
          max_x = 0;
          max_y = r - 1;
        }
        else
        {
          // Find highest count.
          // For this purpose, off-the-board counts as mined.
          int max = counts[0, 0];
          for (int y = 0; y < r; ++y)
          {
            for (int x = 0; x < c; ++x)
            {
              int sqCount = counts[y, x];
              if (sqCount < 0)
              {
                // mined
                continue;
              }
              //if ((x == 0) || (x == (c - 1))) sqCount += 1;
              //if ((y == 0) || (y == (r - 1))) sqCount += 1;
              if (sqCount > max)
              {
                max = sqCount;
                max_x = x;
                max_y = y;
              }
            }
          }
        }

        // Place mine, inc neighbours
        counts[max_y, max_x] = -1;
        for (int y0 = -1; y0 <= 1; ++y0)
        {
          int y1 = max_y + y0;
          if (y1 >= 0 && y1 < r)
          {
            for (int x0 = -1; x0 <= 1; ++x0)
            {
              if ((x0 == 0) && (y0 == 0)) continue;
              int x1 = max_x + x0;
              if (x1 >= 0 && x1 < c)
              {
                int oldc = counts[y1, x1];
                if (oldc >= 0)
                {
                  counts[y1, x1] = oldc + 1;
                }
              }
            }
          }
        }
      }

      // Are there any zeroes left?
      bool found0 = false;
      for (int y = 0; y < r; ++y)
      {
        for (int x = 0; x < c; ++x)
        {
          if (counts[y, x] == 0)
          {
            found0 = true;
            break;
          }
        }
      }

      /*
      for (int y = 0; y < r; ++y)
      {
        for (int x = 0; x < c; ++x)
        {
          int sq = counts[y, x];
          char ch = (sq < 0) ? '*' : (char)('0' + sq);
          Console.Write(ch);
        }
        Console.WriteLine();
      }
       */

      if (found0)
      {
        found0 = false;
        //Console.WriteLine();
        for (int y = 0; y < r; ++y)
        {
          for (int x = 0; x < c; ++x)
          {
            int sq = counts[y, x];
            char ch = (sq < 0) ? '*' : '.';
            if ((sq == 0) && !found0)
            {
              ch = 'c';
              found0 = true;
            }
            Console.Write(ch);
          }
          Console.WriteLine();
        }
      }
      else
      {
        Console.WriteLine("Impossible");
      }
    }
  }
}
