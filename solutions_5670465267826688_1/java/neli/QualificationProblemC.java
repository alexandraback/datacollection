import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 * Created by Darya Shauchenka on 4/11/2015.
 */
public class QualificationProblemC {

    private static final int REPEAT = 4;
    private static final int[][] MULT = new int[8][4];

    static {
        //1
        MULT[0][1] = 1;
        MULT[0][2] = 2;
        MULT[0][3] = 3;
        //i
        MULT[1][1] = 4;
        MULT[1][2] = 3;
        MULT[1][3] = 6;
        //j
        MULT[2][1] = 7;
        MULT[2][2] = 4;
        MULT[2][3] = 1;
        //k
        MULT[3][1] = 2;
        MULT[3][2] = 5;
        MULT[3][3] = 4;

        //-1
        MULT[4][1] = 5;
        MULT[4][2] = 6;
        MULT[4][3] = 7;
        //-i
        MULT[5][1] = 0;
        MULT[5][2] = 7;
        MULT[5][3] = 2;
        //-j
        MULT[6][1] = 3;
        MULT[6][2] = 0;
        MULT[6][3] = 5;
        //-k
        MULT[7][1] = 6;
        MULT[7][2] = 1;
        MULT[7][3] = 0;
    }

    private static int convert(char c) {
        switch (c) {
            case 'i':
                return 1;
            case 'j':
                return 2;
            case 'k':
                return 3;
        }
        throw new IllegalArgumentException();
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("C-large.in"));
        BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));

        int testCases = sc.nextInt();
        nextCase:
        for (int t = 0; t < testCases; t++) {
            int l = sc.nextInt();
            long x = sc.nextLong();
            String s = sc.next();

            //i
            int curr = 0;
            boolean iFound = false;
            int iChar = 0;
            for (; iChar < Math.min(REPEAT, x) * l; iChar++) {
                curr = MULT[curr][convert(s.charAt(iChar % l))];
                if (curr == convert('i')) {
                    iFound = true;
                    break;
                }
            }
            if (!iFound) {
                out.write("Case #" + (t + 1) + ": NO");
                out.newLine();
                continue nextCase;
            }

            //j
            curr = 0;
            boolean jFound = false;
            int jChar = iChar + 1;
            for (; jChar < Math.min(REPEAT * 2, x) * l; jChar++) {
                curr = MULT[curr][convert(s.charAt(jChar % l))];
                if (curr == convert('j')) {
                    jFound = true;
                    break;
                }
            }
            if (!jFound) {
                out.write("Case #" + (t + 1) + ": NO");
                out.newLine();
                continue nextCase;
            }

            //k
            curr = 0;
            int kChar = jChar + 1;
            for (; kChar < Math.min(REPEAT * 3, x) * l; kChar++) {
                curr = MULT[curr][convert(s.charAt(kChar % l))];
                if ((kChar + 1) % l == 0 && ((kChar + 1) / l) % REPEAT == x % REPEAT && curr == convert('k')) {
                    out.write("Case #" + (t + 1) + ": YES");
                    out.newLine();
                    continue nextCase;
                }
            }

            out.write("Case #" + (t + 1) + ": NO");
            out.newLine();
        }

        out.close();
    }
}
