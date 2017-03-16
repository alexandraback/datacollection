package b1;

import java.io.FileInputStream;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.Locale;
import java.util.Scanner;

public class Task1 {

        public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new FileInputStream("1b_task1.txt"));
        scanner.useLocale(Locale.US);
        int T = scanner.nextInt();
        for (int i = 0; i < T; i++) {
            int N = scanner.nextInt();
            int[] s = new int[N];
            boolean[] use = new boolean[N];
            int sum = 0;
            for (int j = 0; j < N; j++) {
                s[j] = scanner.nextInt();
                sum += s[j];
                use[j] = false;
            }
            int currentSum = sum;
            double avg = 0;
            boolean flag = true;
            int notUse = 0;
            while (flag) {
                avg = (sum + currentSum) / (double)(N - notUse);
                currentSum = 0;
                flag = false;
                for (int j = 0; j < N; j++) {
                    if (!use[j]) {
                        if (s[j] > avg) {
                            notUse++;
                            use[j] = true;
                            flag = true;
                        } else {
                            currentSum += s[j];
                        }
                    }
                }
            }

            System.out.print("Case #" + (i + 1) + ": ");
            for (int j = 0; j < N; j++) {
                if (use[j]) {
                    System.out.print("0.000000");
                } else {
                    double need = avg - s[j];
                    if (need < 0) {
                        System.out.print("0.000000");
                    } else {
                        System.out.print(new DecimalFormat("0.000000").format(100 * need / sum).replace(',', '.'));
                    }
                }
                if (j != N - 1) {
                    System.out.print(' ');
                }
            }
            System.out.println();
        }
    }
}
