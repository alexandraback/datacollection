import java.io.*;
import java.util.*;
import java.util.regex.Pattern;

public class A {
    public static void main(String[] args) throws Exception {
//        InputStream in = System.in;
        InputStream in = new FileInputStream("/home/floris/Downloads/A-small-attempt0.in");
        System.setOut(new PrintStream("/home/floris/dev/java/Codejam2016/src/A.out"));
        Scanner sc = new Scanner(in);
        sc.useDelimiter(Pattern.compile("[\n /]"));

        for (int c = 1, cases = sc.nextInt(); c <= cases; c++) {
            long a = sc.nextLong();

            if (a == 0) {
                System.out.printf("Case #%d: INSOMNIA%n", c);
                continue;
            }
            int i = 0;
            int found = 0;
            for (; found != 0b11111_11111;) {
                i++;
                long b = i * a;

                while (b != 0) {
                    found |= (1<<(b%10));
                    b /= 10;
                }
            }
            System.out.printf("Case #%d: %d%n", c, i * a);
        }
    }
}
