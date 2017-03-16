import java.util.Arrays;
import java.util.Scanner;


public class GCJ2014QualD {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            System.out.printf("Case #%d: %s%n", i, new GCJ2014QualD().solve(sc));
        }
    }

    private String solve(Scanner sc) throws Exception {
        int n = sc.nextInt();
        double[] naD = new double[n];
        double[] keD = new double[n];
        for (int i = 0; i < n; i++) {
            naD[i] = sc.nextDouble();
        }
        for (int i = 0; i < n; i++) {
            keD[i] = sc.nextDouble();
        }
        Arrays.sort(naD);
        Arrays.sort(keD);
        int[] nas = new int[n];
        int[] kes = new int[n];
        for (int i = 0, j = 0, k = 0; k < 2 * n; k++) {
            if (i < n && (j == n || naD[i] < keD[j])) nas[i++] = k;
            else kes[j++] = k;
        }

        // play War
        boolean[] keUsed = new boolean[n];
        int warPoint = 0;
        for (int i = 0; i < n; i++) {
            int na = nas[i];
            int minWinabbleJ = -1;
            int minUnusedJ = -1;
            for (int j = 0; j < n; j++) {
                if (keUsed[j]) continue;
                if (minUnusedJ == -1) minUnusedJ = j;
                if (na < kes[j]) {
                    minWinabbleJ = j;
                    break;
                }
            }
            int j = Math.max(minUnusedJ, minWinabbleJ);
            keUsed[j] = true;
            if (na > kes[j]) warPoint++;
        }
        
        // play deceitful war
        int dWarPoint = 0;
        for (int j = 0, i = 0; i < n && j < n; j++) {
            while (i < n && nas[i] < kes[j]) i++;
            if (i < n) {
                i++;
                dWarPoint++;
            }
        }
        
        return dWarPoint + " " + warPoint;
    }
}
