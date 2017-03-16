import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author AlexFetisov
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("input.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC_Dijkstra solver = new TaskC_Dijkstra();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC_Dijkstra {
    int get(int x, int y) {
        if (x < 0 && y < 0) {
            return get(-x, -y);
        }
        if (x < 0) {
            return -get(-x, y);
        }
        if (y < 0) {
            return -get(x, -y);
        }
        if (x == 1) {
            return y;
        }
        if (y == 1) {
            return x;
        }
        if (x == y) {
            return -1;
        }
        if (x == 2) {
            if (y == 3) {
                return 4;
            } else {
                return -3;
            }
        }
        if (x == 3) {
            if (y == 4) {
                return 2;
            } else if (y == 2) {
                return -4;
            }
        }
        if (x == 4) {
            if (y == 2) {
                return 3;
            } else {
                return -2;
            }
        }
        throw new AssertionError(x + " ! " + y);
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int len = in.nextInt();
        int times = in.nextInt();
        String s = in.nextString();
        StringBuilder b = new StringBuilder("");
        for (int i = 0; i < times; ++i) {
            b.append(s);
        }
        s = b.toString();
        char[] c = s.toCharArray();

        boolean[] toI = new boolean[c.length];
        boolean[] toK = new boolean[c.length];
        int cur = 1;
        for (int i = 0; i < c.length; ++i) {
            cur = get(cur, getC(c[i]));
            if (cur == 2) {
                toI[i] = true;
            }
        }
        cur = 1;
        for (int i = c.length-1; i >= 0; --i) {
            cur = get(getC(c[i]), cur);
            if (cur == 4) {
                toK[i] = true;
            }
        }
        out.print("Case #" + testNumber + ": ");
        for (int i = 0; i < c.length; ++i) if (toI[i]) {
            cur = 1;
            for (int j = i + 1, k = i + 2; k < c.length; ++k, ++j) {
                cur = get(cur, getC(c[j]));
                if (toK[k] && cur == 3) {
                    out.println("YES");
                    return;
                }
            }
        }
        out.println("NO");
    }

    private int getC(char c) {
        if (c == 'i') return 2;
        if (c == 'j') return 3;
        return 4;
    }
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer stt;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
    }

    public String nextLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    public String nextString() {
        while (stt == null || !stt.hasMoreTokens()) {
            stt = new StringTokenizer(nextLine());
        }
        return stt.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

    public String next() {
        return nextString();
    }
}

