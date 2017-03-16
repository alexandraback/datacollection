import java.io.*;
import java.util.Scanner;

/**
 * Created by kamil on 09.04.2016.
 */
public class Frac {

    public static void main(String[] args) throws IOException {

        int t;
        long k, c, s;

        Scanner scanner = new Scanner(new FileInputStream("c:\\codejam\\frac.in"));
        Writer writer = new OutputStreamWriter(new FileOutputStream("c:\\codejam\\frac.out"));

        t = scanner.nextInt();

        for (int i = 1; i <= t; i++) {

            k = scanner.nextLong();
            c = scanner.nextLong();
            s = scanner.nextLong();
            System.out.println("K:" + k + " C:" + c + " S:" + s);

            writer.write("Case #" + i + ": ");
            System.out.print("Case #" + i + ": ");
            if (k <= c * s) {
                for (int j = 0; j < k; j += c) {
                    long n = 0;
                    for (int m = 0; m < c; m++) {
                        n *= k;
                        if (j + m < k) {
                            n += j + m;
                        }
                    }
                    n += 1;
                    writer.write("" + n + " ");
                    System.out.print("" + n + " ");
                }

            } else {
                writer.write("IMPOSSIBLE");
                System.out.print("IMPOSSIBLE");
            }


            writer.write("\n");
            System.out.println();
        }

        writer.close();
    }
}
