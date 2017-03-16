package codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Problem3 {

  private int x = 0;
  private int y = 0;
  private int zeroes = 0;
  private int mines = 0;
  private Set<int[][]> cache = new HashSet<int[][]>();

  public static void main(String[] args) throws FileNotFoundException {
    Problem3 problem3 = new Problem3();
    problem3.solve();
  }

  public static int[][] deepCopy(int[][] original) {
    if (original == null) {
      return null;
    }

    final int[][] result = new int[original.length][];
    for (int i = 0; i < original.length; i++) {
      result[i] = Arrays.copyOf(original[i], original[i].length);
    }
    return result;
  }

  private void solve() throws FileNotFoundException {
    String fileName = Problem1.class.getResource("/input3.txt").getPath();

    File problemFile = new File(fileName);

    Scanner scanner = new Scanner(problemFile);
    int cases = scanner.nextInt();

    for (int i = 0; i < cases; i++) {
      cache = new HashSet<int[][]>();
      y = scanner.nextInt();
      x = scanner.nextInt();
      int m = scanner.nextInt();
      mines = m;

      int[][] field = new int[x][y];

      System.out.println("Case #" + (i + 1) + ": ");

      if (m == 0) {
        printSolution(field);
      } else if (setField(field, m, 0, 0) != 1) {
        System.out.println("Impossible");
      }
    }
  }

  private int setField(int[][] field, int m, int sX, int sY) {
//    if (m != 0 && (x * y - ((sX + 1) * (sY + 1))) < m) {
    //cache.add(field);
//      return -1;
//    }

    if (m == 0) {
      int[][] clone = deepCopy(field);
      if (checkSolution(clone)) {
        printSolution(clone);
        return 1;
      }
//      cache.add(field);
      return -1;
    }

    if (cache.contains(field)) {
      return -1;
    }

    for (int j = 0; j < x; j++) {
      for (int k = 0; k < y; k++) {
        if (j > sX || (j == sX && k > sY)) {
          if (field[j][k] != -1) {
            int[][] copy = deepCopy(field);
            int oldM = putMines(copy, j, k);
            int ret = setField(copy, m - 1, j, k);
            if (ret == 1) {
              return 1;
            }
            unputMines(copy, j, k, oldM);
          }
        }
      }
    }

    return -1;
  }

  private void printSolution(int[][] field) {
    boolean printedZero = false;

    boolean containsZero = contZero(field);

    for (int j = 0; j < y; j++) {
      for (int i = 0; i < x; i++) {
        if (((!containsZero && field[i][j] != -1) || (field[i][j] == 0)) && !printedZero) {
          System.out.print("c");
          printedZero = true;
        } else if (field[i][j] == -1) {
          System.out.print("*");
        } else {
          System.out.print(".");
        }
      }
      System.out.println("");
    }
  }

  private boolean contZero(int[][] field) {
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < y; j++) {
        if (field[i][j] == 0) {
          return true;
        }
      }
    }
    return false;
  }

  private boolean checkSolution(int[][] field) {
    int zX = -1;
    int zY = -1;

    int mines = 0;

    boolean contZero = contZero(field);

    for (int i = 0; i < field.length; i++) {
      for (int j = 0; j < field[0].length; j++) {
        if (field[i][j] == -1) {
          mines++;

        } else if ((contZero && field[i][j] == 0)) {
          zX = i;
          zY = j;
        } else if (!contZero) {
          zX = i;
          zY = j;
        }
      }
    }

    if (mines != this.mines) {
      return false;
    }

    zeroes = x * y - mines - 1;
    if (zX != -1 && zY != -1) {
      countConnectedZeroes(deepCopy(field), zX, zY);
    } else {
      return false;
    }

    return zeroes <= 0;
  }

  private void countConnectedZeroes(int[][] field, int zX, int zY) {
    if (zeroes <= 0) {
      return;
    }

    int temp = field[zX][zY];
    field[zX][zY] = -100;
    if (temp != 0) {
      return;
    }

    if (zX - 1 >= 0 && zY - 1 >= 0 && field[zX - 1][zY - 1] >= 0) {
      zeroes -= 1;
      countConnectedZeroes(field, zX - 1, zY - 1);
    }

    if (zY - 1 >= 0 && field[zX][zY - 1] >= 0) {
      zeroes -= 1;
      countConnectedZeroes(field, zX, zY - 1);
    }

    if (zX + 1 < x && zY - 1 >= 0 && field[zX + 1][zY - 1] >= 0) {
      zeroes -= 1;
      countConnectedZeroes(field, zX + 1, zY - 1);
    }

    if (zX + 1 < x && field[zX + 1][zY] >= 0) {
      zeroes -= 1;
      countConnectedZeroes(field, zX + 1, zY);
    }

    if (zX + 1 < x && zY + 1 < y && field[zX + 1][zY + 1] >= 0) {
      zeroes -= 1;
      countConnectedZeroes(field, zX + 1, zY + 1);
    }

    if (zY + 1 < y && field[zX][zY + 1] >= 0) {
      zeroes -= 1;
      countConnectedZeroes(field, zX, zY + 1);
    }

    if (zX - 1 >= 0 && zY + 1 < y && field[zX - 1][zY + 1] >= 0) {
      zeroes -= 1;
      countConnectedZeroes(field, zX - 1, zY + 1);
    }

    if (zX - 1 >= 0 && field[zX - 1][zY] >= 0) {
      zeroes -= 1;
      countConnectedZeroes(field, zX - 1, zY);
    }
  }

  private int putMines(int[][] field, int x, int y) {
    int m = field[x][y];
    field[x][y] = -1;

    if (x - 1 >= 0 && y - 1 >= 0 && field[x - 1][y - 1] != -1)
      field[x - 1][y - 1] += 1;

    if (x - 1 >= 0 && y >= 0 && field[x - 1][y] != -1)
      field[x - 1][y] += 1;

    if (x - 1 >= 0 && y + 1 < this.y && field[x - 1][y + 1] != -1)
      field[x - 1][y + 1] += 1;

    if (y + 1 < this.y && field[x][y + 1] != -1)
      field[x][y + 1] += 1;

    if (x + 1 < this.x && y + 1 < this.y && field[x][y + 1] != -1)
      field[x + 1][y + 1] += 1;

    if (x + 1 < this.x && field[x + 1][y] != -1)
      field[x + 1][y] += 1;

    if (x + 1 < this.x && y - 1 >= 0 && field[x + 1][y - 1] != -1)
      field[x + 1][y - 1] += 1;

    if (y - 1 >= 0 && field[x][y - 1] != -1)
      field[x][y - 1] += 1;

    return m;
  }

  private void unputMines(int[][] field, int j, int k, int m) {
    field[j][k] = m;

    if (j - 1 >= 0 && k - 1 >= 0 && field[j - 1][k - 1] != -1)
      field[j - 1][k - 1] -= 1;

    if (j - 1 >= 0 && k >= 0 && field[j - 1][k] != -1)
      field[j - 1][k] -= 1;

    if (j - 1 >= 0 && k + 1 < y && field[j - 1][k + 1] != -1)
      field[j - 1][k + 1] -= 1;

    if (k + 1 < y && field[j][k + 1] != -1)
      field[j][k + 1] -= 1;

    if (x + 1 < this.x && k + 1 < y && field[j][k + 1] != -1)
      field[j + 1][k + 1] -= 1;

    if (j + 1 < x && field[j + 1][k] != -1)
      field[j + 1][k] -= 1;

    if (j + 1 < x && k - 1 >= 0 && field[j + 1][k - 1] != -1)
      field[j + 1][k - 1] -= 1;

    if (k - 1 >= 0 && field[j][k - 1] != -1)
      field[j][k - 1] -= 1;
  }

}
