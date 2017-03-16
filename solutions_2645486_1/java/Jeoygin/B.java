package gcj2013.round1a;

import java.util.Scanner;

public class B {
    
    public static void solve(Scanner scan) {
        int E = scan.nextInt();
        int R = scan.nextInt();
        int N = scan.nextInt();
        int[] v = new int[N];
        for (int i = 0; i < N; i++) {
            v[i] = scan.nextInt();
        }

        int e = E;
        long gain = 0;
        for (int i = 0; i < N; i++) {
            int j = i + 1;
            for (; j < N; j++) {
                if (v[j] > v[i]) {
                    break;
                }
            }
            long spend;
            if (j == N) {
                spend = e;
                e = 0;
            } else {
                spend = e + R * (j - i) - E;
                if (spend > e) {
                    spend = e;
                } else if (spend < 0) {
                    spend = 0;
                }
                e -= spend;
            }
            gain += spend * v[i];
            e += R;
        }
        System.out.println(gain);
    }
    
    public static final void main(final String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        for (int i = 1; i <= t; i++ ) {
            System.out.print("Case #" + i + ": ");
            solve(scan);
        }
    }
}
