import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Round1BProblemC {

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(
                new InputStreamReader(new FileInputStream("C-small-attempt0.in")));
        String line = br.readLine();
        int T = Integer.parseInt(line);
        PrintWriter pw = new PrintWriter("C-small.out");

        for (int test = 0; test < T; test++) {
            line = br.readLine();
            int N = Integer.parseInt(line);
            String firsts[] = new String[N];
            String seconds[] = new String[N];
            for (int i = 0; i < N; i++) {
                line = br.readLine();
                String tokens[] = line.split(" ");
                firsts[i] = tokens[0];
                seconds[i] = tokens[1];
            }
            pw.println("Case #" + (test + 1) + ": " + solve(firsts, seconds));
            //break;
        }
        pw.close();
        br.close();
    }

    private static String solve(String[] firsts, String[] seconds) {
        int max = 0;
        int N = firsts.length;

        for (int i = 0; i < (1 << N); i++) {

            Set<String> original1 = new HashSet<>();
            Set<String> original2 = new HashSet<>();
            Set<String> fake1 = new HashSet<>();
            Set<String> fake2 = new HashSet<>();

            int count = 0;
            for (int j = 0; j < N; j++) {
                boolean isFake = ((i >> j) & 1) == 0;
                if (isFake) {
                    fake1.add(firsts[j]);
                    fake2.add(seconds[j]);
                    count++;
                } else {
                    original1.add(firsts[j]);
                    original2.add(seconds[j]);
                }
            }

            if (count < max) {
                continue;
            }

            boolean ok = true;
            for (String fake : fake1) {
                if (!original1.contains(fake)) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            for (String fake : fake2) {
                if (!original2.contains(fake)) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                max = count;
            }
        }
        return String.valueOf(max);
    }

}
