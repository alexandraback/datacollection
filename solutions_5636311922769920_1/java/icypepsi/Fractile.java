package codejam2016.fractiles;

import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Fractile {

    // k is the length of original artwork, "LGL" k= 3
    // c is the complexity, number of iterations
    // s is the students, max number of tiles we can clean
    // the 1~k^c tiles are indexed from 1,
    private static String cleanTiles(int k, int c, int s) {
        // we can represent the index-1 of the tile in base k with width c
        // each digit is the choice at one iteration
        // we can use one cleaned tile to determine at most c tiles
        // thus with s tiles we can determin at most s * c tiles
        if (k > s * c) return " IMPOSSIBLE";

        StringBuilder builder = new StringBuilder();

        // the c-width k-based number covering c digits of the k possible digits
        // note that x here is index - 1
        int d = 0;
        for (int i = 0; i < k; i += c) {
            long x = 0;
            for (int j = 0; j < c && d < k; ++j, ++d)
                x = x * k + d;
            builder.append(" ").append(x + 1);
        }
        return builder.toString();
    }

    private static void run(Scanner sc, PrintWriter pw) {
        int t = sc.nextInt(); // number of test cases
        for (int i = 0; i < t; ++i) {
            int k = sc.nextInt();
            int c = sc.nextInt();
            int s = sc.nextInt();
            pw.printf("Case #%d:%s\n", i + 1, cleanTiles(k, c, s));
        }
    }

    public static void main(String[] args) {
        try {
            String in = args[0];
            String out = args[1];

            Scanner sc = new Scanner(new FileReader(in));
            PrintWriter pw = new PrintWriter(out);

            run(sc, pw);

            pw.println();
            pw.flush();
            pw.close();
            sc.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
