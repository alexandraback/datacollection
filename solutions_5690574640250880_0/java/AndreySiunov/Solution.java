import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Solution {
    private static class Result {
        private int testNum;

        private Result(int testNum) {
            this.testNum = testNum;
        }

        private Collection<String> ans = new ArrayList<String>();
        private int n;
        private int m;
        private int k;
    }

    private void printResult(Result result) throws IOException {
        out.print("Case #", result.testNum, ": ");
        out.println();
        for (String s : result.ans) {
            out.println(s);
        }
        if (isDebugMode) {
            if (!isValid(result)) {
                out.println(">>> Wrong answer on test " + result.testNum + ":   n: " + result.n + " m: " + result.m + " k: " + result.k);
            }
        }
    }

    private boolean isValid(Result result) {
        if (result.ans == null || result.ans.size() == 0) return false;
        if (result.ans.size() == 1 && result.ans.iterator().next().equals("Impossible")) return true;
        if (result.ans.size() != result.n) return false;
        int kz = 0;
        int kc = 0;
        int kp = 0;
        for (String s : result.ans) {
            if (s.length() != result.m) return false;
            for (char ch : s.toCharArray()) {
                if (ch == '*') kz++;
                if (ch == '.') kp++;
                if (ch == 'c') kc++;
            }
        }
        if (kz != result.k || kc != 1 || kc + kz + kp != result.n * result.m) return false;

        return true;
    }

    private class Solver implements Callable<Result> {
        private int n;
        private int m;
        private int k;

        private void readData() throws IOException {
            n = in.nextInt();
            m = in.nextInt();
            k = in.nextInt();
        }

        private Result solve(int testNum) throws IOException {
            Result result = new Result(testNum);
            result.n = n;
            result.m = m;
            result.k = k;

            String impossible = "Impossible";
            int p = n * m - k;
            if (k == 0) {
                char[] s = new char[m];
                fill(s, 0, -1);
                String st = new String(s);
                for (int i = 0; i < n - 1; i++) {
                    result.ans.add(st);
                }
                s[m - 1] = 'c';
                result.ans.add(new String(s));
            } else if (p == 1) {
                char[] s = new char[m];
                fill(s, 0, m - 1);
                String st = new String(s);
                for (int i = 0; i < n - 1; i++) {
                    result.ans.add(st);
                }
                s[m - 1] = 'c';
                result.ans.add(new String(s));
            } else if (p == 2 || p == 3 || p == 5 || p == 7 || n == 1 || m == 1) {
                if (n == 1) {
                    char[] s = new char[m];
                    fill(s, 0, m - p - 1);
                    for (int i = m - p; i <= m - 2; i++) {
                        s[i] = '.';
                    }
                    s[m - 1] = 'c';
                    result.ans.add(new String(s));
                } else if (m == 1) {
                    for (int i = 0; i < n - p; i++) {
                        result.ans.add("*");
                    }
                    for (int i = n - p; i <= n - 2; i++) {
                        result.ans.add(".");
                    }
                    result.ans.add("c");
                } else {
                    result.ans.add(impossible);
                }
            } else {
                int x = 0;
                int y = 0;
                int xx = 0;
                int yy = 0;
                for (int i = 2; i <= n; i++) {
                    for (int j = 2; j <= m; j++) {
                        for (int ii = 0; ii <= i; ii++) {
                            for (int jj = 0; jj <= j; jj++) {
                                if (i * j + ii + jj == p && ii != 1 && jj != 1 && (ii > 0 ? 1 : 0) + j <= m && (jj > 0 ? 1 : 0) + i <= n) {
                                    x = i;
                                    y = j;
                                    xx = ii;
                                    yy = jj;
                                }
                            }
                        }
                    }
                }
                if (x == 0) {

                    result.ans.add(impossible);
                } else {

                    char[][] ch = new char[n][m];
                    for (int i = 0; i < n - x; i++) {
                        fill(ch[i], 0, m - 1);
                    }
                    for (int i = n - x; i < n; i++) {
                        fill(ch[i], 0, m - y - 1);
                    }
                    for (int i = n - xx; i < n; i++) {
                        ch[i][m - y - 1] = '.';
                    }
                    for (int i = m - yy; i < m; i++) {
                        ch[n - x - 1][i] = '.';
                    }

                    ch[n - 1][m - 1] = 'c';

                    for (int i = 0; i < n; i++) {
                        result.ans.add(new String(ch[i]));
                    }
                }
            }

            return result;
        }

        private void fill(char[] s, int l, int r) {
            for (int i = 0; i < m; i++) {
                s[i] = (l <= i && i <= r) ? '*' : '.';
            }
        }

        @Override
        public Result call() throws Exception {
            int testNum;
            ioLock.lock();
            try {
                testNum = ++lastTestNum;

                readData();
            } finally {
                ioLock.unlock();
            }

            Result result = solve(testNum);

            if (isDebugMode) {
                ioLock.lock();
                try {
                    printInDebug(">>> Solved test #" + testNum);
                } finally {
                    ioLock.unlock();
                }
            }

            return result;
        }
    }

    private int lastTestNum = 0;
    private final Lock ioLock = new ReentrantLock();

    public static void main(String[] args) throws IOException {
        boolean isDebugMode = Arrays.asList(args).contains("DEBUG_MODE");

        InputStream inputStream;
        OutputStream outputStream;

        if (isDebugMode) {
//            inputStream = new ConsoleInputStream();
            inputStream = new FileInputStream();

//            outputStream = new FileOutputStream();
            outputStream = new ConsoleOutputStream();
        } else {
            inputStream = new FileInputStream();
            outputStream = new FileOutputStream();
        }

        inputStream.open();
        outputStream.open();

        new Solution().run(inputStream, outputStream, isDebugMode);

        outputStream.close();
        inputStream.close();
    }

    private InputStream in;
    private OutputStream out;
    private boolean isDebugMode;
    private Timer timer = new Timer();

    private void printInDebug(String s) throws IOException {
        if (isDebugMode) {
            ioLock.lock();
            try {
                out.println(s);
                out.flush();
            } finally {
                ioLock.unlock();
            }
        }
    }

    private void printTimer(String mark) throws IOException {
        printInDebug(mark + ": " + timer.getMillisAndReset() + " ms.");
    }

    private static String formatDouble(double n, int precision) {
        return String.format(Locale.ENGLISH, "%." + precision + "f", n);
    }

    private void run(InputStream in, OutputStream out, boolean isDebugMode) throws IOException {
        this.in = in;
        this.out = out;
        this.isDebugMode = isDebugMode;

        timer.reset();

        int threadPoolSize = Runtime.getRuntime().availableProcessors() * 2;
        printInDebug(">>> Thread pool size: " + threadPoolSize);
        ExecutorService executorService = Executors.newFixedThreadPool(threadPoolSize);

        int t = in.nextInt();

        ArrayList<Future<Result>> futureResults = new ArrayList<Future<Result>>(t);

        for (int i = 0; i < t; i++) {
            futureResults.add(executorService.submit(new Solver()));
        }

        ArrayList<Result> results = new ArrayList<Result>(t);

        for (Future<Result> f : futureResults) {
            try {
                results.add(f.get());
            } catch (Exception e) {
                e.printStackTrace();
                return;
            }
        }

        executorService.shutdown();

        printTimer(">>> Solved all tests in");

        Collections.sort(results, new Comparator<Result>() {
            @Override
            public int compare(Result o1, Result o2) {
                return o1.testNum - o2.testNum;
            }
        });

        for (Result r : results) {
            printResult(r);
        }

        out.flush();
    }


    /*
     * Template classes
     * Author: Andrey Siunov
     * Date: 29.08.2013
     * Note: all classes are inner, because some testing servers do not run code with several classes
     */

    private static class SegmentTree {
        public static interface MergeFunction {
            int calcValue(int first, int second);
        }

        public static interface UpdateFunction {
            int calcValue(int value);
        }

        private MergeFunction mergeFunction;
        private int n;
        private int[] values;

        public SegmentTree(int[] collection, MergeFunction mergeFunction) {
            this.mergeFunction = mergeFunction;
            n = collection.length;
            values = new int[n * 4];
            build(collection, 1, 0, n - 1);
        }

        private void build(int[] collection, int v, int tl, int tr) {
            if (tl == tr) {
                values[v] = collection[tl];
            } else {
                int tm = (tl + tr) >> 1;
                build(collection, v << 1, tl, tm);
                build(collection, (v << 1) + 1, tm + 1, tr);
                values[v] = mergeFunction.calcValue(values[v << 1], values[(v << 1) + 1]);
            }
        }

        private UpdateFunction updateFunction;

        public void update(int pos, UpdateFunction updateFunction) {
            this.updateFunction = updateFunction;
            update(1, 0, n - 1, pos);
        }

        public void update(int v, int tl, int tr, int pos) {
            if (tl == tr) {
                values[v] = updateFunction.calcValue(values[v]);
            } else {
                int tm = (tl + tr) >> 1;
                if (pos <= tm) {
                    update(v << 1, tl, tm, pos);
                } else {
                    update((v << 1) + 1, tm + 1, tr, pos);
                }
                values[v] = mergeFunction.calcValue(values[v << 1], values[(v << 1) + 1]);
            }
        }

        public int getValue(int index) {
            return getValue(index, index);
        }

        public int getValue(int l, int r) {
            return getValue(1, 0, n - 1, l, r);
        }

        private Integer getValue(int v, int tl, int tr, int l, int r) {
            if (l > r) {
                return null;
            }
            if (l == tl && r == tr) {
                return values[v];
            }
            int tm = (tl + tr) >> 1;
            Integer leftValue = getValue(v << 1, tl, tm, l, Math.min(r, tm));
            Integer rightValue = getValue((v << 1) + 1, tm + 1, tr, Math.max(l, tm + 1), r);
            return leftValue == null ? rightValue :
                    (rightValue == null ? leftValue : mergeFunction.calcValue(leftValue, rightValue));
        }
    }


    private static class Pair<K, V> {
        private K key;
        private V value;

        Pair(K key, V value) {
            this.key = key;
            this.value = value;
        }

        K getKey() {
            return key;
        }

        V getValue() {
            return value;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Pair pair = (Pair) o;

            if (key != null ? !key.equals(pair.key) : pair.key != null) return false;
            if (value != null ? !value.equals(pair.value) : pair.value != null) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = key != null ? key.hashCode() : 0;
            result = 31 * result + (value != null ? value.hashCode() : 0);
            return result;
        }

        @Override
        public String toString() {
            return "Pair{" +
                    "key=" + key +
                    ", value=" + value +
                    '}';
        }
    }

    private static class Timer {
        private long lastTime = 0;

        private Timer() {
            lastTime = System.currentTimeMillis();
        }

        public void reset() {
            lastTime = System.currentTimeMillis();
        }

        public long getMillisAndReset() {
            long current = System.currentTimeMillis();
            long result = current - lastTime;
            lastTime = current;
            return result;
        }
    }

    // IO template {
    private static class FileInputStream extends InputStream {
        private String inputFileName;

        public FileInputStream() throws IOException {
            this("input.txt");
        }

        public FileInputStream(String inputFileName) throws IOException {
            this.inputFileName = inputFileName;
        }

        @Override
        protected Reader getReader() throws IOException {
            return new FileReader(inputFileName);
        }
    }

    private static class ConsoleInputStream extends InputStream {
        @Override
        protected Reader getReader() throws IOException {
            return new InputStreamReader(System.in);
        }
    }

    private static abstract class InputStream {
        private static String DELIMITERS = " \t\n\r\f";
        private BufferedReader in;

        public InputStream open() throws IOException {
            in = new BufferedReader(getReader());
            return this;
        }

        private class Line {
            private Line(String inputLine) {
                this.inputLine = inputLine;
                stringTokenizer = new StringTokenizer(this.inputLine, DELIMITERS);
                readCharacters = 0;
            }

            private int readCharacters;
            private String inputLine = null;
            private StringTokenizer stringTokenizer = null;

            public String nextToken() {
                String result = stringTokenizer.nextToken();
                readCharacters += result.length();
                return result;
            }

            boolean hasNextToken() {
                return stringTokenizer.hasMoreTokens();
            }

            String getLineRest() {
                int position = 0;
                for (int remain = readCharacters; remain > 0; position++) {
                    if (DELIMITERS.indexOf(inputLine.charAt(position)) < 0) {
                        remain--;
                    }
                }
                return inputLine.substring(position);
            }
        }

        private Line currentLine = null;

        abstract protected Reader getReader() throws IOException;

        /**
         * Note: may be incorrect behavior if use this method with hasNextToken method
         */
        public String nextLine() throws IOException {
            setInputLine();
            if (currentLine == null) {
                return null;
            }
            String result = currentLine.getLineRest();
            currentLine = null;
            return result;
        }

        public boolean hasNextLine() throws IOException {
            setInputLine();
            return currentLine != null;
        }

        public String nextToken() throws IOException {
            return hasNextToken() ? currentLine.nextToken() : null;
        }

        /**
         * Note: may be incorrect behavior if use this method with nextLine method
         */
        public boolean hasNextToken() throws IOException {
            while (true) {
                setInputLine();
                if (currentLine == null || currentLine.hasNextToken()) {
                    break;
                } else {
                    currentLine = null;
                }
            }
            return currentLine != null;
        }

        public int nextInt() throws IOException {
            return Integer.valueOf(this.nextToken());
        }

        public long nextLong() throws IOException {
            return Long.valueOf(this.nextToken());
        }

        public double nextDouble() throws IOException {
            return Double.valueOf(this.nextToken());
        }

        public BigInteger nextBigInteger() throws IOException {
            return new BigInteger(this.nextToken());
        }


        public String[] nextTokensArray(int n) throws IOException {
            String[] result = new String[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.nextToken();
            }
            return result;
        }

        public int[] nextIntArray(int n) throws IOException {
            int[] result = new int[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.nextInt();
            }
            return result;
        }

        public long[] nextLongArray(int n) throws IOException {
            long[] result = new long[n];
            for (int i = 0; i < n; i++) {
                result[i] = this.nextLong();
            }
            return result;
        }

        public void close() throws IOException {
            currentLine = null;
            in.close();
        }

        private void setInputLine() throws IOException {
            if (currentLine == null) {
                String line = in.readLine();
                if (line != null) {
                    currentLine = new Line(line);
                }
            }
        }
    }

    private static class FileOutputStream extends OutputStream {
        private String outputFileName;

        public FileOutputStream() throws IOException {
            this("output.txt");
        }

        public FileOutputStream(String outputFileName) throws IOException {
            this.outputFileName = outputFileName;
        }

        @Override
        protected Writer getWriter() throws IOException {
            return new FileWriter(outputFileName);
        }
    }

    private static class ConsoleOutputStream extends OutputStream {
        @Override
        protected Writer getWriter() throws IOException {
            return new OutputStreamWriter(System.out);
        }
    }

    private static abstract class OutputStream {
        private PrintWriter out;

        public OutputStream open() throws IOException {
            out = new PrintWriter(getWriter());
            return this;
        }

        abstract protected Writer getWriter() throws IOException;

        public void print(Object... s) {
            for (Object token : s) {
                out.print(token);
            }
        }

        public void println(Object... s) {
            print(s);
            out.println();
        }

        public void println() {
            out.println();
        }

        public void flush() throws IOException {
            out.flush();
        }

        public void close() throws IOException {
            out.flush();
            out.close();
        }
    }
    // } IO template
}