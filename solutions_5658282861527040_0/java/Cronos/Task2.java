package codejam.y2014.r1b;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Locale;
import java.util.Scanner;

/**
 * @author Cronos
 */
public class Task2 {

    static Scanner input;
    static BufferedWriter output;

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.US);
        input = new Scanner(new File("input.txt"));
        output = new BufferedWriter(new FileWriter("output.txt"));
        int T = input.nextInt();
        for (int i = 1; i <= T; i++) {
            String result = getResult();
            System.out.println("Case #" + i + ": " + result);
            output.write("Case #" + i + ": " + result);
            output.newLine();
        }
        output.close();
    }

    public static String getResult() {
        long A = input.nextLong();
        long B = input.nextLong();
        long K = input.nextLong();
        long result = 0;
        for (long a = 0; a < A; a++) {
            for (long b = 0; b < B; b++) {
                if ((a & b) < K) result++;
            }
        }
        return "" + result;
    }
}
