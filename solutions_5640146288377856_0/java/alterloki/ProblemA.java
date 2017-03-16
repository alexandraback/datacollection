package y2015.contest.r1c;

import java.io.*;
import java.util.Scanner;

/**
 * @author ashevenkov on 10.05.15.
 */
public class ProblemA {

    public static final String TITLE = "A-small-attempt0";
    private static BufferedReader in = prodIn();
    private static BufferedWriter out = prodOut();

    private static BufferedWriter prodOut() {
        try {
            return new BufferedWriter(new FileWriter("codejam/output/" + TITLE + ".out"));
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }

    private static BufferedReader prodIn() {
        try {
            return new BufferedReader(new FileReader("codejam/input/" + TITLE + ".in"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        return null;
    }


    private static BufferedWriter testOut() {
        return new BufferedWriter(new OutputStreamWriter(System.out));
    }

    private static BufferedReader testIn() {
        return new BufferedReader(new InputStreamReader(System.in));
    }

    public static void main(String[] args) throws Exception {
        new ProblemA().solve(in, out);
        out.flush();
        out.close();
    }

    //implement
    private void solve(BufferedReader in, BufferedWriter out) throws Exception {
        Scanner scanner = new Scanner(in);
        int t = scanner.nextInt();
        for(int i = 0; i < t; i++) {
            int r = scanner.nextInt();
            int c = scanner.nextInt();
            int v = scanner.nextInt();
            out.write("Case #" + (i + 1) + ": " + solveCase(r, c ,v));
            out.newLine();
        }
    }

    private int solveCase(int r, int c, int w) {
        int result = (r - 1) * (c / w);
        int parts = (int)Math.ceil((double)c / w);
        result += parts;
        result += w - 1;
        int t = c - w * parts;
        System.out.println(t);
        if(t > 0) {
            double k = Math.log(t) / Math.log(2.0) + 1;
            System.out.println(k);
            result += (int) Math.floor(k);
        }
        return result;
    }
}
