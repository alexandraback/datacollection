package codejam.y2013.r1a;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

/**
 * @author Cronos
 */
public class Task1 {

    static Scanner input;
    static BufferedWriter output;

    public static void main(String[] args) throws Exception {
        input = new Scanner(new File("D:/Programming/Projects/CodeJam/input.txt"));
        output = new BufferedWriter(new FileWriter("D:/Programming/Projects/CodeJam/output.txt"));
        int T = input.nextInt();
        for (int i = 1; i <= T; i++) {
            String result = getResult();
            System.out.println("Case #" + i + ": " + result);
            output.write("Case #" + i + ": " + result);
            output.newLine();
        }
        output.close();
    }

    public static String getResult() {
        long r = input.nextLong();
        long t = input.nextLong();
        long p = 0;
        long count = 0;
        while (true) {
            long tp = getPaintAmount(r);
            if (p + tp > t) return "" + count;
            p += tp;
            r += 2;
            count++;
        }
    }

    private static long getPaintAmount(long r) {
        return 2*r + 1;
    }
}
