package codejam2015;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class OminousOmino {

    public static void main(String[] args) throws IOException {
        String fileName;

        //fileName = "test.in";

        fileName = "D-small-attempt1.in";

        try (BufferedReader reader = new BufferedReader(new FileReader(fileName));
             BufferedWriter writer = new BufferedWriter(new FileWriter(fileName.replace(".in", ".out")))) {
            Scanner sc = new Scanner(reader);
            int T = sc.nextInt();
            long startTotal = System.currentTimeMillis();
            for (int i = 0; i < T; i++) {
                int x = sc.nextInt();
                int r = sc.nextInt();
                int c = sc.nextInt();
                writer.write("Case #" + (i + 1) + ": " + calc(x, r, c) + "\n");
                System.out.println("case " + +(i + 1) + ". time: " + (System.currentTimeMillis() - startTotal));
            }
            System.out.println("Total time: " + (System.currentTimeMillis() - startTotal));
        }

    }

    private static String calc(int x, int r, int c) {
        boolean richardWon = false;
        if ((r * c) % x != 0) {
            richardWon = true;
        }
        int max = Math.max(r, c);
        int min = Math.min(r, c);
        if (max < x || min < (x + 1) / 2) {
            richardWon = true;
        }
        if (x == 4) {
            if (min < 3) {
                richardWon = true;
            }
        }
        if (richardWon) {
            return "RICHARD";
        } else {
            return "GABRIEL";
        }
    }
}
