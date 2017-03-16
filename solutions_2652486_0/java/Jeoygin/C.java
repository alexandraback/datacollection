package gcj2013.round1a;

import java.util.Scanner;

public class C {

    
    
    public static void solve(Scanner scan, int n, int m, int k) {
        int[] cnt = new int[10];
        int[] products = new int[k];
        for (int i = 0; i < k; i++) {
            products[i] = scan.nextInt();
        }
        
        for (int i = 2; i <= 5; i++) {
            cnt[i]++;
            for (int j = i; j <= 5; j++ ) {
                cnt[j]++;
                for (int l = j; l <= 5; l++) {
                    cnt[l]++;
                    boolean error = false;
                    for (int a = 0; a < k; a++) {
                        int p = products[a];
                        int c = 0;
                        if (p % l == 0) {
                            p /= l;
                            c++;
                        }
                        if (p % j == 0) {
                            p /= j;
                            c++;
                        }
                        if (p % i == 0) {
                            p /= i;
                            c++;
                        }
                        if (p != 1) {
                            error = true;
                            break;
                        }
                    }
                    if (!error) {
                        System.out.println(i + "" + j + "" + l);
                        return;
                    }

                    cnt[l]--;
                }
                cnt[j]--;
            }
            cnt[i]--;
        }
    }
    
    public static final void main(final String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        int r = scan.nextInt();
        int n = scan.nextInt();
        int m = scan.nextInt();
        int k = scan.nextInt();
        System.out.println("Case #1:");
        for (int i = 1; i <= r; i++ ) {
            solve(scan, n, m, k);
        }
    }
}
