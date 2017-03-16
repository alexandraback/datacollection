import java.util.Arrays;
import java.util.Scanner;

public class match {

    static long best = 0;
    static char[] bestA, bestB;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int lines = in.nextInt();
        in.nextLine();

        for (int line = 0; line < lines; line++) {
            char[] coders = in.next().toCharArray();
            char[] jammers = in.next().toCharArray();

            char[] a = new char[20];
            char[] b = new char[20];
            Arrays.fill(a, '0');
            Arrays.fill(b, '0');

            for (int i = 0; i < coders.length; i++) {
                a[19-i] = coders[coders.length - 1 - i];
            }
            for (int i = 0; i < jammers.length; i++) {
                b[19-i] = jammers[jammers.length - 1 - i];
            }


//            System.out.println(a);
//            System.out.println(b);
            best = Integer.MAX_VALUE;
            recurse(a, b, 0);

            System.out.print("Case #" + (line + 1) + ": ");
            for (int i = 0; i < coders.length; i++) {
                System.out.print(bestA[20- coders.length + i]);
            }
            System.out.print(" ");
            for (int i = 0; i < jammers.length; i++) {
                System.out.print(bestB[20- jammers.length + i]);
            }
            System.out.println();
        }
    }

    static void recurse(char[] a, char[] b, int depth) {
        if(depth == a.length) {
            long test = dist(a, b);
            if(test < best) {
                best = test;
                bestA = Arrays.copyOf(a, 20);
                bestB = Arrays.copyOf(b, 20);
            }
            return;
        }
        if(a[depth] != '?' && b[depth] != '?') {
            recurse(a, b, depth + 1);
            return;
        }

        if(closest(a,b) >= best)
            return;

        if(a[depth] == '?') {
            for (int i = 0; i <= 9; i++) {
                a[depth] = (char) ('0' + i);
                recurse(a, b, depth);
            }
            a[depth] = '?';
        }
        else if(b[depth] == '?') {
            for (int i = 0; i <= 9; i++) {
                b[depth] = (char) ('0' + i);
                recurse(a, b, depth);
            }
            b[depth] = '?';
        }

    }

    static long max(final char[] arr) {
        long ret = 0;
        for (char c : arr) {
            ret *= 10;
            if(c == '?')
                c = '9';
            ret += c - '0';
        }
        return ret;
    }

    static long min(final char[] arr) {
        long ret = 0;
        for (char c : arr) {
            ret *= 10;
            if(c == '?')
                c = '0';
            ret += c - '0';
        }
        return ret;
    }

    static long closest(final char[] a, final char[] b) {
        if (min(a) > max(b)) {
            return min(a) - max(b);
        }
        else if(min(b) > max(a)) {
            return min(b) - max(a);
        }
        return 0;
    }

    static long dist(final char[] a, final char[] b) {
        return Math.abs(min(a) - min(b));
    }

}
