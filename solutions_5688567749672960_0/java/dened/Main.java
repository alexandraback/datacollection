import java.io.Reader;
import java.io.FileInputStream;
import java.util.ArrayDeque;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.io.BufferedReader;
import java.io.FilenameFilter;
import java.util.Map;
import java.util.Collection;
import java.util.Locale;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Queue;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.File;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Denis Nedelyaev
 */
public class Main {
	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		final String regex = "A-(small|large).*[.]in";
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
		OutputStream outputStream = new FileOutputStream("a.out");
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA(in, out);
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i);
		out.close();
	}
}

class TaskA {
    private final FastScanner in;
    private final PrintWriter out;

    public TaskA(FastScanner in, PrintWriter out) {
        this.in = in;
        this.out = out;
    }

    public void solve(int testNumber) throws IOException {
        long n = in.nextLong();
        Map<Integer, Integer> dists = new HashMap<>();
        Queue<Integer> queue = new ArrayDeque<>();
        queue.add(1);
        dists.put(1, 1);
        while (!queue.isEmpty()) {
            int x = queue.remove();
            int dist = dists.get(x);
            if (x == n) {
                out.println("Case #" + testNumber + ": " + dist);
                return;
            }
            if (!dists.containsKey(x + 1)) {
                queue.add(x + 1);
                dists.put(x + 1, dist + 1);
            }
            int y = reverse(x);
            if (!dists.containsKey(y)) {
                queue.add(y);
                dists.put(y, dist + 1);
            }
        }
    }

    private int reverse(int x) {
        int y = 0;
        while (x > 0) {
            y *= 10;
            y += x % 10;
            x /= 10;
        }
        return y;
    }
}

class FastScanner {
    private BufferedReader br;
    private String line = "";
    private int pos;

    public FastScanner(InputStream is) {
        this(new BufferedReader(new InputStreamReader(is)));
    }

    public FastScanner(Reader reader) {
        br = new BufferedReader(reader);
    }

    public String next() throws IOException {
        if (!goToNextToken()) {
            return null;
        }
        return readString();
    }

    public long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    private boolean goToNextToken() throws IOException {
        if (br == null) {
            return false;
        }

        while (pos == line.length()) {
            line = br.readLine();

            if (line == null) {
                br = null;
                return true;
            }

            pos = 0;

            skipWhitespace();
        }

        return true;
    }

    private String readString() {
        int start = pos;

        while (pos < line.length()) {
            char c = line.charAt(pos);

            if (c == ' ' || c == '\t') {
                break;
            }

            pos++;
        }

        String result = line.substring(start, pos);

        skipWhitespace();

        return result;
    }

    private void skipWhitespace() {
        while (pos < line.length()) {
            char c = line.charAt(pos);

            if (c != ' ' && c != '\t') {
                break;
            }

            pos++;
        }
    }
}

