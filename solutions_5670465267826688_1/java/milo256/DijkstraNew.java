import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Scanner;

//import static java.lang.System.out;

public class DijkstraNew {
    public static int[][] mult = {{}, {0, 1, 2, 3, 4}, {0, 2, -1, 4, -3}, {0, 3, -4, -1, 2}, {0, 4, 3, -2, -1}};
    public static HashMap<Character, Integer> chars;
    static {
        chars = new HashMap<>();
        chars.put('i', 2);
        chars.put('j', 3);
        chars.put('k', 4);
    }

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("C-large.in"));
//        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(new File("DijkstraNew.out"));
        int loops = in.nextInt();
        out: for (int loop = 1; loop <= loops; loop++) {
            String ans = "YES";

            long l = in.nextLong();
            long x = in.nextLong();
            x = Math.min(x, 20 + x % 4);
//            x = x % 4;
            String part = in.next();
            String line = "";
            for (int i = 0; i < x; i++) {
                line += part;
            }
            int c = 1;
            int i = 0;
            while (c != 2 && i < line.length()) {
                c = mult(c, chars.get(line.charAt(i++)));
            }
            c = 1;

            int j = line.length() - 1;
            while (c != 4 && i < j) {
                c = mult(chars.get(line.charAt(j--)), c);
            }

            if(i < line.length() && i <= j) {
                c = 1;
                String middle = line.substring(i, j + 1);
                for (char a : middle.toCharArray()) {
                    c = mult(c, chars.get(a));
                }
                if (c != 3)
                    ans = "NO";
            }
            else
                ans = "NO";

            out.printf("Case #%d: %s%n", loop, ans);
        }

        in.close();
        out.close();
    }

    static int mult(int a, int b) {
        int ret = 1;
        if (a < 0) {
            ret = -ret;
            a = -a;
        }
        if (b < 0) {
            ret = -ret;
            b = -b;
        }
        ret *= mult[a][b];
        return ret;
    }
}
