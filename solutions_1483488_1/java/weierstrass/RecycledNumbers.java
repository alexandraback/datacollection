package javaapplication2;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class RecycledNumbers {

    private final static String INPUT_PATH = "resources/recycled_numbers.in";
    private final static String OUTPUT_PATH = "resources/recycled_numbers.out";
    private static int caseNumber = 0;
    private final static int[] TEN_POWS =
            new int[]{1, 10, 100, 1000, 10000, 100000, 1000000};

    public static void main(String[] args) throws FileNotFoundException, IOException {
        try (Scanner scanner = new Scanner(new File(INPUT_PATH))) {
            int T = scanner.nextInt();
            try (FileWriter out = new FileWriter(OUTPUT_PATH)) {
                for (int i = 0; i < T; ++i) {
                    processCase(scanner, out);
                }
            }
        }
    }

    private static void processCase(Scanner scanner, FileWriter out) throws IOException {
        out.write("Case #" + (++caseNumber) + ": ");
        Set<Pair> pairs = new HashSet<>();
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int result = 0;
        for (int n = A; n <= B; ++n) {
            int shiftCount = ((int) Math.floor(Math.log10(n)));
            for (int i = 1; i <= shiftCount; ++i) {
                int right = n / TEN_POWS[i];
                int left = n % TEN_POWS[i];
                int shifted = left * TEN_POWS[shiftCount + 1 - i] + right;
                if (shifted != n && shifted <= B && shifted >= A
                        && ((int) Math.floor(Math.log10(n))) == shiftCount) {
                    Pair pair = new Pair(n, shifted);
                    if (!pairs.contains(pair)) {
                        ++result;
                        pairs.add(pair);
                    }
                }
            }
        }
        out.write(result + "");
        out.write("\n");
    }

    private static class Pair {

        private int a, b;

        public Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public boolean equals(Object that) {
            if (that instanceof Pair) {
                Pair pair = (Pair) that;
                if (this.a == pair.a && this.b == pair.b) {
                    return true;
                }
                if (this.a == pair.b && this.b == pair.a) {
                    return true;
                }
            }
            return false;
        }

        @Override
        public int hashCode() {
            return new Integer(a).hashCode() + new Integer(b).hashCode();
        }
    }
}
