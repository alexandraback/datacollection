import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class C {

    private static final String FILE_NAME = "C-small-attempt0";

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader(FILE_NAME + ".in"));
        BufferedWriter out = new BufferedWriter(new FileWriter(FILE_NAME + ".out"));

        int t = Integer.parseInt(in.readLine());
        for (int c = 1; c <= t; ++c) {
            String[] split = in.readLine().split(" ");
            int count = Integer.parseInt(split[0]);
            int value = Integer.parseInt(split[2]);
            List<Integer> coins = new ArrayList<Integer>();
            for (String s : in.readLine().split(" ")) {
                coins.add(Integer.parseInt(s));
            }
            int newCoins = 0;
            for (int i = 0; i < 10; ++i) {
                if (canMakeWith(i, count, value, coins)) {
                    newCoins = i;
                    break;
                }
            }
            String ans = String.format("Case #%d: %d\n", c, newCoins);
            out.write(ans);
            System.out.print(ans);
        }
        out.close();
    }

    private static boolean canMakeWith(int newCoins, int count, int value, List<Integer> coins) {
        if (newCoins == 0) {
            boolean[] canMake = canMake(count, value, coins);
            return isDone(canMake);
        }
        for (int i = 1; i < value+1; ++i) {
            if (!coins.contains(i)) {
                List<Integer> coins2 = new ArrayList<Integer>(coins);
                coins2.add(i);
                if (canMakeWith(newCoins-1, count, value, coins2)) {
                    return true;
                }
            }
        }
        return false;
    }

    private static boolean isDone(boolean[] canMake) {
        for (boolean b : canMake) {
            if (!b) {
                return false;
            }
        }
        return true;
    }

    private static boolean[] canMake(int count, int value, List<Integer> coins) {
        boolean[] canMake = new boolean[value+1];
        canMake[0] = true;
        for (Integer coin : coins) {
            for (int i = 0; i < count; ++i) {
                for (int p = value-coin; p >= 0; --p) {
                    if (canMake[p]) {
                        canMake[p+coin] = true;
                    }
                }
            }
        }
        return canMake;
    }
}
