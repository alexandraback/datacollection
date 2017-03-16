import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class FallingDiamonds implements Runnable {

  P nextLeft(P p) {
    if (p.x == 0) {
      return new P(-p.y - 2, 0);
    } else {
      return new P(p.x + 1, p.y + 1);
    }
  }

  P nextRight(P p) {
    if (p.x == 0) {
      return new P(p.y + 2, 0);
    } else {
      return new P(p.x - 1, p.y + 1);
    }
  }

  boolean[] can(P p1, P p2) {
    if (p1.x == 0) {
      if (p2.x == 0) {
        return new boolean[]{true, true};
      } else {
        return new boolean[]{false, true};
      }
    } else {
      if (p2.x == 0) {
        return new boolean[]{true, false};
      } else {
        return new boolean[]{true, true};
      }
    }
  }

  @Override
  public void run() {
    try {
      Scanner in = new Scanner(new File("b1.in"));
      PrintWriter out = new PrintWriter("b1.out");

      int testNum = in.nextInt();

      for (int test = 1; test <= testNum; test++) {
        int n = in.nextInt();
        int x = in.nextInt();
        int y = in.nextInt();

        if (x == 0 && y == 0) {
          out.println("Case #" + test + ": " + 1.0);
          continue;
        }

        HashMap<PP, Double> r = new HashMap<PP, Double>();
        r.put(new PP(new P(0, 0), new P(0, 0)), 1.0);
        double res = 0;

        for (int i = 1; i < n; i++) {
          HashMap<PP, Double> newR = new HashMap<PP, Double>();
          for (PP pp: r.keySet()) {
            double cc = r.get(pp);
            P nl = nextLeft(pp.left);
            P nr = nextRight(pp.right);

            boolean[] b = can(nl, nr);

            if (b[0]) {
              double c = b[1] ? 0.5 : 1;
              c = c * cc;
              if (nl.x == x && nl.y == y) {
                res = res + c;
              } else {
                PP lp = new PP(nl, pp.right);
                if (nl.x == 0) {
                  lp = new PP(nl, nl);
                }
                if (!newR.containsKey(lp)) {
                  newR.put(lp, 0.0);
                }
                newR.put(lp, newR.get(lp) + c);
              }
            }

            if (b[1]) {
              double c = b[0] ? 0.5 : 1;
              c = c * cc;
              if (nr.x == x && nr.y == y) {
                res = res + c;
              } else {
                PP rp = new PP(pp.left, nr);
                if (nr.x == 0) {
                  rp = new PP(nr, nr);
                }
                if (!newR.containsKey(rp)) {
                  newR.put(rp, 0.0);
                }
                newR.put(rp, newR.get(rp) + c);
              }
            }

          }

          r = newR;
//          System.out.println("\nnum = " + (i + 1) + "\n");
//          for(PP pp: newR.keySet()) {
//            System.out.println(pp + ": " + newR.get(pp));
//          }
        }
        out.println("Case #" + test + ": " + res);
      }
      out.close();

    } catch (Exception e) {
      throw new RuntimeException(e);
    }
  }

  public static void main(String[] args) {
    new Thread(new FallingDiamonds()).start();
  }

  class P {
    int x;
    int y;

    P(int x, int y) {
      this.x = x;
      this.y = y;
    }

    @Override
    public boolean equals(Object o) {
      if (this == o) return true;
      if (!(o instanceof P)) return false;

      P p = (P) o;

      if (x != p.x) return false;
      if (y != p.y) return false;

      return true;
    }

    @Override
    public int hashCode() {
      int result = x;
      result = 31 * result + y;
      return result;
    }

    @Override
    public String toString() {
      return "{" +
          "x=" + x +
          ", y=" + y +
          '}';
    }
  }

  class PP {
    P left;
    P right;

    PP(P left, P right) {
      this.left = left;
      this.right = right;
    }

    @Override
    public boolean equals(Object o) {
      if (this == o) return true;
      if (!(o instanceof PP)) return false;

      PP pp = (PP) o;

      if (!left.equals(pp.left)) return false;
      if (!right.equals(pp.right)) return false;

      return true;
    }

    @Override
    public int hashCode() {
      int result = left.hashCode();
      result = 31 * result + right.hashCode();
      return result;
    }

    @Override
    public String toString() {
      return "PP{" +
          "left=" + left +
          ", right=" + right +
          '}';
    }
  }
}
