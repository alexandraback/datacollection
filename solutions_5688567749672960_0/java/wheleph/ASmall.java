package wheleph.gcj2015.round1b;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class ASmall {
    private static final String INPUT_FILE = "/A-small-attempt1.in";
    private static final String OUTPUT_FILE = "src/main/resources/A-small-attempt1.out";

    public static void main(String[] args) throws FileNotFoundException {
        InputStream inputStream = ASmall.class.getResourceAsStream(INPUT_FILE);
        Scanner scanner = new Scanner(inputStream);

        PrintWriter printWriter = new PrintWriter(new FileOutputStream(OUTPUT_FILE));

        int t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            long n = scanner.nextInt();
            int count = 1;

            while (n > 1) {
                long cand1 = n - 1;
                long cand2 = cand1;
                if (!isPowerOf10(n)) {
                    cand2 = reverseInt(n);
                }

                n = Math.min(cand1, cand2);

                System.out.print(n + " ");

                count++;
            }

            System.out.println("\n");

            printWriter.print(String.format("Case #%d: %d%n", i + 1, count));
        }

        scanner.close();
        printWriter.close();
    }

    private static long reverseInt(long value) {
        long reversedValue = 0;
        while (value != 0) {
            reversedValue = reversedValue * 10 + value % 10;
            value = value / 10;
        }

        return reversedValue;
    }

    private static boolean isPowerOf10(long value) {
        return value % 10 == 0;
//        assert value > 0;
//        assert value < 1000000000000000L;
//
//        return (value == 10 ||
//                value == 100 ||
//                value == 1000 ||
//                value == 10000 ||
//                value == 100000 ||
//                value == 1000000 ||
//                value == 10000000 ||
//                value == 100000000 ||
//                value == 1000000000 ||
//                value == 10000000000L ||
//                value == 100000000000L ||
//                value == 1000000000000L ||
//                value == 10000000000000L ||
//                value == 100000000000000L);
    }
}
