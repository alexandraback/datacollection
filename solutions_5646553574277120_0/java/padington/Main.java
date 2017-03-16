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
        final boolean[] isDenomination = new boolean[V + 1];
        for (int i = 0; i < D; i++) {
            int d = in.nextInt();
			isDenomination[d] = true;
        }

        int sum = 0;
        int ans = 0;
        for (int i = 1; i <= V; i++) {
            if (isDenomination[i]) {
                sum += i;
            } else if (sum < i) {
				ans++;
				sum += i;
			}
        }

        out.println(String.format("Case #%d: %d", testNumber, ans));
    }
}

