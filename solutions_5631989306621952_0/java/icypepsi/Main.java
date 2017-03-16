package codejam2016.a;

import java.util.*;
import java.io.*;

public class Main {
    static String testCase = "A-small-attempt0";

    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File(testCase + ".in"));
            PrintWriter out = new PrintWriter(new File(testCase + ".out"));
            run(in, out);
            out.flush();
            out.close();
            in.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void run(Scanner in, PrintWriter out) {
        Solution sol = new Solution();
        int t = in.nextInt();
        in.nextLine();
        for (int i = 1; i <= t; ++i) {
            //Read
            String s = in.nextLine();
            //Solve
            System.out.printf("Case %d\n", i);
            out.printf("Case #%d: %s\n", i, sol.solve(s));
            System.out.print("Finished.\n");
        }
    }
}

class Solution {
    public String solve(String s) {
        String ans = "";
        for (char c : s.toCharArray()) {
            String s1 = ans + c;
            String s2 = c + ans;
            if (s1.compareTo(s2) > 0) ans = s1;
            else ans = s2;
        }
        return ans;
    }
}
