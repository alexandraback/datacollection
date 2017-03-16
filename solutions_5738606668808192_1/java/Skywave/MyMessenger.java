import java.io.*;
import java.util.Scanner;

public class MyMessenger {
    public static void main(String... args) throws IOException {
        Scanner in = new Scanner(new File("java/in.txt"));
        BufferedWriter out = new BufferedWriter(new FileWriter(new File("java/out.txt")));

        int problemCount = in.nextInt();
        int length = in.nextInt(); // must be even!
        int goal = in.nextInt();
        int partLength = (length - 2) / 2;

        for (int problem = 1; problem <= problemCount; problem++) {
            out.write(String.format("Case #%d:\n", problem));
            int printed = 0;
            for (int a1 = 0; a1 < partLength && printed < goal; a1++) {
                for (int a2 = a1 + 1; a2 < partLength && printed < goal; a2++) {
                    for (int b1 = 0; b1 < partLength && printed < goal; b1++) {
                        for (int b2 = b1 + 1; b2 < partLength && printed < goal; b2++) {
                            char[] result = new char[length];

                            for (int i = 0; i < length; i++) {
                                result[i] = '0';
                            }
                            result[0] = '1';
                            result[length - 1] = '1';

                            result[2 * a1 + 1] = '1';
                            result[2 * a2 + 1] = '1';
                            result[2 * b1 + 2] = '1';
                            result[2 * b2 + 2] = '1';
                            String resultString = new String(result);
                            out.write(String.format("%s 3 2 3 2 7 2 3 2 3\n", resultString));
                            printed++;
                        }
                    }
                }
            }

            System.out.println(printed);
        }

        out.close();
    }
}

