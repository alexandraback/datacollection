import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Paths;
import java.util.Scanner;

public class Bs {

//    private static final String FNAME = "test";
    private static final String FNAME = "small-0";
//    private static final String FNAME = "large-0";

    private static int K;
    private static int L;
    private static int S;

    private static char[] keyboard;
    private static String target;

    private static double sum;
    private static double max;

    public static void main(String[] args) throws IOException {
        String fname = "data/" + "B-" + FNAME + ".";
        Scanner sc = new Scanner(Paths.get(fname + "in"));
        PrintWriter w = new PrintWriter(fname + "out");

        int T = sc.nextInt();
        for (int tc = 0; tc < T; tc++) {

            K = sc.nextInt();
            L = sc.nextInt();
            S = sc.nextInt();
            keyboard = sc.next().toCharArray();
            target = sc.next();

            sum = 0;
            max = 0;
            f1("");

            double num = Math.pow(keyboard.length, S);
            w.printf("Case #%d: %f\n", tc + 1, (max * num - sum) / num);
        }

        w.close();
    }

    private static void f1(String s) {
        if (s.length() < S) {
            for (char c : keyboard) {
                f1(s + c);
            }
            return;
        }

        int pos = -1;
        int z = 0;
        while (true) {
            pos = s.indexOf(target, pos + 1);
            if (pos != -1) {
                z++;
            } else {
                break;
            }
        }
        sum += z;
        if (z > max) {
            max = z;
        }
    }
}
