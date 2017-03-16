import java.io.*;
import java.util.*;
import java.util.regex.Pattern;

public class A {
    public static void main(String[] args) throws Exception {
//        InputStream in = System.in;
        InputStream in = new FileInputStream("/home/floris/Downloads/A-large.in");
        System.setOut(new PrintStream("/home/floris/dev/java/Codejam2016/src/A.out"));
        Scanner sc = new Scanner(in);
        sc.useDelimiter(Pattern.compile("[\n /]"));

        for (int c = 1, cases = sc.nextInt(); c <= cases; c++) {
            String s = sc.next();
            System.out.printf("Case #%d: %s%n", c, f(s));
        }
    }

    private static String f(String s) {
        if (s.length() == 0) return "";
        for (char a = 'Z'; a>='A'; a--) {
            int i = s.lastIndexOf(a);
            if (i>=0) {
                return Character.toString(a) + f(s.substring(0, i)) + s.substring(i+1);
            }
        }
        throw new RuntimeException();
    }
}
