package codejam;

import java.io.*;
import java.util.Scanner;

/**
 * Created by chengpan on 4/15/16.
 */
public class LastWord {

    public static void main(String[] args) throws Exception {
        final BufferedInputStream in = new BufferedInputStream(new FileInputStream(new File("A-small-attempt0.in")));
        Scanner sc = new Scanner(in);
        final BufferedWriter writer = new BufferedWriter(new FileWriter(new File("output.out")));

        int T = sc.nextInt();

        for (int i = 0;i<T;i++) {
            String str = sc.next();

            writer.write(String.format("Case #%d: %s\n", i+1, solve(str)));
        }

        in.close();
        writer.close();
    }

    private static String solve(String str) {
        StringBuilder sb = new StringBuilder();
        sb.append(str.charAt(0));
        char ch = str.charAt(0);

        for (int i = 1; i<str.length(); i++) {
            if (str.charAt(i) >= ch) {
                sb.insert(0, str.charAt(i));
                ch = str.charAt(i);
            } else {
                sb.append(str.charAt(i));
            }
        }

        return sb.toString();
    }
}
