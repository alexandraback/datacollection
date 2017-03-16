package qualif2;

import java.io.File;
import java.util.Arrays;
import java.util.Scanner;

public class Qualif2 {

    public static void main(String[] args) throws Exception {

        Scanner scan = new Scanner(new File("input"));

        int num = Integer.parseInt(scan.nextLine());

        for (int i = 1; i <= num; i++) {
            int googlers = scan.nextInt();
            int surprising = scan.nextInt();
            int score = scan.nextInt();

            int[] totals = new int[googlers];

            for (int j = 0; j < googlers; j++) {
                totals[j] = scan.nextInt();
            }

            System.out.println("Case #" + i + ": " + solve(googlers, surprising, score, totals));
        }
    }

    private static int solve(int googlers, int surprising, int score, int[] totals) {
        Arrays.sort(totals);
        int count = 0;

        if (score == 0) {
            return googlers;
        }

        for (int i = totals.length - 1; i >= 0; i--) {
            int total = totals[i];
            if (total > 28) {
                count++;
                continue;
            }

            if (total == 0) {
                continue;
            }

            int base = total / 3;
            int r = total % 3;

            int n = base + (r > 0 ? 1 : 0);

            if (n >= score) {
                count++;
            } else if (surprising > 0) {
                surprising--;
                if (n + (r == 1 ? 0 : 1) >= score) {
                    count++;
                }
            } else {
                break;
            }
        }

        return count;
    }
}
