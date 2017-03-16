package codejam;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Dijkstra {

    public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
        Scanner in = new Scanner(new FileReader("C-small-attempt0 (1).in"));
        PrintWriter out = new PrintWriter("output.txt", "UTF-8");

        int T = in.nextInt();

        for (int t = 1; t <= T; t++) {
            int L = in.nextInt();
            int X = in.nextInt();
            String s = in.next();
            boolean ansBoolean = isIJK(L, X, s);
            String ans;
            if (ansBoolean)
                ans = "YES";
            else
                ans = "NO";
            out.println("Case #" + t + ": " + ans);
            System.out.println(ans);
        }
        in.close();
        out.close();
    }
    // 1 = 1, 2 = i, 3 = j, 4 = k
    public static int evaluate(int a, int b) {
        int sign = a*b / Math.abs(a*b);
        a = Math.abs(a);
        b = Math.abs(b);
        if (a == 1)
            return b * sign;
        if (b == 1)
            return a * sign;
        if (a == 2) {
            if (b == 2)
                return -1 * sign;
            if (b == 3)
                return 4 * sign;
            if (b == 4)
                return -3 * sign;
        }
        if (a == 3) {
            if (b == 2)
                return -4 * sign;
            if (b == 3)
                return -1 * sign;
            if (b == 4)
                return 2 * sign;
        }
        if (a == 4) {
            if (b == 2)
                return 3 * sign;
            if (b == 3)
                return -2 * sign;
            if (b == 4)
                return -1 * sign;
        }
        return 0;
    }
    public static int convert(String s) {
        if (s.equals("i"))
            return 2;
        if (s.equals("j"))
            return 3;
        if (s.equals("k"))
            return 4;
        return 1;
    }
    // 2 4 -1
    public static boolean isIJK(int L, int X, String s) {
        if (X > 4)
            X = 4 + X%4;

        boolean hasI = false;
        boolean hasJ = false;
        int current = 1;
        for (int x = 0; x < X; x++) {
            for (int i = 0; i < s.length(); i++) {
                int next = convert(s.substring(i,  i+1));
                current = evaluate(current, next);
                
                if (current == 2)
                    hasI = true;
                if (hasI && current == 4)
                    hasJ = true;
            }
        }
        return hasJ && (current == -1);
    }



}
