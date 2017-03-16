import java.util.Scanner;

class Rush
{
  public static void main(String... args)
  {
    Scanner sc = new Scanner(System.in);
    int tests = sc.nextInt();
    for (int test = 1; test <= tests; test++)
    {
      int n = sc.nextInt();
      Level[] ls = new Level[n];
      for (int i = 0; i < n; i++)
      {
        ls[i] = new Level(sc.nextInt(), sc.nextInt(), i);
      }
      int result = solve(ls);
      if (result < 0)
      {
        System.out.println("Case #" + test + ": Too Bad");
      }
      else
      {
        System.out.println("Case #" + test + ": " + result);
      }
    }
  }

  static class Level
  {
    int a;
    int b;
    int n;
    Level(int a, int b, int na)
    {
      this.a = a;
      this.b = b;
      n = na;
    }
  }

  public static int solve(Level[] bLevels)
  {
    java.util.Arrays.sort(bLevels, new java.util.Comparator<Level>()
        {
          public int compare(Level l1, Level l2)
    {
      return l1.b - l2.b;
    }
        });
    Level[] aLevels = bLevels.clone();
java.util.Arrays.sort(aLevels, new java.util.Comparator<Level>()
        {
          public int compare(Level l1, Level l2)
    {
      if (l1.a == l2.a)
{
  return l2.b - l1.b;
}
      return l1.a - l2.a;
    }
        });

    int aStart = 0;
    int bStart = 0;
    int score = 0;
    boolean changed = true;
    int levels = 0;
    while (changed && bStart < bLevels.length)
    {
      changed = false;
      if (bLevels[bStart].b != -1 && bLevels[bStart].a != -1 && bLevels[bStart].b <= score)
      {
        //System.out.println("Picking " + bLevels[bStart].n + ".b for " + bLevels[bStart].b);
        bLevels[bStart].b = -1;
        score += (bLevels[bStart].a == -1 ? 1 : 2);
        bLevels[bStart].a = -1;
        levels++;
        changed = true;
        bStart++;
        continue;
      }
      if (changed)
      {
        continue;
      }
      if (bLevels[bStart].b != -1 && bLevels[bStart].b <= score)
      {
        //System.out.println("Picking " + bLevels[bStart].n + ".b for " + bLevels[bStart].b);
        bLevels[bStart].b = -1;
        score += (bLevels[bStart].a == -1 ? 1 : 2);
        bLevels[bStart].a = -1;
        levels++;
        changed = true;
        bStart++;
        continue;
      }
      while (aStart < aLevels.length && aLevels[aStart].a == -1)
      {
        aStart++;
      }
      if (aStart < aLevels.length && aLevels[aStart].a != -1 && aLevels[aStart].a <= score)
      {
        //System.out.println("Picking " + aLevels[aStart].n + ".a for " + aLevels[aStart].a);
        aLevels[aStart].a = -1;
        score++;
        levels++;
        changed = true;
        aStart++;
      }
    }
    if (score == 2 * bLevels.length)
    {
      return levels;
    }
    return -1;
  }
}
