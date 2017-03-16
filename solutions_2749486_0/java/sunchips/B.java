package round1c;

import java.awt.Point;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Comparator;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class B {
  public static void main(String[] args) throws Exception, IOException {
    String round = "round1c";
    String question = "B";
    String type = "small";
    String attempt = "2";
    boolean practice = false;

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    if (practice) {
      out = new PrintWriter(new FileWriter(round + "/" + question + "-" + type + "-practice.out"));
      br = new BufferedReader(new FileReader(round + "/" + question + "-" + type + "-practice.in"));
    } else {
      if (type.equals("small")) {
        out = new PrintWriter(new FileWriter(round + "/" + question + "-" + type + "-attempt" + attempt + ".out"));
        br = new BufferedReader(new FileReader(round + "/" + question + "-" + type + "-attempt" + attempt + ".in"));
      } else {
        out = new PrintWriter(new FileWriter(round + "/" + question + "-" + type + ".out"));
        br = new BufferedReader(new FileReader(round + "/" + question + "-" + type + ".in"));
      }
    }

    int cases = Integer.parseInt(br.readLine());
    for (int zz = 1; zz <= cases; zz++) {
      System.err.println(zz);
      st = new StringTokenizer(br.readLine().trim());
      final Point goal = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
      Point start = new Point(0, 0);

      StringBuilder ans = new StringBuilder();

      // Go E/W
      int val = 1;
      int dir = -1;
      if (start.x < goal.x) {
        dir = 1;
      }
      while (start.x != goal.x) {
        // left/right
        start.translate(dir, 0);
        if (dir == 1)
          ans.append("WE");
        else
          ans.append("EW");
        val += 2;
        out.flush();
      }

      // Go N/S
      dir = -1;
      if (start.y < goal.y)
        dir = 1;
      while (start.y != goal.y) {
        start.translate(0, dir);
        if (dir == 1)
          ans.append("SN");
        else
          ans.append("NS");
        val += 2;
        out.flush();
      }
      if (ans.length() >= 500) {
        System.err.println("ERRRRRRRRRRRRROR");
      }
      out.println("Case #" + zz + ": " + ans.toString());
      out.flush();
    }
    out.close();
    br.close();
  }

  private static class Path {
    Point p;
    String path;
    int val;

    public Path(Point p) {
      this.p = p;
      this.path = "";
      this.val = 1;
    }

    public Path(Point p, String sb, String c, int val) {
      this.p = p;
      this.path = sb + c;
      this.val = val + 1;
    }
  }
}
