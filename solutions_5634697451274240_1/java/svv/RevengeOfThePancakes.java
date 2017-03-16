package codejam.year2016.qualification.revengeofthepancakes;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class RevengeOfThePancakes {


    public static void main(String[] args) {
        new RevengeOfThePancakes().run();
    }

    private void run() {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int N = in.nextInt();
        in.skip("\n");
        for (int i = 1; i <= N; ++i) {
            System.out.print("Case #" + i + ": " + readAndSolve(in));
            if (i != N) {
                System.out.println();
            }
        }
    }

    private String readAndSolve(Scanner in) {
        String S = in.nextLine();

        int len = S.length();
        char[] state = new char[len];
        for (int i = 0; i < len; i++) {
            state[i] = S.charAt(len - 1 - i);
        }
        int k = countToFix(state, 0, '+', '-');
        return Integer.toString(k);
    }

    private int countToFix(char[] state, int start, char required, char invalid) {
        int pos = start;
        int len = state.length;

        while (pos < len && state[pos] == required) {
            pos++;
        }
        if (pos == len) {
            return 0; // fixed
        }

        while (pos < len && state[pos] == invalid) {
            pos++;
        }

        return 1 + countToFix(state, pos, invalid, required);
    }

    private void flip(char state[], int start) {
        int a = start, b = state.length - 1;
        while (a < b) {
            char t = state[a];
            state[a] = state[b];
            state[b] = t;
            a++;
            b--;
        }
    }

}
