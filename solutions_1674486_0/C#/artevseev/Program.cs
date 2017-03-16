using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _2012C1
{
  class Program
  {

    public static bool IsDiamond(int n, int[,] graph)
    {
      for (int i = 1; i <= n; i++)
      {
        int[] idx = new int[n + 1];
        idx[i] = 1;
        bool check = true;
        while (check)
        {
          check = false;
          for (int i1 = 1; i1 <= n; i1++)
            for (int j1 = 1; j1 <= n; j1++)
            {
              if (i1 == j1)
                continue;
              if (graph[i1, j1] != 1)
                continue;
              if (idx[i1] != 1)
                continue;
              if (idx[j1] != 1)
                check = true;
              idx[j1] = 1;
            }
        }
        for (int j = 1; j <= n; j++)
        {
          if (idx[j] == 0) 
            continue;
          if (i == j)
            continue;
          int count = 0;
          for (int j1 = 1; j1 <= n; j1++)
          {
            if (j == j1)
              continue;
            if (graph[j1, j] == 1 && idx[j1] == 1)
              count++;
          }
          if (count > 1)
            return true;
        }
      }
      return false;

    }

    static void Main(string[] args)
    {
      int tests = int.Parse(Console.ReadLine());
      for (int test = 0; test < tests; test++)
      {
        int n = int.Parse(Console.ReadLine());
        int[,] graph = new int[n + 1, n + 1];
        for (int i = 0; i < n; i++)
        {
          string[] line = Console.ReadLine().Split(' ');
          int m = int.Parse(line[0]);
          for (int j = 0; j < m; j++)
          {
            int point = int.Parse(line[j + 1]);
            graph[i + 1, point] = 1;
          }          
        }
        Console.WriteLine(string.Format("Case #{0}: {1}", test + 1, IsDiamond(n, graph) ? "Yes" : "No"));
      }
        
    }
  }
}
