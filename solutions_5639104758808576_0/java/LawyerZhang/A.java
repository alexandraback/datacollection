import java.util.*;

public class A {
    public static final void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int T = scan.nextInt();
        for (int cs = 1; cs <= T; ++cs) {
            scan.nextInt();
            String s = scan.next();
            long ans = 0, current = 0;
            for (int i = 0; i < s.length(); ++i) {
                int t = s.charAt(i) - '0';
                ans += Math.max(0, i - current);
                current += Math.max(0, i - current);
                current += t;
            }
            System.out.format("Case #%d: %d\n", cs, ans);
        }
    }
}
