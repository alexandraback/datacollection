/*
 * Copyright (c) 2015. Made just for fun.
 */

package qualification;

import java.util.Scanner;
import java.util.regex.Pattern;

/**
 * @author Tomik
 */
public class C {

    private static final Pattern DIJKSTRA = Pattern.compile("[ijk]+");

    static class Q {
        String val = "1";

        public Q() {
        }

        public Q(Q other) {
            this.val = other.val;
        }

        public void mult(char c) {
            val = C.mult(val, String.valueOf(c));
        }
        public void mult(Q o) {
            val = C.mult(val, o.val);
        }
        public void lmult(char c) {
            val = C.mult(String.valueOf(c), val);
        }
        public void pow(long p) {
            Q tmp = new Q(this);
            Q res = new Q();
            while (p > 0) {
                if (p % 2 == 1) {
                    res.mult(tmp);
                }
                p /= 2;
                tmp.mult(tmp);
            }
            val = res.val;
        }
        public boolean equals(char c) {
            if (val.length() > 1) {
                return false;
            }
            return val.charAt(0) == c;
        }
    }

    static String mult(String stra, String strb) {
        boolean minusa = stra.charAt(0) == '-';
        boolean minusb = strb.charAt(0) == '-';
        boolean minus = (minusa || minusb) && (!(minusa && minusb));
        char a = stra.charAt(minusa ? 1 : 0);
        char b = strb.charAt(minusb ? 1 : 0);
        char result = '1';
        switch (a) {
            case '1':
                result = b;
                break;
            case 'i':
                switch (b) {
                   case '1':
                        result = 'i';
                        break;
                    case 'i':
                        minus = !minus;
                        result = '1';
                        break;
                    case 'j':
                        result = 'k';
                        break;
                    case 'k':
                        minus = !minus;
                        result = 'j';
                        break;
                }
                break;
            case 'j':
                switch (b) {
                    case '1':
                        result = 'j';
                        break;
                    case 'i':
                        minus = !minus;
                        result = 'k';
                        break;
                    case 'j':
                        minus = !minus;
                        result = '1';
                        break;
                    case 'k':
                        result = 'i';
                        break;
                }
                break;
            case 'k':
                switch (b) {
                    case '1':
                        result = 'k';
                        break;
                    case 'i':
                        result = 'j';
                        break;
                    case 'j':
                        minus = !minus;
                        result = 'i';
                        break;
                    case 'k':
                        minus = !minus;
                        result = '1';
                        break;
                }
                break;
        }
        return (minus ? "-" : "") + result;
    }

    static boolean possible(int L, long x, String line) {
        long size = L*x;


        int js = 0;
        Q iq = new Q();
        long imax = Math.min(size, L*16);
        while (!iq.equals('i') && js < imax) {
            iq.mult(line.charAt(js%L));
            ++js;
        }
        if (js >= imax && !iq.equals('i')) {
            return false;
        }

        long ks = size;
        Q kq = new Q();
        long kmax = Math.max(0, size - imax);
        while (!kq.equals('k') && ks > js && ks > kmax) {
            --ks;
            kq.lmult(line.charAt((int)(ks%L)));
        }
        if ((ks <= kmax || ks <= js) && !kq.equals('k')) {
            return false;
        }

        if (ks - js < 3*L) {
            Q jq = new Q();
            for (long i = js; i < ks; i++) {
                jq.mult(line.charAt((int)(i%L)));
            }
            return jq.equals('j');
        } else {
            long rj = (js-1) / L;
            long rk = ks / L;
            Q jq1 = new Q();
            while (js % L != 0) {
                jq1.mult(line.charAt((int)(js%L)));
                ++js;
            }
            Q jq2 = new Q();
            for (int i = 0; i < L; i++) {
                jq2.mult(line.charAt(i));
            }
            jq2.pow(rk - rj - 1);
            Q jq3 = new Q();
            int m3 = (int) (ks%L);
            for (int i = 0; i < m3; i++) {
                jq2.mult(line.charAt(i));
            }
            jq1.mult(jq2);
            jq1.mult(jq3);
            return jq1.equals('j');
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 1; i <= T; i++) {
            int L = sc.nextInt();
            long x = sc.nextLong();
            String line = sc.next(DIJKSTRA);

            boolean yes = possible(L, x, line);
            System.out.println("Case #" + i + ": " + (yes ? "YES" : "NO"));
        }
    }

}
