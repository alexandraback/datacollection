package qualification;

import java.util.Scanner;
import java.io.FileInputStream;
import java.io.PrintStream;

public class D {
    public static void main(String[] args) throws Exception {
        // set up scanner and iterate over test cases
        Scanner scanner = new Scanner(new FileInputStream(
            "/storage/emulated/0/Download/D-small-attempt0.in"));
        PrintStream output = new PrintStream(
            "/storage/emulated/0/Download/D-small-attempt0.out");
        int T = scanner.nextInt();
        for (int t = 1; t <= T; ++t) {
            // get parameters
            int K = scanner.nextInt();
            int C = scanner.nextInt();
            int S = scanner.nextInt();
            // solve problem
            output.print("Case #" + t + ":");
            for (int k = 1; k <= K; ++k)
                output.print(" " + k);
            output.println();
        }
        output.close();
        System.out.println("finished");
    }
}

