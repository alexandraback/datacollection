package javaapplication2;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class DancingWithTheGooglers {
    private final static String INPUT_PATH = "resources/dancing_with_the_googlers.in";
    private final static String OUTPUT_PATH = "resources/dancing_with_the_googlers.out";
    private static int caseNumber = 0;
    
    public static void main(String[] args) throws FileNotFoundException, IOException {
        try (Scanner scanner = new Scanner(new File(INPUT_PATH))) {
            int T = scanner.nextInt();
            try (FileWriter out = new FileWriter(OUTPUT_PATH)) {
                for (int i = 0; i < T; ++i) {
                    processCase(scanner, out);
                }
            }
        }
    }
    
    private static void processCase(Scanner scanner, FileWriter out) throws IOException {
        out.write("Case #" + (++caseNumber) + ": ");
        int N = scanner.nextInt();
        int S = scanner.nextInt();
        int p = scanner.nextInt();
        int result = 0;
        for (int i = 0; i < N; ++i) {
            int P = scanner.nextInt();
            if ((P + 2) / 3 >= p) {
                ++result;
            } else if (p + 2 * Math.max(p - 2, 0) <= P && S > 0) {
                ++result;
                --S;
            }
        }
        out.write(result + "");
        out.write("\n");
    }
}
