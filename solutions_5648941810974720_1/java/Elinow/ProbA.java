import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

import org.apache.commons.lang3.StringUtils;

import com.google.common.collect.HashMultiset;
import com.google.common.collect.Multiset;

public class ProbA {

    private static final String INPUT_FILE = "e:/downloads/A-large.in";
    private static final String OUTPUT_FOLDER = "C:/workspaces/algo/GCJ/src/";
    private static final String OUTPUT_FILE = "A-large.out";


    public static void main(String[] args) throws Exception {
        InputReader in = new InputReader(new FileInputStream(INPUT_FILE));
        PrintWriter pw = new PrintWriter(new File(OUTPUT_FOLDER, OUTPUT_FILE));
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            String st = in.next();
            Multiset<Character> charIndex = HashMultiset.create();
            for (int i = 0; i < st.length(); i++) {
                charIndex.add(st.charAt(i));
            }
            int x0 = charIndex.count('Z');
            int x6 = charIndex.count('X');
            int x2 = charIndex.count('W');
            int x4 = charIndex.count('U');
            int x8 = charIndex.count('G');
            int x5 = charIndex.count('F') - x4;
            int x7 = charIndex.count('V') - x5;
            int x3 = charIndex.count('H') - x8;
            int x32 = charIndex.count('R') - x0 - x4;
            int x1 = charIndex.count('O') - x0 - x2 - x4;
            int x9 = charIndex.count('E') - x0 - x1 - 2 * x3 - x5 - 2 * x7 - x8;
            if (x32 != x3) {
                throw new IllegalStateException(x3 + " vs " + x32);
            }
            int[] freq = { x0, x1, x2, x3, x4, x5, x6, x7, x8, x9 };
            String tempRes = "";
            for (int i = 0; i < freq.length; i++) {
                char ch = (char) ('0' + i);
                tempRes += StringUtils.repeat(ch, freq[i]);
            }
            String res = String.format("Case #%d: %s", t, tempRes);
            pw.println(res);
            System.out.println(res);
        }
        pw.close();
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
