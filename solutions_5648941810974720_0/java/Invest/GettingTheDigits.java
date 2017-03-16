import java.io.*;
import java.util.*;

public class GettingTheDigits {

    public String getAns(String s) {
//        0 - Z, 2 - W, 4 - U, 5 / 4 - F, 6 - X, 7 / 5 - V, 8 - G, 9 / 7 - N, 3 / 8 - H, rest -> 1
//        "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"

        Map<Character, Integer> occs = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char cur = s.charAt(i);
            if (!occs.containsKey(cur)) {
                occs.put(cur, 0);
            }

            occs.put(cur, occs.get(cur) + 1);
        }

        List<Integer> res = new ArrayList<>();
        fillRes(occs, res, 'Z', "ZERO", 0);
        fillRes(occs, res, 'W', "TWO", 2);
        fillRes(occs, res, 'U', "FOUR", 4);
        fillRes(occs, res, 'F', "FIVE", 5);
        fillRes(occs, res, 'X', "SIX", 6);
        fillRes(occs, res, 'V', "SEVEN", 7);
        fillRes(occs, res, 'G', "EIGHT", 8);
        fillRes(occs, res, 'I', "NINE", 9);
        fillRes(occs, res, 'H', "THREE", 3);
        fillRes(occs, res, 'N', "ONE", 1);

        Collections.sort(res);

        StringBuilder sb = new StringBuilder();

        res.forEach(sb::append);

        return sb.toString();
    }

    public static void fillRes(Map<Character, Integer> occs, List<Integer> res, char unq, String number, int resVal) {
        if (!occs.containsKey(unq) || occs.get(unq) == 0) return;

        int count = occs.get(unq);

        for (int i = 0; i < count; i++) {
            for (int j = 0; j < number.length(); j++) {
                char curChar = number.charAt(j);

                occs.put(curChar, occs.get(curChar) - 1);
            }

            res.add(resVal);
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        String inputFileName = "/Users/roman/Downloads/A-small-attempt0.in.txt";
        String outputFileName = "/Users/roman/Downloads/testOutput";

        InputStream inputStream = new FileInputStream(inputFileName);
        OutputStream outputStream = new FileOutputStream(outputFileName);

        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);

        int testCount = in.nextInt();
        for (int i = 0; i < testCount; i++) {
            writeTestCase(out, i + 1, new GettingTheDigits().getAns(in.next()));
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