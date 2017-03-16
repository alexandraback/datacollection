package codejam;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by evgen on 08.05.2016.
 */
public class Slides {


    final static String PROBLEM_NAME = "slide";
    final static String WORK_DIR = "C:\\Users\\evgen\\Desktop\\" + PROBLEM_NAME + "\\";
    final static String INPUT_FILE_NAME = "A-large.in";
    final static String OUTPUT_FILE_NAME = "A-large.out";


    public static final String OUT_FORMATTER = "Case #%d: %s";
    public static final String POSSIBLE = "POSSIBLE";
    public static final String IMPOSSIBLE = "IMPOSSIBLE";


    String solve(Scanner in, PrintWriter pw) {
        int B = in.nextInt();
        long M = in.nextLong();

        long total = 1 << (B - 2);
//        System.out.println(total);
        if (total < M) {
            return IMPOSSIBLE;
        }

        int[][] matr = new int[B][B];
        for (int i = 1; i < B - 1; i++) {
            for (int j = i + 1; j < B; j++) {
                matr[i][j] = 1;
            }
        }

        if (total == M) {
            for (int i = 1; i < B; i++) {
                matr[0][i] = 1;
            }
        } else {
            for (int i = 1; i < B; i++) {
                long l = 1 << (i - 1);
                if ((M & l) > 0) {
                    matr[0][B - i - 1] = 1;
                }
            }
        }


//        for(int i = 0; i < matr.length; i++) {
//            System.out.println(Arrays.toString(matr[i]));
//        }

        StringBuilder sb = new StringBuilder();
        sb.append(POSSIBLE).append("\n");
        for (int i = 0; i < B; i++) {
            for (int j = 0; j < B; j++) {
                sb.append(matr[i][j]);
            }
            if (i != B - 1) {
                sb.append("\n");
            }
        }




        return sb.toString();
    }


    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + INPUT_FILE_NAME));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR
                + OUTPUT_FILE_NAME));
        int caseCnt = sc.nextInt();
        Slides countingSheep = new Slides();
        for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            String r = String.format(OUT_FORMATTER, (caseNum + 1), countingSheep.solve(sc, pw));
            System.out.println(r);
            pw.println(r);
        }
        pw.flush();
        pw.close();
        sc.close();
    }

}
