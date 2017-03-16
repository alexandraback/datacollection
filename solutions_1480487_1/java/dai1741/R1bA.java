import java.util.Scanner;


public class R1bA {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            solve(sc, i);
        }
    }
    
    static int n;
    static int sum;
    static double[] js;
    
    static void solve(Scanner sc, int c) {
        n = sc.nextInt();
        sum = 0;
        double max = 0;
        js = new double[n]; 
        for (int i = 0; i < n; i++) {
            js[i] = sc.nextDouble();
            sum += js[i];
            max = Math.max(max, js[i]);
        }
        double l = 0;
        double r = sum + 0.1;
        double mid = 0;
        for (int i = 0; i < 1000; i++) {
            mid = (l + r) / 2;
            if (isPossibleAllContestantsGetPoint(mid)) {
                l = mid;
            }
            else {
                r = mid; // r 含まない
            }
        }
        
        // mid が最低必要なポイント
        StringBuilder sb = new StringBuilder(n*10).append("Case #").append(c).append(":");
        for (int i = 0; i < n; i++) {
            sb.append(" ");
            double diff = mid - js[i];
            if (diff <= 0) sb.append(0.0);
            else sb.append(diff / sum * 100);
        }
        System.out.println(sb);
    }
    
    static boolean isPossibleAllContestantsGetPoint(double p) {
        double ySum = 0;
        for (int i = 0; i < n; i++) {
            double diff = p - js[i];
            if (diff > 0) {
                ySum += diff / sum;
            }
        }
        return ySum <= 1;
    }

}
