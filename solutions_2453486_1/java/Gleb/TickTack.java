import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class TickTack implements Runnable {
  boolean check(String[] g, int x, int y, int dx, int dy, char c) {
    for (int i = 0; i < 4; i++) {
      char cur = g[x + i * dx].charAt(y + i * dy);
      if (cur != 'T' && cur != c) return false;
    }
    return true;
  }

  boolean win(String[] g, char c) {
    for(int i = 0; i < 4; i++) {
      if (check(g, i, 0, 0, 1, c)) return true;
      if (check(g, 0, i, 1, 0, c)) return true;
    }
    return check(g, 0, 0, 1, 1, c) || check(g, 3, 0, -1, 1, c);
  }

  @Override
  public void run() {
    try {
      Scanner in = new Scanner(new File("tick.in"));
      PrintWriter out = new PrintWriter("tick.out");

      int tests = in.nextInt();

      for (int test = 1; test <= tests; test++) {
        in.nextLine();
        String[] g = new String[4];
        for (int i = 0; i < 4; i++) {
          g[i] = in.nextLine();
        }

        boolean f = true;
        for (int i = 0; i < 4; i++) {
          if (g[i].contains(".")) f = false;
        }

        out.print("Case #" + test + ": ");
        if (win(g, 'X')) {
          out.println("X won");
        } else if (win(g, 'O')) {
          out.println("O won");
        } else if (f) {
          out.println("Draw");
        } else {
          out.println("Game has not completed");
        }
      }

      out.close();
    } catch (Exception e) {
      throw new RuntimeException(e);
    }
  }

  public static void main(String[] args) {
    new Thread(new TickTack()).start();
  }
}
