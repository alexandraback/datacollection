package qualification;


import java.io.FileInputStream;
import java.io.IOException;
import java.util.Scanner;

public class Task2 {

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new FileInputStream("task21.txt"));
        int T = scanner.nextInt();
        for (int i = 0; i < T; i++) {
            int N = scanner.nextInt();
            int S = scanner.nextInt();
            int p = scanner.nextInt();
            int[] t = new int[N];
            for (int j = 0; j < N; j++) {
                t[j] = scanner.nextInt();
            }
            int noProbMin = Math.max(p * 3 - 2, p);
            int surpriseMin = Math.max(p * 3 - 4, p);
            int noProbCount = 0;
            int surpriseCount = 0;
            for (int googler : t) {
                if (googler >= noProbMin) {
                    noProbCount++;
                }
                if (googler < noProbMin && googler >= surpriseMin) {
                    surpriseCount++;
                }
            }
            surpriseCount = Math.min(surpriseCount, S);
            System.out.println("Case #" + (i + 1) + ": " + (noProbCount + surpriseCount));
        }
    }
}
