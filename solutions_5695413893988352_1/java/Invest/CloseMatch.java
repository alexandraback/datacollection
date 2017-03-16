import java.io.*;
import java.util.StringTokenizer;

public class CloseMatch {

    static class Pair {
        long x, y;
        String xStr, yStr;

        public Pair(long x, long y, String xStr, String yStr) {
            this.x = x;
            this.y = y;
            this.xStr = xStr;
            this.yStr = yStr;
        }

        @Override
        public String toString() {
            return xStr + " " + yStr;
        }
    }

    private Pair bestPair;

    public String getAns(String f, String s) {
        rec(f, s, 0);

        return bestPair.toString();
    }

    public void rec(String f, String s, int curIndex) {
        if (curIndex >= f.length()) {
            checkPair(findMin(f), findMin(s));
            return;
        }

        if (f.charAt(curIndex) == '?' && s.charAt(curIndex) == '?') {
            rec(changeChar(f, curIndex, '0'), changeChar(s, curIndex, '1'), curIndex);
            rec(changeChar(f, curIndex, '1'), changeChar(s, curIndex, '0'), curIndex);
            rec(changeChar(f, curIndex, '0'), changeChar(s, curIndex, '0'), curIndex);
        } else if (f.charAt(curIndex) == '?' && s.charAt(curIndex) != '?') {
            int curVal = s.charAt(curIndex) - '0';

            rec(changeChar(f, curIndex, Character.forDigit(curVal, 10)), s, curIndex);
            rec(changeChar(f, curIndex, Character.forDigit((curVal + 1) % 10, 10)), s, curIndex);
            rec(changeChar(f, curIndex, Character.forDigit(curVal == 0 ? 9 : curVal - 1, 10)), s, curIndex);
        } else if (f.charAt(curIndex) != '?' && s.charAt(curIndex) == '?') {
            int curVal = f.charAt(curIndex) - '0';

            rec(f, changeChar(s, curIndex, Character.forDigit(curVal, 10)), curIndex);
            rec(f, changeChar(s, curIndex, Character.forDigit((curVal + 1) % 10, 10)), curIndex);
            rec(f, changeChar(s, curIndex, Character.forDigit(curVal == 0 ? 9 : curVal - 1, 10)), curIndex);
        } else {
            int fVal = f.charAt(curIndex) - '0';
            int sVal = s.charAt(curIndex) - '0';

            if (fVal == sVal) {
                rec(f, s, curIndex + 1);
            } else if (fVal > sVal) {
                checkPair(findMin(f), findMax(s));
            } else {
                checkPair(findMax(f), findMin(s));
            }
        }
    }

    private String findMax(String s) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '?') {
                sb.append('9');
            } else {
                sb.append(s.charAt(i));
            }
        }

        return sb.toString();
    }

    private String findMin(String s) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '?') {
                sb.append('0');
            } else {
                sb.append(s.charAt(i));
            }
        }

        return sb.toString();
    }

    private void checkPair(String sX, String fY) {
        long x = Long.parseLong(sX);
        long y = Long.parseLong(fY);

        Pair newPair = new Pair(x, y, sX, fY);
        if (bestPair == null) {
            bestPair = newPair;
            return;
        }

        if (Math.abs(x - y) < Math.abs(bestPair.x - bestPair.y)) {
            bestPair = newPair;
        } else if (Math.abs(x - y) == Math.abs(bestPair.x - bestPair.y)) {
            if (bestPair.x > x) {
                bestPair = newPair;
            } else if (bestPair.x == x) {
                if (bestPair.y > y) {
                    bestPair = newPair;
                }
            }
        }
    }

    private String changeChar(String str, int index, char tarChar) {
        StringBuilder res = new StringBuilder(str);
        res.setCharAt(index, tarChar);

        return res.toString();
    }

    public static void main(String[] args) throws FileNotFoundException {
        String inputFileName = "/Users/roman/Downloads/B-large.in.txt";
        String outputFileName = "/Users/roman/Downloads/testOutput";

//        InputStream inputStream = System.in;
        InputStream inputStream = new FileInputStream(inputFileName);
        OutputStream outputStream = new FileOutputStream(outputFileName);

        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);

        int testCount = in.nextInt();
        for (int i = 0; i < testCount; i++) {
            writeTestCase(out, i + 1, new CloseMatch().getAns(in.next(), in.next()));
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