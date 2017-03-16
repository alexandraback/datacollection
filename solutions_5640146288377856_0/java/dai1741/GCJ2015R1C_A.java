import java.util.Scanner;


public class GCJ2015R1C_A {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            System.out.printf("Case #%d: %d%n", i, new GCJ2015R1C_A().solve(sc));
        }
    }
    
    private int solve(Scanner sc) throws Exception {
        int r = sc.nextInt();
        int c = sc.nextInt();
        int w = sc.nextInt();
        int ans = 0;
        if (r > 1) {
            ans += c / w * (r-1);
        }
        while (c > w*2) {
            c -= w;
            ans++;
        }
        ans += w + (c == w ? 0 : 1);

        return ans;
    }
}
