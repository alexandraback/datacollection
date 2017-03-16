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

            int N = sc.nextInt();
            int[] dist = new int[Math.max(N + 1, 2)];
            dist[1] = 1;
            for (int i = 2; i < N + 1; i++) {
                int tr = transform(i);
                if (tr < i && i == transform(tr))
                    dist[i] = Math.min(dist[i - 1] + 1, dist[tr] + 1);
                else
                    dist[i] = dist[i - 1] + 1;
            }
            pw.println(dist[N]);

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