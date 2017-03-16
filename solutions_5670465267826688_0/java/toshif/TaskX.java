package gcj.qual2015.c;

import java.io.*;
import java.net.URL;
import java.util.Scanner;

/**
 * @author fuku
 */
public class TaskX {

    static final int[][] m = new int[][]{
            {0, 0, 0, 0, 0},
            {0, 1, 2, 3, 4},
            {0, 2, -1, 4, -3},
            {0, 3, -4, -1, 2},
            {0, 4, 3, -2, -1},
    };

    public static void main(String[] args) throws IOException {
        String inFile = "C-small-attempt0.in";

        URL inFileUrl = TaskX.class.getResource(inFile);
        InputStream inputStream = new BufferedInputStream(new FileInputStream(inFileUrl.getFile()));
        Scanner in = new Scanner(inputStream);

        String outFile = inFile + ".out";
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(outFile)));

        System.out.printf("Input File = [%s]\n", inFile);
        System.out.printf("Output File = [%s]\n", outFile);

        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            System.out.println("------------------");
            System.out.println("test " + (i + 1));
            Solver solver = new Solver();
            String ans = solver.solve(i, in, out);
            out.println("Case #" + (i + 1) + ": " + ans);
            System.out.println("Case #" + (i + 1) + ": " + ans);
        }
        out.close();
    }

    static class Solver {

        public String solve(int testNumber, Scanner in, PrintWriter out) {
            long L = in.nextLong();
            long X = in.nextLong();
            in.nextLine();
            String S = in.nextLine();

            if (X > 10) {
                long M = X - 10;
                M = M % 4;
                X = 10 + M;
            }

            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < X; i++) {
                sb.append(S);
            }

            String S2 = sb.toString();

            String t = findLeft(S2, 2);
            t = findRight(t, 4);
            if (red(t) == 3) {
                return "YES";
            } else {
                return "NO";
            }
        }

        int red(String s) {
            if (s == null) return 0;

            int ls = 1;
            for (int i = 0; i < s.length(); i++) {
                ls = mul(ls, getIdx(s.charAt(i)));
            }
            return ls;
        }

        String findLeft(String s, int t) {
            if (s == null) return null;

            char[] cs = s.toCharArray();
            int ls = 1;
            int i = 0;
            for (i = 0; i < cs.length; i++) {
                ls = mul(ls, getIdx(s.charAt(i)));
                if (ls == t) {
                    return s.substring(i + 1);
                }
            }
            return null;
        }

        String findRight(String s, int t) {
            if (s == null) return null;

            char[] cs = s.toCharArray();
            int ls = 1;
            int i = 0;
            for (i = cs.length-1; i >= 0; i--) {
                ls = mul(getIdx(s.charAt(i)), ls);
                if (ls == t) {
                    return s.substring(0, i);
                }
            }
            return null;
        }

        int mul(int a, int b) {
            int signA = Integer.signum(a);
            int signB = Integer.signum(b);
            int r = m[Math.abs(a)][Math.abs(b)];
            return signA * signB * r;
        }

        int getIdx(char c) {
            if (c == 'i') {
                return 2;
            }
            if (c == 'j') {
                return 3;
            }
            if (c == 'k') {
                return 4;
            }
            return 1;
        }
    }
}


