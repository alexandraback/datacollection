import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader in = new BufferedReader(new FileReader("A-small-attempt0.in"));
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A-small-attempt0.out")));
    Solver solver = new Solver();
    solver.solve(in, out);
    in.close();
    out.close();
  }
}

class Solver {

  public void solve(BufferedReader in, PrintWriter out) throws IOException {
    int ntest = Integer.parseInt(in.readLine());
    String[] t = new String[4];
    for (int itest = 0; itest < ntest; itest++) {
      boolean hasDots = false;
      boolean oWin = false;
      boolean xWin = false;
      for (int j = 0; j < 4; j++) {
        t[j] = in.readLine();
        hasDots |= t[j].contains(".");
        oWin |= (!t[j].contains(".") && !t[j].contains("X"));
        xWin |= (!t[j].contains(".") && !t[j].contains("O"));
      }
      for (int j = 0; j < 4; j++) {
        oWin |= isWin(t, j, 'O');
        xWin |= isWin(t, j, 'X');
      }
      boolean x = true;
      boolean o = true;
      for (int i = 0; i < 4; i++) {
        x &= (t[i].charAt(i) != '.' && t[i].charAt(i) != 'O');
        o &= (t[i].charAt(i) != '.' && t[i].charAt(i) != 'X');
      }

      boolean x1 = true;
      boolean o1 = true;
      for (int i = 0; i < 4; i++) {
        x1 &= (t[i].charAt(3 - i) != '.' && t[i].charAt(3 - i) != 'O');
        o1 &= (t[i].charAt(3 - i) != '.' && t[i].charAt(3 - i) != 'X');
      }

      xWin |= (x1 || x);
      oWin |= (o1 || o);

      out.print(String.format("Case #%d: ", itest + 1));
      if (xWin)
        out.println("X won");
      else if (oWin)
        out.println("O won");
      else if (hasDots)
        out.println("Game has not completed");
      else
        out.println("Draw");
      in.readLine();
    }
  }

  private boolean isWin(String[] t, int j, char c) {
    if (c == 'X') {
      c = 'O';
    } else {
      c = 'X';
    }
    boolean res = true;
    for (int i = 0; i < 4; i++) {
      res &= (t[i].charAt(j) != '.' && t[i].charAt(j) != c);
    }
    return res;
  }


}
