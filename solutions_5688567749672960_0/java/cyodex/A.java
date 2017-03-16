import java.util.*;
import java.io.*;

public class A {

    int INF = 1000001;
    public static void main(String[] args) throws FileNotFoundException {
        new A().solve();
    }

    public void solve() throws FileNotFoundException{
        //Scanner in = new Scanner(System.in);
        Scanner in = new Scanner(new File("a.in"));
        PrintWriter out = new PrintWriter("a.out");
        int t = Integer.parseInt(in.nextLine());
        for (int test = 1; test <= t; test++) {
            int n = Integer.parseInt(in.nextLine());
            Queue<Integer> q = new LinkedList<Integer>();
            boolean[] v = new boolean[1000001];
            v[1] = true;
            q.add(1);
            q.add(1);
            int ans = 1;
            while(!q.isEmpty()) {
                int num = q.remove();
                int steps = q.remove();
                if (num == n) {
                    ans = steps;
                    break;
                }
                if (num + 1 < INF && !v[num + 1]) {
                    q.add(num + 1);
                    q.add(steps + 1);
                    v[num + 1] = true;
                }
                if (reverse(num) < INF && !v[reverse(num)]) {
                    q.add(reverse(num));
                    q.add(steps + 1);
                    v[reverse(num)] = true;
                }
            }
            //System.out.println(ans);
            out.println("Case #" + test + ": " + ans);
        }

        out.close();
    }

    public int reverse(int n) {
        int ans = 0;
        while (n > 0) {
            ans = ans * 10 + n % 10;
            n /= 10;
        }
        return ans;
    }
}