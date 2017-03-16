package round1b;

import java.util.Scanner;

/**
 * Created by tomas on 03.05.14.
 */
public class B {

    public static void main(String[] argv) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 1; i <= T; i++) {
            int A = sc.nextInt();
            int B = sc.nextInt();
            int K = sc.nextInt();

            int[] p = new int[1000];
            for (int j = 0; j < A; j++) {
                for (int k = 0; k < B; k++) {
                    p[j & k]++;
                }
            }

            int s = 0;
            for (int j = 0; j < K; j++) {
                s += p[j];
            }

            System.out.println("Case #" + i + ": " + s);

        }
    }
}
