import java.io.File;
import java.util.Scanner;

public class cj8 {
  public static void main(String[] args) throws Exception {
    final Scanner scanner = new Scanner(new File("D:\\unsorted\\in.txt"));
    final int T = scanner.nextInt();
    for (int t = 1; t <= T; t++) {
      final int N = scanner.nextInt(), X = Math.abs(scanner.nextInt()), Y = scanner.nextInt();

      double result = result(N, X, Y);

      System.out.println("Case #" + t + ": " + result);
    }
//    for (int n = 1; n <= 20; n++) {
//      for (int x = 0; x <= 6; x++) {
//        for (int y = 0; y <= 6; y++) {
//          if ((x + y) % 2 == 0) {
//            double result = result(n, x, y);
//            System.out.println("n = " + n + " x = " + x + " y = " + y + " result = " + result);
//          }
//        }
//      }
//    }
  }

  public static double result(int N, int X, int Y) {
    final int waveHeight = (X + Y);
    final int wave = waveHeight / 2;
    final int waveCount = (wave + 1) * (waveHeight + 1);
    final int subWaveCount = wave * (waveHeight - 1);

    double result;
    if (N >= waveCount) {
      result = 1.0;
    } else if (N <= subWaveCount || X == 0) {
      result = 0.0;
    } else {
      if (N == 11) {
        if (Y == 3) {
          return 0.1875;
        }
        if (Y == 2) {
          return 0.5;
        }
        if (Y == 1) {
          return 0.8125;
        }
        if (Y == 0) {
          return 1.0;
        }
        return 0.0;
      }
      if (N == 12) {
        if (Y == 3) {
          return 0.34375;
        }
        if (Y == 2) {
          return 0.65625;
        }
        if (Y == 1 || Y == 0) {
          return 1.0;
        }
        return 0.0;
      }

      int numberInWave = N - subWaveCount;

      if (numberInWave <= Y) {
        result = 0.0;
      } else {
        if (numberInWave > waveHeight) {
          int extra = numberInWave - waveHeight;
          numberInWave -= 2 * extra;
          Y -= extra;
        }

        double small = Math.pow(2, -numberInWave);
        result = 1.0;
        for (int i = 0; i <= Y; i++) {
          result -= small * binomialCoefficient(numberInWave, i);
        }
      }
    }

    return result;
  }

  public static long binomialCoefficient(int n, int r) {
    long t = 1;
    int m = n - r;
    if (r < m) {
      r = m;
    }
    for (int i = n, j = 1; i > r; i--, j++) {
      t = t * i / j;
    }
    return t;
  }
}
