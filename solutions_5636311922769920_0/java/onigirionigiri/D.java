import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Created by onigiri on 16/04/09.
 */
public class D implements AutoCloseable {
    private static final String input = "/home/onigiri/Downloads/D-small-attempt2.in";
    private static final String output = "/home/onigiri/Downloads/output5.txt";
    private final BufferedReader br;
    private final BufferedWriter bw;

    private D() throws IOException {
        this.br = Files.newBufferedReader(Paths.get(input));
        this.bw = Files.newBufferedWriter(Paths.get(output));
    }

    public static void main(String[] args) throws Exception {
        try (D a = new D()) {
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
        int k = inputs[0];
        int c = inputs[1];
        int s = inputs[2];

        int current = 0;
        final List<Long> res = new ArrayList<>();
        for (int i = 0; i < s; i++) {
            long val = 0;
            for (int j = 0; j < c; j++) {
                if (current == k) {
                    current = k - 1;
                }
                val = val * k + current;
                current++;
            }
            res.add(val);
        }

        if (current < k) {
            return "IMPOSSIBLE";
        } else {
            return res.stream().distinct().map(x -> Long.toString(x + 1)).collect(Collectors.joining(" "));
        }
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
