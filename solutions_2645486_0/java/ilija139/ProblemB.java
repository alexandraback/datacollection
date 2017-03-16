package my.codejam.y13.round1a;

import java.io.*;
import java.util.*;

public class ProblemB {

    static void runIt() throws IOException {

        String inFName = "resource/cj13/B-small-attempt0.in";
        // String inFName = "resource/cj13/B-large.in";
        String outFName = "resource/cj13/B-small.out";
        // String outFName = "resource/cj13/B-large.out";

        PrintWriter out = new PrintWriter(new File(outFName));
        Scanner sc = new Scanner(new File(inFName));

        int testCases = Integer.parseInt(sc.nextLine());

        for (int t = 0; t < testCases; ++t) {

            int E = sc.nextInt();
            int R = sc.nextInt();
            int N = sc.nextInt();
            int[] v = new int[N];

            for (int i = 0; i < N; ++i) {
                v[i] = sc.nextInt();
            }

            int currentE = E;
            int sum = 0;
            for (int i = 0; i < N - 1; i += 2) {
                int candidate = currentE;
                int max = 0;
                for (int j = candidate; j > -1; --j) {
                    int temp = j * v[i] + Math.min(E, (currentE - j + R))
                            * v[i + 1];

                    if (temp >= max) {
                        max = temp;
                        candidate = j;
                    }
                }
                currentE = Math.min(E, candidate + R);
                sum += max;
            }

            if (N == 1) {
                sum = v[0] * E;
            }
            if (N % 2 == 1) {
                sum += v[v.length - 1] * currentE;
            }

            StringBuilder output = new StringBuilder();
            output.append("Case #" + (t + 1) + ": ");
            output.append(sum);
            System.out.println(output);
            out.println(output.toString().trim());
        }
        sc.close();

        out.flush();
        out.close();
    }

    public static void main(String[] args) {

        try {
            ProblemB.runIt();
        } catch (IOException e) {

            System.out.println(e.getMessage());
            e.printStackTrace();

        } catch (Exception e) {

            System.out.println(e.getMessage());
            e.printStackTrace();

        }
    }
}
