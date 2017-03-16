package codejam.y2013.r1c;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

/**
 * @author Cronos
 */
public class Task2 {

    static Scanner input;
    static BufferedWriter output;

    public static void main(String[] args) throws Exception {
        input = new Scanner(new File("D:/Programming/Projects/CodeJam/input.txt"));
        output = new BufferedWriter(new FileWriter("D:/Programming/Projects/CodeJam/output.txt"));
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
        int x = input.nextInt();
        int y = input.nextInt();
        StringBuilder sb = new StringBuilder();

        if (y > 0) {
            for (int i = 0; i < Math.abs(y); i++) {
                sb.append("SN");
            }
        } else if (y < 0) {
            for (int i = 0; i < Math.abs(y); i++) {
                sb.append("NS");
            }
        }

        if (x > 0) {
            for (int i = 0; i < Math.abs(x); i++) {
                sb.append("WE");
            }
        } else if (x < 0) {
            for (int i = 0; i < Math.abs(x); i++) {
                sb.append("EW");
            }
        }

        return sb.toString();
    }
}
