import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.StringTokenizer;
import java.io.ByteArrayOutputStream;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author abra
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		MinesweeperMaster solver = new MinesweeperMaster();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class MinesweeperMaster extends SavingChelperSolution {

  private void fill(boolean[][] array, int n, int m, int takeDown, int takeRight) {
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        array[i][j] = true;
      }
    }
    for (int i = 0; i < takeDown; i++) {
      array[n + 1][i] = true;
    }
    for (int i = 0; i < takeRight; i++) {
      array[i][m + 1] = true;
    }
  }

  public void solve() {
    int n = in.nextInt();
    int m = in.nextInt();
    int minesCount = in.nextInt();

    int freeCount = n * m - minesCount;

    out.println();
//    out.println(n + " " + m + " " + minesCount + " " + freeCount);

    boolean[][] mines = new boolean[n][m];
    boolean ok = false;

    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        int left = freeCount - (i + 1) * (j + 1);

        int takeDown = 0;
        int takeRight = 0;

        for (int ii = 2; ii <= i; ii++) {
          for (int jj = 2; jj <= j; jj++) {
            if (i != n - 1 && j != m - 1 && left == ii + jj) {
              takeDown = jj;
              takeRight = ii;
              left = 0;
            }
          }
        }

        if (i != n - 1 && left > 1 && left <= j) {
          takeDown = left;
          left = 0;
        }
        if (j != m - 1 && left > 1 && left <= i) {
          takeRight = left;
          left = 0;
        }

        if (left != 0) {
          continue;
        }


        ok = true;
        fill(mines, i, j, takeDown, takeRight);
        i = n;
        break;
      }
    }

    if (!ok && freeCount == 1) {
      ok = true;
      fill(mines, 0, 0, 0, 0);
    }
    if (!ok && n == 1) {
      ok = true;
      fill(mines, 0, freeCount - 1, 0, 0);
    }
    if (!ok && m == 1) {
      ok = true;
      fill(mines, freeCount - 1, 0, 0, 0);
    }


    if (!ok) {
      out.println("Impossible");
    } else {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (i == 0 && j == 0) {
            out.print('c');
            continue;
          }
          if (mines[i][j]) {
            out.print('.');
          } else {
            out.print('*');
          }
        }
        out.println();
      }
    }
  }
}

abstract class SavingChelperSolution {

  public InputReader in;
  public OutputWriter out;

  private OutputWriter toFile;

  public SavingChelperSolution() {
    try {
      toFile = new OutputWriter("gcj-output.txt");
    } catch (FileNotFoundException e) {
      throw new RuntimeException(e);
    }
  }

  public abstract void solve();

  public void solve(int testNumber, InputReader in, OutputWriter out) {

    ByteArrayOutputStream saved = new ByteArrayOutputStream();

    OutputWriter savingOut = new OutputWriter(saved);

    this.in = in;
    this.out = savingOut;

    solve();
    savingOut.flush();

    String result = "Case #" + testNumber + ": " + saved.toString();
    if (!result.endsWith("\n")) {
      result += "\n";
    }

    out.write(result);
    out.flush();
    toFile.write(result);
    toFile.flush();
  }

}

class InputReader {

  BufferedReader br;
  StringTokenizer in;

  public InputReader(String fileName) {
    try {
      br = new BufferedReader(new FileReader(fileName));
    } catch (IOException e) {
      throw new RuntimeException(e);
    }
  }

  public InputReader(InputStream inputStream) {
    br = new BufferedReader(new InputStreamReader(inputStream));
  }

  boolean hasMoreTokens() {
    while (in == null || !in.hasMoreTokens()) {
      String s = nextLine();
      if (s == null) {
        return false;
      }
      in = new StringTokenizer(s);
    }
    return true;
  }

  public String nextString() {
    return hasMoreTokens() ? in.nextToken() : null;
  }

  public String nextLine() {
    try {
      in = null; // riad legacy
      return br.readLine();
    } catch (Exception e) {
      e.printStackTrace();
      return null;
    }
  }

  public int nextInt() {
    return Integer.parseInt(nextString());
  }

  public String next() {
    return nextString();
  }
}

class OutputWriter extends PrintWriter {

  public OutputWriter(String fileName) throws FileNotFoundException {
    super(fileName);
  }

  public OutputWriter(OutputStream outputStream) {
    super(outputStream);
  }

  public OutputWriter(Writer writer) {
    super(writer);
  }

}

