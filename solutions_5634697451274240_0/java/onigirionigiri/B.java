import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.HashSet;
import java.util.Set;

/**
 * Created by onigiri on 16/04/09.
 */
public class B implements AutoCloseable {
    private static final String input = "/home/onigiri/Downloads/B-small-attempt0.in";
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

    private String calc() throws Exception {
        String str = readString();
        while (true) {
            final String tmp = str.replaceAll("--", "-").replaceAll("\\+\\+", "+");
            if (tmp.length() == str.length()) {
                break;
            }
            str = tmp;
        }
        final int res = str.length() - (str.endsWith("+") ? 1 : 0);
        return res + "";
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
