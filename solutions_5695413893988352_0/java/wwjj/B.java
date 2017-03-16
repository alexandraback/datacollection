package r1a;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.Scanner;

public class B {

    public static void main(String[] args) throws IOException {
//        Scanner sc = new Scanner(Files.newInputStream(Paths.get("in.txt")));
//        Scanner sc = new Scanner(Files.newInputStream(Paths.get("B-small-attempt2.in")));
        Scanner sc = new Scanner(Files.newInputStream(Paths.get("B-small-attempt7.in")));
//        Scanner sc = new Scanner(Files.newInputStream(Paths.get("")));

        int num = sc.nextInt();
        String s = "";
        for (int i = 0; i < num; i++) {
            s += String.format("Case #%d: %s\n", i + 1, solve(sc.next(), sc.next()));
//            s += String.format("%s\n", solve(sc.next(), sc.next()));
        }
        System.out.println(s);
        Files.write(Paths.get("out_.txt"), s.getBytes());
    }

    private static String solve(String c, String j) {
        StringBuffer retC = new StringBuffer();
        StringBuffer retJ = new StringBuffer();
        for (int i = 0; i < c.length(); i++) {
            if (c.charAt(i) == '?' && j.charAt(i) == '?') {
                retC.append("0");
                retJ.append("0");
            } else if (c.charAt(i) == '?') {
                retC.append(j.charAt(i));
                retJ.append(j.charAt(i));
            } else if (j.charAt(i) == '?') {
                retC.append(c.charAt(i));
                retJ.append(c.charAt(i));
            } else if (c.charAt(i) == j.charAt(i)) {
                retC.append(c.charAt(i));
                retJ.append(c.charAt(i));
            } else {

                long diff5 = Math.abs(
                        Long.parseLong(oneDown(retC.toString(), c.substring(0, i), retJ.toString()) + "" + max1(c.substring(i))) -
                                Long.parseLong(retJ.toString() + "" + min1(j.substring(i)))
                );


                long diff6 = Math.abs(
                        Long.parseLong(oneDown(retJ.toString(), j.substring(0, i), retC.toString()) + "" + max1(j.substring(i))) -
                                Long.parseLong(retC.toString() + "" + min1(c.substring(i)))
                );


                long diff1 = Math.abs(Long.parseLong(min1(c.substring(i))) - Long.parseLong(max1(j.substring(i))));
                long diff2 = Math.abs(Long.parseLong(max1(c.substring(i))) - Long.parseLong(min1(j.substring(i))));

                long diff3 = Math.abs(
                        Long.parseLong(oneUp(retC.toString(), c.substring(0, i), retJ.toString()) + "" + min1(c.substring(i))) -
                        Long.parseLong(retJ.toString() + "" + max1(j.substring(i)))
                );

                long diff4 = Math.abs(
                        Long.parseLong(oneUp(retJ.toString(), j.substring(0, i), retC.toString()) + "" + min1(j.substring(i))) -
                        Long.parseLong(retC.toString() + "" + max1(c.substring(i)))
                );

                long totalMin = Arrays.stream(new long[]{diff5, diff6, diff1, diff2, diff3, diff4}).min().getAsLong();

                if (diff5 == totalMin) {
                    return oneDown(retC.toString(), c.substring(0, i), retJ.toString()) + "" + max1(c.substring(i)) + " " +
                            retJ.toString() + "" + min1(j.substring(i));

                }else if (diff6 == totalMin) {
                    return retC.toString() + "" + min1(c.substring(i)) + " " +
                            oneDown(retJ.toString(), j.substring(0, i), retC.toString()) + "" + max1(j.substring(i));

                } else if (diff1 == totalMin) {
                    return retC.toString() + min1(c.substring(i)) + " " + retJ.toString() + max1(j.substring(i));

                } else if (diff2 == totalMin) {
                    return retC.toString() + max1(c.substring(i)) + " " + retJ.toString() + min1(j.substring(i));

                } else if (diff4 == totalMin) {
                    return retC.toString() + "" + max1(c.substring(i)) + " " +
                            oneUp(retJ.toString(), j.substring(0, i), retC.toString()) + "" + min1(j.substring(i));

                } else if (diff3 == totalMin) {
                    return oneUp(retC.toString(), c.substring(0, i), retJ.toString()) + "" + min1(c.substring(i)) + " " +
                            retJ.toString() + "" + max1(j.substring(i));

                } else {
                    throw new AssertionError();
                }
            }
        }
        return retC.toString() + " " + retJ.toString();
    }

    private static String oneUp(String cur, String sub, String other) {
        if (sub.length() == 0) return "";

        if (sub.charAt(sub.length() - 1) == '?') {
            int next = Integer.parseInt("" + other.charAt(other.length() - 1)) + 1;
            if (next < 10) {
                return cur.substring(0, cur.length() - 1) + next;
            } else {
                return oneUp(cur.substring(0, cur.length() - 1), sub.substring(0, sub.length() - 1), other.substring(0, other.length() - 1)) + "0";
//                return cur.substring(0, cur.length() - 1) + "9";
            }
//            return cur.substring(0, cur.length() - 1) + "1";
        } else {
            return oneUp(cur.substring(0, cur.length() - 1), sub.substring(0, sub.length() - 1), other.substring(0, other.length() - 1)) + cur.charAt(cur.length() - 1);
//            return cur;
        }
    }

    private static String oneDown(String cur, String sub, String other) {
        if (sub.length() == 0) return "";

        if (sub.charAt(sub.length() - 1) == '?') {
            int next = Integer.parseInt("" + other.charAt(other.length() - 1)) - 1;
            if (next >= 0) {
                return cur.substring(0, cur.length() - 1) + next;
            } else {
                return oneDown(cur.substring(0, cur.length() - 1), sub.substring(0, sub.length() - 1), other.substring(0, other.length() - 1)) + "9";
            }
        } else {
            return oneDown(cur.substring(0, cur.length() - 1), sub.substring(0, sub.length() - 1), other.substring(0, other.length() - 1)) + cur.charAt(cur.length() - 1);
//            return cur;
        }
    }

    private static String max1(String sub) {
        StringBuffer ret = new StringBuffer();
        for (int i = 0; i < sub.length(); i++) {
            if (sub.charAt(i) == '?') {
                ret.append('9');
            } else {
                ret.append(sub.charAt(i));
            }
        }
        return ret.toString();
    }

    private static String min1(String sub) {
        StringBuffer ret = new StringBuffer();
        for (int i = 0; i < sub.length(); i++) {
            if (sub.charAt(i) == '?') {
                ret.append('0');
            } else {
                ret.append(sub.charAt(i));
            }
        }
        return ret.toString();
    }
}
