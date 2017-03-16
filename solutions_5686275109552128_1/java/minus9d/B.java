import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class B
{
    Scanner sc = new Scanner(System.in);
    
    int solve() {
        int D = sc.nextInt();
        ArrayList<Integer> dishes = new ArrayList<Integer>();

        for (int d = 0; d < D; ++d) {
            dishes.add(sc.nextInt());
        }

        int max_dish = Collections.max(dishes);
        int ret = max_dish;
        for (int mx = 1; mx <= max_dish; ++mx) {
            int minutes = mx;
            for (int dish: dishes) {
                minutes += (dish - 1) / mx;
            }
            if (minutes < ret) ret = minutes;
        }

        return ret;
    }

    void run() {
        int T = sc.nextInt();
        for (int t = 1; t <= T; ++t) {
            System.out.printf("Case #%d: %d\n", t, solve());
            System.out.flush();
        }
    }

    public static void main(String[] args) {
        new B().run();
    }
}

