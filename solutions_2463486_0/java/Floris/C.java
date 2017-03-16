
import java.io.File;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class C {
    static ArrayList<Long> values = new ArrayList<>();
    public static void main(String[] args) throws Exception {
        prepopulate();

        System.setOut(new PrintStream("/home/floris/temp/dev/codejam2013/in/out.txt"));
        Scanner sc = new Scanner(new File("/home/floris/temp/dev/codejam2013/in/C-small-attempt0.in"));
        for (int count = sc.nextInt(), current = 1; count > 0; count--, current++) {
            long start = sc.nextLong();
            long end = sc.nextLong();
            System.out.printf("Case #%d: %s%n", current, solve(start, end));
        }
    }
    public static String solve(long start, long end) {
        long result = 0;
        long smallStart = (long)Math.sqrt(start);
        if (smallStart * smallStart < start) smallStart++;
        long smallEnd = (long)Math.sqrt(end) + 1;
        for (int i = 0; i < values.size(); i++) {
            if (smallStart <= values.get(i) && values.get(i) < smallEnd) result++;
        }
        return ""+result;
    }

    private static void prepopulate() {
        for (long i = 1; i <= 100000000; i++) {
            if (isP(String.valueOf(i)) && isP(String.valueOf(i*i))) {
                //System.out.println(i);
                values.add(i);
            }
        }
    }

    private static boolean isP(String a) {
        for (int i = 0; i < a.length()/2; i++) {
            if (a.charAt(i) != a.charAt(a.length()-i-1)) return false;
        }
        return true;
    }
}
