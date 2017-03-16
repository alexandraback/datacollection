// @gilesgardam
import java.util.*;
import static java.lang.Math.*;

public class ProblemB {

    void run() {
        Scanner sc = new Scanner(System.in);
        int numCases = sc.nextInt();
        for (int caseNum = 1; caseNum <= numCases; caseNum++) {
            int X = sc.nextInt();
            int Y = sc.nextInt();
            String answer = "";
            for (int i = 0; i < X; ++i) {
                answer += "WE";
            }
            for (int i = 0; i < -X; ++i) {
                answer += "EW";
            }
            for (int i = 0; i < Y; ++i) {
                answer += "SN";
            }
            for (int i = 0; i < -Y; ++i) {
                answer += "NS";
            }

            System.out.printf("Case #%d: %s\n", caseNum, answer);
        }
    }

    boolean debug = false;
    void p(String f, Object...params) {
        System.out.printf(f, params);
    }
    void d(Object...params) {
        if (debug) {
            p("DEBUG: %s\n", Arrays.deepToString(params));
        }
    }
    void die() {
        throw new RuntimeException();
    }
    public ProblemB(String[] args) {
        if (args.length > 0 && args[0].equals("debug")) {
            debug = true;
        }
    }
    public static void main(String[] args) {
        new ProblemB(args).run();
    }
}
