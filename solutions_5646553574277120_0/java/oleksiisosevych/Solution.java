package C;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class Solution {
    public void doMain() throws Exception {
        Scanner sc = new Scanner(new FileReader("input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));

        int caseCnt = sc.nextInt();

        for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
            pw.print("Case #" + (caseNum + 1) + ": ");

            int C = sc.nextInt();
            int D = sc.nextInt();
            int V = sc.nextInt();

            ArrayList<Integer> den = new ArrayList<Integer>();
            for (int i = 0; i < D; i++) {
                den.add(sc.nextInt());
            }
            int res = 0;
            while (true) {
                int nextDen = nextDen(den, V);
                if (nextDen == -1) break;
                res++;
                den.add(nextDen);
            }


            pw.println(res);
        }

        pw.flush();
        pw.close();
        sc.close();
    }

    private int nextDen(ArrayList<Integer> den, int v) {
        boolean check[] = new boolean[v + 1];
        for (int i = 1; i < 1 << den.size(); i++) {
            int num = 0;
            for (int j = 0; j < den.size(); j++) {
                if ((i & (1 << j)) == (1 << j)) {
                    num += den.get(j);
                }
            }
            if (num <= v)
                check[num] = true;
        }
        for (int i = 1; i <= v; i++) {
            if (!check[i]) return i;
        }
        return -1;
    }


    public static void main(String[] args) throws Exception {
        new Solution().doMain();
    }
}