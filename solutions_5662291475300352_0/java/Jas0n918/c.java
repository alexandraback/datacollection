import java.util.Scanner;

/**
 * @Author Jason918
 */
public class Main {


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int c = 1; c <= t; c++) {
            int n = sc.nextInt();
            int[] d = new int[n];
            int[] h = new int[n];
            int[] m = new int[n];
            for (int i = 0; i < n; i++) {
                d[i] = sc.nextInt();
                h[i] = sc.nextInt();
                m[i] = sc.nextInt();
            }
            System.out.printf("Case #%d: %d%n", c, solve(n, d, h, m));
        }


    }

    private static int solve(int n, int[] d, int[] h, int[] m) {
        int d1,m1,d2,m2;
        if (n == 1) {
            if (h[0] == 1) {
                return 0;
            } else {
                d1 = d[0];
                d2 = d[0];
                m1 = m[0];
                m2 = m[0]+1;
            }
        } else {
            d1 = d[0];
            m1 = m[0];
            d2 = d[1];
            m2 = m[1];
        }
        if (m1 == m2) {
            return 0;
        }
        if (m1 > m2) {
            int tmp = d1;
            d1 = d2;
            d2 = tmp;
            tmp = m1;
            m1 = m2;
            m2 = tmp;
        }
//        if ((d1 + 360.0 - d2) / (360.0/m1 - 360.0/m2) < d2*m2/360.0) {
        if ((d1 + 360.0 - d2) * m1 < 1.0*d2 *(m2 - m1)) {
            return 1;
        } else {
            return 0;
        }
    }

}
