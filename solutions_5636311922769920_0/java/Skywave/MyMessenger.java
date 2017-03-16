import java.io.*;
import java.util.Scanner;

public class MyMessenger {
    public static void main(String... args) throws IOException {
        Scanner in = new Scanner(new File("java/D-small-attempt0.in"));
        BufferedWriter out = new BufferedWriter(new FileWriter(new File("java/out.txt")));

        // small only!

        int problemCount = in.nextInt();
        for (int problem = 1; problem <= problemCount; problem++) {
            int k = in.nextInt();
            int c = in.nextInt();
            int s = in.nextInt();
            out.write(String.format("Case #%d: ", problem));

            long pow = 1;
            for (int i = 1; i < c; i++) {
                pow *= k;
            }

            for (int i = 0; i < s; i++) {
                out.write(String.format("%d ", pow * i + 1));
            }

            out.newLine();
        }

        out.close();
    }
}

