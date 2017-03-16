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
        Scanner in = new Scanner(new FileInputStream("/Users/max/Downloads/D-small-attempt1.in"));
        PrintStream out = new PrintStream(new FileOutputStream("/Users/max/Work/Source/foobar/src/main/resources/output.txt"));
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            int K = in.nextInt();
            int C = in.nextInt();
            int S = in.nextInt();
            String a = solve(K, C, S);
            String answ = "Case #" + t + ": " + a;
            out.println(answ);
            System.out.println(answ);
        }
        out.close();
    }

    private static String solve(long K, long C, long S) {
        if (K != S) {
            return "IMPOSSIBLE"; // TODO
        }
        long prevSize = C > 1 ? Math.round(Math.pow(K, C - 1)) : 0;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < S; i++) {
            if (i > 0) {
                sb.append(" ");
            }
            long z = 1 + prevSize * i + i;
            sb.append(z);
        }
        return sb.toString();
    }
}
