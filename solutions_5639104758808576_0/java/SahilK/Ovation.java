import java.util.Scanner;
import java.util.PriorityQueue;

public class Ovation {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i=1;i<=T;i++) {
            int n = sc.nextInt();
            int[] a = new int[n+1];
            String s = sc.next();
            for (int k=0; k<=n; k++) {
                a[k] = s.charAt(k) - '0';
            }
            System.out.printf("Case #%d: %d",i,solve(a,n));
            System.out.println("");

        }
    }

    public static int solve(int[] a, int n) {
        int[] b = new int[n+1];
        b[0] = 0;
        for (int q=1; q<=n; q++) {
            b[q] = b[q-1] + a[q-1];
        }
        for (int y=0; y<=n; y++) {
            b[y] = y - b[y];
        }
        int maxima = 0;
        for (int j=0; j<=n; j++) {
            if (a[j] != 0 && b[j] > maxima) {
                maxima = b[j];
            }
        }
        return maxima;
    }
}
