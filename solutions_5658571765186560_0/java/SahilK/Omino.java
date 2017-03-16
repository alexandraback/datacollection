import java.util.Scanner;
import java.util.PriorityQueue;

public class Omino {

    public static String Richard = "RICHARD";
    public static String Gabriel = "GABRIEL";
    public static int[][] three = {{0,0,0,0},
                            {0,0,1,0},
                            {0,1,1,1},
                            {0,0,1,0}};
    public static int[][] four = { {0,0,0,0},
                            {0,0,0,0},
                            {0,0,0,1},
                            {0,0,1,1}};


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i=1;i<=T;i++) {
            int x = sc.nextInt();
            int r = sc.nextInt();
            int c = sc.nextInt();
            String s = solve(x,r,c);
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
        if (x==3) {
            int ans = three[r-1][c-1];
            if (ans == 1) {
                return Gabriel;
            }
            return Richard;
        }
        if (x==4) {
            int ans = four[r-1][c-1];
            if (ans == 1) {
                return Gabriel;
            }
            return Richard;
        }
        return Richard;
    }
}
