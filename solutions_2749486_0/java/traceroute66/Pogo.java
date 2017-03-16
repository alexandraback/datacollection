import java.util.*;

public class Pogo {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();

    for (int i = 1; i <= n; i++)
      System.out.println("Case #" + i + ": " + new Pogo().solve(sc.nextInt(), sc.nextInt()));
  }

  public String solve(int x, int y) {
    StringBuilder dirs = new StringBuilder();

    Set<Point> visited = new HashSet<Point>();
    Queue<Point> q = new LinkedList<Point>();
    q.add(new Point(0, 0, "", 1));

    while (!q.isEmpty()) {
      Point p = q.poll();

      //System.out.println("X: " + p.x + ", Y: " + p.y + ": " + p.depth);

      if (p.x == x && p.y == y)
        return p.dirs;

      Point p1 = new Point(p.x - p.depth, p.y, p.dirs + "W", p.depth + 1);
      Point p2 = new Point(p.x + p.depth, p.y, p.dirs + "E", p.depth + 1);
      Point p3 = new Point(p.x, p.y + p.depth, p.dirs + "N", p.depth + 1);
      Point p4 = new Point(p.x, p.y - p.depth, p.dirs + "S", p.depth + 1);

      if (visited.add(p1))
        q.add(p1);
      if (visited.add(p2))
        q.add(p2);
      if (visited.add(p3))
        q.add(p3);
      if (visited.add(p4))
        q.add(p4);
    }

    throw new RuntimeException("Will never get here.");
  }

  class Point {
    int x;
    int y;
    String dirs;
    int depth;

    public Point(int x, int y, String dirs, int depth) {
      this.x = x;
      this.y = y;
      this.dirs = dirs;
      this.depth = depth;
    }

    @Override
    public boolean equals(Object o) {
      Point p = (Point)o;
      return x == p.x && y == p.y && depth == p.depth;
    }

    @Override
    public int hashCode() {
      int result = 17;
      result += 31 * x;
      result += 31 * y;
      result += 31 * depth;
      return result;
    }
  }
}
