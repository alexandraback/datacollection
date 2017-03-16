import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

/**
 * Created by onigiri on 16/04/09.
 */
public class C implements AutoCloseable {
    private static final String input = "/home/onigiri/Downloads/C-small-attempt2.in";
    private static final String output = "/home/onigiri/Downloads/output.txt";
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
        final int N = readInt();
        final int[] edges = readInts();
        final List<List<Integer>> reverse = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            reverse.add(new ArrayList<>());
        }
        for (int i = 0; i < N; i++) {
            final int next = edges[i] - 1;
            reverse.get(next).add(i);
        }

        int sum = 0;
        int res = 0;
        for (int i = 0; i < N; i++) {
            final int a = edges[i] - 1;
            final int b = edges[a] - 1;
            if (i != b) {
                res = Math.max(res, cycle(edges, i));
            } else {
                sum +=  line(a, b, reverse);
                res = Math.max(res, line(a, b, reverse) + line(b, a, reverse));
            }
        }
        res = Math.max(res, sum);
        return res + "";
    }

    private int line(int start, int prohibited, List<List<Integer>> reverse) {
        int res = 1;
        for (int next : reverse.get(start)) {
            if (next == prohibited) {
                continue;
            }
            res = Math.max(res, line(next, prohibited, reverse) + 1);
        }
        return res;
    }

    private int cycle(int[] edges, int start) {
        int cur = start;
        final Set<Integer> visited = new HashSet<>();
        visited.add(start);
        while (true) {
            final int next = edges[cur] - 1;
            if (visited.contains(next)) {
                return (next == start ? visited.size() : 0);
            }
            visited.add(next);
            cur = next;
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
