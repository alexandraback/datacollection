import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

import static java.lang.Integer.signum;
import static java.lang.Math.abs;

public class C {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for (int ti = 1; ti <= t; ti++) {
            int l = scanner.nextInt();
            int x = scanner.nextInt();
            scanner.nextLine();
            String s = scanner.nextLine();
            boolean res = check(x, s);
            System.out.printf("Case #%d: %s\n", ti, res ? "YES" : "NO");
        }
    }

    private static boolean check(int x, String s) {
        IJKSource ijkSource = new IJKSource(s, x);
        int w = 2;
        int c = 1;
//        Set<Integer> ces = new HashSet<>();
        int g;
        while ((g = ijkSource.get()) != 0) {
            c = mul(c, g);
            if (c == w && w < 4) {
                w++;
                c = 1;
//                ces = new HashSet<>();
            }
//            if (ijkSource.lineEnd()) {
//                if (w < 4) {
//                    if (!ces.add(c)) {
//                        return false;
//                    }
//                } else {
//                    c = mul(c, pow(ijkSource.patMul(), ijkSource.x));
//                    break;
//                }
//            }
        }
        return c == 4 && w == 4;
    }

    static int pow(int a, long b) {
        if (a == 1) return 1;
        else {
            int r = (int) b % 4;
            switch (r) {
                case 0:
                    return 1;
                case 1:
                    return a;
                case 2:
                    return -1;
                case 3:
                    return -a;
                default:
                    throw new Error("pow error");
            }
        }
    }

    static int parse(char c) {
        switch (c) {
            case 'i':
                return 2;
            case 'j':
                return 3;
            case 'k':
                return 4;
            default:
                throw new Error("parse error");
        }
    }

    static int mul(int a, int b) {
        int s = signum(a) * signum(b);
        int aa = abs(a);
        int ab = abs(b);
        int m;
        if (aa == 1) {
            m = ab;
        } else if (ab == 1) {
            m = aa;
        } else if (aa == ab) {
            m = -1;
        } else {
            int p = aa * 0x10 + ab;
            switch (p) {
                case 0x23:
                    m = 4;
                    break;
                case 0x24:
                    m = -3;
                    break;
                case 0x32:
                    m = -4;
                    break;
                case 0x34:
                    m = 2;
                    break;
                case 0x42:
                    m = 3;
                    break;
                case 0x43:
                    m = -2;
                    break;
                default:
                    throw new Error("mul error");
            }
        }
        return m * s;
    }

    private static class IJKSource {
        int cur;
        final String pat;
        long x;

        public IJKSource(String pat, long x) {
            this.pat = pat;
            this.x = x;
            cur = pat.length();
        }

        int get() {
            if (lineEnd()) {
                x--;
                if (x < 0) return 0;
                cur = 0;
            }
            int res = parse(pat.charAt(cur));
            cur++;
            return res;
        }

        boolean lineEnd() {
            return cur == pat.length();
        }

        int patMul() {
            int m = 1;
            for (char c : pat.toCharArray()) {
                m = mul(m, parse(c));
            }
            return m;
        }
    }
}
