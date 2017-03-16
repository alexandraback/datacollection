package gcj14.qualification;

import java.util.Arrays;
import java.util.Scanner;

public class MinesweeperMaster {
    void fill(char[][] grid, char c) {
        for (int i = 0; i < grid.length; i++) {
            Arrays.fill(grid[i], c);
        }
    }

    void solve(Scanner scan) {
        int r = scan.nextInt();
        int c = scan.nextInt();
        int n = scan.nextInt();
        int left = r * c - n;

        char[][] grid = new char[r][c];
        fill(grid, '.');

        if (n == r * c - 1) {
            fill(grid, '*');
        } else if (r == 1 || c == 1 || (c == 2 && n % 2 == 0 && left > 2)) {
            int t = 0;
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c && t < n; j++, t++) {
                    grid[r-1-i][c-1-j] = '*';
                }
            }
        } else if ((r == 2 && n % 2 == 0 && left > 2)) {
            int t = 0;
            for (int i = 0; i < c; i++) {
                for (int j = 0; j < r && t < n; j++, t++) {
                    grid[r-1-j][c-1-i] = '*';
                }
            }
        }
        else if (c == 2 || r == 2 || left < 4 || left == 5 || left == 7) {
            System.out.println("Impossible");
            return;
        } else {
            fill(grid, '*');
            if (left % 2 == 1) {
                grid[2][0] = '.';
                grid[2][1] = '.';
                grid[2][2] = '.';
                left -= 3;
            }
            for (int i = 0; i < c && left > 0; i++, left -= 2) {
                grid[0][i] = grid[1][i] = '.';
            }
            if (left > 0 && grid[2][2] != '.') {
                grid[2][0] = '.';
                grid[2][1] = '.';
                left -= 2;
            }
            for (int i = 2; i < r && left > 0; i++) {
                if (grid[i][0] != '.') {
                    grid[i][0] = grid[i][1] = '.';
                    left -= 2;
                }
            }
            for (int i = 2; i < r; i++) {
                for (int j = 2; j < c && left > 0; j++) {
                    if (grid[i][j] != '.') {
                        grid[i][j] = '.';
                        left--;
                    }
                }
            }
        }

        grid[0][0] = 'c';
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                System.out.print(grid[i][j]);
            }
            System.out.println("");
        }
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        for (int i = 1; i <= t; i++) {
            System.out.printf("Case #%d:\n", i);
            new MinesweeperMaster().solve(scan);
        }
    }
}
