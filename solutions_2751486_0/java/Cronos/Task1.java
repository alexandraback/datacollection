package codejam.y2013.r1c;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.Scanner;

/**
 * @author Cronos
 */
public class Task1 {

    static Scanner input;
    static BufferedWriter output;

    public static void main(String[] args) throws Exception {
        input = new Scanner(new File("D:/Programming/Projects/CodeJam/input.txt"));
        output = new BufferedWriter(new FileWriter("D:/Programming/Projects/CodeJam/output.txt"));
        int T = input.nextInt();
        input.nextLine();
        for (int i = 1; i <= T; i++) {
            String result = getResult();
            System.out.println("Case #" + i + ": " + result);
            output.write("Case #" + i + ": " + result);
            output.newLine();
        }
        output.close();
    }

    public static String getResult() {
        String name = input.nextLine();
        int n = Integer.valueOf(name.split(" ")[1]);
        name = name.split(" ")[0];
        int L = name.length();
        BigInteger res = BigInteger.ZERO;
        int con = 0;
        int last = -1;
        for (int i = 0; i < L; i++) {
            char c = name.charAt(i);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') con = 0;
            else con++;
            if (con >= n && last != -1) {
                res = res.add(BigInteger.valueOf(L - i).multiply(BigInteger.valueOf(i - (n - 1) + 1 - (last - n + 2))));
                last = i;
            } else if (con >= n && last == -1) {
                res = res.add(BigInteger.valueOf(L - i).multiply(BigInteger.valueOf(i - (n - 1) + 1)));
                last = i;
            }
        }
        return res.toString();
    }
}
