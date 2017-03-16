/*
 * This submission is using the template from https://github.com/krka/codejamjavatemplate
 * Dependencies: standard java, google guava
 * Revision: e20bb6576d30168d022a1af95aa1be5d1bd35e4a
 */
import com.google.common.collect.Collections2;
import com.google.common.collect.Lists;
import com.google.common.collect.Maps;
import com.google.common.collect.Sets;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.concurrent.atomic.AtomicInteger;

public class C {
    private static final String INPUT = "large"; // override to use a specific input (i.e. "small-1", "large-2", "sample", "stdin").

    public static void main(String[] args) throws Exception {
        new C().run();
    }

    private final PrintStream out;
    private final BufferedReader reader;
    private StringTokenizer tokenizer = new StringTokenizer("");

    public C() throws Exception {
        String problem = getClass().getSimpleName();
        if (INPUT == null) {
            File input = findInput(problem);
            if (input == null) {
                throw new IOException("No input file found");
            }
            File output = new File(input.getParent(), input.getName().replace(".in", ".out"));
            System.err.println("input:  " + input.getPath());
            System.err.println("output: " + output.getPath());
            out = new PrintStream(new FileOutputStream(output));
            reader = new BufferedReader(new FileReader(input));
        } else if (INPUT.equals("stdin")) {
            System.err.println("input:  stdin");
            System.err.println("output: stdout");
            out = System.out;
            reader = new BufferedReader(new InputStreamReader(System.in));
        } else {
            System.err.println("input:  " + problem + "-" + INPUT + ".in");
            System.err.println("output: " + problem + "-" + INPUT + ".out");
            out = new PrintStream(new FileOutputStream("source/" + problem + "-" + INPUT + ".out"));
            reader = new BufferedReader(new FileReader("source/" + problem + "-" + INPUT + ".in"));
        }
    }

    public static File findInput(String problem) throws Exception {
        File dir = new File("source");
        long bestTimestamp = -1;
        File bestFile = null;
        for (File file : dir.listFiles()) {
           if (file.getName().startsWith(problem + "-") && file.getName().endsWith(".in")) {
               long timestamp = file.lastModified();
               if (timestamp > bestTimestamp) {
                   bestTimestamp = timestamp;
                   bestFile = file;
               }
           }
        }
        return bestFile;
    }

    public void run() {
        try {
            runCases();
        } finally {
            out.close();
        }
    }

    public void debug(String s, Object... args) {
        System.err.printf("DEBUG: " + s + "\n", args);
    }

    private void runCases() {
        try {
            int cases = getInt();
            for (int c = 1; c <= cases; c++) {
                try {
                    String answer = new Solver(c).solve();
                    String s = "Case #" + c + ": " + answer;
                    out.println(s);
                    if (out != System.out) {
                        System.out.println(s);
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        } finally {
            debug("done with all!");
        }
    }

    public String readLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public String getToken() {
        while (true) {
            if (tokenizer.hasMoreTokens()) {
                return tokenizer.nextToken();
            }
            String s = readLine();
            if (s == null) {
                return null;
            }
            tokenizer = new StringTokenizer(s, " \t\n\r");
        }
    }

    public double getDouble() {
        return Double.parseDouble(getToken());
    }

    public int getInt() {
        return Integer.parseInt(getToken());
    }

    public long getLong() {
        return Long.parseLong(getToken());
    }

    public BigInteger getBigInt() {
        return new BigInteger(getToken());
    }

    public BigDecimal getBigDec() {
        return new BigDecimal(getToken());
    }

    public class Solver {
        private final int caseNumber;

        public Solver(int caseNumber) {
            this.caseNumber = caseNumber;
        }

        public String solve() throws Exception {
            debug("solving case %d", caseNumber);
            int rows = getInt();

            Map<String, AtomicInteger> mapping1 = Maps.newHashMap();
            Map<String, AtomicInteger> mapping2 = Maps.newHashMap();

            List<Pair> topics = Lists.newArrayList();
            for (int i = 0; i < rows; i++) {
                Pair pair = new Pair(getToken(), getToken());
                topics.add(pair);

                mapping1.putIfAbsent(pair.a, new AtomicInteger());
                mapping1.get(pair.a).incrementAndGet();

                mapping2.putIfAbsent(pair.b, new AtomicInteger());
                mapping2.get(pair.b).incrementAndGet();
            }

            List<Pair> original = Lists.newArrayList();
            for (Pair topic : topics) {
                if (mapping1.get(topic.a).get() == 1 || mapping2.get(topic.b).get() == 1) {
                    original.add(topic);
                }
            }

            topics.removeAll(original);

            Set<String> seen1 = Sets.newHashSet();
            Set<String> seen2 = Sets.newHashSet();

            for (Pair pair : original) {
                seen1.add(pair.a);
                seen2.add(pair.b);
            }

            int best = 0;

            Set<String> xseen1 = Sets.newHashSet();
            Set<String> xseen2 = Sets.newHashSet();

            for (int i = 0; i < 1000; i++) {
                ArrayList<Pair> permutation = Lists.newArrayList(topics);
                Collections.shuffle(permutation);

                xseen1.clear();
                xseen1.addAll(seen1);
                xseen2.clear();
                xseen2.addAll(seen2);

                int fakes = 0;
                for (Pair pair : permutation) {
                    if (!xseen1.add(pair.a) & !xseen2.add(pair.b)) {
                        fakes++;
                    }
                }

                best = Math.max(best, fakes);
            }

            return "" + best;
        }

        private class Pair {
            private final String a;
            private final String b;

            public Pair(String b, String a) {
                this.b = b;
                this.a = a;
            }
        }
    }
}
