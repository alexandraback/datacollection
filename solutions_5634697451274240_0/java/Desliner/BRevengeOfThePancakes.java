package codejam.y2016.qualification;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

/**
 * @author Max Myslyvtsev
 * @since 4/8/16
 */
public class BRevengeOfThePancakes {

    public static void main(String[] args) throws Exception {
        //Scanner in = new Scanner(new FileInputStream("/Users/max/Work/Source/foobar/src/main/resources/input.txt"));
        Scanner in = new Scanner(new FileInputStream("/Users/max/Downloads/B-small-attempt0.in"));
        PrintStream out = new PrintStream(new FileOutputStream("/Users/max/Work/Source/foobar/src/main/resources/output.txt"));
        int T = in.nextInt();
        in.nextLine();
        for (int t = 1; t <= T; t++) {
            String s = in.nextLine();
            int a = solve(s);
            String answ = "Case #" + t + ": " + a;
            out.println(answ);
            System.out.println(answ);
        }
        out.close();
    }

    private static int solve(String s) {
        boolean lastValid = s.charAt(0) == '+';
        char lastChar = s.charAt(0);
        int done = 1;
        int flips = 0;
        while (done < s.length()) {
            if (s.charAt(done) == lastChar) {

            } else {
                flips++;
                lastChar = s.charAt(done);
            }
            done++;
        }
        if (lastChar != '+') {
            flips++;
        }
        return flips;
    }
}
