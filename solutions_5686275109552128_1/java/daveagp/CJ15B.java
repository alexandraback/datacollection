import java.util.*;
public class CJ15B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        for (int u=1; u<=k; u++) {
            int n = sc.nextInt();
            int[] cakes = new int[n];
            for (int i=0; i<n; i++) cakes[i] = sc.nextInt();
            int result = 1000;
            for (int per = 1; per <= 1000; per++) {
                int trial = per;
                for (int i=0; i<n; i++) trial += (cakes[i]-1)/per;
                result = Math.min(result, trial);
            }
            System.out.println("Case #" + u + ": " + result);
        }
    }
}