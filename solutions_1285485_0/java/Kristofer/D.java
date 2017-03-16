import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class D {
	private static String FILENAME = "stdin";
	static {
		//FILENAME = "D-sample";
		FILENAME = "D-small";
		//FILENAME = "D-large";
	}

	public static void main(String[] args) {
		new D().run();
	}

	private PrintStream out;
	private final BufferedReader reader;
	private StringTokenizer tokenizer = new StringTokenizer("");

	public D() {
		try {
			out = System.out;
			if (FILENAME == "stdin") {
				reader = new BufferedReader(new InputStreamReader(System.in));
			} else {
				out = new PrintStream(new FileOutputStream("source/" + FILENAME + ".out"));
				reader = new BufferedReader(new FileReader("source/" + FILENAME + ".in"));
			}
		} catch (FileNotFoundException e) {
			throw new RuntimeException(e);
		}
	}

	public void run() {
		try {
			runCases();
		} finally {
			closeAll();
		}
	}

	private void runCode(int theCase) {
		int H = getInt();
		int W = getInt();
        int D = 2 * getInt();
        int D2 = D * D;
        int count = 0;
        int HSize = 2 * (H - 2);
        int WSize = 2 * (W - 2);
        int HPos = -1;
        int WPos = -1;

        boolean fail = false;
        for (int i = 0; i < H; i++) {
            String s = getToken();
            if (i == 0 || i == H-1) {
                if (!fail && (s.contains("X") || s.contains("."))) {
                    out.println("invalid grid1");
                    fail = true;
                }
            } else if (!fail && s.substring(1, s.length() - 2).contains("#")) {
                out.println("invalid grid2");
                fail = true;
            } else {
                int index = s.indexOf('X');
                if (index > -1) {
                    if (HPos > -1) {
                        throw new RuntimeException();
                    }
                    HPos = 2 * i - 1;
                    WPos = 2 * index - 1;
                }
            }
        }
        if (fail) {
            return;
        }
        if (HPos == -1) {
            throw new RuntimeException();
        }
        int hlimit = 1 + D / Math.min(HSize, WSize);
        int wlimit = 1 + D / Math.min(HSize, WSize);
        int HPos2 = HSize - HPos;
        int WPos2 = WSize - WPos;
        Set<String> visited1 = new HashSet<String>();
        Set<String> visited2 = new HashSet<String>();
        Set<String> visited3 = new HashSet<String>();
        Set<String> visited4 = new HashSet<String>();
        if (2 * HPos <= D) {
            count++;
        }
        if (2 * HPos2 <= D) {
            count++;
        }
        if (2 * WPos <= D) {
            count++;
        }
        if (2 * WPos2 <= D) {
            count++;
        }
        for (int h = 1; h <= hlimit; h++) {
            for (int w = 1; w <= wlimit; w++) {
                int h1 = h / 2;
                int h2 = h - h1;
                int w1 = w / 2;
                int w2 = w - w1;
                count += f(visited1, D2, HPos, WPos, HPos2, WPos2, h1, h2, w1, w2);
                count += f(visited2, D2, HPos2, WPos, HPos, WPos2, h1, h2, w1, w2);
                count += f(visited3, D2, HPos, WPos2, HPos2, WPos, h1, h2, w1, w2);
                count += f(visited4, D2, HPos2, WPos2, HPos, WPos, h1, h2, w1, w2);
            }
        }
        out.println(count);
	}

    private int f(Set<String> visited, int D2, int H1, int W1, int H2, int W2, int h1, int h2, int w1, int w2) {
        int hpart = 2 * H1 * h1 + 2 * H2 * h2;
        int wpart = 2 * W1 * w1 + 2 * W2 * w2;
        int len = hpart * hpart + wpart * wpart;
        if (len <= D2) {
            int gcd = gcd(hpart, wpart);
            String key = hpart / gcd + "," + wpart / gcd;
            if (visited.add(key)) {
                return 1;
            }
        }
        return 0;
    }

    private void runCases() {
		int cases = getInt();
		for (int c = 1; c <= cases; c++) {
			out.print("Case #" + c + ": ");
			runCode(c);
		}
	}

    static int gcd(int a, int b) {
        if (b > a) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        while (b != 0) {
            int tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }

	private void closeAll() {
		out.close();
	}

	private String getToken() {
		try {
			while (true) {
				if (tokenizer.hasMoreTokens()) {
					return tokenizer.nextToken();
				}
				String s = reader.readLine();
				if (s == null) {
					return null;
				}
				tokenizer = new StringTokenizer(s, " \t\n\r");
			}
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}
	public double getDouble() {
		return Double.parseDouble(getToken());
	}

	public int getInt() {
		return Integer.parseInt(getToken());
	}

	public long getLong() {
		return Long.parseLong(getToken());
	}

	public BigInteger getBigInt() {
		return new BigInteger(getToken());
	}

	public BigDecimal getBigDec() {
		return new BigDecimal(getToken());
	}

}
