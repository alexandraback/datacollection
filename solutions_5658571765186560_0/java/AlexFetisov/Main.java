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
		TaskD_OminousOmino solver = new TaskD_OminousOmino();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskD_OminousOmino {

    private int n;
    private int m;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int X = in.nextInt();
        n = in.nextInt();
        m = in.nextInt();
        if (n > m) {
            int t = n;
            n = m;
            m = t;
        }
        out.print("Case #" + testNumber + ": ");
        if (X > m) {
            out.println("RICHARD");
            return;
        }

        if (X == 4) {
            if (n == 1 || m == 1) {
                out.println("RICHARD");
                return;
            }
            if (n == 2) {
                out.println("RICHARD");
                return;
            }
            if (n == 3 && m == 3) {
                out.println("RICHARD");
                return;
            }

//            mustUse = new boolean[19];
//            Arrays.fill(mustUse, false);
//            mustUse[0] = mustUse[1] = true;
//            if (!canFill()) {
//                out.println("RICHARD");
//                return;
//            }
//
//            Arrays.fill(mustUse, false);
//            mustUse[2] = mustUse[3] = mustUse[4] = mustUse[5] = true;
//            if (!canFill()) {
//                out.println("RICHARD");
//                return;
//            }
//
//            Arrays.fill(mustUse, false);
//            mustUse[6] = mustUse[7] = mustUse[8] = mustUse[9] = mustUse[10] = mustUse[11] = mustUse[12] = mustUse[13] = true;
//            if (!canFill()) {
//                out.println("RICHARD");
//                return;
//            }
//
//            Arrays.fill(mustUse, false);
//            mustUse[14] = true;
//            if (!canFill()) {
//                out.println("RICHARD");
//                return;
//            }
//
//            Arrays.fill(mustUse, false);
//            mustUse[15] = mustUse[16] = mustUse[17] = mustUse[18] = true;
//            if (!canFill()) {
//                out.println("RICHARD");
//                return;
//            }
        } else if (X == 2) {
            if (n % 2 == 1 && m % 2 == 1) {
                out.println("RICHARD");
                return;
            }
        } else if (X == 3) {
            if (n == 1) {
                out.println("RICHARD");
                return;
            }
            if (n == 2) {
                if (m == 2 || m == 4) {
                    out.println("RICHARD");
                    return;
                }
            }
            if (n == 4 && m == 4) {
                out.println("RICHARD");
                return;
            }
        }
        out.println("GABRIEL");
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

