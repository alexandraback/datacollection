package CodeJam;

import com.sun.javafx.binding.StringFormatter;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Scanner;

/**
 * User: balder
 * Date: 4/12/15
 * Time: 3:19 AM
 * With Intellij IDEA for JavaTest
 */
public class Q4 {
    public static void main(String[] args) throws IOException {
        FileInputStream inputStream = new FileInputStream("Q4.txt");
        Scanner scanner = new Scanner(inputStream);

        FileOutputStream outputStream = new FileOutputStream("Q4_out.txt");

        String[] names = {"RICHARD", "GABRIEL"};
        int round = scanner.nextInt();
        for (int i = 0; i < round; i++) {
            int X = scanner.nextInt();
            int R = scanner.nextInt();
            int C = scanner.nextInt();

            int res = 0;
            if ((R*C)%X != 0) {
                res = 0;
            } else if (X == 1) {
                res = 1;
            } else if (X == 2) {
                res = 1;
            } else if (X == 3) {
                if (Math.min(R,C) == 1) {
                    res = 0;
                } else {
                    res = 1;
                }
            } else if (X == 4) {
                if (Math.min(R,C) == 4 || Math.min(R,C) == 3) {
                    res = 1;
                } else {
                    res = 0;
                }
            }

            System.out.format("Case #%d: " + names[res] + "\n\n", i+1);
            outputStream.write(StringFormatter.format("Case #%d: " + names[res] + "\n", i + 1).getValue().getBytes());
        }
        outputStream.close();
    }
}
