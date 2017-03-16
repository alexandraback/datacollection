import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class ProblemD {

    public static void main(String[] args) throws Exception {
//        Scanner in = new Scanner(System.in);
//        PrintStream out = System.out;
        Scanner in = new Scanner(new File("D.in"));
        PrintStream out = new PrintStream("D.out");
        int TOTAL_TESTS = in.nextInt();
        for (int t = 1; t <= TOTAL_TESTS; t++) {
            int k, c, s;
            k = in.nextInt();
            c = in.nextInt();
            s = in.nextInt();
            out.print("Case #" + t + ":");
            for (int i = 1; i <= k; i++) {
                out.print(" " + i);
            }
            out.println();
        }
    }

}
