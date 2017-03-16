package codejam.v2015;

import java.util.Scanner;

public class R1BA {

    static long[] tens = new long[] {
            1L,
            10L,
            100L,
            1000L,
            10000L,
            100000L,
            1000000L,
            10000000L,
            100000000L,
            1000000000L,
            10000000000L,
            100000000000L,
            1000000000000L,
            10000000000000L,
            100000000000000L,
            1000000000000000L
    };

    public static void main(String args[]) {

        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {

            final long N = in.nextLong();

            long x = N;
            long c = 0;

            int bits = bits(x);

            /*
            while(bits > 1) {

                int bits2 = bits / 2;

                int lb = 0;
                long l = 0, h = 0;
                while(lb < bits2) {
                    int hb = bits - lb - 1;
                    l = get(x, lb);
                    h = get(x, hb);
                    if (l != h)
                        break;
                    if ((lb == 0 && l != 1) || (lb > 0 && l != 0))
                        break;
                    lb++;
                }

                if(lb == 0 && h == 0) {
                    throw new RuntimeException();
                }

                if(lb >= bits2) {
                    // pattern 1000001..
                    long all9 = tens[bits - 1] - 1;
                    c += (x - all9);
                    x = all9;
                    bits --;
                    continue;
                }

                if(lb == 0) {
                    if(l > 1) {
                        x -= (l - 1);
                        c += (l - 1);
                    } else if(l == 1) {
                        // l == 1, h != l (h > 1)
                        x = flip(x);
                        c++;
                    } else {
                        // l = 0
                        x--;
                        c++;
                        bits = bits(x);
                    }
                } else {
                    if(l > 0) {
                        x -= (l * tens[lb]);
                        c += (l * tens[lb]);
                    } else {
                        x = flip(x);
                        c++;
                    }
                }
            }
            */

            while(bits > 1) {
                if(x % 10 == 0) {
                    x--;
                    c++;
                    bits = bits(x);
                    continue;
                }
                int lb = 0;
                long lo = 0, hi = 0;
                while (lb < bits / 2) {
                    int hb = bits - lb - 1;
                    long l = get(x, lb);
                    long h = get(x, hb);
                    lo += (l * tens[lb]);
                    hi += (h * tens[lb]);
                    lb++;
                }

                if(lo > 1) {
                    // reduce lower to 1
                    x -= (lo - 1);
                    c += (lo - 1);
                } else {
                    // already reduced
                    if(hi > 1) {
                        x = flip(x);
                        c++;
                    } else {
                        // pattern 1000x0001..
                        long all9 = tens[bits - 1] - 1;
                        c += (x - all9);
                        x = all9;
                        bits --;
                    }
                }
            }

            c += x;

            System.out.format("Case #%d: %d\n", t, c);
        }

    }

    public static long get(long x, int bit) {
        return (x % tens[bit + 1]) / tens[bit];
    }

    public static int bits(long x) {
        int bits = 0;
        while(x > 0) {
            bits++;
            x /= 10;
        }
        return bits;
    }

    public static long flip(long x) {
        /*
        if (x < 10 || (x % 10 == 0)) {
            throw new RuntimeException();
        }
        */

        long n = 0;
        while (x > 0) {
            long m = x % 10;
            x /= 10;
            n = (n * 10) + m;
        }
        return n;
    }

}
