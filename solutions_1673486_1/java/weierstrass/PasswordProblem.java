package javaapplication2;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class PasswordProblem {
    
    private final static String INPUT_PATH = "resources/password_problem.in";
    private final static String OUTPUT_PATH = "resources/password_problem.out";
    private static int caseNumber = 0;

    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner scanner = new Scanner(new File(INPUT_PATH));
        
        int T = scanner.nextInt();
        
        //scanner.useDelimiter("\n|");
        try (FileWriter out = new FileWriter(OUTPUT_PATH)) {
            while (scanner.hasNext()) {
                processCase(scanner, out);
            }
        }
    }
    
    private static double[] pr = new double[999999];
    
    private static void processCase(Scanner scanner, FileWriter out) throws IOException {
        out.write("Case #" + (++caseNumber) + ": ");
        int A = scanner.nextInt(), B = scanner.nextInt();
        double prev = 1.0;
        for (int i = 0; i < A; ++i) {
            pr[i] = prev * scanner.nextDouble();
            prev = pr[i];
        }
        double keepTyping = (B - A + 1) * prev + (1.0 - prev) * (2 * B - A + 2);
        double best = keepTyping;
        for (int i = 1; i < A; ++i)  {
            double backspace = pr[A - i - 1] * (B - A + 1 + 2 * i) + (1 - pr[A - i - 1]) * (2 * B - A + 2 + 2 * i);
            best = Math.min(best, backspace);
        }
        double giveUp = B + 2;
        best = Math.min(best, giveUp);
        out.write(best + "");
        out.write("\n");
    }
}
