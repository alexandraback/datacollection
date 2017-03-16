import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Q2 {

    public static String solve(String C, String J) {

        int len = C.length();

        char[] cs = C.toCharArray();
        char[] js = J.toCharArray();

        List<String> cres = new ArrayList<>();
        List<String> jres = new ArrayList<>();
        cres.add("");
        jres.add("");

        for (int i = 0; i < len; i++) {
            if (cs[i] == '?' && js[i] == '?') {
                cres = add(cres, new char[]{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'});
                jres = add(jres, new char[]{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'});
            } else if (cs[i] == '?') {
                cres = add(cres, new char[]{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'});
                jres = add(jres, new char[]{js[i]});
            } else if (js[i] == '?') {
                cres = add(cres, new char[]{cs[i]});
                jres = add(jres, new char[]{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'});
            } else {
                cres = add(cres, new char[]{cs[i]});
                jres = add(jres, new char[]{js[i]});
            }
        }

        long min = Long.MAX_VALUE;
        String a = "";
        String b = "";
        for (String cre : cres) {
            for (String jre : jres) {
                long m = Long.parseLong(cre);
                long n = Long.parseLong(jre);
                long diff = Math.abs(m - n);
                if (min > diff) {
                    min = diff;
                    a = cre;
                    b = jre;
                }
            }
        }

        return String.valueOf(a) + " " + String.valueOf(b);
    }

    private static char minus(char j) {
        if (j == '0') {
            return '9';
        }
        return (char) (j - 1);
    }

    private static char plus(char j) {
        if (j == '9') {
            return '0';
        }
        return (char) (j + 1);
    }

    private static List<String> add(List<String> res, char[] a) {
        List<String> r = new ArrayList<>();
        for (String s : res) {
            for (char c : a) {
                r.add(s + c);
            }
        }
        return r;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int t = in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.
        in.nextLine();
        for (int i = 1; i <= t; ++i) {
            String c = in.next();
            String j = in.next();
            System.out.println("Case #" + i + ": " + solve(c, j));
        }
    }
}
