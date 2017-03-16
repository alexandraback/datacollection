import java.io.FileNotFoundException;
import java.util.Locale;
import java.util.SortedSet;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Set;
import java.util.Iterator;
import java.util.TreeSet;
import java.util.StringTokenizer;
import java.math.BigInteger;
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
		C solver = new C();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class C {
    int N = 55;

    List<Set<String>> answers = new ArrayList<Set<String>>();

    public C() {
        for (int i = 0; i < N; i++) {
            answers.add(new TreeSet<String>());
        }

        answers.get(1).add("1");
        answers.get(1).add("2");
        answers.get(1).add("3");

        answers.get(2).add("11");
        answers.get(2).add("22");

        answers.get(3).add("101");
        answers.get(3).add("111");
        answers.get(3).add("121");
        answers.get(3).add("202");
        answers.get(3).add("212");

        StringBuilder q;
        String t;

        for (int i = 4; i < N; i++) {
            for (String s : answers.get(i - 2)) {
                if (s.charAt(0) == '1') {
                    q = new StringBuilder();
                    q.append("10");
                    q.append(s.substring(1, s.length() - 1));
                    q.append("01");
                    t = q.toString();
                    if (check(t)) {
                        answers.get(i).add(t);
                    }
                    q = new StringBuilder();
                    q.append("11");
                    q.append(s.substring(1, s.length() - 1));
                    q.append("11");
                    t = q.toString();
                    if (check(t)) {
                        answers.get(i).add(t);
                    }
                }
                if (s.charAt(0) == '2') {
                    q = new StringBuilder();
                    q.append("20");
                    q.append(s.substring(1, s.length() - 1));
                    q.append("02");
                    t = q.toString();
                    if (check(t)) {
                        answers.get(i).add(t);
                    }
                }
            }
        }

        for (Set<String> answer : answers) {
            for (String s : answer) {
                set.add(new BigInteger(s).pow(2));
            }
        }
    }

    SortedSet<BigInteger> set = new TreeSet<BigInteger>();

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        BigInteger a = new BigInteger(in.nextString());
        BigInteger b = new BigInteger(in.nextString());

        out.printCase(testNumber);
        out.println(set.tailSet(a).headSet(b.add(BigInteger.ONE)).size());
    }

    boolean check(String s) {
        return isPalindrome(s) && isPalindrome(new BigInteger(s).pow(2).toString());
    }

    boolean isPalindrome(String s) {
        for (int i = 0; i < s.length() / 2; i++) {
            if (s.charAt(i) != s.charAt(s.length() - 1 - i)) {
                return false;
            }
        }
        return true;
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

class OutputWriter {

    final PrintWriter out;

    public OutputWriter(String fileName) {
        try {
            out = new PrintWriter(fileName);
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    public OutputWriter(OutputStream outputStream) {
        out = new PrintWriter(outputStream);
    }

    public OutputWriter(Writer writer) {
        out = new PrintWriter(writer);

    }

    /* PrintWriter methods */

    public void close() {
        out.close();
    }

    public void println(int x) {
        out.println(x);
    }

    public void printf(String format, Object... args) {
        out.printf(format, args);
    }

    /* My helper methods */

    public void printCase(int index) {
        printf("Case #%d: ", index);
    }
}

