
import java.io.File;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class A {
    static long[] others;
    public static void main(String[] args) throws Exception {
        System.setOut(new PrintStream("/home/floris/temp/dev/codejam2013/src/out.txt"));
        Scanner sc = new Scanner(new File("/home/floris/temp/dev/codejam2013/src/A-large.in"));
        for (int count = sc.nextInt(), current = 1; count > 0; count--, current++) {
            long armin = sc.nextLong();
            others = new long[sc.nextInt()];
            for (int i = 0; i < others.length; i++) others[i] = sc.nextLong();
            Arrays.sort(others);
//            for (int i = 0; i < others.length; i++) System.out.print(others[i]+" ");
//            System.out.println("\n"+armin);

            System.out.printf("Case #%d: %d%n", current, count(armin, 0));
        }
    }

    private static int count(long a, int i) {
        if (a == 1 && a <= others[i]) return others.length - i;
        if (i >= others.length) return 0;

        if (a > others[i]) {
            return count(a + others[i], i+1);
        }
        int ops = 0;
        while (a <= others[i]) {a+=a-1; ops++;}
        return Math.min(others.length - i, ops + count(a + others[i], i+1));
    }
}
