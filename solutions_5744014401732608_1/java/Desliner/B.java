package codejam.y2016.round1.subroundC;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

/**
 * @author Max Myslyvtsev
 * @since 4/30/16
 */
public class B {

    public static void main(String[] args) throws Exception {
        //Scanner in = new Scanner(new FileInputStream("/Users/max/Work/Source/foobar/src/main/resources/input.txt"));
        Scanner in = new Scanner(new FileInputStream("/Users/max/Downloads/B-large.in"));
        PrintStream out = new PrintStream(new FileOutputStream("/Users/max/Work/Source/foobar/src/main/resources/output.txt"));
        int T = in.nextInt();
        in.nextLine();
        for (int t = 1; t <= T; t++) {
            int B = in.nextInt();
            long M = in.nextLong();
            String a = solve(B, M);
            String answ = "Case #" + t + ": " + a;
            out.println(answ);
            System.out.println(answ);
        }
    }

    private static String solve(int B, long M) {
        long max = 1L << (B-2);
        if (M > max) {
            return "IMPOSSIBLE";
        }
        int[][] e = new int[B][B];
        e[B-2][B-1] = 1;
        int idx = B-2;
        long cur = 1;
        long M2 = M >> 1;
        long[] q = new long[B];
        q[B-1] = 1;
        q[B-2] = 1;
        while (cur <= M2) {
            for (int j = idx; j < B; j++) {
                e[idx-1][j] = 1;
            }
            idx--;
            cur <<= 1;
            q[idx] = cur;
        }
        int first = idx;
        if (cur == M) {

        } else {
            idx--;
            first = idx;

            long rem = M;
            while (rem > 0) {
                idx++;
                if (q[idx] <= rem) {
                    e[first][idx] = 1;
                    rem -= q[idx];
                }
            }
        }

        if (first != 0) {
            e[0][first] = 1;
        }


        StringBuilder sb = new StringBuilder();
        sb.append("POSSIBLE");
        for (int i = 0; i < B; i++) {
            sb.append("\n");
            for (int j = 0; j < B; j++) {
                sb.append(e[i][j]);
            }
        }
        return sb.toString();
    }


}
