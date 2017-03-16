import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

/**
 * Created by onigiri on 16/04/09.
 */
public class B implements AutoCloseable {
    private static final String input = "/home/onigiri/Downloads/B-large.in";
    private static final String output = "/home/onigiri/Downloads/output.txt";
    private final BufferedReader br;
    private final BufferedWriter bw;

    private B() throws IOException {
        this.br = Files.newBufferedReader(Paths.get(input));
        this.bw = Files.newBufferedWriter(Paths.get(output));
    }

    public static void main(String[] args) throws Exception {
        try (B a = new B()) {
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

    private static final int MAX = 3000;
    private String calc() throws Exception {
        final int N = readInt();
        final int[] cnts = new int[MAX];
        for(int i=0;i<2*N-1;i++){
            final int[]read = readInts();
            for(int j=0;j<read.length;j++){
                cnts[read[j]]++;
            }
        }
        final List<Integer> res = new ArrayList<>();
        for(int i=0;i<MAX;i++){
            if((cnts[i]&1)==1){
                res.add(i);
            }
        }
        return res.stream()
                .sorted()
                .map(x->x+"")
                .collect(Collectors.joining(" "));
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
