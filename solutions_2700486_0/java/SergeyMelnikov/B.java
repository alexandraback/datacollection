import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class B {
    int X0 = 10;
    int MAXY = 6;

    private void solve(int n, int qx, int qy) {
        boolean[][] u = new boolean[2 * X0 + 1][MAXY + 1];
        qx += X0;
        int count = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            for (boolean[] b : u) {
                Arrays.fill(b, false);
            }

            for (int i = 0; i < n; i++) {
                int x = X0;
                int y = MAXY;
                while (y > 0 && (y - 2 < 0 || !u[x][y - 2])) {
                    y--;
                }
                if (y > 0) {
                    boolean canLeft = !u[x - 1][y - 1];
                    boolean canRight = !u[x + 1][y - 1];
                    int dir = 0;
                    if (canLeft || canRight) {
                        if (!canLeft) {
                            dir = 1;
                        } else if (!canRight) {
                            dir = -1;
                        } else {
                            if ((mask & (1 << i)) > 0) {
                                dir = 1;
                            } else {
                                dir = -1;
                            }
                        }
                        while (y > 0 && !u[x + dir][y - 1]) {
                            y--;
                            x += dir;
                        }
                    }
                }
                u[x][y] = true;
//                System.err.println("(" + x + ", " + y + ")");
//
//                for (int yy = MAXY; yy >= 0; yy--) {
//                    for (int xx = 0; xx <= 2 * X0; xx++) {
//                        System.err.print(u[xx][yy] ? "*" : " ");
//                    }
//                    System.err.println();
//                }
//                System.err.println();
//                System.err.println();

            }
            if (0 <= qx && qx <= u.length && 0 <= qy && qy <= u[0].length && u[qx][qy]) {
                count++;
            }
        }
        System.out.println((count + 0.0) / (1 << n));
    }

    void run() throws FileNotFoundException {
        Scanner in = new Scanner(System.in);
//        Scanner in = new Scanner(new File("test"));
        int t = in.nextInt();
        for (int it = 0; it < t; it++) {
            System.out.print("Case #" + (it + 1) + ": ");
            int n = in.nextInt();
            int x = in.nextInt();
            int y = in.nextInt();
            solve(n, x, y);

        }
    }


    public static void main(String[] args) throws FileNotFoundException {
        new B().run();
    }
}
