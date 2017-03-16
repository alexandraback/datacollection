package gcj.round1B;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * @author fuku
 */
public class TaskB {
    public static void main(String[] args) throws FileNotFoundException {
        InputStream inputStream = TaskB.class.getResourceAsStream("B-small-attempt0.in");
        Scanner in = new Scanner(inputStream);

        PrintWriter out = new PrintWriter(new FileOutputStream("./out.txt"));

        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            System.out.println("------------------");
            System.out.println("test " + (i+1));
            SolB solver = new SolB();
            String ans = solver.solve(i, in, out);
            out.println("Case #" + (i+1) + ": " + ans);
            System.out.println("Case #" + (i+1) + ": " + ans);
        }
        out.close();
    }
}

class SolB {

    int[] Aa;
    int[] Ba;
    int[] Ka;

    int AN;
    int BN;
    int KN;

    public String solve(int testNumber, Scanner in, PrintWriter out) {
        long A = in.nextLong();
        long B = in.nextLong();
        long K = in.nextLong();

        // make A < B
        if (A > B) {
            long tmp = A;
            A = B;
            B = tmp;
        }

        // bit array
        Aa = bit(A);
        Ba = bit(B);
        Ka = bit(K);

        AN = Aa.length;
        BN = Ba.length;
        KN = Ka.length;

        long tot = 0;
        for (long i = 0; i < A; i++) {
            for (long j = 0; j < B; j++) {
                if ((i & j) < K) tot++;
            }
        }

        String ans = "" + tot;
        return ans;
    }

    long numZero(int i, boolean consK) {
        long p = 1;
        for (int j = i; j < BN; j++) {
            if (consK && j < KN && Ka[j] == 1) {
                continue;
            }
            if (j < AN) p *= 3;
            else if (AN<= j && j < BN) p *= 2;
        }
        return p;
    }

    int[] bit(long a) {
        String bs = Long.toBinaryString(a);
        int[] b = new int[bs.length()];
        int c= 0;
        for (int i = b.length -1; i >=0; i--) {
            if ( bs.charAt(i) == '1' ) b[c] = 1;
            c++;
        }
        System.out.printf("a, b = %s, %s\n", a, Arrays.toString(b));
        return b;
    }

    static final long MOD = Long.MAX_VALUE;

    static long modPow(int x, int y) {
        long res = 1, a = x;
        while (y > 0) {
            if ((y & 1) > 0) {
                res = (res * a) % MOD;
            }
            a = (a * a) % MOD;
            y >>= 1;
        }
        return res;
    }
}
