import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Solution {
    private static double INITIAL_RATE = 2.0;
    public static void main(String args[]) throws FileNotFoundException {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(new File("/Users/ebogdanov/Downloads/output"));
        //PrintWriter out = new PrintWriter(System.out);
        int T = in.nextInt();
        int i, j, k;
        for (int curTest = 1; curTest <= T; curTest++) {
            double C = in.nextDouble();
            double F = in.nextDouble();
            double X = in.nextDouble();
            double curRate = INITIAL_RATE;
            double timeTaken = 0.0;

            while (timeNeeded(C, curRate) + timeNeeded(X, curRate + F) < timeNeeded(X, curRate)) {
                timeTaken += timeNeeded(C, curRate);
                curRate += F;
            }
            timeTaken += timeNeeded(X, curRate);

            out.println("Case #" + curTest + ": " + timeTaken);
        }
        in.close();
        out.close();
    }

    private static double timeNeeded(double goal, double rate) {
        return goal / rate;
    }
}