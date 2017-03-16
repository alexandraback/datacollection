
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author zhs
 */
public class Main {

    private static int row;
    private static int col;
    private static int m;

    private static void solve() {
        if (row == 1) {
            for (int i = 0; i < m; i++) {
                System.out.print("*");
            }
            for (int i = 0; i < col - m - 1; i++) {
                System.out.print(".");
            }
            System.out.println("c");
            return;
        }
        if (col == 1) {
            for (int i = 0; i < m; i++) {
                System.out.println("*");
            }
            for (int i = 0; i < row - m - 1; i++) {
                System.out.println(".");
            }
            System.out.println("c");
            return;

        }
        if (m == row * col - 1) {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (i == row - 1 && j == col - 1) {
                        System.out.print("c");
                    } else {
                        System.out.print("*");
                    }
                }
                System.out.println();
            }
            return;
        }
        if (m <= (col - 2) * (row - 2)) {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (m > 0 && j < col - 2) {
                        System.out.print("*");
                        m--;
                    } else if (i == row - 1 && j == col - 1) {
                        System.out.print("c");
                    } else {
                        System.out.print(".");
                    }
                }
                System.out.println();
            }
            return;
        }
        if (m <= col * (row - 2) && m % col <= col - 2) {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (m > 0) {
                        System.out.print("*");
                        m--;
                    } else if (i == row - 1 && j == col - 1) {
                        System.out.print("c");
                    } else {
                        System.out.print(".");
                    }
                }
                System.out.println();
            }
            return;
        }
        if (m <= (col - 2) * row && m % row <= row - 2) {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (j * row + i < m) {
                        System.out.print("*");
                    } else if (i == row - 1 && j == col - 1) {
                        System.out.print("c");
                    } else {
                        System.out.print(".");
                    }
                }
                System.out.println();
            }
            return;
        }
        if (m <= row * col - 4) {
            if ((m - (col - 2) * (row - 2)) % 2 == 0) {
                for (int i = 0; i < row; i++) {
                    for (int j = 0; j < col; j++) {
                        if (i < row - 2 && j < col - 2) {
                            System.out.print("*");
                        } else if (i < row - 2 && m - (col - 2) * (row - 2) > i * 2) {
                            System.out.print("*");
                        } else if (m - col * (row - 2) > j * 2) {
                            System.out.print("*");
                        } else if (i == row - 1 && j == col - 1) {
                            System.out.print("c");
                        } else {
                            System.out.print(".");
                        }
                    }
                    System.out.println();
                }
                return;
            }
        }
        for (int r = 1; r <= row - 2; r++) {
            for (int c = 1; c <= col - 2 && r * c <= m; c++) {
                for (int k = 0; (row - r) * k + r * c <= m; k++) {
                    if (k <= c && (m - r * c - (row - r) * k) / (col - c) <= r
                            && (m - r * c - (row - r) * k) % (col - c) == 0) {
                        for (int i = 0; i < row; i++) {
                            for (int j = 0; j < col; j++) {
                                if (i < r && j < c) {
                                    System.out.print("*");
                                } else if (j < k) {
                                    System.out.print("*");
                                } else if (i < (m - r * c - (row - r) * k) / (col - c)) {
                                    System.out.print("*");
                                } else if (i == row - 1 && j == col - 1) {
                                    System.out.print("c");
                                } else {
                                    System.out.print(".");
                                }
                            }
                            System.out.println();
                        }
                        return;
                    }
                }
            }
        }
        System.out.println("Impossible");
    }

    public static void main(String[] args) throws FileNotFoundException {
        try {
            System.setIn(new FileInputStream("/home/zhs/file/code/codejam/in"));
             System.setOut(new PrintStream("/home/zhs/file/code/codejam/out"));
        } catch (FileNotFoundException ex) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        }
        Scanner sc = new Scanner(new File("/home/zhs/file/code/codejam/out"));
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for (int cnt = 1; cnt <= t; cnt++) {
            System.out.println("Case #" + cnt + ":");
            row = scanner.nextInt();
            col = scanner.nextInt();
            m = scanner.nextInt();
            solve();

//            sc.nextLine();
//            int c = 0;
//            for (int i = 0; i < row; i++) {
//                String line = sc.nextLine();
//                if (line.equals("Impossible")) {
//                    c = -1;
//                    System.out.println(row + " " + col + " " + m);
//                    break;
//                }
//                for (byte b : line.getBytes()) {
//                    if (b == '*') {
//                        c++;
//                    }
//                }
//            }
//            if (c >= 0 && c != m) {
//                System.out.println("!!!" + cnt);
//            }
        }
    }
}
