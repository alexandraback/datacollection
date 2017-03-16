import java.io.OutputStreamWriter;
import java.util.Locale;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.File;
import java.io.Writer;
import java.io.FilenameFilter;
import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.io.Reader;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "C-(small|large).*[.]in";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("c.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        out.printf("Case #%d: ", testNumber);
        int n = in.readInt();
        ArrayList<Pair> hikers = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int d = in.readInt(), h = in.readInt(), m = in.readInt();
            for (int j = 0; j < h; j++) {
                hikers.add(new Pair(new Rational(BigInteger.valueOf(d), BigInteger.valueOf(360)), new Rational(BigInteger.ONE, BigInteger.valueOf(j + m))));
            }
        }
        Collections.sort(hikers);
        long ans = Long.MAX_VALUE;
        for (int x = 0; x < hikers.size();) {
            int it = x;
            while (it < hikers.size() && hikers.get(x).first.equals(hikers.get(it).first)) {
                it++;
            }
            for (int i = x; i < it; i++) {
                long curAns = -(it - i);
                for (Pair hiker : hikers) {
                    Rational time = new Rational(1).subtract(hikers.get(i).first).divide(hikers.get(i).second);
                    curAns += intersect(hikers.get(i), hiker, time);
                }
                ans = Math.min(ans, curAns);
            }
            x = it;
        }
        out.printLine(ans);
    }

    public long intersect(Pair a, Pair b, Rational time) {
        Rational position = b.first.subtract(a.first);
        if (position.compareZero() < 0) {
            position = position.add(new Rational(1));
        }
        Rational speed = b.second.subtract(a.second);
        if (speed.compareZero() < 0) {
            speed = new Rational(0).subtract(speed);
            position = new Rational(0).subtract(position);
            while (position.compareZero() < 0) {
                position = position.add(new Rational(1));
            }
        }
        return intersect(position, speed, time);
    }

    public Rational distance(Rational position) {
        if (position.compareZero() == 0) {
            return position;
        }
        return new Rational(1).subtract(position);
    }

    public long intersect(Rational position, Rational speed, Rational time) {
        if (speed.compareZero() == 0 && position.compareZero() == 0) {
            return 1;
        } else if (speed.compareZero() == 0) {
            return 0;
        }
        Rational firstTime = distance(position).divide(speed);
        if (firstTime.compareTo(time) > 0) {
            return 0;
        }
        time = time.subtract(firstTime);
        Rational realAns = time.multiply(speed);
        return 1 + realAns.p.divide(realAns.q).longValue();
    }
}

class Pair implements Comparable<Pair> {
    public Rational first, second;

    public Pair(Rational first, Rational second) {
        this.first = first;
        this.second = second;
    }

    public int compareTo(Pair o) {
        int k = first.compareTo(o.second);
        if (k != 0) {
            return k;
        }
        return second.compareTo(o.second);
    }
}

class Rational implements Comparable<Rational> {
    public BigInteger p, q;

    public Rational(long a) {
        this(BigInteger.valueOf(a), BigInteger.ONE);
    }

    public Rational(BigInteger p, BigInteger q) {
        this.p = p;
        this.q = q;
        normalize();
    }

    private void normalize() {
        if (q.compareTo(BigInteger.ZERO) < 0) {
            q = q.negate();
            p = p.negate();
        }
        BigInteger d = p.abs().gcd(q);
        p = p.divide(d);
        q = q.divide(d);
    }

    public Rational add(Rational b) {
        return new Rational(p.multiply(b.q).add(b.p.multiply(q)), q.multiply(b.q));
    }

    public Rational subtract(Rational b) {
        return new Rational(p.multiply(b.q).subtract(b.p.multiply(q)), q.multiply(b.q));
    }

    public Rational multiply(Rational b) {
        return new Rational(p.multiply(b.p), q.multiply(b.q));
    }

    public Rational divide(Rational b) {
        return new Rational(p.multiply(b.q), q.multiply(b.p));
    }

    public int compareZero() {
        return p.compareTo(BigInteger.ZERO);
    }

    public int compareTo(Rational b) {
        return subtract(b).compareZero();
    }

    public boolean equals(Rational b) {
        return compareTo(b) == 0;
    }
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(BufferedReader reader) {
        this.reader = reader;
    }

    public InputReader(Reader reader) {
        this(new BufferedReader(reader));
    }

    public InputReader(InputStream stream) {
        this(new InputStreamReader(stream));
    }

    private String nextLine() {
        String result;
        try {
            result = reader.readLine();
        } catch (IOException exception) {
            throw new RuntimeException(exception);
        }
        return result;
    }

    public String readWord() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(nextLine());
        }
        return tokenizer.nextToken();
    }

    public String next() {
        return readWord();
    }

    public int readInt() {
        return Integer.parseInt(readWord());
    }

}

class OutputWriter {
    private PrintWriter writer;

    public OutputWriter(PrintWriter writer) {
        this.writer = writer;
    }

    public OutputWriter(Writer writer) {
        this(new PrintWriter(writer));
    }

    public OutputWriter(OutputStream stream) {
        this(new OutputStreamWriter(stream));
    }

    public void print(Object...args) {
        for (Object o : args) {
            writer.print(o);
        }
    }

    public void printLine(Object...args) {
        print(args);
        writer.println();
    }

    public void printf(String format, Object...args) {
        writer.printf(format, args);
    }

    public void close() {
        writer.close();
    }
}

