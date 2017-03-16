package codejam;

import java.io.File;
import java.io.FileWriter;
import java.io.Writer;
import java.util.Scanner;

public class Lawnmover {

  private static String getResultString(int caseNo, boolean result) {
    return "Case #" + caseNo + ": " + (result == true ? "YES" : "NO");
  }

  private static boolean checkMap(int[][] map, int row, int col) {
    for (int i = 0; i < map.length; i++) {
      for (int j = 0; j < map[0].length; j++) {
        if (false == checkCell(map, row, col, i, j)) {
          return false;
        }

      }
    }
    return true;
  }

  private static boolean checkCell(int[][] map, int row, int col, int curRow, int curCol) {
    // for each cell, all elements in the row OR the column containing it must be equal or smaller
    // than cell value.
    int cur = map[curRow][curCol];
    int i, j;
    for (j = 0; j < col; j++) {
      if (map[curRow][j] > cur) {
        break;
      }
    }
    if (j == col) return true;

    for (i = 0; i < row; i++) {
      if (map[i][curCol] > cur) {
        break;
      }
    }
    if (i == row) return true;

    return false;
  }

  public static void main(String[] args) throws Exception {
    String file = "D:\\B-small-attempt0.in";
    Scanner cin = new Scanner(new File(file));
    Writer writer = new FileWriter(new File("D:\\t3-out.dat"));
    int n = Integer.parseInt(cin.nextLine());
    for (int caseNum = 1; caseNum <= n; caseNum++) {
      int row = cin.nextInt(), col = cin.nextInt();
      int[][] map = new int[row][col];
      for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
          map[i][j] = cin.nextInt();
        }
      }
      boolean result = checkMap(map, row, col);
      writer.append(getResultString(caseNum, result) + "\n");
    }
    writer.close();
    cin.close();
    System.out.println("Finished.");
  }

}
