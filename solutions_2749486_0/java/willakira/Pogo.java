import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Pogo {

    public static void main(String[] args) throws IOException {
        System.setOut(new PrintStream("out"));
        System.setIn(new FileInputStream("in"));
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int c = 1; c <= t; c++) {
            int x = in.nextInt();
            int y = in.nextInt();
            int absX = Math.abs(x);
            int absY = Math.abs(y);
            if (absX < absY) {
                int step = 0;
                StringBuilder stringBuilder = new StringBuilder("");
                for (int i = 0; i < absX - 1; i++)
                    stringBuilder.append("WE");
                if (x > 0)
                    stringBuilder.append("WE");
                if (x < 0)
                    stringBuilder.append("W");
                step = stringBuilder.length() + 1;
                if (y == 0) {
                    System.out.println(String.format("Case #%d: %s", c, stringBuilder.toString()));
                    continue;
                }
                if (y > 0) {
                    stringBuilder.append("N");
                }
                if (y < 0) {
                    stringBuilder.append("S");
                }
                int gapY = absY - step;
                for (int i = 0; i < Math.abs(gapY); i++) {
                    if ((gapY > 0 && y > 0) || (gapY < 0 && y < 0))
                        stringBuilder.append("SN");
                    else
                        stringBuilder.append("NS");
                }
                System.out.println(String.format("Case #%d: %s", c, stringBuilder.toString()));
            } else {
                int step = 0;
                StringBuilder stringBuilder = new StringBuilder("");
                for (int i = 0; i < absY - 1; i++)
                    stringBuilder.append("SN");
                if (y > 0)
                    stringBuilder.append("SN");
                if (y < 0)
                    stringBuilder.append("S");
                step = stringBuilder.length() + 1;
                if (x == 0) {
                    System.out.println(String.format("Case #%d: %s", c, stringBuilder.toString()));
                    continue;
                }
                if (x > 0) {
                    stringBuilder.append("E");
                }
                if (x < 0) {
                    stringBuilder.append("W");
                }
                int gapX = absX - step;
                for (int i = 0; i < Math.abs(gapX); i++) {
                    if ((gapX > 0 && x > 0) || (gapX < 0 && x < 0))
                        stringBuilder.append("WE");
                    else
                        stringBuilder.append("EW");
                }
                System.out.println(String.format("Case #%d: %s", c, stringBuilder.toString()));
            }

        }
    }
}
