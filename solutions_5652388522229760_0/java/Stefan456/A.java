package qualification;

import java.util.Scanner;
import java.io.FileInputStream;
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

public class A {
    public static void main(String[] args) throws Exception {
        // set up scanner and iterate over test cases
        Scanner scanner = new Scanner(new FileInputStream(
                                          "/storage/emulated/0/Download/A-small-attempt0.in"));
        int T = scanner.nextInt();
        for (int t = 1; t <= T; ++t) {
            // get parameters
            int N = scanner.nextInt();
            // solve problem
            System.out.print("Case #" + t + ": ");
            if (N == 0)
                System.out.println("INSOMNIA");
            else {
                ArrayList<String> unseen = new ArrayList<String>(Arrays.asList(
                    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"));
                for (int i = 1;; ++i) {
                    int number = i * N;
                    for (int index = unseen.size() - 1; index >= 0; --index)
                        if (String.valueOf(number).contains(unseen.get(index)))
                            unseen.remove(index);
                    if (unseen.isEmpty()) {
                        System.out.println(number);
                        break;
                    }
                }
            }
        }
    }
}

