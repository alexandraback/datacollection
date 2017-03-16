import java.io.*;
import java.util.Random;
import java.util.StringTokenizer;

public class Task {

    final long MAGIC = 1_000_000;

    class Tree {
        Item[] data;
        int size;

        Tree(int n) {
            size = n;
            data = new Item[4 * n + 10];
            for (int i = 0; i < data.length; i++)
                data[i] = new Item("1");
        }

        void put(int i, int l, int r, int pos, Item value) {
            if (l == r) {
                data[i] = value;
                return;
            }
            int m = (l + r) / 2;
            if (pos <= m)
                put(2 * i + 1, l, m, pos, value);
            else
                put(2 * i + 2, m + 1, r, pos, value);
            data[i] = data[2 * i + 1].mult(data[2 * i + 2]);
        }

        void put(int pos, Item value) {
            put(0, 0, size - 1, pos, value);
        }

        Item get() {
            return data[0];
        }
    }

    boolean solveSmall(String s) {
        int n = s.length();
        int firstI = -1;
        int firstK = -1;
        Item cur = new Item("1");
        Item ii = new Item("i");
        Item kk = new Item("k");
        for (int i = 0; i < n; i++) {
            cur = cur.mult(new Item(s.substring(i, i + 1)));
            if (cur.equals(ii)) {
                firstI = i;
                break;
            }
        }
        Tree tree = new Tree(n);
        for (int i = n - 1; i >= 0; i--) {
            tree.put(i, new Item(s.substring(i, i + 1)));
            if (tree.get().equals(kk)) {
                firstK = i;
                break;
            }
        }
       // System.err.println();
        //System.err.println(firstI + " " + firstK);
        if (firstI == -1 || firstK == -1)
            return false;
        return firstI < firstK;
    }

    Item pow(Item base, long n) {
        Item res = new Item("1");
        for (; n > 0; n /= 2) {
            if (n % 2 == 1)
                res = res.mult(base);
            base = base.mult(base);
        }
        return res;
    }

    Item calc(String s) {
        Item cur = new Item("1");
        for (int i = 0; i < s.length(); i++) {
            cur = cur.mult(new Item(s.substring(i, i + 1)));
        }
        return cur;
    }

    boolean solveBig(String s, String want) {
        Item goal = new Item(want);
        Item cur = new Item("1");
        for (int i = 0; i < s.length(); i++) {
            cur = cur.mult(new Item(s.substring(i, i + 1)));
            if (cur.equals(goal))
                return true;
        }
        return false;
    }

    boolean solveBigReverse(String s, String want) {
        Item goal = new Item(want);
        Tree tree = new Tree(s.length());
        for (int i = s.length() - 1; i >= 0; i--) {
            tree.put(i, new Item(s.substring(i, i + 1)));
            if (tree.get().equals(goal))
                return true;
        }
        return false;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) throws IOException {
        out.printf("Case #%d: ", testNumber);
        long len = in.nextLong();
        long x = in.nextLong();
        String s = in.next();
        if (len * x <= MAGIC) {
            StringBuilder sb = new StringBuilder();
            for (long i = 0; i < x; i++)
                sb.append(s);
            boolean ok = solveSmall(sb.toString());
            Item exp = calc(sb.toString());
            Item ans = pow(calc(s), x);
            if (!ans.equals(exp)) {
                System.err.println("exp = " + exp);
                System.err.println("ans = " + ans);
                throw new AssertionError("ans != exp");
            }
            ok &= pow(calc(s), x).equals(new Item("i").mult(new Item("j")).mult(new Item("k")));
            out.println(ok ? "YES" : "NO");
        } else {
            if (x < 20)
                throw new AssertionError("x is too small");
            System.err.println("test large");
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < 10; i++)
                sb.append(s);
            boolean ok = solveBig(sb.toString(), "i");
            ok &= solveBigReverse(sb.toString(), "k");
            ok &= pow(calc(s), x).equals(new Item("i").mult(new Item("j")).mult(new Item("k")));
            out.println(ok ? "YES" : "NO");
        }
    }


    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner(new FileInputStream("input"));
        PrintWriter out = new PrintWriter(new FileOutputStream("output"));
        int testsCount = in.nextInt();
        for (int i = 1; i <= testsCount; i++)
            new Task().solve(i, in, out);
        in.close();
        out.close();
    }
}

class Item {
    String type;

    Item(String type) {
        this.type = type;
    }

    @Override
    public boolean equals(Object o) {
        if (!(o instanceof Item))
            return false;
        Item i = (Item) o;
        return type.equals(i.type);
    }

    @Override
    public String toString() {
        return "{Item = " + type + "}";
    }

    static boolean hasMinus(String s) {
        return s.length() == 2;
    }

    static String getLetter(String s) {
        if (hasMinus(s))
            return s.substring(1);
        return s;
    }

    Item inverse() {
        String s = "";
        if (type.equals("1"))
            s = "1";
        if (type.equals("-1"))
            s = "-1";
        if (type.equals("i"))
            s = "-i";
        if (type.equals("-i"))
            s = "i";
        if (type.equals("j"))
            s = "-j";
        if (type.equals("-j"))
            s = "j";
        if (type.equals("k"))
            s = "-k";
        if (type.equals("-k"))
            s = "k";
        if (s.equals(""))
            throw new AssertionError();
        return new Item(s);
    }

    Item mult(Item other) {
        String res = table[getId()][other.getId()];
        boolean hasMinus = hasMinus(res);
        hasMinus ^= hasMinus(type);
        hasMinus ^= hasMinus(other.type);
        if (hasMinus && res.length() != 2)
            res = "-" + res;
        if (!hasMinus && res.length() == 2)
            res = res.substring(1);
        return new Item(res);
    }

    int getId() {
        String cur = type;
        if (type.length() == 2)
            cur = type.substring(1);
        if (cur.equals("1"))
            return 0;
        if (cur.equals("i"))
            return 1;
        if (cur.equals("j"))
            return 2;
        if (cur.equals("k"))
            return 3;
        throw new AssertionError("must be unreachable");
    }

    static String[][] table = {
            {"1", "i", "j", "k"},
            {"i", "-1", "k", "-j"},
            {"j", "-k", "-1", "i"},
            {"k", "j", "-i", "-1"}
    };
}

class FastScanner {
    private StringTokenizer tokenizer;
    private BufferedReader reader;

    public FastScanner(InputStream inputStream) {
        reader = new BufferedReader(new InputStreamReader(inputStream));
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            String line;
            try {
                line = reader.readLine();
            } catch (IOException e) {
                return null;
            }
            if (line == null)
                return null;
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    public String nextLine() {
        String line;
        try {
            line = reader.readLine();
        } catch (IOException e) {
            return null;
        }
        return line;
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public void close() {
        try {
            reader.close();
        } catch (IOException e) {

        }
    }
}
