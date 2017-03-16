import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class C {
    private static L[][] Q = {
            {L.ONE, L.I,    L.J,    L.K},
            {L.I,   L._ONE, L.K,    L._J},
            {L.J,   L._K,   L._ONE, L.I},
            {L.K,   L.J,    L._I,   L._ONE},
    };
    public static void main(String[] args) throws Exception {
        PrintWriter writer = new PrintWriter(new FileOutputStream("C.out"));
        Scanner scanner = new Scanner(new FileInputStream("C.in"));
        //PrintWriter writer = new PrintWriter(System.out);
        //Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        for (int t = 0; t < T; t++) {
            int l = scanner.nextInt();
            long tx = scanner.nextLong();
            int x;
            if (tx > 100) {
                x = (int)(100 - (tx % 2));
            } else {
                x = (int)tx;
            }
            String s = scanner.next();
            L[] arr = new L[l * x];
            for (int i = 0; i < arr.length; i++) {
                if (i < l) {
                    arr[i] = L.parse(s.charAt(i));
                } else {
                    arr[i] = arr[i % l];
                }
            }

            boolean done = solve(arr);
            writer.println(String.format("Case #%d: %s", t + 1, done ? "YES" : "NO"));
        }
        scanner.close();
        writer.close();
    }
    static boolean solve(L[] arr) {
        int i, j;
        L r = L.ONE;
        for (i = 0; i < arr.length - 2; i++) {
            L c = arr[i];
            r = r.mult(c);
            if (r == L.I) {
                break;
            }
        }
        if (r != L.I) return false;
        i++;
        r = L.ONE;
        for (j = arr.length - 1; j > i; j--) {
            L c = arr[j];
            r = c.mult(r);
            if (r == L.K) {
                break;
            }
        }
        if (r != L.K) return false;
        r = calc(arr, i, j);
        return r == L.J;
    }
    static int want(L[] arr, int start, int end, L want) {
        L r = L.ONE;
        while (start < end) {
            L c = arr[start++];
            r = r.mult(c);
            if (r == want) {
                return start;
            }
        }
        return -1;
    }

    static L calc(L[]arr, int start, int end) {
        L r = L.ONE;
        while (start < end) {
            L c = arr[start++];
            r = r.mult(c);
        }
        return r;
    }

    static enum L {
        ONE, I, J, K, _ONE, _I, _J, _K;

        L minus() {
            return L.values()[(this.ordinal() + 4) % 8];
        }

        static L parse(char c) {
            if (c == 'i') {
                return I;
            } else if (c == 'j') {
                return J;
            } else if (c == 'k') {
                return K;
            }
            throw new RuntimeException("Unknown " + c);
        }

        int sign() {
            return this.ordinal() < 4 ? 1 : -1;
        }

        L abs() {
            return this.ordinal() < 4 ? this : this.minus();
        }

        L mult(L l) {
            int sign = this.sign() * l.sign();
            L r = Q[this.abs().ordinal()][l.abs().ordinal()];
            if (sign < 0) {
                r = r.minus();
            }
            return r;
        }
    }
}

