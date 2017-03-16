import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Solver solver = new Solver();
        solver.solve();
    }
}

class Solver {

    class Pair {
        public String c;
        public String j;
    }

    String padding(String s, String n) {
        // padding
        int pad = s.length() - n.length();
        for(int i = 0; i < pad; i++) {
            n = "0" + n;
        }
        return n;
    }

    boolean match(String s, int number) {
        String n = "" + number;
        if (s.length() < n.length()) {
            return false;
        }
        n = padding(s, n);
        System.err.println(s + " " + n);
        for(int i = 0; i < s.length(); i++) {
            if (!(s.charAt(i) == '?' || s.charAt(i) == n.charAt(i))) {
                return false;
            }
        }
        return true;
    }

    String solve(String c, String j) {
        // 1. coder를 계산
        // 2. jammer를 계산
        Pair pair = new Pair();
        int min = Integer.MAX_VALUE;
        for(int i = 0; i < 1000; i++) {
            if (!match(c, i)) {
                continue;
            }
            for(int k = 0; k < 1000; k++) {
                if (!match(j, k)) {
                    continue;
                }
                int diff = Math.abs(i - k);
                if (diff < min) {
                    min = diff;
                    pair = new Pair();
                    pair.c = padding(c, "" + i);
                    pair.j = padding(j, "" + k);
                }
            }
        }
        return pair.c + " " + pair.j;
    }

    void solve() {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int j = 0; j < t; j++) {
            System.err.printf("Case #%d%n", j + 1);
            System.out.printf("Case #%d: %s%n", j + 1, solve(sc.next(), sc.next()));
        }
    }
}
