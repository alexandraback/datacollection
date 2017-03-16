package gcj12;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class C {
    void solve() {
        Scanner scan = new Scanner(System.in);
        int tCase = scan.nextInt();
        for (int i = 1; i <= tCase; i++) {
            int res = 0;
            int a = scan.nextInt();
            int b = scan.nextInt();
            for (int j = a; j <= b; j++) {
                int pow = 10;
                Map<Integer, Integer> map = new HashMap<Integer, Integer>();
                while (j / pow > 0) {
                    int tmp = Integer.valueOf((j % pow) + "" + (j / pow));
                    if (tmp > j && tmp <= b && map.get(tmp) == null) {
                        map.put(tmp, tmp);
                        res++;
                    }
                    pow *= 10;
                }
            }
            System.out.println("Case #" + i + ": " + res);
        }

    }

    public static void main(String[] args) {
        new C().solve();
    }
}
