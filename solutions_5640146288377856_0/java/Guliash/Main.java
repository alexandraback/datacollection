import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Artem Gilmudinov
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("A-small-attempt2.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Reader in = new Reader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, Reader in, PrintWriter out) {
        int T = in.ni();
        for(int t = 1; t <= T; t++) {
            int r, c, w;
            r = in.ni(); c = in.ni(); w = in.ni();
            int ans = 0;
            if(w == 1) {
                ans = r * c;
            } else {
                if (w == c) {
                    ans = r + w - 1;
                } else {
                    if(c % w == 0) {
                        ans = (c / w - 1) * r + w;
                    } else {
                        ans = (c / w) * r + w;
                    }
                }
            }
            out.println(String.format("Case #%d: %d", t, ans));
        }
    }
}

class Reader {
    private BufferedReader in;
    private StringTokenizer st = new StringTokenizer("");
    private String delim = " ";

    public Reader(InputStream in) {
        this.in = new BufferedReader(new InputStreamReader(in));
    }

    public String next() {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(rl());
        }
        return st.nextToken(delim);
    }

    public String rl() {
        try {
            return in.readLine();
        } catch(IOException e) {
            throw new RuntimeException(e);
        }
    }

    public int ni() {
        return Integer.parseInt(next());
    }

}

