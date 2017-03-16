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
public class A implements AutoCloseable {
    private static final String input = "/home/onigiri/Downloads/A-large.in";
    private static final String output = "/home/onigiri/Downloads/output.txt";
    private final BufferedReader br;
    private final BufferedWriter bw;

    private A() throws IOException {
        this.br = Files.newBufferedReader(Paths.get(input));
        this.bw = Files.newBufferedWriter(Paths.get(output));
    }

    public static void main(String[]args) throws Exception {
        try (A a = new A()) {
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
        final int num = readInt();
        final Set<Character> set = new HashSet<>();
        for (int i = 0; i < 111; i++) {
            final char[] array = ((i + 1) * num + "").toCharArray();
            for (char c : array) {
                set.add(c);
            }
            if (set.size() == 10) {
                return (i + 1) * num + "";
            }
        }
        return "INSOMNIA";
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
