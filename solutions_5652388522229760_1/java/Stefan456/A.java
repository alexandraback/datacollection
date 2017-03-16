package qualification;

import java.util.Scanner;
import java.io.FileInputStream;
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;
import java.io.PrintStream;

public class A {
    public static void main(String[] args) throws Exception {
        // set up scanner and iterate over test cases
        Scanner scanner = new Scanner(new FileInputStream(
                                      "/storage/emulated/0/Download/A-large.in"));
        PrintStream output = new PrintStream(
            "/storage/emulated/0/Download/A-large.out");
        int T = scanner.nextInt();
        for (int t = 1; t <= T; ++t) {
            // get parameters
            int N = scanner.nextInt();
            // solve problem
            output.print("Case #" + t + ": ");
            if (N == 0)
                output.println("INSOMNIA");
            else {
                ArrayList<String> unseen = new ArrayList<String>(Arrays.asList(
                    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"));
                for (int i = 1;; ++i) {
                    int number = i * N;
                    for (int index = unseen.size() - 1; index >= 0; --index)
                        if (String.valueOf(number).contains(unseen.get(index)))
                            unseen.remove(index);
                    if (unseen.isEmpty()) {
                        output.println(number);
                        break;
                    }
                }
            }
        }
        output.close();
        System.out.println("finished");
    }
}

