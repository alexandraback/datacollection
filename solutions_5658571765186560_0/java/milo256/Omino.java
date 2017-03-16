import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Omino {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("D-small-attempt1.in"));
        PrintWriter out = new PrintWriter(new File("Omino.out"));
        int loops = in.nextInt();
        for (int loop = 1; loop <= loops; loop++) {
            boolean rich = false;

            int x = in.nextInt();
            int r = in.nextInt();
            int c = in.nextInt();

            if(r * c % x != 0) {
                rich = true;
            }
            else if (x >= r + c)
                rich = true;
            else if(constricts(x, r, c) || constricts(x, c, r))
                rich = true;

            out.printf("Case #%d: %s%n", loop, rich ? "RICHARD" : "GABRIEL");
        }

        in.close();
        out.close();
    }

    private static boolean constricts(int x, int r, int c) {
        if(r == 1 || c == 1)
            return x > 2;

        return x >= c + c;
    }
}
