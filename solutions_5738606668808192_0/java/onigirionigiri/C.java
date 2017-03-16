import com.sun.istack.internal.Nullable;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.stream.Collectors;

/**
 * Created by onigiri on 16/04/09.
 */
public class C implements AutoCloseable {
    private static final String input = "/home/onigiri/Downloads/C-small-attempt2.in";
    private static final String output = "/home/onigiri/Downloads/output3.txt";
    private final BufferedReader br;
    private final BufferedWriter bw;

    private C() throws IOException {
        this.br = Files.newBufferedReader(Paths.get(input));
        this.bw = Files.newBufferedWriter(Paths.get(output));
    }

    public static void main(String[] args) throws Exception {
        try (C a = new C()) {
            a.solve();
        }
    }

    private void solve() throws Exception {
        final int T = readInt();
        for (int i = 0; i < T; i++) {
            final String ans = calc();
            final String output = String.format("Case #%s: %s\n", i + 1, ans);
            bw.write(output);
            System.out.print(output);
        }
    }


    private String calc() throws Exception {
        final int[] inputs = readInts();
        int n = inputs[0];
        int j = inputs[1];
        final List<BigInteger> primes = createPrimes();
        final List<String> res = new ArrayList<>();
        long state = (1L << n - 1) + (1L << 0);
        while (res.size() < j) {
            @Nullable List<Integer> list = calcList(state, primes, n);
            if (Objects.nonNull(list)) {
                res.add(Long.toBinaryString(state) + " "
                        + list.stream().map(x -> x + "").collect(Collectors.joining(" ")));
            }
            state += 2;
        }
        return "\n" + res.stream().collect(Collectors.joining("\n"));
    }

    private
    @Nullable
    List<Integer> calcList(long state, List<BigInteger> primes, int n) {
        final List<Integer> list = new ArrayList<>();
        for (int base = 2; base <= 10; base++) {
            BigInteger bb = BigInteger.valueOf(base);
            BigInteger val = BigInteger.ZERO;
            BigInteger p = BigInteger.ONE;
            for (int i = 0; i < n; i++) {
                if ((state >> i & 1) > 0) {
                    val = val.add(p);
                }
                p = p.multiply(bb);
            }
            boolean found = false;
            for (BigInteger d : primes) {
                if (val.mod(d).equals(BigInteger.ZERO)) {
                    list.add(d.intValue());
                    found = true;
                    break;
                }
            }
            if (!found) {
                return null;
            }
        }
        return list;
    }

    private List<BigInteger> createPrimes() {
        final int max = 10_000;
        final boolean[] isPrime = new boolean[max];
        for (int i = 0; i < max; i++) {
            isPrime[i] = true;
        }
        isPrime[0] = isPrime[1] = false;
        for (int i = 0; i < max; i++) {
            if (!isPrime[i]) {
                continue;
            }
            for (int j = i * i; j < max; j += i) {
                isPrime[j] = false;
            }
        }
        final List<BigInteger> res = new ArrayList<>();
        for (int i = 0; i < max; i++) {
            if (isPrime[i]) {
                res.add(BigInteger.valueOf(i));
            }
        }
        return res;
    }

    private int[] readInts() throws Exception {
        final String[] tmp = br.readLine().split(" ");
        final int[] res = new int[tmp.length];
        for (int i = 0; i < res.length; i++) {
            res[i] = Integer.parseInt(tmp[i]);
        }
        return res;
    }

    private String readString() throws Exception {
        return br.readLine();
    }

    private int readInt() throws Exception {
        return Integer.parseInt(br.readLine());
    }

    @Override
    public void close() throws Exception {
        br.close();
        bw.close();
    }
}
