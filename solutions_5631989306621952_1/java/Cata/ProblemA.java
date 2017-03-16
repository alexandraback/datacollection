import java.io.File;
import java.io.PrintStream;
import java.util.List;
import java.util.Scanner;

public class ProblemA {
    private final String s;

    public ProblemA(String s) {
        this.s = s;
    }


    public String solution() {
        char first = s.charAt(0);
        String result = first + "";
        for (int i = 1; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c >= first) {
                result = c + result;
                first = c;
            } else {
                result += c;
            }
        }
        return result;
    }

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new File("A.in"));
//        PrintStream out = System.out;
        PrintStream out = new PrintStream("A.out");
        int TOTAL_TESTS = in.nextInt();
        for (int t = 1; t <= TOTAL_TESTS; t++) {
            String s = in.next();
            out.println("Case #" + t + ": " + new ProblemA(s).solution());
        }
    }

}
