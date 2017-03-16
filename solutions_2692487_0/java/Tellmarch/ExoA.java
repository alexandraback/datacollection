package exoA;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author jean
 */
public class ExoA {

    public static void main(String[] args) {


        String base = "/home/jean/gcj2013/1B/ExoA/";
        String input = base + "s1.in";
        String output = base + "s1.out";

        try {
            Scanner sc = new Scanner(new FileReader(input));
            PrintWriter pw = new PrintWriter(output);

            int n = sc.nextInt();
            sc.nextLine();
            for (int c = 0; c < n; c++) {
                System.out.println("Test case " + (c + 1) + "...");
                pw.print("Case #" + (c + 1) + ": ");
                test(sc, pw);
                pw.println();
            }
            pw.println();
            pw.flush();
            pw.close();
            sc.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(ExoA.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    private static void test(Scanner sc, PrintWriter pw) {
        int a = sc.nextInt();
        int n = sc.nextInt();



        int sizes[] = new int[n];
        for (int i = 0; i < n; i++) {
            sizes[i] = sc.nextInt();
        }
        Arrays.sort(sizes);


        if (a == 1) {
            pw.print(n);
            return;
        }

        int j = 0;
        int o = 0;
        int fo = 1000;
        while (true) {
            while (sizes[j] < a) {
                a += sizes[j];
                j++;
                if (j == n) {
                    pw.print(Math.min(fo, o));
                    return;
                }
            }
            fo = Math.min(fo, o + (n - j));
            while (a <= sizes[j]) {
                a += a - 1;
                o++;
            }
        }

    }
}
