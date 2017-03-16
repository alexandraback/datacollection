import java.util.*;
import java.math.*;

public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        B th = new B();
        for (int i = 0; i < T; i++) {
            int N = sc.nextInt();
            int[] s1 = new int[N];
            int[] s2 = new int[N];
            for (int j = 0; j < N; j++) {
                s1[j] = sc.nextInt();
                s2[j] = sc.nextInt();
            }
            int c = th.getAnswer(N, s1, s2);
            String S = "" + c;
            if (c == 0) {
                S = "Too Bad";
            }
            System.out.println("Case #" + (i+1) + ": " + S);
        }
    }
    public int getAnswer(int n, int[] s1, int[] s2) {
        int count = 0;
        int turn = 0;
        boolean[] b1 = new boolean[n];
        boolean[] b2 = new boolean[n];
        while (count < n*2) {
            boolean f = false;
            for (int i = 0; i < n; i++) {
                if (b2[i] == false && s2[i] <= count) {
                    b2[i] = true;
                    if (b1[i] == false) {
                        b1[i] = true;
                        count++;
                    }
                    count++;
                    turn++;
                    f = true;
                }
            }
            if (f)
                continue;
            int max = 0;
            int maxi = -1;
            for (int i = 0; i < n; i++) {
                if (b1[i] == false && s1[i] <= count) {
                    if (max < s2[i]) {
                        max = s2[i];
                        maxi = i;
                    }
                }
            }
            if (maxi == -1)
                return 0;
            b1[maxi] = true;
            count++;
            turn++;
        }
        return turn; 
    }
}

