package codejam2015;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Dijkstra {
    public static final int I = 2;
    public static final int J = 3;
    public static final int K = 4;

    private static final int[][] MUL = {
            {1, I, J, K},
            {I, -1, K, -J},
            {J, -K, -1, I},
            {K, J, -I, -1}
    };

    public static void main(String[] args) throws IOException {
        String fileName;

        //fileName = "test.in";
        // fileName = "C-small-attempt0.in";
         fileName = "C-large.in";

        try (BufferedReader r = new BufferedReader(new FileReader(fileName));
             BufferedWriter w = new BufferedWriter(new FileWriter(fileName.replace(".in", ".out")))) {
            Scanner sc = new Scanner(r);
            int T = sc.nextInt();
            long startTotal = System.currentTimeMillis();
            for (int i = 0; i < T; i++) {
                int l = sc.nextInt();
                long x = sc.nextLong();
                sc.nextLine();
                String line = sc.nextLine();

                w.write("Case #" + (i + 1) + ": " + calc(l, x, line) + "\n");
                System.out.println("case " + +(i + 1) + ". time: " + (System.currentTimeMillis() - startTotal));
            }
            System.out.println("Total time: " + (System.currentTimeMillis() - startTotal));
        }

    }

    private static String calc(int l, long x, String line) {
        int rep;
        if (x > 12) {
            rep = (int) (x % 12 + 12);
            while (rep > 12) {
                rep -= 4;
            }
        } else {
            rep = (int) x;
        }

        int[] arr = new int[rep * l];
        for (int i = 0; i < l; i++) {
            arr[i] = toInt(line.charAt(i));
        }

        for (int i = 1; i < rep; i++) {
            for (int j = 0; j < l; j++) {
                arr[i * l + j] = arr[j];
            }
        }

        int total = 1;
        for (int i = 0; i < arr.length; i++) {
            total = mul(total, arr[i]);
        }

        int first = 1;
        int remainder = total;
        for (int i = 0; i < arr.length - 2; i++) {
            int c = arr[i];
            first = mul(first, c);
            remainder = -1 * mul(c, remainder);
            if (I == first) {
                int second = 1;
                int remainder2 = remainder;
                for (int j = i + 1; j < arr.length - 1; j++) {
                    int c2 = arr[j];
                    second = mul(second, c2);
                    remainder2 = -1 * mul(c2, remainder2);
                    if (J == second && K == remainder2) {
                        return "YES";
                    }
                }
            }
        }
        return "NO";
    }

    private static int toInt(char c) {
        switch (c) {
            case '1':
                return 1;
            case 'i':
                return I;
            case 'j':
                return J;
            case 'k':
                return K;
            default:
                throw new RuntimeException("Unknown char:" + c);
        }

    }


    private static int mul(int x1, int x2) {
        int sign = 1;
        if ((x1 > 0 && x2 > 0) ||
                (x1 < 0 && x2 < 0)) {
            sign = 1;
        } else {
            sign = -1;
        }
        return sign * MUL[Math.abs(x1) - 1][Math.abs(x2) - 1];
    }


    private static int[] getArray(Scanner sc, int d) {
        int[] p = new int[d];
        for (int j = 0; j < d; j++) {
            p[j] = sc.nextInt();
        }
        return p;
    }


}
