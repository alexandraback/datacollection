package A;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class Solution {

    public void doMain() throws Exception {
        Scanner sc = new Scanner(new FileReader("input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));

        int caseCnt = sc.nextInt();

        for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
            pw.print("Case #" + (caseNum + 1) + ": ");

            int R = sc.nextInt();
            int C = sc.nextInt();
            int W = sc.nextInt();

            int rawChecks = C / W;

            int res = (R - 1) * rawChecks;
            if (C % W == 0) {
                res += rawChecks + W - 1;
            } else {
                res += rawChecks + W;
            }

            pw.println(res);

        }
        pw.flush();
        pw.close();
        sc.close();
    }

    private int transform(int a) {
        String str = a + "";
        String res = "";
        boolean start = true;
        for (int i = 0; i < str.length(); i++) {
            if (start && str.charAt(str.length() - 1 - i) == '0')
                continue;
            start = false;
            res += str.charAt(str.length() - 1 - i);
        }
        return Integer.parseInt(res);
    }

    public static void main(String[] args) throws Exception {
        new Solution().doMain();
    }
}