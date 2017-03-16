/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam;

import java.util.*;

/**
 *
 * @author QuanYang
 */
public class minesweeper {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numTC = sc.nextInt();
        int impossible=0;
        for (int x = 0; x < numTC; x++) {
            int R = sc.nextInt();
            int C = sc.nextInt();
            int M = sc.nextInt();
            int m = M;
            int c = C;
            int r = R;
            System.out.println("Case #" + (x + 1) + ":");
            if (R * C - M == 1) {
                char[][] tile = new char[R][C];
                for (int i = 0; i < R; i++) {
                    for (int y = 0; y < C; y++) {
                        tile[i][y] = '*';
                    }
                }
                tile[R - 1][C - 1] = 'c';
                for (char[] a : tile) {
                    for (char b : a) {
                        System.out.print(b + "");
                    }
                    System.out.println("");
                }

            } else {


                char[][] tile = new char[R][C];
                for (int i = 0; i < R; i++) {
                    for (int y = 0; y < C; y++) {
                        tile[i][y] = '.';
                    }
                }
                int rowTile = 0;
                int columnTile = 0;


                while (m >= C && (R - rowTile > 2)) {
                    //fill entire row.
                    m -= C;
                    for (int i = 0; i < C; i++) {
                        tile[rowTile][i] = '*';
                    }
                    rowTile++;
                    r--;
                }
                while (m >= r && (C - columnTile > 2)) {
                    //fill entire column
                    m -= r;
                    for (int i = 0; i < R; i++) {
                        tile[i][columnTile] = '*';
                    }
                    columnTile++;
                }
                int rowIndex = columnTile;
                int columnIndex = rowTile;

                while (m > 0) {
                    //remainders
                    tile[columnIndex][rowIndex++] = '*';
                    if (rowIndex >= C - 2) {
                        rowIndex = columnTile;
                        columnIndex++;
                    }
                    m--;
                }
                if (open(tile, R - 1, C - 1, new int[tile.length][tile[0].length]) == (R * C - M)) {
                    tile[R - 1][C - 1] = 'c';

                    for (char[] a : tile) {
                        for (char b : a) {
                            System.out.print(b + "");
                        }
                        System.out.println("");
                    }
                } else {
                    m = M;
                    c = C;
                    r = R;
                    tile = new char[R][C];
                    for (int i = 0; i < R; i++) {
                        for (int y = 0; y < C; y++) {
                            tile[i][y] = '.';
                        }
                    }
                    rowTile = 0;
                    columnTile = 0;
                    while (m >= C && (R - rowTile > 3)) {
                        //fill entire row.
                        m -= C;
                        for (int i = 0; i < C; i++) {
                            tile[rowTile][i] = '*';
                        }
                        rowTile++;
                        r--;
                    }
                    while (m >= r && (C - columnTile > 3)) {
                        //fill entire column
                        m -= r;
                        for (int i = 0; i < R; i++) {
                            tile[i][columnTile] = '*';
                        }
                        columnTile++;
                    }

                

                    rowIndex = columnTile;
                    columnIndex = rowTile;
                    while (m > 0) {
                        //remainders.
                         tile[rowIndex / tile[0].length][rowIndex++ % tile[0].length] = '*';

                        m--;
                    }
                    if (open(tile, R - 1, C - 1, new int[tile.length][tile[0].length]) == (R * C - M)) {
                        tile[R - 1][C - 1] = 'c';
                        for (char[] a : tile) {
                            for (char b : a) {
                                System.out.print(b + "");
                            }
                            System.out.println("");
                        }
                    } else {
                        System.out.println("Impossible");
                        impossible++;
                    }
                }


            }

        }
      //  System.out.println(impossible);
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
        //   tile[y][x]= (mines+"").charAt(0);
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
