package google.code.jam.qualification;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;

/**
 * Created by chen on 4/9/16.
 */
public class A {

    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new FileReader("A.in"));
        PrintWriter out = new PrintWriter(new FileWriter("A.out"));

        int T = Integer.parseInt(in.readLine());

        for (int k = 1; k <= T; k ++) {
            int N = Integer.parseInt(in.readLine());

            if (N != 0) {
                Set<Integer> digits = new HashSet<>();

                int multiplier = 0;
                do {
                    multiplier += 1;
                    int t = N * multiplier;
                    while (t != 0) {
                        digits.add(t % 10);
                        t = t / 10;
                    }
                } while (digits.size() != 10);

                out.printf("Case #%d: %d\n", k, N * multiplier);
            }
            else {
                out.printf("Case #%d: INSOMNIA\n", k);
            }
        }

        in.close();
        out.close();
    }
}
