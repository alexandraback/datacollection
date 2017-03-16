import java.io.*;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * Created by Rafal on 4/12/14.
 */
public class C {

    public static void main(String[] args) {
        try {

            InputStream in = new FileInputStream("c:/codejam/C.in");
            Scanner scanner = new Scanner(in);
            OutputStream out = new FileOutputStream("c:/codejam/C.out");
            PrintWriter writer = new PrintWriter(new OutputStreamWriter(out, "utf8"));
            int t = scanner.nextInt();
            for (int i = 0; i < t; i++) {
                solve(scanner, i+1, writer);
            }
            writer.close();
        } catch (Exception e) {
            System.out.println("Error: " + e);
            e.printStackTrace();
        }
    }


    public static void solve(Scanner scanner, int t, PrintWriter out) {
        int r, c, m;
        r = scanner.nextInt();
        c = scanner.nextInt();
        m = scanner.nextInt();

        int result[][] = null; // 0 - mine, 1 - empty, 2 - initial hit
        int totalCells = r * c;
        int emptyCells = totalCells - m;
        boolean impossible = false;
        boolean tranpose = false;
        if (r == 1 || c == 1) {
            // special case - only one row
            if (r > c) {
                int x = c;
                c = r;
                r = x;
                tranpose = true;
            }
            result = new int[r][c];
            for (int i = 0; i < emptyCells; i++) {
                result[0][i] = 1;
            }
            result[0][0] = 2;
        } else if (r == 2 || c == 2) {
            // special case - two rows
            if (r > c) {
                int x = c;
                c = r;
                r = x;
                tranpose = true;
            }
            if (emptyCells == 2 || emptyCells == 3 || (emptyCells > 3 && emptyCells % 2 != 0)) {
                impossible = true;
            } else {
                result = new int[r][c];
                if (emptyCells == 1) {
                    result[0][0] = 2;
                } else {
                    for (int i = 0; i < emptyCells / 2; i++) {
                        result[0][i] = 1;
                        result[1][i] = 1;
                    }
                    result[0][0] = 2;
                }
            }
        } else {
            // normal
            if (emptyCells == 2 || emptyCells == 3 || emptyCells == 5 || emptyCells == 7) {
                impossible = true;
            } else {
                if (r > c) {
                    int x = c;
                    c = r;
                    r = x;
                    tranpose = true;
                }
                result = new int[r][c];
                // now r <= c
                if (emptyCells == 1) {
                    result[0][0] = 2;
                } else if (emptyCells < 2 * c) {
                    if (emptyCells % 2 == 0) {
                        // even number
                        for (int i = 0; i < emptyCells / 2; i++) {
                            result[0][i] = 1;
                            result[1][i] = 1;
                        }
                    } else {
                        // odd number
                        int cnt = emptyCells / 2 - 1;
                        for (int i = 0; i < cnt; i++) {
                            result[0][i] = 1;
                            result[1][i] = 1;
                        }
                        result[2][0] = 1;
                        result[2][1] = 1;
                        result[2][2] = 1;
                    }
                    result[0][0] = 2;
                } else /* emptyCells >= 2 * c */ {
                    result[0][0] = 2;
                    int fullRows = emptyCells / c;
                    for (int i = 0; i < fullRows; i++) {
                        for (int j = 0; j < c; j++) {
                            result[i][j] = 1;   // empty
                        }
                    }
                    int left = emptyCells - fullRows * c;
                    for (int j = 0; j < left; j++) {
                        result[fullRows][j] = 1;
                    }
                    result[0][0] = 2;   // we start in the corner
                    if (emptyCells == fullRows * c + 1) {
                        if (fullRows > 2) {
                            result[fullRows-1][c - 1] = 0;
                            result[fullRows][1] = 1;
                        } else {
                            // fullRows == 2
                            result[0][c - 1] = 0;
                            result[1][c - 1] = 0;
                            result[fullRows][1] = 1;
                            result[fullRows][2] = 1;
                        }
                    }
                }
            }
        }
        if (!impossible && tranpose) {
            result = transposeArray(result);
        }

        System.out.println("Case #" + t + ":");
        out.println("Case #" + t + ":");
        if (impossible) {
            System.out.println("Impossible");
            out.println("Impossible");
        } else {
            for (int i = 0; i < result.length; i++) {
                for (int j = 0; j < result[0].length; j++) {
                    if (result[i][j] == 0) {
                        System.out.print("*");
                        out.print("*");
                    } else if (result[i][j] == 1) {
                        System.out.print(".");
                        out.print(".");
                    } else {
                        System.out.print("c");
                        out.print("c");
                    }
                }
                System.out.print("\n");
                out.print("\n");
            }
        }

    }

    private static int[][] transposeArray(int[][] result) {
        int rows = result.length;
        int cols = result[0].length;

        int r[][] = new int[cols][rows];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                r[j][i] = result[i][j];
            }
        }
        return r;
    }


}
