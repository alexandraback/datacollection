import java.util.*;
import java.io.*;

public class OminousOmino {
    public static void main(String[] args) throws Exception {
        if (args.length == 0)
            throw new IllegalArgumentException("Require input file name");
        Scanner sc = new Scanner(new FileReader(args[0]));
        String outFilename = args[0].replaceFirst("[.][^.]+$", "").concat(".out");
        PrintWriter pw = new PrintWriter(new FileWriter(outFilename));
        int caseCnt = Integer.parseInt(sc.nextLine());
        for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
            pw.print("Case #" + (caseNum + 1) + ": ");
            String[] testCase = sc.nextLine().split("\\s+");
            int X = Integer.parseInt(testCase[0]);
            int R = Integer.parseInt(testCase[1]);
            int C = Integer.parseInt(testCase[2]);
            boolean solvable = true;
            if (X >= 7) {
                solvable = false;
            } else if ((R*C)%X != 0) {
                solvable = false;
            } else if (X > Math.max(R, C)) {
                solvable = false;
            } else if ((X+1)/2 > Math.min(R, C)) {
                solvable = false;
            } else if (X == 4) {
                solvable = (R > 2) && (C > 2);
            } else if (X == 5) {
                solvable = !(Math.min(R, C) == 3 && Math.max(R, C) == 5);
            } else if (X == 6) {
                solvable = Math.min(R, C) > 3;
            }
            if (solvable) {
                pw.println("GABRIEL");
            } else {
                pw.println("RICHARD");
            }
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}