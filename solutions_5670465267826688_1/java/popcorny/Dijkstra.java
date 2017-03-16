package idv.popcorny.jam2015;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

import static idv.popcorny.jam2015.Dijkstra.*;

public class Dijkstra {

    public static final int C_1  = 0;
    public static final int C_I  = 1;
    public static final int C_J  = 2;
    public static final int C_K  = 3;
    public static final int C_N1 = 4;
    public static final int C_NI = 5;
    public static final int C_NJ = 6;
    public static final int C_NK = 7;

    public static final int[][] TABLE = {
        { C_1,  C_I,  C_J,  C_K, C_N1, C_NI, C_NJ, C_NK},
        { C_I, C_N1,  C_K, C_NJ, C_NI,  C_1, C_NK,  C_J},
        { C_J, C_NK, C_N1,  C_I, C_NJ,  C_K,  C_1, C_NI},
        { C_K,  C_J, C_NI, C_N1, C_NK, C_NJ,  C_I,  C_1},
        {C_N1, C_NI, C_NJ, C_NK,  C_1,  C_I,  C_J,  C_K},
        {C_NI,  C_1, C_NK,  C_J,  C_I, C_N1,  C_K, C_NJ},
        {C_NJ,  C_K,  C_1, C_NI,  C_J, C_NK, C_N1,  C_I},
        {C_NK, C_NJ,  C_I,  C_1,  C_K,  C_J, C_NI, C_N1}
    };

    public static final String[] CODE = {
        "1",
        "i",
        "j",
        "k",
        "-1",
        "-i",
        "-j",
        "-k"
    };



    public static boolean test(int[] tokens, long totalTimes) {
        if (totalTimes >= 12) {
            totalTimes = (totalTimes % 4) + 8;
        }

        int state = 0;
        int tokenCurrent = C_1;

        for(long times=0; times<totalTimes; times++) {

            for(int i=0; i<tokens.length; i++) {
                tokenCurrent = TABLE[tokenCurrent][tokens[i]];

                if (state == 0 && tokenCurrent == C_I) {
//                    System.out.println("i found");
                    state = 1;
                    tokenCurrent = C_1;
                } else if (state == 1 && tokenCurrent == C_J) {
                    tokenCurrent = C_1;
//                    System.out.println("j found");
                    state = 2;
                }
            }
        }

        if(state == 2 && tokenCurrent == C_K) {
            return true;
        } else {
            return false;
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner scanner;
        PrintWriter writer;
        String input   = "quiz/dijkstra_large.in";
        String output  = "quiz/dijkstra_large.out";

        if (new File(input).exists()) {
            scanner = new Scanner(new File(input));
            writer = new PrintWriter(output);
            //writer = new PrintWriter(System.out);
        } else {
            scanner = new Scanner(System.in);
            writer = new PrintWriter(System.out);
        }


        int t = scanner.nextInt();

        for (int i = 0; i < t; i++) {
            int token = scanner.nextInt();
            long times = scanner.nextLong();
            String sequence = scanner.next();

            int[] tokens = new int[token];
            char[] ts = sequence.toCharArray();
            for(int j=0; j<ts.length; j++) {
                switch (ts[j]) {
                    case 'i':
                        tokens[j] = C_I;
                        break;
                    case 'j':
                        tokens[j] = C_J;
                        break;
                    case 'k':
                        tokens[j] = C_K;
                        break;
                    default:
                        break;
                }
            }
//            System.out.printf("%d, %d, %s\n", token, times, sequence);
            writer.printf("Case #%d: %s\n", i+1, test(tokens, times) ? "YES" : "NO");
        }
        writer.flush();

    }
}
