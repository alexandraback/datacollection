import java.math.BigInteger;
import java.util.*;

public class Main {


    char[] bits = new char[32];
    Integer[] primes = new Integer[1000];
    int tot;
    int sum;
    int tar = 50;

    void solve() {
        if (sum == tar) return;
        for (int i = 2; i <= 10; i += 2) {
            BigInteger num = new BigInteger(new String(bits), i);
            boolean flag = false;
            for (int j = 0; j < tot; j++) {
                if (num.divideAndRemainder(new BigInteger(primes[j].toString()))[1].equals(BigInteger.ZERO)) {
                    flag = true;
                    break;
                }
            }
            if (flag == false) {
                return;
            }
        }

        sum++;
        System.out.print(new String(bits).substring(16));
        for (int i = 2; i <= 10; i++) {
            BigInteger num = new BigInteger(new String(bits), i);
            boolean flag = false;
            for (int j = 0; j < tot; j++) {
                if (num.divideAndRemainder(new BigInteger(primes[j].toString()))[1].equals(BigInteger.ZERO)) {
                    System.out.print(" " + primes[j]);
                    flag = true;
                    break;
                }
            }
            if (flag == false) {
                return;
            }
        }
        System.out.println();

    }

    void dfs(int pos, int num) {
        if (pos == 31) {
            if (num % 2 == 0)
                solve();
            return;
        }
        dfs(pos + 1, num);
        bits[pos] = '1';
        dfs(pos + 1, num + 1);
        bits[pos] = '0';
    }

    void run() {
        tot = 0;
        for (int i = 2; i < 1000; i++) {
            boolean flag = true;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                primes[tot++] = i;
            }
        }
        Arrays.fill(bits, '0');
        bits[16] = '1';
        bits[31] = '1';
        System.out.println("Case #1:");
        dfs(17, 2);
    }

    public static void main(String[] args) {
        new Main().run();
    }
}
