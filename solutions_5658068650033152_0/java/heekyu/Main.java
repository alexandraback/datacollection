import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Locale;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.util.StringTokenizer;
import java.io.FilenameFilter;
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
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        out.print("Case #" + testNumber + ": ");
        int N = in.nextInt();
        int M = in.nextInt();
        int K = in.nextInt();
        if (K <= 4 || N <= 2 || M <= 2) {
            out.println(K);
            return;
        } else if (K >= N*M - 4) {
            int ret = 2 * (N - 2 + M - 2) + (K - N*M + 4);
            out.println(ret);
            return;
        }
        int lo = 0;
        int hi = K;
        while (hi - lo > 1) {
            int mid = (lo+hi)/2;
            if (canmake(K-mid, mid)) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        if (canmake(K - hi, hi)) {
            out.println(K-hi);
        } else {
            out.println(K-lo);
        }
    }

    private boolean canmake(int stone, int inner) {
        if (inner == 1) return stone >= 4;
        else if (inner == 2) return stone >= 6;
        return stone >= inner+4;
        /*
        int maxdiv = (int) Math.sqrt(inner);
        for (int i = maxdiv; i >= 1; i--) {
            if (inner % i == 0) {
                int need = 2 * (i + inner/i);
                return stone >= need;
            }
        }

        return false;
        */
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

}

