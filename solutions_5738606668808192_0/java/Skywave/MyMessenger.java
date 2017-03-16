import java.io.*;
import java.util.Scanner;

public class MyMessenger {
    public static void main(String... args) throws IOException {
        Scanner in = new Scanner(new File("java/B-large.in"));
        BufferedWriter out = new BufferedWriter(new FileWriter(new File("java/out.txt")));

        int problemCount = 1;
        //small!

        for (int problem = 1; problem <= problemCount; problem++) {
            out.write(String.format("Case #%d:\n", problem));
            int printed = 0;
            for (int i = 0; i < 7 && printed < 50; i++) {
                for (int j = i + 1; j < 7 && printed < 50; j++) {
                    for (int k = 0; k < 7 && printed < 50; k++) {
                        for (int l = k + 1; l < 7 && printed < 50; l++) {
                            char[] result = "1000000000000001".toCharArray();
                            result[2 * i + 1] = '1';
                            result[2 * j + 1] = '1';
                            result[2 * k + 2] = '1';
                            result[2 * l + 2] = '1';
                            String resultString = new String(result);
                            out.write(String.format("%s 3 2 3 2 7 2 3 2 3\n", resultString));
                            printed++;
                        }
                    }
                }
            }
        }

        out.close();
    }
}

