import java.io.*;
import java.math.BigInteger;
import java.util.*;

@SuppressWarnings("unused")
public class Program {
    public static void main(String[] args) throws IOException {
        boolean isDebugMode = Arrays.asList(args).contains("DEBUG_MODE");

        InputStream inputStream;
        OutputStream outputStream;

        if (isDebugMode) {
//            inputStream = new ConsoleInputStream();
            inputStream = new FileInputStream();

            outputStream = new FileOutputStream();
//            outputStream = new ConsoleOutputStream();
        } else {
            inputStream = new ConsoleInputStream();
            outputStream = new ConsoleOutputStream();
        }

        inputStream.open();
        outputStream.open();

        new Program().run(inputStream, outputStream, isDebugMode);

        outputStream.close();
        inputStream.close();
    }

    private InputStream in;
    private OutputStream out;
    private boolean isDebugMode;
    private Timer timer = new Timer();

    private void printInDebug(String s) throws IOException {
        if (isDebugMode) {
            out.println(s);
            out.flush();
        }
    }

    private void printTimer(String mark) throws IOException {
        printInDebug(mark + ": " + timer.getMillisAndReset() + " ms.");
    }

    private static String formatDouble(double n, int precision) {
        double t = 1;
        for (int i = 0; i < precision; i++) t *= 10;
        n = Math.round(n * t);
        n /= t;
        return String.format(Locale.ENGLISH, "%." + precision + "f", n);
    }

    private void run(InputStream in, OutputStream out, boolean isDebugMode) throws IOException {
        this.in = in;
        this.out = out;
        this.isDebugMode = isDebugMode;

        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
            solve(i + 1);
            out.flush();
        }
    }

    private char[] s;
    private int n;

    private void solve(int testNum) throws IOException {
        out.print("Case #", testNum, ": ");

        int a = in.nextInt();
        int b = in.nextInt();
        int k = in.nextInt();

        int res = 0;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if ((i & j) < k) {
                    res++;
                }
            }
        }
        out.println(res);
    }

    private double getValue(List<Item> a, double x) {
        Stack<Double> d = new Stack<Double>();
        for (Item i : a) {
            if (i.isOperation()) {
                double right = d.pop();
                double left = d.pop();
                d.push(i.operate(left, right));
            } else {
                d.push(i.getVal(x));
            }
        }
        if (d.size() != 1) throw new IllegalArgumentException();
        return d.pop();
    }

    private static final Collection<Character> minop = Arrays.asList('(', '+', '-', '*', '/', '^');

    private static final String[] zns = new String[]{"+", "-", "*/", "^"};

    private List<Item> gen(int left, int right) {
        if (s[left] == '(' && s[right] == ')') return gen(left + 1, right - 1);

        for (String zn : zns) {
            int c = 0;
            for (int i = left; i <= right; i++) {
                if (s[i] == '(') c++;
                else if (s[i] == ')') c--;
                else if (c == 0 && zn.indexOf(s[i]) != -1) {
                    List<Item> leftItems = gen(left, i - 1);
                    List<Item> rightItems = gen(i + 1, right);

                    List<Item> res = new ArrayList<Item>(leftItems);
                    res.addAll(rightItems);
                    res.add(Item.operation(s[i]));

                    return res;
                }
            }
        }

        return Arrays.asList(Item.fromToken(s, left, right));
    }

    private static class Item {
        static enum Operation {
            PLUS('+'),
            MINUS('-'),
            MULT('*'),
            DIV('/'),
            POW('^');

            private char ch;

            Operation(char ch) {
                this.ch = ch;
            }

            @Override
            public String toString() {
                return "" + ch;
            }
        }

        private Operation op;
        private boolean variable;
        private boolean positive;
        private double val;

        public static Item fromToken(char[] line, int left, int right) {
            Item res = new Item();
            res.positive = line[left] != '$';
            if (line[left] == '$') left++;
            if (line[left] == 'x') {
                if (left != right) throw new IllegalArgumentException();
                res.variable = true;
            } else {
                res.variable = false;
                String num = "";
                for (int i = left; i <= right; i++) {
                    num += line[i];
                }
                res.val = Double.valueOf(num);
            }
            return res;
        }

        public static Item operation(char ch) {
            Item res = new Item();
            res.variable = false;
            switch (ch) {
                case '+':
                    res.op = Operation.PLUS;
                    break;
                case '-':
                    res.op = Operation.MINUS;
                    break;
                case '*':
                    res.op = Operation.MULT;
                    break;
                case '/':
                    res.op = Operation.DIV;
                    break;
                case '^':
                    res.op = Operation.POW;
                    break;
            }
            return res;
        }

        private double operate(double left, double right) {
            switch (op) {
                case PLUS:
                    return left + right;
                case MINUS:
                    return left - right;
                case MULT:
                    return left * right;
                case DIV:
                    return left / right;
                case POW:
                    return Math.pow(left, right);
            }
            throw new IllegalArgumentException();
        }

        private double getVal(double x) {
            double res = variable ? x : val;
            if (!positive) res = -res;
            return res;
        }

        boolean isOperation() {
            return op != null;
        }

        @Override
        public String toString() {
            if (isOperation()) {
                return op.toString();
            }
            return (positive ? "" : "-") + (variable ? "x" : Double.toString(val));
        }
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

            return !(key != null ? !key.equals(pair.key) : pair.key != null) && !(value != null ? !value.equals(pair.value) : pair.value != null);
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
