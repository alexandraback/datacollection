package codejam2014;


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class PartElf {
    public static void main(String[] args) throws IOException {

        String fileName;

//        fileName = "test.in";
        fileName = "A-small-attempt0.in";
//        fileName = "A-large.in";


        try (BufferedReader r = new BufferedReader(new FileReader(fileName));
             BufferedWriter w = new BufferedWriter(new FileWriter(fileName.replace(".in", ".out")));) {
            Scanner s = new Scanner(r);
            int T = s.nextInt();
            s.nextLine();
            long startTotal = System.currentTimeMillis();
            for (int i = 0; i < T; i++) {
                String str = s.nextLine();
                String[] split = str.split("/");
                long p = Long.parseLong(split[0]);
                long q = Long.parseLong(split[1]);

                w.write("Case #" + (i + 1) + ": " + calc(p, q) + "\n");
                System.out.println("case " + +(i + 1) + ". time: " + (System.currentTimeMillis() - startTotal));
            }
            System.out.println("Total time: " + (System.currentTimeMillis() - startTotal));
        }

    }

    private static String calc(long p, long q) {
        long div = gcd(p, q);
        p /= div;
        q /= div;
        long k = 0;
        while (q != 1) {
            if (q % 2 == 0) {
                q /= 2;
                k++;
            } else {
                return "impossible";
            }
        }

        long logx = 0;
        while (p > 0) {
            p /= 2;
            logx++;
        }
        long res = k - logx + 1;
        if (res <= 40) {
            return "" + res;
        } else {
            return "impossible";
        }
    }


    static long gcd(long a, long b) {
        while (b > 0) {
            long c = b;
            b = a % b;
            a = c;
        }
        return a;
    }

}
