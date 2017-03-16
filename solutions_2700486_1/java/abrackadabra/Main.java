import java.util.Map;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Abrackadabra
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		B solver = new B();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class B {
    OutputWriter out = new OutputWriter("output.txt");

    public void solve(int testNumber, InputReader in, OutputWriter cout) {
        out.printf("Case #%d: ", testNumber);

        int n = in.nextInt();

        int x = in.nextInt();
        int y = in.nextInt();

        x = Math.abs(x);

        int bottom = 1;

        for (; bottom * (bottom + 1) / 2 <= n; bottom += 2);
        bottom -= 2;

        n -= bottom * (bottom + 1) / 2;

        if (x + y > bottom + 1) {
            out.println(0.0);
            out.flush();
            return;
        }

        if (x + y < bottom + 1) {
            out.println(1.0);
            out.flush();
            return;
        }

        Map<Pair<Integer, Integer>, Double> map = new HashMap<Pair<Integer, Integer>, Double>();

        map.put(new Pair<Integer, Integer>(0, 0), 1.0);

        for (int i = 0; i < n; i++) {
            Map<Pair<Integer, Integer>, Double> nextMap = new HashMap<Pair<Integer, Integer>, Double>();

            for (Map.Entry<Pair<Integer, Integer>, Double> entry : map.entrySet()) {
                int a = entry.getKey().first;
                int b = entry.getKey().second;

                double p = entry.getValue();

                if (a == bottom + 1) {
                    add(new Pair<Integer, Integer>(a, b + 1), p, nextMap);
                } else if (b == bottom + 1) {
                    add(new Pair<Integer, Integer>(a + 1, b), p, nextMap);
                } else {
                    add(new Pair<Integer, Integer>(a + 1, b), p / 2, nextMap);
                    add(new Pair<Integer, Integer>(a, b + 1), p / 2, nextMap);
                }
            }

            map = nextMap;
        }

        double ans = 0.0;

        for (Map.Entry<Pair<Integer, Integer>, Double> entry : map.entrySet()) {
            if (entry.getKey().second > y) {
                ans += entry.getValue();
            }
        }

        out.println(ans);

        out.flush();
    }

    void add(Pair<Integer, Integer> pair, double value, Map<Pair<Integer, Integer>, Double> map) {
        if (!map.containsKey(pair)) {
            map.put(pair, 0.0);
        }

        map.put(pair, map.get(pair) + value);
    }
}

class OutputWriter extends PrintWriter {

    public OutputWriter(String fileName) {
        super(getWriter(fileName));
    }

    private static Writer getWriter(String s) {
        Writer writer;

        try {
            writer = new FileWriter(s);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        return writer;
    }

    public OutputWriter(OutputStream outputStream) {
        super(outputStream);
    }

    public OutputWriter(Writer writer) {
        super(writer);
    }

    }

class InputReader implements Iterable<String> {
    BufferedReader br;
    StringTokenizer in;

    public InputReader(String fileName) {
        try {
            br = new BufferedReader(new FileReader(fileName));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public InputReader(InputStream inputStream) {
        br = new BufferedReader(new InputStreamReader(inputStream));
    }

    String lastLine = null;

    boolean hasMoreTokens() {
        while (in == null || !in.hasMoreTokens()) {
            lastLine = nextLine();
            if (lastLine == null) {
                return false;
            }
            in = new StringTokenizer(lastLine);
        }
        return true;
    }

    public String nextString() {
        return hasMoreTokens() ? in.nextToken() : null;
    }

    public String nextLine() {
        boolean somethingLeft = in != null && in.hasMoreTokens();
        in = null;
        if (somethingLeft) {
            return lastLine;
        }
        try {
            return br.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

    public String next() {
        return nextString();
    }

    public Iterator<String> iterator() {
        return new Iterator<String>() {
            @Override
            public boolean hasNext() {
                return hasMoreTokens();
            }

            @Override
            public String next() {
                return nextString();
            }

            @Override
            public void remove() {
                throw new RuntimeException();
            }
        };
    }
}

class Pair<A, B> implements Comparable<Pair<A, B>> {
    public final A first;
    public final B second;

    public Pair(A a, B b) {
        this.first = a;
        this.second = b;
    }

    public int compareTo(Pair<A, B> o) {
        int result = ((Comparable<A>) first).compareTo(o.first);
        if (result != 0)
            return result;
        return ((Comparable<B>)second).compareTo(o.second);
    }

    public int hashCode() {
        int result = first != null ? first.hashCode() : 0;
        result = 31 * result + (second != null ? second.hashCode() : 0);
        return result;
    }

    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }

        Pair pair = (Pair) o;

        if (first != null ? !first.equals(pair.first) : pair.first != null) {
            return false;
        }
        if (second != null ? !second.equals(pair.second) : pair.second != null) {
            return false;
        }

        return true;
    }

    public String toString() {
        return "[" + first + ", " + second + "]";
    }
}

