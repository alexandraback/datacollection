package codejam.y2016.round1.subroundB;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.*;

/**
 * @author Max Myslyvtsev
 * @since 4/30/16
 */
public class C {

    public static void main(String[] args) throws Exception {
        //Scanner in = new Scanner(new FileInputStream("/Users/max/Work/Source/foobar/src/main/resources/input.txt"));
        Scanner in = new Scanner(new FileInputStream("/Users/max/Downloads/C-small-attempt0.in"));
        PrintStream out = new PrintStream(new FileOutputStream("/Users/max/Work/Source/foobar/src/main/resources/output.txt"));
        int T = in.nextInt();
        in.nextLine();
        for (int t = 1; t <= T; t++) {
            int N = in.nextInt();
            in.nextLine();
            String[] s = new String[N];
            for (int i = 0; i < N; i++) {
                s[i] = in.nextLine();
            }
            int a = solveBF(s);
            String answ = "Case #" + t + ": " + a;
            out.println(answ);
            System.out.println(answ);
        }
    }

    private static int solveBF(String[] s) {
        Map<String, Integer> first = new HashMap<>();
        Map<String, Integer> second = new HashMap<>();
        return bf(new boolean[s.length], s, 0);
    }

    static int bf(boolean[] fake, String[] s, int idx) {
        if (idx == s.length) {
            Set<String> first = new HashSet<>();
            Set<String> second = new HashSet<>();
            for (int i = 0; i < s.length; i++) {
                if (!fake[i]) {
                    String[] parts = s[i].split(" ");
                    first.add(parts[0]);
                    second.add(parts[1]);
                }
            }
            for (int i = 0; i < s.length; i++) {
                if (fake[i]) {
                    String[] parts = s[i].split(" ");
                    if (!first.contains(parts[0])) {
                        return Integer.MIN_VALUE;
                    }
                    if (!second.contains(parts[1])) {
                        return Integer.MIN_VALUE;
                    }
                }
            }
            int count = 0;
            for (int i = 0; i < s.length; i++) {
                if (fake[i]) {
                    count++;
                }
            }
            return count;
        }

        fake[idx] = true;
        int res1 = bf(fake, s, idx + 1);

        fake[idx] = false;
        int res2 = bf(fake, s, idx + 1);

        return Math.max(res1, res2);
    }

    private static int solve(String[] s) {
        Map<String, Integer> first = new HashMap<>();
        Map<String, Integer> second = new HashMap<>();
        return 0;
    }

    static int[][] convert(String[] s) {
//        int id = 0;
//        Map<String, Integer> map = new HashMap<>();
//        int[][] res = new int[s.length][2];
//        for (int i = 0; i < s.length; i++) {
//            String[] parts = s[i].split(" ");
//            Integer x = map.get(parts[0]);
//            if (x == null) {
//                map.put()
//            }
//        }
        return null;
    }
}
