package codejam.y2016.round1b;

import codejam.template.Runner;
import codejam.template.Solver;

import java.io.PrintStream;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * Created by raggzy on 4/30/2016.
 */
public class A extends Solver {

    public A(Scanner in, PrintStream out, int TC) {
        super(in, out, TC);
    }

    private static void reduce(int[] countChar, String str, int occurences) {
        for (int i = 0; i < str.length(); i++) {
            countChar[str.charAt(i)] -= occurences;
        }
    }

    /**
     * By Precalcer
     * G EIGHT
     * U FOUR
     * W TWO
     * X SIX
     * Z ZERO
     * F FIVE
     * H THREE
     * O ONE
     * R THREE
     * S SEVEN
     * T THREE
     * E NINE
     * I NINE
     * N NINE
     */
    private static class Num {
        private final char c;
        private final int d;
        private final String s;

        public Num(char c, int digit, String s) {
            this.c = c;
            this.d = digit;
            this.s = s;
        }
    }

    private static List<Num> ORDER = Arrays.asList(
            new Num('G', 8, "EIGHT"),
            new Num('U', 4, "FOUR"),
            new Num('W', 2, "TWO"),
            new Num('X', 6, "SIX"),
            new Num('Z', 0, "ZERO"),
            new Num('F', 5, "FIVE"),
            new Num('H', 3, "THREE"),
            new Num('O', 1, "ONE"),
            new Num('S', 7, "SEVEN"),
            new Num('E', 9, "NINE")
    );

    @Override
    public void solve() {
        String s = in.nextLine();
        int[] count = new int[255];
        for (int i = 0; i < s.length(); i++) {
            count[s.charAt(i)]++;
        }
        int[] countDig = new int[10];
        for (Num n : ORDER) {
            countDig[n.d] = count[n.c];
            reduce(count, n.s, countDig[n.d]);
        }
        StringBuilder sb = new StringBuilder();
        for (int d = 0; d < 10; d++) {
            for (int t = 0; t < countDig[d]; t++) {
                sb.append(d);
            }
        }
        println("Case #%d: %s", TC, sb.toString());
    }

    public static void main(String[] args) throws Exception {
        /*
        String[] SS = new String[]{"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
        Set<String>[] canGive = new Set[255];
        for (char c = 'A'; c <= 'Z'; c++) {
            canGive[c] = new HashSet<>();
        }
        for (String S : SS) {
            for (char c : S.toCharArray()) {
                canGive[c].add(S);
            }
        }
        while (true) {
            List<String> uniqs = new ArrayList<>();
            for (char c = 'A'; c <= 'Z'; c++) {
                if (canGive[c].size() == 1) {
                    String uniq = canGive[c].stream().findFirst().get();
                    System.out.println(String.format("%c %s", c, uniq));
                    uniqs.add(uniq);
                }
            }
            if (uniqs.size() == 0) break;
            for (String S : uniqs) {
                for (char c : S.toCharArray()) {
                    canGive[c].remove(S);
                }
            }
        }
        */
        Runner.main(A.class);
    }
}
