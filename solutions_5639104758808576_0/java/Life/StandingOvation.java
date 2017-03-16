package codejam2015;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class StandingOvation {
    public static void main(String[] args) throws IOException {
        String fileName;

//        fileName = "test.in";
//        fileName = "A-large.in";
        fileName = "data/A-small-attempt0.in";

        try (BufferedReader r = new BufferedReader(new FileReader(fileName));
             BufferedWriter w = new BufferedWriter(new FileWriter(fileName.replace(".in", ".out")))) {
            Scanner s = new Scanner(r);
            int T = s.nextInt();
            long startTotal = System.currentTimeMillis();
            for (int i = 0; i < T; i++) {
                int sMax = s.nextInt();
                String shyness = s.next();


                w.write("Case #" + (i + 1) + ": " + calc(sMax, shyness) + "\n");
                System.out.println("case " + +(i + 1) + ". time: " + (System.currentTimeMillis() - startTotal));
            }
            System.out.println("Total time: " + (System.currentTimeMillis() - startTotal));
        }

    }

    private static String calc(int sMax, String shyness) {
        int clapping = 0;
        int invite = 0;
        for (int i = 0; i <= sMax; i++) {
            int atLevel = shyness.charAt(i) - '0';
            if (i <= clapping) {
                clapping += atLevel;
            } else {
                int toInvite = i - clapping;
                invite += toInvite;
                clapping += toInvite + atLevel;
            }
        }
        return "" + invite;
    }
}
