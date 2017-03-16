import java.util.Scanner;

public class R1CB {


    final static int total = 1001 * 1001 / 4;
    static int[] solves = new int[total * 4 + 4];

    public static void main(String args[]) {

        solves[0] = 0;
        solves[1] = 1;
        solves[2] = 2;
        solves[3] = 3;
        solves[4] = 5;
        for(int i = 1; i < total; i++) {
            solves[4 * i + 1] = solves[4 * i] + i + 0;
            solves[4 * i + 2] = solves[4 * i + 1] + i + 1;
            solves[4 * i + 3] = solves[4 * i + 2] + i + 1;
            solves[4 * i + 4] = solves[4 * i + 3] + i + 2;
            // System.out.format("%d, %d\n", 4 * i, solves[ 4 * i]);
        }

        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {

            int M = in.nextInt();
            int N = in.nextInt();
            int K = in.nextInt();

            int s = solve(N, M, K);
            System.out.format("Case #%d: %s\n", t, s);
        }
    }

    public static int solve(int n, int m, int k) {

        int i;
        for(i = 0; i < solves.length; i++) {
            if(solves[i] >= k)
                break;
        }
        if(n == 1 && m == 1 && k == 1) {
            return 1;
        }
        if(n == 1 || m == 1)
            return k;

        if(n == m && n > 2) {
            if (k == n * m) {
                return 2 * (n + m);
            }
            else if (k == n * m - 1) {
                return 2 * (n + m) - 1;
            }
            else if (k == n * m - 2) {
                return 2 * (n + m) - 2;
            }
            else if (k == n * m - 3) {
                return 2 * (n + m) - 3;
            }
        }



        int mx, my;
        int[] xcuts, ycuts;
        if(i % 4 == 0) {
            mx = i / 2 + 1;
            my = i / 2 + 1;
            xcuts = new int[] { 1, 1 };
            ycuts = new int[] { 1, 1 };
        } else if(i % 4 == 1 || i % 4 == 3) {
            mx = i / 2 + 1;
            my = i / 2 + 1;
            xcuts = new int[] { 1, 2 };
            ycuts = new int[] { 1, 2 };
        } else { // i % 4 == 2
            mx = i / 2;
            my = i / 2 + 1;
            xcuts = new int[] { 2, 2 };
            ycuts = new int[] { 1, 1 };
        }

        if(n > m) {
            n = n + m;
            m = n - m;
            n = n - m;
        }

        if(n >= mx && m > my) {
            return i;
        }

        int allcut = solves[i] - k;
        int xcut = 0;
        int ycut = 0;

        while(allcut > 0) {
            if(n < mx) {
                if(xcuts[0] <= xcuts[1]) {
                    allcut -= xcuts[0];
                    xcuts[0] += 2;
                } else {
                    allcut -= xcuts[1];
                    xcuts[1] += 2;
                }
                mx--;
            } else if(m < my) {
                if(ycuts[0] <= ycuts[1]) {
                    allcut -= ycuts[0];
                    ycuts[0] += 2;
                } else {
                    allcut -= ycuts[1];
                    ycuts[1] += 2;
                }
                my--;
            } else {
                break;
            }
        }


        if(n >= mx && m > my) {
            return i;
        }


        if(m != n) {
            int c = m - n;
            int s = solve(n, n, k - n * c);
            return s + 2 * c;
        } else {
            int s = solve(n, m - 1, k - n);
            return s + 2;
        }
    }

}
