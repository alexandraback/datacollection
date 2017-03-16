import java.io.*;
import java.util.*;

public class Technobabble {

    static class Topic {
        String f;
        String s;

        public Topic(String f, String s) {
            this.f = f;
            this.s = s;
        }
    }

    public String getAns(Topic[] topics) {
        Map<String, Integer> fMap = new HashMap<>();
        Map<String, Integer> sMap = new HashMap<>();

        int res = 0;
        for (int i = 0; i < topics.length; i++) {
            Topic cur = topics[i];

            if (!fMap.containsKey(cur.f)) {
                fMap.put(cur.f, 0);
            }
            if (!sMap.containsKey(cur.s)) {
                sMap.put(cur.s, 0);
            }
            fMap.put(cur.f, fMap.get(cur.f) + 1);
            sMap.put(cur.s, sMap.get(cur.s) + 1);
        }

        for (int i = 0; i < topics.length; i++) {
            Topic cur = topics[i];

            if (fMap.get(cur.f) > 1 && sMap.get(cur.s) > 1) {
                res++;

                fMap.put(cur.f, fMap.get(cur.f) - 1);
                sMap.put(cur.s, sMap.get(cur.s) - 1);
            }
        }

        return String.valueOf(res);
    }

    public static void main(String[] args) throws FileNotFoundException {
        String inputFileName = "/Users/roman/Downloads/C-small-attempt2.in.txt";
        String outputFileName = "/Users/roman/Downloads/testOutput";

        InputStream inputStream = new FileInputStream(inputFileName);
        OutputStream outputStream = new FileOutputStream(outputFileName);

        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);

        int testCount = in.nextInt();
        for (int i = 0; i < testCount; i++) {
            int n = in.nextInt();

            Topic[] topics = new Topic[n];
            for (int j = 0; j < topics.length; j++) {
                topics[j] = new Topic(in.next(), in.next());
            }
            writeTestCase(out, i + 1, new Technobabble().getAns(topics));
        }

        out.close();
    }

    static void writeTestCase(PrintWriter writer, int num, Object res) {
        System.out.println(String.format("Case #%d: %s", num, res.toString()));
        writer.println(String.format("Case #%d: %s", num, res.toString()));
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
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

        public long nextLong() {
            return Long.parseLong(next());
        }

        public int[] nextIntArr(int n) {
            int[] arr = new int[n];
            for (int j = 0; j < arr.length; j++) {
                arr[j] = nextInt();
            }

            return arr;
        }

        public long[] nextLongArr(int n) {
            long[] arr = new long[n];
            for (int j = 0; j < arr.length; j++) {
                arr[j] = nextLong();
            }

            return arr;
        }
    }
}