package qual;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
    private static final String PROBLEM = "qual/A-large";
    private final Scanner in;
    public A(Scanner in) {
        this.in = in;
    }

    private String runCase() {
        in.nextInt();
        String shyness = in.next();
        int numSpent = 0;
        int numLeft = 0;
        for (char c : shyness.toCharArray()) {
            numLeft += c - '0';
            if (numLeft > 0) {
                numLeft--;
            } else {
                numSpent++;
            }
        }
        return String.format("%s", numSpent);
    }

    private void runCases() throws FileNotFoundException {
        int numCases = in.nextInt();
        PrintWriter writer = new PrintWriter(PROBLEM + ".out");
        for (int casenum = 1; casenum <= numCases; casenum++) {
            String result = runCase();
            System.out.printf("Case #%d: %s%n", casenum, result);
            writer.printf("Case #%d: %s%n", casenum, result);
            writer.flush();
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(PROBLEM + ".in"));
        new A(in).runCases();
    }
}
