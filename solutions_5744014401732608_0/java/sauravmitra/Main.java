import java.util.Scanner;

public class Main {
  public static void solveSlides(int b, int m, int i, short[][] slides) {
    int mask = 1;
    int nextSolveIndex = -1;
    int nextSolveMask = mask;
    if (m == (1 << (b - i - 2))) {
      slides[i][slides.length-1] = 1;
      m--;
    }
    for (int j = slides.length - 2; j >= i; j--) {
      if ((m & mask) != 0) {
        if (j == i) {
          slides[i][slides.length-1] = 1;
        } else {
          slides[i][j] = 1;
          nextSolveIndex = j;
          nextSolveMask = mask;
        }
      }
      mask = mask << 1;
    }
    if (nextSolveIndex != -1) {
      solveSlides(b, nextSolveMask, nextSolveIndex, slides);
    }
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = Integer.parseInt(sc.next());
    for (int i = 1; i <= t; i++) {
      int b = sc.nextInt();
      int m = sc.nextInt();
      String res = "POSSIBLE";
      short[][] mat = null; 
      if (m > (1 << (b-2))) {
        res = "IM" + res;
      } else {
        mat = new short[b][b];
        solveSlides(b, m, 0, mat);
      }
      System.out.println("Case #" + i + ": " + res);
      if (mat != null) {
        for (short[] row: mat) {
          for (short val: row) {
            System.out.print(val);
          }
          System.out.println();
        }
      }
    }
  }
}
