import java.util.*;
import java.math.*;

public class B
{
  public static void main(String arg[])
  {
    Scanner s = new Scanner(System.in);
    String line = s.nextLine();
    Solve solve = new Solve();

    int tc = Integer.parseInt(line);
    for (int t = 1; t <= tc; t++)
    {
      line = s.nextLine();
      String sp[] = line.split(" +");
      int x = Integer.parseInt(sp[0]);
      int y = Integer.parseInt(sp[1]);
      System.out.println("Case #" + t + ": " + solve.recall(x + 200, y + 200));
    }
  }
}

class Double
{
  int x, y;
  Double(int a, int b) {x = a; y = b; }
}

class Solve
{
  final int MAX_MOVE = 800;
  char w[][][] = new char[401][401][MAX_MOVE + 1];
  Queue<Double> q1, q2;
  Solve()
  {
    q1 = new LinkedList<Double>();
    q1.add(new Double(200, 200));

    for (int i = 1; i <= MAX_MOVE; i++)
    {
      q2 = new LinkedList<Double>();
      while (!q1.isEmpty())
      {
        Double d = q1.remove();
        if (d.x + i <= 400 && w[d.x + i][d.y][i] == (char) 0)
        {
          w[d.x + i][d.y][i] = 'E';
          q2.add(new Double(d.x + i, d.y));
        }
        if (d.x - i >= 0 && w[d.x - i][d.y][i] == (char) 0)
        {
          w[d.x - i][d.y][i] = 'W';
          q2.add(new Double(d.x - i, d.y));
        }
        if (d.y + i <= 400 && w[d.x][d.y + i][i] == (char) 0)
        {
          w[d.x][d.y + i][i] = 'N';
          q2.add(new Double(d.x, d.y + i));
        }
        if (d.y - i >= 0 && w[d.x][d.y - i][i] == (char) 0)
        {
          w[d.x][d.y - i][i] = 'S';
          q2.add(new Double(d.x, d.y - i));
        }
      }
      q1 = q2;
    }
  }

  String recall(int x, int y)
  {
    StringBuffer sb = new StringBuffer();
    for (int i = 1; i <= MAX_MOVE; i++)
      if (w[x][y][i] != (char) 0)
      {
        while (i > 0)
        {
          sb = sb.append(w[x][y][i]);
          if (w[x][y][i] == 'N') y -= i;
          else if (w[x][y][i] == 'S') y += i;
          else if (w[x][y][i] == 'E') x -= i;
          else if (w[x][y][i] == 'W') x += i;
          else
          {
            System.err.println("Blah!");
            System.exit(1);
          }
          i--;
        }
        break;
      }
    return sb.reverse().toString();
  }
}
