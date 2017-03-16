import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * @author Max Loewenthal
 */
public class B {


  int H;
  int N;
  int M;

  boolean[][] startable;
  int[][] timeReachable;

  int[][] C;
  int[][] F;
  public void solve(Scanner input, StringBuilder buffer) {
    H = input.nextInt();
    N = input.nextInt();
    M = input.nextInt();

    C = new int[N][M];
    F = new int[N][M];

    startable = new boolean[N][M];
    timeReachable = new int[N][M];

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        C[i][j] = input.nextInt();
        startable[i][j] = false;
        timeReachable[i][j] = -1;
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        F[i][j] = input.nextInt();
      }
    }


    startable[0][0] = true;

    determineStartables();
    determinePaths();

    buffer.append(String.format("%.1f", (double) timeReachable[N-1][M-1] / 10));
  }

  private void determinePaths() {
    forAllSquares(new SquareAction() {
      public void doiIt(int x, int y) {
        if (startable[x][y]) {
          reached(x,y,0);
        }
      }
    });
  }

  private void reached(int x, int y, final int time) {
    if (timeReachable[x][y] == -1 ||
        timeReachable[x][y] > time) {
      timeReachable[x][y] = time;
      forAllDirections(x, y, new MoveAction() {
        public void doiIt(int x1, int y1, int x2, int y2) {
          MoveCosts costs = determineMoveCosts(x1, y1, x2, y2);

          if (costs.possibleEver) {
            int moveTime = Math.max(time, costs.startingTime);

            if (moveTime > costs.slowTime) {
              reached(x2, y2, moveTime + 100);
            }
            else {
              reached(x2, y2, moveTime + 10);
            }
          }
        }
      });
    }
  }

  private void determineStartables() {
    determineStartable(0, 0);
  }

  private interface SquareAction {
    public void doiIt(int x, int y);
  }

  private interface MoveAction {
    public void doiIt(int x1, int y1, int x2, int y2);
  }

  private void forAllSquares(SquareAction action) {
    for (int x = 0; x < N; x++) {
      for (int y = 0; y < M; y++) {
        action.doiIt(x, y);

      }
    }
  }

  private void forAllDirections(int x, int y, MoveAction action) {
    if (testBounds(x + 1, y)) {
      action.doiIt(x, y, x+1, y);
    }
    if (testBounds(x - 1, y)) {
      action.doiIt(x, y, x-1, y);
    }
    if (testBounds(x , y + 1)) {
      action.doiIt(x, y, x, y+1);
    }
    if (testBounds(x , y - 1)) {
      action.doiIt(x, y, x, y-1);
    }
  }

  private void determineStartable(int x, int y) {
    forAllDirections(x,y, new MoveAction() {
      public void doiIt(int x1, int y1, int x2, int y2) {
        if (!startable[x2][y2]) {
          MoveCosts costs = determineMoveCosts(x1, y1, x2, y2);
          if (costs.possibleAtStart) {
            startable[x2][y2] = true;
            determineStartable(x2, y2);
          }
        }
      }
    });
  }

  private class MoveCosts {
    boolean possibleEver = false;
    boolean possibleAtStart= false;
    int startingTime;
    int slowTime;
  }

  private boolean testBounds(int x, int y) {
    return x>=0 && x < N && y >= 0 && y<M;
  }
  private MoveCosts determineMoveCosts(int x1, int y1, int x2, int y2) {
    MoveCosts result = new MoveCosts();

    if (testBounds(x1, y1) && testBounds(x2,y2)) {
      int floorLimit = C[x2][y2] - 50;
//The water level, the floor height of your current square, and the floor height of the adjacent square must all be at least 50 centimeters lower than the ceiling height of
      result.possibleEver = floorLimit >= F[x1][y1] && floorLimit>=F[x2][y2];
      result.possibleEver = result.possibleEver && F[x2][y2] <= C[x1][y1] - 50;

      //The floor height of the adjacent square must be at least 50 centimeters below the ceiling height of your current square as well.

      if (result.possibleEver) {
        result.startingTime = Math.max(H - floorLimit, 0);
        result.slowTime = Math.max(0, H - F[x1][y1] - 20);
        result.possibleAtStart = result.startingTime == 0;
      }
    }

    return result;
  }

  public static void main(String[] args) {
    try {
      InputStream input = System.in;
      OutputStream output = System.out;

      if (args.length > 0) {
        input = new FileInputStream(new File(args[0]));
      }

      if (args.length > 1) {
        File outputFile = new File(args[1]);

        if (outputFile.exists()) {
          throw new Exception("Output file already exists");
        }

        output = new FileOutputStream(new File(args[1]));
      }

      Scanner scanner = new Scanner(input);
      PrintWriter writer = new PrintWriter(output);

      B a = new B();

      int count = scanner.nextInt();
      scanner.nextLine();

      for (int i = 0; i < count; i++) {
        StringBuilder result = new StringBuilder();
        a.solve(scanner, result);


        writer.println("Case #" + (i + 1) + ": " + result.toString());
      }

      writer.close();
    }
    catch (Exception e) {
      e.printStackTrace();
    }
  }
}
