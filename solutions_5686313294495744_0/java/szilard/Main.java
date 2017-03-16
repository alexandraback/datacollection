import java.io.FileInputStream;
import java.util.HashSet;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.File;
import java.util.Set;
import java.util.StringTokenizer;

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
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {

    static class Pair {
        public String x, y;

        public Pair(String x, String y) {
            this.x = x;
            this.y = y;
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();

        Pair[] a = new Pair[n];

        for (int i = 0; i < n; i++) {
            String s1 = in.next();
            String s2 = in.next();

            a[i] = new Pair(s1, s2);
        }

        int max = 0;

        for (int i = 0; i < (1 << n); i++) {
            Set<String> first = new HashSet<String>();
            Set<String> second = new HashSet<String>();

            for (int j = 0; j < n; j++) {
                if (((1 << j) & i) != 0) {
                    first.add(a[j].x);
                    second.add(a[j].y);
                }
            }

            boolean ok = true;

            for (int j = 0; j < n; j++) {
                if (((1 << j) & i) == 0) {
                    if (!first.contains(a[j].x) || !second.contains(a[j].y)) {
                        ok = false;
                        break;
                    }
                }
            }

            if (ok) {
                int len = n - count(i);
                max = Math.max(max, len);
            }
        }

        out.println(String.format("Case #%d: %d", testNumber, max));
    }

    private int count(int x) {
        int v =0;

        while (x != 0){
            v++;
            x = x - (x & (-x));
        }

        return v;
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;


    public InputReader(InputStream stream){
        reader = new BufferedReader(new InputStreamReader(stream));
    }

    public String next(){
        while (tokenizer == null || !tokenizer.hasMoreTokens()){
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException("FATAL ERROR", e);
            }
        }

        return tokenizer.nextToken();
    }

    public int nextInt(){
        return Integer.valueOf(next());
    }

}

