import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;

public class ProbC {

    private static final String INPUT_FILE = "e:/downloads/C-small-attempt0.in";
    private static final String OUTPUT_FOLDER = "C:/workspaces/algo/GCJ/src/";
    private static final String OUTPUT_FILE = "C-small.out";


    public static void main(String[] args) throws Exception {
        InputReader in = new InputReader(new FileInputStream(INPUT_FILE));
        PrintWriter pw = new PrintWriter(new File(OUTPUT_FOLDER, OUTPUT_FILE));
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            int N = in.nextInt();
            List<String> firsts = new ArrayList<>();
            List<String> seconds = new ArrayList<>();
            for (int i = 0; i < N; i++) {
                firsts.add(in.next());
                seconds.add(in.next());
            }
            int max = 0;
            for (int i = 0; i < 1 << N; i++) {
                Set<String> origFirsts = new HashSet<>();
                Set<String> origSeconds = new HashSet<>();
                List<String> fakeFirsts = new ArrayList<>();
                List<String> fakeSeconds = new ArrayList<>();
                for (int j = 0; j < N; j++) {
                    int jthBit = i & 1 << j;
                    if (jthBit > 0) {
                        origFirsts.add(firsts.get(j));
                        origSeconds.add(seconds.get(j));
                    } else {
                        fakeFirsts.add(firsts.get(j));
                        fakeSeconds.add(seconds.get(j));
                    }
                }
                int fakes = fakeFirsts.size();
                if (isValid(origFirsts, origSeconds, fakeFirsts, fakeSeconds)) {
                    max = Math.max(fakes, max);
                }
            }
            String res = String.format("Case #%d: %d", t, max);
            pw.println(res);
            System.out.println(res);
        }
        pw.close();
    }

    private static boolean isValid(Set<String> origFirsts, Set<String> origSeconds, List<String> fakeFirsts, List<String> fakeSeconds) {
        Set<String> firsts = new HashSet<>(origFirsts);
        Set<String> seconds = new HashSet<>(origSeconds);
        boolean added = false;
        do {
            added = false;
            for (int i = 0; i < fakeFirsts.size(); i++) {
                String fakeFirst = fakeFirsts.get(i);
                String fakeSecond = fakeSeconds.get(i);
                if ((firsts.contains(fakeFirst) || seconds.contains(fakeFirst)) && seconds.contains(fakeSecond)) {
                    firsts.add(fakeFirst);
                    added = true;
                    fakeFirsts.remove(i);
                    fakeSeconds.remove(i);
                    break;
                }
            }
        } while (added);
        return fakeFirsts.isEmpty();
    }

    public static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }

}
