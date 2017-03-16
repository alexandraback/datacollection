package codejam.y2016.qualification;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;


/*

      LG
     LGGG
LGGGGGGGGGGGGGGG

      123
   123123123
123123123123123123123123123123123123123123123123123123123123123123123123123123123

Original sequence GLL: GGG|GLL|GLL
Original sequence LGL: LGL|GGG|LGL
Original sequence LLG: LLG|LLG|GGG
Original sequence LLL: LLL|LLL|LLL


 */
/**
 *
 *
 *
 *
 * @author Max Myslyvtsev
 * @since 4/8/16
 */
public class DFractiles {

    public static void main(String[] args) throws Exception {
        //Scanner in = new Scanner(new FileInputStream("/Users/max/Work/Source/foobar/src/main/resources/input.txt"));
        Scanner in = new Scanner(new FileInputStream("/Users/max/Downloads/D-large.in"));
        PrintStream out = new PrintStream(new FileOutputStream("/Users/max/Work/Source/foobar/src/main/resources/output.txt"));
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            int K = in.nextInt();
            int C = in.nextInt();
            int S = in.nextInt();
            System.out.println(K+ " " + C + " " + S);
            String a = solve(K, C, S);
            String answ = "Case #" + t + ": " + a;
            out.println(answ);
            System.out.println(answ);
            System.out.println();
        }
        out.close();
    }

    private static String solve(long K, long C, long S) {
        if (K >= S && false) {
            return solveStrict(K, C);
        } else {
            return solveShit(K, C, S);
        }
    }

    private static String solveStrict(long K, long C) {
        long prevSize = C > 1 ? Math.round(Math.pow(K, C - 1)) : 0;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < K; i++) {
            if (i > 0) {
                sb.append(" ");
            }
            long z = 1 + prevSize * i + i;
            sb.append(z);
        }
        return sb.toString();
    }

    private static String solveShit(long K, long C, long S) {
        if (K == 1) {
            return "1";
        }
        int last = 0;
        StringBuilder sb = new StringBuilder();
        boolean first = true;
        for (int i = 0; i < S; i++) {
            long q = ++last;
            long maxK = K;
            for (int j = 1; j < C; j++) {
                if (q >= maxK) {
                    q = maxK;
                }
                q = (q-1) * C + (++last);
                maxK *= K;
            }

            if (!first) {
                sb.append(" ");
            } else {
                first = false;
            }
            sb.append(q);
            if (last >= K) {
                return sb.toString();
            }
        }
        return "IMPOSSIBLE";
    }
}

