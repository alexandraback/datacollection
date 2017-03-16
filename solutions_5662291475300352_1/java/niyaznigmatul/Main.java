import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.List;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.io.Reader;
import java.util.Arrays;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.PrintStream;
import java.util.Comparator;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Niyaz Nigmatullin
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    static class Hiker {
        int startPos;
        int period;

        public Hiker(int startPos, int period) {
            this.startPos = startPos;
            this.period = period;
        }
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        System.err.println("[" + testNumber + "]");
        int dontUseThisN = in.nextInt();
        List<Hiker> hikers = new ArrayList<>();
        for (int i = 0; i < dontUseThisN; i++) {
            int start = in.nextInt();
            int count = in.nextInt();
            int time = in.nextInt();
            for (int j = 0; j < count; j++) hikers.add(new Hiker(start, time + j));
        }
        Hiker[] a = hikers.toArray(new Hiker[hikers.size()]);
        Arrays.sort(a, new Comparator<Hiker>() {
            public int compare(Hiker o1, Hiker o2) {
                return Integer.compare(o1.startPos, o2.startPos);
            }
        });
        long ans = Long.MAX_VALUE;
        if (a.length == 0) ans = 0;
        for (int i = 0; i < a.length; i++) {
            long[] q = new long[a.length];
            Rational timeToFinish = getTimeToFinish(a[i]);
            for (int j = 0; j < a.length; j++) {
//                if (i == j) continue;
                Rational timeToFinish2 = getTimeToFinish(a[j]);
//                System.out.println(timeToFinish + " " + timeToFinish2);
                if (timeToFinish.compareTo(timeToFinish2) < 0) {
                    q[j] = 0;
                } else {
                    Rational z = timeToFinish.subtract(timeToFinish2);
                    z = z.divide(new Rational(BigInteger.valueOf(a[j].period)));
                    q[j] = z.getNum().divide(z.getDen()).longValue() + 1;
                }
            }
//            System.out.println(Arrays.toString(q));
            long curAns = 0;
            for (int j = 0; j < a.length; j++) {
                if (q[j] == 0) ++curAns; else {
                    curAns += q[j] - 1;
                }
            }
            ans = Math.min(ans, curAns);
        }
        out.println("Case #" + testNumber + ": " + ans);
    }

    private Rational getTimeToFinish(Hiker hiker) {
        return new Rational(BigInteger.valueOf((long) (360 - hiker.startPos) * hiker.period), BigInteger.valueOf(360));
    }
}

class FastScanner extends BufferedReader {

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
//            if (isEOF && ret < 0) {
//                throw new InputMismatchException();
//            }
//            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    public String next() {
        StringBuilder sb = new StringBuilder();
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        if (c < 0) {
            return null;
        }
        while (c >= 0 && !isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
    }

    static boolean isWhiteSpace(int c) {
        return c >= 0 && c <= 32;
    }

    public int nextInt() {
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int ret = 0;
        while (c >= 0 && !isWhiteSpace(c)) {
            if (c < '0' || c > '9') {
                throw new NumberFormatException("digit expected " + (char) c
                        + " found");
            }
            ret = ret * 10 + c - '0';
            c = read();
        }
        return ret * sgn;
    }

    public String readLine() {
        try {
            return super.readLine();
        } catch (IOException e) {
            return null;
        }
    }

}

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }


}

class Rational implements Comparable<Rational> {
	BigInteger num;
	BigInteger den;

    public Rational(BigInteger a) {
		if (a == null) {
			throw new NullPointerException();
		}
		num = a;
		den = BigInteger.ONE;
		norm();
	}

	public Rational(BigInteger num, BigInteger den) {
		if (num == null || den == null) {
			throw new NullPointerException();
		}
		if (den.equals(BigInteger.ZERO)) {
			throw new Error("den == 0");
		}
		this.num = num;
		this.den = den;
		norm();
	}

    public BigInteger getNum() {
        return num;
    }

    public BigInteger getDen() {
        return den;
    }

    private void norm() {
		if (den.compareTo(BigInteger.ZERO) < 0) {
			den = den.negate();
			num = num.negate();
		}
		BigInteger g = num.gcd(den);
		if (g.compareTo(BigInteger.ONE) > 0) {
			num = num.divide(g);
			den = den.divide(g);
		}
	}

    public Rational subtract(Rational r) {
		BigInteger a = num.multiply(r.den).subtract(r.num.multiply(den));
		BigInteger b = den.multiply(r.den);
		return new Rational(a, b);
	}

    public Rational divide(Rational r) {
		return new Rational(num.multiply(r.den), den.multiply(r.num));
	}

    public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((den == null) ? 0 : den.hashCode());
		result = prime * result + ((num == null) ? 0 : num.hashCode());
		return result;
	}

	public boolean equals(Object obj) {
		Rational other = (Rational) obj;
		if (den == null) {
			if (other.den != null)
				return false;
		} else if (!den.equals(other.den))
			return false;
		if (num == null) {
			if (other.num != null)
				return false;
		} else if (!num.equals(other.num))
			return false;
		return true;
	}

    public String toString() {
		return num.toString()
				+ (den.equals(BigInteger.ONE) ? "" : "/" + den.toString());
	}

    public int compareTo(Rational o) {
        return num.multiply(o.den).compareTo(den.multiply(o.num));
    }

}

