package B;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class Solution {
    int dir_x[] = {1, 0, 0, -1};
    int dir_y[] = {0, 1, -1, 0};

    public void doMain() throws Exception {
        Scanner sc = new Scanner(new FileReader("input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));

        int caseCnt = sc.nextInt();

        for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
            pw.print("Case #" + (caseNum + 1) + ": ");

            int K = sc.nextInt();
            int L = sc.nextInt();
            int S = sc.nextInt();
            sc.nextLine();
            String keyboard = sc.nextLine();
            String word = sc.nextLine();

            int maxBananas = 0;
            long totalBananas = 0;
            for (int i = 0; i < Math.round(Math.pow(K, S)); i++) {
                int n = i;
                String temp = "";
                for (int j = 0; j < S; j++) {
                    temp += keyboard.charAt(n % K);
                    n /= K;
                }
                int bananas = 0;
                int index = 0;
                while (true) {
                    index = temp.indexOf(word, index);
                    if (index > -1) {
                        index++;
                        bananas++;
                    } else {
                        break;
                    }
                }
                maxBananas = Math.max(bananas, maxBananas);
                totalBananas += bananas;
            }


            pw.println((double) maxBananas - (double) totalBananas / Math.round(Math.pow(K, S)));

        }

        pw.flush();
        pw.close();
        sc.close();
    }

    private void putNeightbour(boolean[][] board, int[][] neighbors, int i, int j) {
        if (board[i][j]) return;
        board[i][j] = true;
        for (int dir = 0; dir < 4; dir++) {
            int newX = i + dir_x[dir];
            int newY = j + dir_y[dir];
            if (newX < neighbors.length && newX >= 0 && newY < neighbors[0].length && newY >= 0) {
                neighbors[newX][newY]++;
            }
        }
    }

    public static void main(String[] args) throws Exception {
        new Solution().doMain();
    }
}