import java.util.*;

public class C {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int t = in.nextInt();
    for (int test = 1; test <= t; ++test) {
      int r = in.nextInt();
      int c = in.nextInt();
      int m = in.nextInt();
      char[][] grid = new char[r][c];
      for(char[] cc: grid) Arrays.fill(cc, '*');
      grid[0][0] = 'c';
      int neededHoles = r*c - m;
      int curHoles = 1;
      boolean possible = true;
      if (r == 1 || c == 1) {
        for (int i = 0 ; i < r; ++i) {
          for (int j = 0; j < c; ++j) {
            if (i == 0 && j == 0) continue;
            if (curHoles < neededHoles) {
              grid[i][j] = '.';
              ++curHoles;
            }
          }
        }
      } else if (r == 2 || c == 2) {
        if ((curHoles < neededHoles && (m % 2) == 1) || neededHoles == 2) possible = false;
        if (r == 2) {
          curHoles = 2;
          grid[1][0] = '.';
          for (int i = 1; i < c; ++i) {
            grid[0][i] = grid[1][i] = '.';
            curHoles += 2;
            if (curHoles >= neededHoles) break;
          }
        }
        if (c == 2) {
          curHoles = 2;
          grid[0][1] = '.';
          for (int i = 1; i < r; ++i) {
            grid[i][0] = grid[i][1] = '.';
            curHoles += 2;
            if (curHoles >= neededHoles) break;
          }
        }
      } else {
        if (neededHoles == 2 || neededHoles == 3 || neededHoles == 5 || neededHoles == 7) possible = false;
        if (neededHoles <= 8) {
          switch(neededHoles) {
            case 8:
              grid[0][2] = grid[1][2] = '.';
            case 6:
              grid[2][0] = grid[2][1] = '.';
            case 4:
              grid[1][0] = grid[0][1] = grid[1][1] = '.';
          }
        } else {
          curHoles = 8;
          grid[1][0] = grid[0][1] = grid[1][1] = grid[0][2] = grid[1][2] = grid[2][0] = grid[2][1] = '.';
          int leftIdx = 3;
          int rightIdx = 3;
          while (curHoles < neededHoles) {
            if (leftIdx == r && rightIdx == c) break;
            if (curHoles == neededHoles -1) {
              grid[2][2] = '.';
              ++curHoles;
              break;
            }
            if (leftIdx != r) {
              curHoles += 2;
              grid[leftIdx][0] = grid[leftIdx][1] = '.';
              ++leftIdx;
            } else { // rightIdx != c
              curHoles += 2;
              grid[0][rightIdx] = grid[1][rightIdx] = '.';
              ++rightIdx;
            }
          }
          for (int i = 2; i < r; ++i) {
            for (int j = 2; j < c; ++j) {
              if (curHoles < neededHoles) {
                ++curHoles;
                grid[i][j] = '.';
              }
            }
          }
        }
      }
      System.out.printf("Case #%d:\n", test);
      if (!possible) {
        System.out.printf("Impossible\n");
        continue;
      }
      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
          System.out.print(grid[i][j]);
        }
        System.out.println();
      }
    }
  }
}