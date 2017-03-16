import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.io.File;

class solver {

    private long bits[];
    BufferedWriter bw;

    private boolean check() {
        BigInteger bases[] = new BigInteger[9];
        int base;
        int i = 0;
        int j;
        for (base = 2; base <= 10; base++) {
            BigInteger tmp = new BigInteger("1");
            bases[i] = new BigInteger("0");
            for (j = bits.length - 1; j >= 0; j--) {
                BigInteger b = new BigInteger(bits[j] + "");
                bases[i] = bases[i].add(tmp.multiply(b));
                tmp = tmp.multiply(new BigInteger("" + base));
            }
            i++;
        }
        boolean ok = true;
        for (i = 0; i < 9; i++) {
            boolean tmp = false;
            int stop = 0;
            BigInteger z = new BigInteger("2");
            BigInteger zero = new BigInteger("0");
            while (z.compareTo(bases[i]) == -1) {
                if ((bases[i].mod(z)).equals(zero)) {
                    tmp = true;
                    bases[i] = z;
                    break;
                }
                stop++;
                if (stop == 100) {
                    return false;
                }
                z = z.add(new BigInteger("1"));
            }
            if (tmp) continue;
            ok = false;
            break;
        }
        if (ok) {
            try {
                for (i = 0; i < bits.length; i++) bw.write(bits[i] + "");
                bw.write(" ");
                for (i = 0; i < 9; i++) {
                    bw.write(bases[i] + " ");
                }
                bw.write("\n");
            } catch (IOException ex) {

            }
        }
        return ok;
    }

    public void solve(int J, int N) {
        try {
            bw = new BufferedWriter(new FileWriter(new File("out.txt")));
            long one = 1;
            long bound = one << N - 1;
            bits = new long[N];
            bits[0] = 1;
            bw.write("Case #1: \n");
            bits[N - 1] = 1;
            int i, n, end;
            end = 0;

            if (check()) end++;
            for (n = 1; n <= bound; n++) {
                long x = n;
                i = N - 2;
                while (x != 0) {
                    bits[i] = x % 2;
                    x = x / 2;
                    i--;
                }
                if (check()) {
                    end++;
                }
                if (end == J) break;
            }
            bw.close();
        } catch (IOException ex) {

        }
    }
}
public class main {
    public static void main(String[] argvs){
        solver s = new solver();
        s.solve(500, 32);
    }
}
