package codejam.round1c;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.*;

/**
 * User: RK
 */
public class B {

    public static class Pair {
        public BigDecimal mx;
        public int count;

        public Pair(BigDecimal mx, int max) {
            this.mx = mx;
            this.count = max;
        }
    }

    public static Pair[][] mem;

    public static int find(String word) {
        for (int s = word.length() - 1; s >= 0; s--) {
            int l = word.lastIndexOf(word.substring(0, s));
            if (l == word.length() - s) {
                return s;
            }
        }
        return 0;
    }

    public static int find(String word, int oldS, char c) {
        String old = word.substring(0, oldS) + c;

        for (int s = old.length() - 1; s >= 0; s--) {
            int l = word.indexOf(old.substring(old.length() - s));
            if (l == 0) {
                return s;
            }
        }
        return 0;
    }


    public static Pair rec(char[] letters, String word, int s, int count) {
        if (count == word.length()) {
            Pair p = rec(letters, word, s, find(word));
            return new Pair(p.mx.add(BigDecimal.ONE), p.count+1);
        }
        if (s == 0) {
            return new Pair(BigDecimal.ZERO, 0);
        }
        if (mem[s][count] != null) {
            return mem[s][count];
        }

        BigDecimal answer = BigDecimal.ZERO;
        int max = 0;
        Pair p;
        for (char c : letters) {
            if (c == word.charAt(count)) {
                p = rec(letters, word, s - 1, count + 1);
            } else {
                p = rec(letters, word, s - 1, find(word, count, c));
            }

            answer = answer.add(p.mx);
            max = Math.max(max, p.count);
        }
        answer = answer.divide(BigDecimal.valueOf(letters.length), 1000, BigDecimal.ROUND_DOWN);
        return mem[s][count] = new Pair(answer, max);
    }

    public static void main(String[] args) throws FileNotFoundException {

        Scanner in = new Scanner(new FileInputStream("test_codejam/b.in"));
        PrintWriter out = new PrintWriter(new FileOutputStream("test_codejam/b.out"));
        //Scanner in = new Scanner(System.in);
        //PrintWriter out = new PrintWriter(System.out);
        int t = in.nextInt();
        int test = 1;
        while (t-- > 0) {
            int k, l, s;
            k = in.nextInt();
            l = in.nextInt();
            s = in.nextInt();
            in.nextLine();
            String letters = in.nextLine();
            String word = in.nextLine();
            mem = new Pair[s + 1][l + 1];

            Pair p = rec(letters.toCharArray(), word, s, 0);
            out.println(String.format(Locale.US, "Case #%d: %.7f", test, p.count - p.mx.doubleValue()));
            //out.println(p.count-p.mx);
            out.flush();
            test++;
        }
        out.close();
    }

}
