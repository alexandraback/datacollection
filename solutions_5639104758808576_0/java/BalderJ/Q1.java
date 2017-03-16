package CodeJam;

import com.sun.javafx.binding.StringFormatter;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Scanner;

/**
 * User: balder
 * Date: 4/11/15
 * Time: 2:15 PM
 * With Intellij IDEA for JavaTest
 */
public class Q1 {

    public static void main(String[] args) throws IOException {
        FileInputStream inputStream = new FileInputStream("Q1.txt");
        Scanner scanner = new Scanner(inputStream);

        FileOutputStream outputStream = new FileOutputStream("Q1_out.txt");

        int round = scanner.nextInt();
        for (int i = 0; i < round; i++) {
            int max = scanner.nextInt();
            String audience = scanner.next();
            System.out.println("Round:"+i+" "+audience);
            int need = 0;
            int stood = audience.charAt(0) - '0';
            for (int j = 1; j < audience.length(); j++) {
                int current = audience.charAt(j) - '0';
                if (stood < j) {
                    int toAdd = j-stood;
                    stood += toAdd;
                    need += toAdd;
                }
                stood += current;
            }
            System.out.format("Case #%d: %d\n\n", i+1, need);
            outputStream.write(StringFormatter.format("Case #%d: %d\n", i+1, need).getValue().getBytes());
        }
        outputStream.close();
    }
}
