import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;

class Diamond
{
  public static void main(String... args)
  {
    Scanner sc = new Scanner(System.in);
    int tests = sc.nextInt();
    for (int test = 1; test <= tests; test++)
    {
      int n = sc.nextInt();
      int[][] links = new int[n][];
      for (int i = 0; i < n; i++)
      {
        int m = sc.nextInt();
        links[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
          links[i][j] = sc.nextInt() - 1;
        }
      }
      boolean result = solve(links);
      System.out.println("Case #" + test + ": " + (result ? "Yes" : "No"));
    }
  }

  public static boolean solve(int[][] links)
  {
    List<HashSet<Integer>> sets = new ArrayList<HashSet<Integer>>(links.length);
    for (int i = 0; i < links.length; i++)
    {
      HashSet<Integer> set = new HashSet<Integer>();
      sets.add(set);
      set.add(i);
    }
    for (int i = 0; i < links.length; i++)
    {
      Set<Integer> currentSet = sets.get(i);
      for (int j = 0; j < links[i].length; j++)
      {
        // try adding links[i][j] to all sets that contain node i
//        System.err.println("Adding " + links[i][j] + " to " + i);
        Set<Integer> linkedSet = sets.get(links[i][j]);
        for (Set<Integer> set : sets)
        {
          if (set.contains(i))
          {
            for (Integer node : linkedSet)
            {
              if (set.contains(node))
              {
                return true;
              }
              set.add(node);
            }
          }
        }
      }
    }
    return false;
  }
}
