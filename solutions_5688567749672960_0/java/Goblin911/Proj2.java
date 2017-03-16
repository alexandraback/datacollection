import java.io.PrintStream;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Proj2 {

    static Scanner cin = new Scanner(System.in);
    static PrintStream cout = System.out;

    int n;
    int[] f;
    int MA = Integer.MAX_VALUE >> 2;
    int[] out(int t) {
        int[] res = new int[2];
        res[0] = t + 1;
        String s = Integer.toString(t);
        String e = "";
        for (int i = s.length() - 1; i >= 0; i--)
            e = e + s.charAt(i);
        res[1] = Integer.parseInt(e);
        return res;
    }

    void solve() {
        n = cin.nextInt();
        f = new int[10000011];
        for (int i = 0; i < f.length; i++)
            f[i] = MA;
        Queue<Integer> q = new LinkedList<>();
        f[1] = 1;
        q.add(1);
        while (!q.isEmpty()) {
            int now = q.poll();
            int dis = f[now];
            if (now > n * 10)
                continue;
            int[] t = out(now);
            for (int i = 0; i < 2; i++) {
                if (f[t[i]] == MA) {
                    f[t[i]] = dis + 1;
                    q.add(t[i]);
                }
            }
        }
        cout.println(f[n]);
    }

    Proj2() {
        int t = cin.nextInt();
        for (int i = 1; i <= t; i++) {
            cout.print("Case #" + i + ": ");
            solve();
        }

    }

    public static void main(String[] args) {
        new Proj2();
    }

}

