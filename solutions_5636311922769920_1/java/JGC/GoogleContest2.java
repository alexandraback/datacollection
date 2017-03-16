package googlecontest;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Timer;
import java.util.TimerTask;

public class GoogleContest2 {

    public static boolean expire = false;

    public static void main(String[] args) {
        Scanner stdin = new Scanner(System.in);
        int numCases = stdin.nextInt();

        for (int i = 1; i <= numCases; i++) {
            int K = stdin.nextInt();
            int C = stdin.nextInt();
            int S = stdin.nextInt();
            String finalString = "";
            if (S == K) {
                for (int j = 1; j <= K; j++) {
                    finalString += String.valueOf(j);
                    if (j != K) {
                        finalString += " ";
                    }
                }
            } else if (C > 1 && S == K - 1) {
                for (int j = 2; j <= K; j++) {
                    finalString += String.valueOf(j);
                    if (j != K) {
                        finalString += " ";
                    }
                }
            } else {
                finalString = "IMPOSSIBLE";
            }
            System.out.println("Case #" + i + ": " + finalString);
        }

    }
}
