import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileInputStream;
import java.util.Scanner;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.File;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author padington
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
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        final int C = in.nextInt();
        final int D = in.nextInt();
        final int V = in.nextInt();
        final long[] denominations = new long[D + 1];
        for (int i = 0; i < D; i++) {
            denominations[i] = in.nextInt();
        }
		denominations[D] = Long.MAX_VALUE;

        long sum = 0;
        int ans = 0;
		int curI = 0;
        while (sum < V) {
			while (denominations[curI] <= (sum + 1)) {
				sum += C * denominations[curI];
				curI++;
			}

			if (sum < V) {
				ans++;
				sum += (sum + 1) * C;
			}
        }

        out.println(String.format("Case #%d: %d", testNumber, ans));
    }
}

