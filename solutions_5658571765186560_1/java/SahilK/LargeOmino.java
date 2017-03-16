import java.util.Scanner;
import java.util.PriorityQueue;

public class LargeOmino {

    public static String Richard = "RICHARD";
    public static String Gabriel = "GABRIEL";

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i=1;i<=T;i++) {
            int x = sc.nextInt();
            int r = sc.nextInt();
            int c = sc.nextInt();
            String s = solve(x,Math.min(r,c),Math.max(r,c));
            System.out.printf("Case #%d: %S", i, s);
            System.out.println("");
        }
    }

    public static String solve(int x, int r, int c) {
        if (x==1) {
            return Gabriel;
        }
        if (x==2) {
            if ((r*c)% 2 == 0) {
                return Gabriel;
            }
            return Richard;
        }
        if (x>=7) {
            return Richard;
        }
        if ((r*c)%x != 0) {
            return Richard;
        }
        if (c>=x && r>=x) {
            return Gabriel;
        }
        if (c<x) {
            return Richard;
        }
        if (r==1) {
            return Richard;
        }
        if (x==3) {
            return Gabriel;
        }
        if (x==4) {
            if (r==2) {
                return Richard;
            }
            return Gabriel;
        }
        if (x==5) {
            if (r==2) {
                return Richard;
            }
            return Gabriel;
        }
        if (x==6) {
            if (r==2) {
                return Richard;
            }
            if (r==3) {
                return Richard;
            }
            return Gabriel;
        }
        return "error";
    }
}
