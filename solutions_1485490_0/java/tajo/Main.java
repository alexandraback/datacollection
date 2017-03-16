
import java.util.Scanner;

public class Main {

    static long[] numOfToys;
    static int[] toyType;
    static long[] numOfBoxes;
    static int[] boxType;
    static long max;

    private static void find(int i, int j, long sum) {
        if (sum > max) max = sum;
        if (i == numOfToys.length || j == numOfBoxes.length) return;
        if (boxType[j] == toyType[i]) {
            long res = Math.min(numOfToys[i], numOfBoxes[j]);
            numOfToys[i] -= res;
            numOfBoxes[j] -= res;
            find(i + 1, j + 1, sum + res);
            find(i, j + 1, sum + res);
            find(i + 1, j, sum + res);
            numOfToys[i] += res;
            numOfBoxes[j] += res;
        } else {
            find(i, j + 1, sum);
            find(i + 1, j, sum);
            find(i + 1, j + 1, sum);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int x = 1; x <= t; x++) {
            max = 0;
            int n = sc.nextInt();
            int m = sc.nextInt();
            numOfToys = new long[n];
            toyType = new int[n];
            numOfBoxes = new long[m];
            boxType = new int[m];
            for (int i = 0; i < n; i++) {
                numOfToys[i] = sc.nextLong();
                toyType[i] = sc.nextInt();
            }
            for (int i = 0; i < m; i++) {
                numOfBoxes[i] = sc.nextLong();
                boxType[i] = sc.nextInt();
            }
            find(0, 0, 0);
            System.out.println("Case #" + x + ": " + max);
        }
    }
}
