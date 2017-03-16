import java.util.*;

public class Mow {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int numTests = in.nextInt();
    StringBuilder output = new StringBuilder();
    for (int testNum = 1; testNum <= numTests; ++testNum) {
      output.append(String.format("Case #%d: ", testNum));
      int rows = in.nextInt();
      int cols = in.nextInt();
      int[][] pattern = new int[rows][cols];
      for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
          pattern[r][c] = in.nextInt();
        }
      }
      int[] rowMax = new int[rows];
      for (int r = 0; r < rows; ++r) {
        int max = 0;
        for (int c = 0; c < cols; ++c) {
          max = Math.max(max, pattern[r][c]);
        }
        rowMax[r] = max;
      }
      
      int[] colMax = new int[cols];
      for (int c = 0; c < cols; ++c) {
        int max = 0;
        for (int r = 0; r < rows; ++r) {
          max = Math.max(max, pattern[r][c]);
        }
        colMax[c] = max;
      }
      // check expected pattern against desired pattern
      boolean okay = true;
      for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
          int expected = Math.min(rowMax[r], colMax[c]);
          if (expected != pattern[r][c])
            okay = false;
        }
      }
      if (okay) {
        output.append("YES\n");
      } else {
        output.append("NO\n");
      }
    }
    System.out.print(output);
  }
}