import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

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
        final String S = readString();
        final int len = S.length();
        int s = 0;
        int t = len-1;
        final char[]ans = new char[len];

        for(int i=len-1;i>=0;i--){
            boolean biggest = true;
            for(int j=0;j<i;j++){
                if(S.charAt(j)>S.charAt(i)){
                    biggest = false;
                }
            }
            if(biggest){
                ans[s++] = S.charAt(i);
            }else {
                ans[t--] = S.charAt(i);
            }
        }
        final StringBuilder stringBuilder = new StringBuilder();
        for(int i=0;i<len;i++){
            stringBuilder.append(ans[i]);
        }
        return stringBuilder.toString();
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
