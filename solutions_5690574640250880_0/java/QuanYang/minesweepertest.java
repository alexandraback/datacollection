/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam;

import java.util.*;

/**
 *
 * @author QuanYang Matric No: A0111889W
 */
public class minesweepertest {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numTC = sc.nextInt();
        for (int x = 0; x < numTC; x++) {
            System.out.println("Case #" + (x + 1) + ":");
            int sizeY = sc.nextInt();
            int sizeX = sc.nextInt();
            int bomb = sc.nextInt();
            char[][] tile = new char[sizeY][sizeX];

            for (int i = 0; i < sizeY; i++) {
                for (int y = 0; y < sizeX; y++) {
                    tile[i][y] = '.';
                }
            }
            if(permutate(tile, bomb, 0, 0, sizeY * sizeX - bomb)){
            for (char[] a : tile) {
                for (char b : a) {
                    System.out.print(b + "");
                }
                System.out.println("");
            }
            } else{
                System.out.println("Impossible");
            }
        }

    }

    public static boolean permutate(char[][] tile, int mines, int x, int y, int remain) {
        if (mines < 0) {
            return false;
        }
        if (mines == 0) {

            for (int i = 0; i < tile.length; i++) {
                for (int k = 0; k < tile[0].length; k++) {
                    if (tile[i][k] != '*') {
                        if (open(tile, i, k, new int[tile.length][tile[0].length]) == remain) {
                            tile[i][k] = 'c';
                            return true;
                        }
                    }
                }
            }
        }
        //choose
        if (x < tile.length * tile[0].length) {
            tile[x / tile[0].length][x % tile[0].length] = '*';
            if(permutate(tile, mines - 1, x + 1, x + 1, remain))
                return true;
            tile[x / tile[0].length][x % tile[0].length] = '.';
            return permutate(tile, mines, x + 1, x + 1, remain);
        }
        return false;
    }

    public static int open(char[][] tile, int y, int x, int[][] visited) {
        //check surrounding for mines
        if (y < 0 || x < 0 || y > tile.length - 1 || x > tile[0].length - 1 || visited[y][x] == 1) {
            return 0;
        }
        int mines = 0;
        mines += checkNeighbours(tile, y - 1, x - 1);
        mines += checkNeighbours(tile, y - 1, x);
        mines += checkNeighbours(tile, y - 1, x + 1);

        mines += checkNeighbours(tile, y, x - 1);
        mines += checkNeighbours(tile, y, x + 1);

        mines += checkNeighbours(tile, y + 1, x - 1);
        mines += checkNeighbours(tile, y + 1, x);
        mines += checkNeighbours(tile, y + 1, x + 1);

        int open = 1;
        // tile[y][x] = (mines + "").charAt(0);
        visited[y][x] = 1;
        if (mines == 0) {
            open += open(tile, y - 1, x - 1, visited);
            open += open(tile, y - 1, x, visited);
            open += open(tile, y - 1, x + 1, visited);

            open += open(tile, y, x - 1, visited);
            open += open(tile, y, x + 1, visited);

            open += open(tile, y + 1, x - 1, visited);
            open += open(tile, y + 1, x, visited);
            open += open(tile, y + 1, x + 1, visited);
        }

        return open;
    }

    public static int checkNeighbours(char[][] tile, int y, int x) {
        try {
            if (tile[y][x] == '*') {
                return 1;
            }
        } catch (Exception E) {
        }
        return 0;
    }
}
