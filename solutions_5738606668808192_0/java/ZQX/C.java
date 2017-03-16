/**
 * Created by qixinzhu on 4/8/16.
 */

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class C {

    public static void genLargeP() throws FileNotFoundException {
        File inputFile = new File("C-small-attempt0.in");
        PrintWriter out = new PrintWriter("test_b.txt");
        Scanner in = new Scanner(inputFile);
        int T = in.nextInt();
        out.println(T);
        for (int i = 0; i < T; i++) {
            out.printf("%d\n", (int) (Math.random() * 100000));
        }
        in.close();
        out.close();
    }

    public static void main(String[] args) throws FileNotFoundException {
        // test case
//        genLargeP();
//        File inputFile = new File("test.txt");
//        PrintWriter out = new PrintWriter("test_out.txt");

        // real case
        File inputFile = new File("C-small-attempt0.in");
        PrintWriter out = new PrintWriter("C_out.txt");
//        File inputFile = new File("C-large.in");
//        PrintWriter out = new PrintWriter("C_out_large.txt");

        Scanner in = new Scanner(inputFile);

        int T = in.nextInt();
        int N = in.nextInt();
        int J = in.nextInt();
        out.println("Case #1:");
        String divisors = "3 4 5 6 7 8 9 10 11";
        int divisor = 11;
        int counter = 0;

        // 11 * 10..010..01
        for (int i = 2; i < N - 3; i++) {
            counter++;
            int[] val = new int[N];
            val[0] = 1;
            val[1] = 1;
            val[N - 1] = 1;
            val[N - 2] = 1;
            val[i] = 1;
            val[i + 1] = 1;
            String answer = "";
            for (int m = 0; m < N; m++) {
                answer += val[m];
            }
            out.printf("%s %s\n", answer, divisors);
        }

        // 11 * 10..010..010..01
        for (int i = 2; i < N - 3; i++) {
            for (int j = i + 2; j < N - 3; j++) {
                counter++;
                int[] val = new int[N];
                val[0] = 1;
                val[1] = 1;
                val[N - 1] = 1;
                val[N - 2] = 1;
                val[i] = 1;
                val[i + 1] = 1;
                val[j] = 1;
                val[j + 1] = 1;
                String answer = "";
                for (int m = 0; m < N; m++) {
                    answer += val[m];
                }
                if (counter <= J) {
                    out.printf("%s %s\n", answer, divisors);
                }
            }
        }

        // 11 * 10..010..010..010..01
        for (int i = 2; i < N - 3; i++) {
            for (int j = i + 2; j < N - 3; j++) {
                for (int k = j + 2; k < N - 3; k++) {
                    counter++;
                    int[] val = new int[N];
                    val[0] = 1;
                    val[1] = 1;
                    val[N - 1] = 1;
                    val[N - 2] = 1;
                    val[i] = 1;
                    val[i + 1] = 1;
                    val[j] = 1;
                    val[j + 1] = 1;
                    val[k] = 1;
                    val[k + 1] = 1;
                    String answer = "";
                    for (int m = 0; m < N; m++) {
                        answer += val[m];
                    }
                    if (counter <= J) {
                        out.printf("%s %s\n", answer, divisors);
                    }
                }
            }
        }
        System.out.println(counter);

        in.close();
        out.close();
    }
}
