import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

import com.google.common.base.Charsets;
import com.google.common.base.Predicate;
import com.google.common.collect.ArrayListMultimap;
import com.google.common.collect.Collections2;
import com.google.common.collect.HashMultimap;
import com.google.common.collect.Lists;
import com.google.common.collect.Multimap;
import com.google.common.collect.Sets;
import com.google.common.io.Files;

public class Main {
  
  public static class Point implements Comparable<Point>{
    public Point(double x, double y) {
      super();
      this.x = x;
      this.y = y;
      this.di = Math.sqrt(x * x + y * y);
    }
    double x;
    double y;
    double di;

    @Override
    public int compareTo(Point o) {
      if (di > o.di) {
        return 1;
      } else if (di < o.di)  {
        return -1; 
      } else {
        return 0;
      }
    }
  }

  public static void main(String[] args) throws IOException {

    File f = new File("D-small-attempt0.in");
//    File f = new File("C-small-attempt1.in");
//    File f = new File("C-small-attempt2.in");
//    File f = new File("C-large.in");
//    File f = new File("B-large.in");
//    File f = new File("A-large-practice.in");
//    File f = new File("example.in");
//    File f = new File("test.in");
    List<String> lines = Files.readLines(f, Charsets.UTF_8);
//
    int cases = Integer.valueOf(lines.get(0));
    int c = 0;
    int line = 1;
    while (c++ < cases) {
      String[] tokens = lines.get(line++).split(" ");
      int h = Integer.valueOf(tokens[0]);
      int w = Integer.valueOf(tokens[1]);
      int d = Integer.valueOf(tokens[2]);

      int x = -1, y = -1;
      
      line++;
      for (int i = 1; i < h - 1; i++) {
        String s = lines.get(line++);
        for (int k = 1; k < w; k++) {
          if (s.charAt(k) == 'X') {
            assert x == -1;
            assert y == -1;
            x = k;
            y = i;
          }
        }
      }
      line++;
      assert x > 0;
      assert y > 0;
      
      double du = y - 0.5;
      double dr = w - x - 1.5;
      double db = h - y - 1.5;
      double dl = x - 0.5;
//      System.out.printf("%d, %d\n", x, y);
//      System.out.printf("%d, %3.1f, %3.1f, %3.1f, %3.1f\n", d, du, dr, db, dl);
      int result = solve(d, du, dr, db, dl);
      System.out.println("Case #" + c + ": " + result);
    }
//    solve(50, 9.5, 12.5, 20.5, 17.5);
//    solve(2, 0.5, 0.5, 0.5, 0.5);
//    int r = solve(8, 0.5, 0.5, 1.5, 0.5);
//    System.out.println(r);
  }
  
  public static int solve(int di, double du, double dr, double db, double dl) {
    
    Point[][] m = new Point[2*di+1][2*di+1];
    m[di][di] = new Point(0, 0);
    
    { // fill up
      double p = 0, c = du, n = db, t;
      for (int i = di - 1; i >= 0; i--) {
        p = p + c;
        t = c; c = n; n = t;
        double y = -2*p;
        m[i][di] = new Point(0,y);
      }
    }
    
    { // fill down
      double p = 0, c = db, n = du, t;
      for (int i = di + 1; i < 2*di + 1; i++) {
        p = p + c;
        t = c; c = n; n = t;
        double y = 2*p;
        m[i][di] = new Point(0,y);
      }
    }
    
    { // fill right
      double p = 0, c = dr, n = dl, t;
      for (int i = di + 1; i < 2*di + 1; i++) {
        p = p + c;
        t = c; c = n; n = t;
        double x = 2 * p;
        m[di][i] = new Point(x,0);
        for (int k = 0; k < 2*di + 1; k++) {
          double y = m[k][di].y; 
          m[k][i] = new Point(x,y);
        }
      }
    }
    
    { // fill left
      double p = 0, c = dl, n = dr, t;
      for (int i = di - 1; i >= 0; i--) {
        p = p + c;
        t = c; c = n; n = t;
        double x = -2 * p;
        m[di][i] = new Point(x,0);
        for (int k = 0; k < 2*di + 1; k++) {
          double y = m[k][di].y; 
          m[k][i] = new Point(x,y);
        }
      }
    }
    
    List<Point> list = Lists.newArrayListWithExpectedSize((di + 1) * (di + 1));
    for (int i = 0; i < 2*di + 1; i++) {
      for (int k = 0; k < 2*di + 1; k++) {
//        System.out.printf("(%6.1f, %6.1f) ", m[i][k].x, m[i][k].y);
        list.add(m[i][k]);
      }
//      System.out.println();
    }
    Collections.sort(list);

    for (Point p : list) {
//      System.out.printf("(%6.1f, %6.1f) %6.1f\n", p.x, p.y, p.di);
    }
//    System.out.println("===");
    
    List<Point> reflections = Lists.newArrayList();
    for (Point p : list) {
      if (p.di - di > 0 
          || isObstructed(reflections, p)
          || p.di == 0 ) continue;
      
      reflections.add(p);
    }
    for (Point p : reflections) {
//      System.out.printf("(%6.1f, %6.1f) %7.2f\n", p.x, p.y, p.di);
    }
    return reflections.size();
    
  }

  private static boolean isObstructed(List<Point> reflections, Point p) {
    for (Point e : reflections) {
      if (Math.signum(e.x) != Math.signum(p.x)
          || Math.signum(e.y) != Math.signum(p.y)) {
        continue;
      }
      
      if (isCollinear(e, p)) {
        return true;
      }
    }
    return false;
  }
  
  private static boolean isCollinear(Point p1, Point p2)  {
    return (p1.y - p2.y) * (p1.x - (2* p1.x)) == (p1.y - (2 * p1.y)) * (p1.x - p2.x);
  }

}