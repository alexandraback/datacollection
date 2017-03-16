import java.io.*;
import java.util.*;

public class Main {
    static String number(int[] a) {
        String[] digits = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
        for (int i = 0; i < digits.length; i++) {
            String d = digits[i];
            boolean f = true;
            for (char c : d.toCharArray()) {
                if (a[(int)c - (int)'A'] == 0) {
                    f = false;
                    break;
                }
            }
            if (f) {
                for (char c : d.toCharArray()) {
                    a[(int)c - (int)'A']--;
                }
                String res = number(a);
                if (!res.equals("*")) {
                    res += Integer.toString(i);
                    return res;
                }
                for (char c : d.toCharArray()) {
                    a[(int)c - (int)'A']++;
                }
            }
        }
        for (int t : a) {
            if (t > 0) {
                return "*";
            }
        }
        return "";
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("A-small-attempt0.in"));
        PrintWriter out = new PrintWriter("out.txt");
        int t = in.nextInt();
        for (int c = 1; c <= t; c++) {
            System.out.println(c);
            String s = in.next();
            int[] a = new int[(int)'Z' - (int)'A' + 1];
            for (int i = 0; i < s.length(); i++) {
                a[(int)s.charAt(i) - (int)'A']++;
            }
            char[] res = number(a).toCharArray();
            Arrays.sort(res);
            out.print("Case #" + c + ": ");
            for (char q : res) {
                out.print(q);
            }
            out.println();
        }
        out.close();
    }
}