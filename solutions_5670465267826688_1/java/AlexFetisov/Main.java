import java.io.InputStreamReader;
import java.io.IOException;
import java.util.HashMap;
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
    static int get(int x, int y) {
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

    HashMap<Integer, Integer> to;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        to = new HashMap<Integer, Integer>();
        out.print("Case #" + testNumber + ": ");

        in.nextInt();
        long x = in.nextLong();
        String s = in.nextString();

        for (int enter = 1; enter <= 4; ++enter) {
            int cur = enter;
            for (int i = 0; i < s.length(); ++i) {
                cur = get(cur, getC(s.charAt(i)));
            }
            to.put(enter, cur);
            cur = -enter;
            for (int i = 0; i < s.length(); ++i) {
                cur = get(cur, getC(s.charAt(i)));
            }
            to.put(-enter, cur);
        }

        if (!endsWell(x)) {
            out.println("NO");
            return;
        }

        StringBuilder b = new StringBuilder("");
        for (int i = 0; i < x && i < 1000 && b.length() < 1000000; ++i) {
            b.append(s);
        }
        boolean hasI = false;
        s = b.toString();
        int cur = 1;
        for (int i = 0; i < s.length(); ++i) {
            cur = get(cur, getC(s.charAt(i)));
            if (cur == 2 && !hasI) {
                hasI = true;
            } else if (cur == 4 && hasI) {
                out.println("YES");
                return;
            }
        }
        out.println("NO");
    }

    private boolean endsWell(long x) {
        if (x <= 1000000) {
            int cur = 1;
            for (int i = 0; i < x; ++i) {
                cur = to.get(cur);
            }
            return cur == -1;
        }
        HashMap<Integer, Integer> was = new HashMap<Integer, Integer>();
        int cur = 1;
        for (int i = 1; i <= x; ++i) {
            int next = to.get(cur);
            if (was.containsKey(next)) {
                int id = was.get(next);
                int len = i - id;
                x -= id;
                x %= len;
                for (int j = 0; j < x; ++j) {
                    next = to.get(next);
                }
                return next == -1;
            } else {
                was.put(next, i);
                cur = next;
            }
        }
        return cur == -1;
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

    public long nextLong() {
        return Long.parseLong(nextString());
    }

    public String next() {
        return nextString();
    }
}

