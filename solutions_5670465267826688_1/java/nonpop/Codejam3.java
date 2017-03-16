package codejam3;

import java.util.Scanner;

public class Codejam3 {

    static int toQ(char c) {
        if (c == '1') {
            return 1;
        } else {
            return c - 'i' + 2;
        }
    }

    static int mulQ(int q1, int q2) {
        if (q1 < 0) {
            return -mulQ(-q1, q2);
        }
        if (q2 < 0) {
            return -mulQ(q1, -q2);
        }
        if (q1 == 1) {
            return q2;
        }
        if (q2 == 1) {
            return q1;
        }
        if (q1 == q2) {
            return -1;
        }
        if (q1 == 2) {
            if (q2 == 3) {
                return 4;
            } else {
                return -3;
            }
        }
        if (q1 == 3) {
            if (q2 == 2) {
                return -4;
            } else {
                return 2;
            }
        }
        if (q1 == 4) {
            if (q2 == 2) {
                return 3;
            } else {
                return -2;
            }
        }
        throw new IllegalArgumentException();
    }

    private static boolean check(int L, long X, String str) {
        long ipos = -1;
        int prev = 1;
        boolean done = false;
        for (int i = 0; i < 4 && !done; i++) {
            for (int j = 0; j < L; j++) {
                int next = toQ(str.charAt(j));
                prev = mulQ(prev, next);
                if (prev == 2) {
                    ipos = i*L + j;
                    done = true;
                    break;
                }
            }
        }
        if (ipos == -1) return false;

        long kpos = 1;
        prev = 1;
        done = false;
        for (int i = 0; i < 4 && !done; i++) {
            for (int j = 0; j < L; j++) {
                int next = toQ(str.charAt(L - 1 - j));
                prev = mulQ(next, prev);
                if (prev == 4) {
                    kpos = -(i*L + j);
                    done = true;
                    break;
                }
            }
        }
        if (kpos == 1) return false;

        kpos = L*X - 1 + kpos;

        if (ipos >= kpos)
            return false;

        long iseg = ipos / L;
        long kseg = kpos / L;

        long jsegs = (kseg - iseg - 1) / 4;
        kpos -= jsegs*4*L;

        prev = 1;
        for (long pos = ipos + 1; pos < kpos; pos++) {
            int next = toQ(str.charAt((int)(pos % str.length())));
            prev = mulQ(prev, next);
        }

        return prev == 3;
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int testCases = s.nextInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            int L = s.nextInt();
            long X = s.nextLong();
            String str = s.next();

            System.out.println("Case #" + testCase + ": " + (check(L, X, str)? "YES" : "NO"));
        }
    }

}
