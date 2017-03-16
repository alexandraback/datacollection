import java.io.*;
import java.util.*;

public class Main {
    static String number(int[] a) {
        String[] digits = {"ZERO", "TWO", "SIX", "EIGHT", "FOUR", "THREE", "FIVE", "SEVEN", "ONE", "NINE"};
        int[] realDigits = {0, 2, 6, 8, 4, 3, 5, 7, 1, 9};
        String res = "";
        for (int i = 0; i < digits.length; i++) {
            String d = digits[i];
            boolean f = true;
            while (f) {
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
                    res += Integer.toString(realDigits[i]);
                }
            }
        }
        return res;
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("A-large.in"));
        PrintWriter out = new PrintWriter("out2.txt");
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