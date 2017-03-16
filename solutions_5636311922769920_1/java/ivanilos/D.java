import java.io.*;
import java.util.*;

public class D {

    public static long Pot(int b, int p) {
        long r = 1;
        while(p > 0) {
            p--;
            r = r * b;
        }
        return r;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        int k, c, s;

        for (int caso = 1; caso <= t; caso++) {
            System.out.print("Case #" + caso + ":");
            ArrayList<Long> res = new ArrayList<Long> ();
            k = in.nextInt();
            c = in.nextInt();
            s = in.nextInt();

            int got = 0;
            while(got < k) {
                int pos = got + 1;
                long idx = 0;
                for (int i = 1; i < c; i++) {
                    int delta = pos - 1;
                    idx += delta * Pot(k, c - i);
                    pos = Math.min(pos + 1, k);
                }
                res.add(idx + pos);
                got += c;
            }
            if (res.size() > s) {
                System.out.println(" IMPOSSIBLE");
            } else {
                for (int i = 0; i < res.size(); i++) {
                    System.out.print(" " + res.get(i));
                }
                System.out.println("");
            }
        }
    }
}
