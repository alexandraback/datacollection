package com.forthgo.google.g2012r0;

import com.forthgo.math.Helper;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by Xan Gregg.
 * Date: 4/14/12
 */
public class ProblemC {
    private static final int SELF = 2;
    private static final int MIRROR = 1;

    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("C.in"));
            PrintWriter out = new PrintWriter(new FileWriter("C.out"));
            //PrintWriter out = new PrintWriter(System.out);
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                int h = in.nextInt();
                int w = in.nextInt();
                int d = in.nextInt();
                int k = solve(in, h, w, d);
                out.printf("Case #%d: %d%n", i + 1, k);
                out.flush();
            }

        } catch (IOException e) {
            throw new RuntimeException();
        }

    }

    private static int solve(Scanner in, int H, int W, int D) {
        in.nextLine();
        int [][] cell = new int[W][H];
        int count = 0;
        int x = 0;
        int y = 0;
        for (int i = 0; i < H; i++) {
            String row = in.nextLine();
            for (int j = 0; j < W; j++) {
                if (row.charAt(j) == '#')
                    cell[j][i] = MIRROR;
                else if (row.charAt(j) == 'X') {
                    cell[j][i] = SELF;
                    x = j;
                    y = i;
                }
                else if (row.charAt(j) != '.') {
                    throw new RuntimeException();
                }
            }
        }
        for (int i = 1; i < W; i++) {
            if (cell[x + i][y] == MIRROR) {
                if (2 * i - 1 <= D)
                    count++;
                break;
            }
        }
        for (int i = 1; i < W; i++) {
            if (cell[x - i][y] == MIRROR) {
                if (2 * i - 1 <= D)
                    count++;
                break;
            }
        }
        for (int i = 1; i < H; i++) {
            if (cell[x][y + i] == MIRROR) {
                if (2 * i - 1 <= D)
                    count++;
                break;
            }
        }
        for (int i = 1; i < H; i++) {
            if (cell[x][y - i] == MIRROR) {
                if (2 * i - 1 <= D)
                    count++;
                break;
            }
        }
        //room.offset(x, y);

        for (int xdir = 1; xdir <= D; xdir++) {
            int my = (int) Math.sqrt(D * D - xdir * xdir);
            for (int ydir = 1; ydir <= my; ydir++) {
                if (gcd(xdir, ydir) == 1) {
                    int k = (int) (D / Math.sqrt(xdir * xdir + ydir * ydir));
                    for (int xsign = -1; xsign <= 1; xsign += 2)
                        for (int ysign = -1; ysign <= 1; ysign += 2)
                                count += countPaths(cell, x, y, k * xdir, k * ydir, xsign, ysign);
                }
            }
        }
        return count;
    }

    private static int countPaths(int [][] cell, int x, int y, int xdir, int ydir, int xsign, int ysign) {
        int dx = 0;
        int dy = 0;
        while (dx <= xdir && dy < ydir || dx < xdir && dy <= ydir) {
            int x2next = 2 * dx + 1;
            int y2next = x2next * ydir / xdir;
            if (y2next == 2 * dy + 1 && y2next * xdir == ydir * x2next) {
                int xcell = cell[x + xsign][y];
                int ycell = cell[x][y + ysign];
                int xycell = cell[x + xsign][y + ysign];
                // corner
                if (xycell == MIRROR && xcell == MIRROR && ycell == MIRROR) {
                    xsign = -xsign;
                    ysign = -ysign;
                }
                else if (xycell == MIRROR && xcell == MIRROR && ycell != MIRROR) {
                    y += ysign;
                    xsign = -xsign;
                }
                else if (xycell == MIRROR && xcell != MIRROR && ycell == MIRROR) {
                    x += xsign;
                    ysign = -ysign;
                }
                else if (xycell == MIRROR && xcell != MIRROR && ycell != MIRROR) {
                    return 0;   // kills beam
                }
                else if (xycell != MIRROR) {
                    // pass through
                    x += xsign;
                    y += ysign;
                }
                else
                    throw new RuntimeException();
                dx++;
                dy++;
            }

            else if (y2next < 2 * dy + 1) {
                // next x cell
                if (cell[x + xsign][y] == MIRROR) {
                    xsign = -xsign;
                }
                else {
                    // empty
                    x += xsign;
                }
                dx++;
            }
            else if (y2next >= 2 * dy + 1) {
                // next y cell
                if (cell[x][y + ysign] == MIRROR) {
                    ysign = -ysign;
                }
                else {
                    // empty
                    y += ysign;
                }
                dy++;
            }
            else
                throw new RuntimeException();
            if (dx > xdir || dy > ydir)
                break;
            if (cell[x][y] == SELF) {
                if ((2 * dy) * xdir == ydir * (2 * dx)) {
//                    System.out.printf("%2d %2d %2d %2d %2d %2d %6.3f%n", xdir, ydir, dx, dy, xsign, ysign, Math.sqrt(dx * dx + dy * dy));
                    return 1;
                }
            }
        }
        return 0;
    }

    public static int gcd(int a, int b) {
        if (a < 0 || b < 0)
            return -1;
        while (b != 0) {
            int x = a % b;
            a = b;
            b = x;
        }
        return a;
    }


}

class Room {
    int[][] cell;
    int xoffset = 0;
    int yoffset = 0;
    int xscale = 1;
    int yscale = 1;

    public Room(int w, int h) {
        cell = new int[w][h];
    }

    public int height() {
        return cell[0].length;
    }

    public int width() {
        return cell.length;
    }

    public void set(int x, int y, int value) {
        cell[x * xscale + xoffset][y * yscale + yoffset] = value;
    }

    public int get(int x, int y) {
        return cell[x * xscale + xoffset][y * yscale + yoffset];
    }

    public int getXoffset() {
        return xoffset;
    }

    public void offset(int dx, int dy) {
        xoffset += dx * xscale;
        yoffset += dy * yscale;
    }

    public void reset(int x, int y) {
        xoffset = x;
        yoffset = y;
        xscale = 1;
        yscale = 1;
    }

    public int getYoffset() {
        return yoffset;
    }

    public int getXscale() {
        return xscale;
    }

    public void setXscale(int xscale) {
        this.xscale = xscale;
    }

    public int getYscale() {
        return yscale;
    }

    public void setYscale(int yscale) {
        this.yscale = yscale;
    }

    public void flipX() {
        xscale = -xscale;
    }

    public void flipY() {
        yscale = -yscale;
    }

}
