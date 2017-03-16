import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/*
 * Google Code Jam 2013
 * Qualification Round 2013
 * raguenets@gmail.com
 * Usage : java Lawnmower inputFileName outputFileName
 */
public class Lawnmower {
  /**
   * @param args
   */
  public static void main(String[] args) {
    int T = 0;
    int N = 0;
    int M = 0;
    if (args.length == 2) {
      String inputFilename = args[0];
      File finput = new File(inputFilename);
      String outputFilename = args[1];
      File foutput = new File(outputFilename);
      Scanner scanner = null;
      BufferedWriter bw = null;
      try {
        bw = new BufferedWriter(new FileWriter(foutput));
      }
      catch (IOException e1) {
        e1.printStackTrace();
      }
      if (finput.exists()) {
        try {
          scanner = new Scanner(finput);
          // Reads first line : number of Tests
          if (scanner.hasNextInt()) {
            T = scanner.nextInt();
          }
          for (int k = 0; k < T; k++) {
            if (scanner.hasNextInt()) {
              N = scanner.nextInt();
            }
            if (scanner.hasNextInt()) {
              M = scanner.nextInt();
            }
            int[][] grid = new int[N][M];
            for (int i = 0; i < N; i++) {
              // Read grid
              for (int j = 0; j < M; j++) {
                if (scanner.hasNextInt()) {
                  grid[i][j] = scanner.nextInt();
                }
              }
            }
            String result = checkConfiguration(N, M, grid);
            bw.write("Case #" + (k + 1) + ": " + result + "\n");
          }
        }
        catch (FileNotFoundException e) {
          // TODO Auto-generated catch block
          e.printStackTrace();
        }
        catch (IOException e) {
          // TODO Auto-generated catch block
          e.printStackTrace();
        }
        finally {
          try {
            bw.close();
            if (scanner != null) {
              scanner.close();
            }
          }
          catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
          }
        }
      }
    }

  }

  private static String checkConfiguration(int N, int M, int[][] grid) {
    // Max
    int[] colMax = new int[M];
    int[] lineMax = new int[N];
    for (int col = 0; col < M; col++) {
      int max = -1;
      for (int row = 0; row < N; row++) {
        if (grid[row][col] > max) {
          max = grid[row][col];
        }
      }
      colMax[col] = max;
    }
    for (int row = 0; row < N; row++) {
      int max = -1;
      for (int col = 0; col < M; col++) {
        if (grid[row][col] > max) {
          max = grid[row][col];
        }
      }
      lineMax[row] = max;
    }

    for (int row = 0; row < N; row++) {
      for (int col = 0; col < M; col++) {
        if (grid[row][col] != lineMax[row] && grid[row][col] != colMax[col]) { return "NO"; }
      }
    }
    return "YES";
  }

}
