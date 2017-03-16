package codejam.y2016.round1.subroundB;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

/**
 * @author Max Myslyvtsev
 * @since 4/30/16
 */
public class B {

    public static void main(String[] args) throws Exception {
        //Scanner in = new Scanner(new FileInputStream("/Users/max/Work/Source/foobar/src/main/resources/input.txt"));
        Scanner in = new Scanner(new FileInputStream("/Users/max/Downloads/B-small-attempt2.in"));
        PrintStream out = new PrintStream(new FileOutputStream("/Users/max/Work/Source/foobar/src/main/resources/output.txt"));
        int T = in.nextInt();
        in.nextLine();
        for (int t = 1; t <= T; t++) {
            String q = in.nextLine();
            String[] split = q.split(" ");
            String a = solveBf(split[0], split[1]);
            String answ = "Case #" + t + ": " + a;
            out.println(answ);
            System.out.println(answ);
        }
    }

    static class Res {
        String ans;
        long diff;

        public Res(String ans, long diff) {
            this.ans = ans;
            this.diff = diff;
        }
    }

    static String solveBf(String s1s, String s2s) {
        long[] s1 = toIntArr(s1s);
        long[] s2 = toIntArr(s2s);
        long[] d10 = new long[s1.length];
        {
            long d = 1;
            for (int i = d10.length - 1; i >= 0; i--) {
                d10[i] = d;
                d *= 10;
            }
        }
        Res r = bf(s1, s2, d10);
        return r.ans;
    }

    static Res bf(long[] s1, long[] s2, long[] d10) {
        for (int i = 0; i < s1.length; i++) {
            if (s1[i] == -1) {
                Res minRes = null;
                for (int j = 0; j <= 9; j++) {
                    s1[i] = j;
                    Res curRes = bf(s1, s2, d10);
                    if (minRes == null || curRes.diff < minRes.diff) {
                        minRes = curRes;
                    }
                }
                s1[i] = -1;
                return minRes;
            }
        }
        for (int i = 0; i < s2.length; i++) {
            if (s2[i] == -1) {
                Res minRes = null;
                for (int j = 0; j <= 9; j++) {
                    s2[i] = j;
                    Res curRes = bf(s1, s2, d10);
                    if (minRes == null || curRes.diff < minRes.diff) {
                        minRes = curRes;
                    }
                }
                s2[i] = -1;
                return minRes;
            }
        }
        long diff = getDiff(s1, s2, d10);
        return new Res(toResult(s1, s2), diff);
    }

    private static String solve(String s1s, String s2s) {
        long[] s1 = toIntArr(s1s);
        long[] s2 = toIntArr(s2s);
        long[] d10 = new long[s1.length];
        {
            long d = 1;
            for (int i = d10.length - 1; i >= 0; i--) {
                d10[i] = d;
                d *= 10;
            }
        }
        for (int k = 0; k < s1.length; k++) {
            if (s1[k] == -1 && s2[k] != -1) {
                Long minDiff = Long.MAX_VALUE;
                int minVal = -2;
                for (int i = 0; i <= 9; i++) {
                    s1[k] = i;
                    long curDiff = getDiff(s1, s2, d10);
                    if (curDiff < minDiff) {
                        minDiff = curDiff;
                        minVal = i;
                    }
                }
                s1[k] = minVal;

            }
            if (s1[k] != -1 && s2[k] == -1) {
                Long minDiff = Long.MAX_VALUE;
                int minVal = -2;
                for (int i = 0; i <= 9; i++) {
                    s2[k] = i;
                    long curDiff = getDiff(s1, s2, d10);
                    if (curDiff < minDiff) {
                        minDiff = curDiff;
                        minVal = i;
                    }
                }
                s2[k] = minVal;

            }
            if (s1[k] == -1 && s2[k] == -1) {
                Long minDiff = Long.MAX_VALUE;
                int minVal1 = -2;
                int minVal2 = -2;
                for (int i = 0; i <= 9; i++) {
                    for (int j = 0; j <= 9; j++) {
                        s1[k] = i;
                        s2[k] = j;
                        long curDiff = getDiff(s1, s2, d10);
                        if (curDiff < minDiff) {
                            minDiff = curDiff;
                            minVal1 = i;
                            minVal2 = j;
                        }
                    }
                }
                s1[k] = minVal1;
                s2[k] = minVal2;

            }
        }
        return toResult(s1, s2);
    }

    private static String toResult(long[] s1, long[] s2) {
        StringBuilder sb = new StringBuilder();
        for (long c : s1) {
            sb.append((char)('0'+c));
        }
        sb.append(' ');
        for (long c : s2) {
            sb.append((char)('0'+c));
        }
        return sb.toString();
    }

    private static long getDiff(long[] s1, long[] s2, long[] d10) {
        long ex1 = 0;
        long pot1 = 0;
        for (int i = 0; i < s1.length; i++) {
            if (s1[i] != -1) {
                ex1 += s1[i] * d10[i];
            } else {
                pot1 += 9 * d10[i];
            }
        }
        long ex2 = 0;
        long pot2 = 0;
        for (int i = 0; i < s2.length; i++) {
            if (s2[i] != -1) {
                ex2 += s2[i] * d10[i];
            } else {
                pot2 += 9 * d10[i];
            }
        }
        long a = ex2;
        long b = ex2 + pot2;
        long c = ex1;
        long d = ex1 + pot1;
        if (c > a) {
            if (c > b) {
                return c - b;
            } else {
                return 0;
            }
        } else {
            if (d < a) {
                return a - d;
            } else {
                return 0;
            }
        }/*
        long diff = Math.abs(ex2 - ex1);
        diff = Math.min(diff, Math.abs(ex2+pot2 - ex1));
        diff = Math.min(diff, Math.abs(ex2 - ex1-pot1));
        diff = Math.min(diff, Math.abs(ex2+pot2 - ex1-pot1));
        return diff;*/
    }

    static long[] toIntArr(String s1s) {
        long[] s1 = new long[s1s.length()];
        for (int i = 0; i < s1s.length(); i++) {
            char c = s1s.charAt(i);
            if (c == '?') {
                s1[i] = -1;
            } else {
                s1[i] = c - '0';
            }
        }
        return s1;
    }
}
