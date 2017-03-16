package CodeJam;

import com.sun.javafx.binding.StringFormatter;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.*;

/**
 * User: balder
 * Date: 4/11/15
 * Time: 2:44 PM
 * With Intellij IDEA for JavaTest
 */
public class Q2 {

    public static void main(String[] args) throws IOException {
        FileInputStream inputStream = new FileInputStream("Q2.txt");
        Scanner scanner = new Scanner(inputStream);

        FileOutputStream outputStream = new FileOutputStream("Q2_out.txt");

        int round = scanner.nextInt();
        for (int i = 1; i < round+1; i++) {
            List<Integer> plates = new ArrayList<>();
            int dCount = scanner.nextInt();
            int ret = 0;
            for (int j = 0; j < dCount; j++) {
                int amount = scanner.nextInt();
                plates.add(amount);
                if (amount > ret) {
                    ret = amount;
                }
                System.out.format("%d ", amount);
            }
            System.out.println();
            int min = 1;
            while (min < ret) {
                int minutes = 0;
                for (int amount : plates) {
                    minutes += amount/min + (amount%min > 0 ? 1 : 0) - 1;
                }
                minutes += min;
                System.out.format("min %d, step, %d\n", min, minutes);
                ret = ret > minutes ? minutes : ret;
                min += 1;
            }

            System.out.format("Case #%d: min %d, step %d\n\n", i, min-1, ret);
            outputStream.write(StringFormatter.format("Case #%d: %d\n", i, ret).getValue().getBytes());
        }
        outputStream.close();
    }
}
