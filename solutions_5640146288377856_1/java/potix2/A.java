package gcj2015.r1c;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class A {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new FileReader(args[0]));
        FileWriter writer = new FileWriter(args[1]);
        int t = scanner.nextInt();
        for(int i = 1; i <= t; i++) {
            int r = scanner.nextInt();
            int c = scanner.nextInt();
            int w = scanner.nextInt();
            int score = run(r, c, w);
            String result = String.format("Case #%d: %d", i, score);

            //System.out.println(result);
            writer.append(result);
            writer.append("\n");
        }
        writer.close();
    }

    public static int run(int r, int c, int w) {
        int reminder = c % w;
        if ( reminder == 0 ) {
            return (c / w) * (r - 1) + (c / w) + (w - 1);
        }
        else {
            return (c / w) * (r - 1) + (c / w) + w;
        }
    }
}
