import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Locale;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.util.TreeSet;
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
			final String regex = "B-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("b.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        out.print("Case #" + testNumber + ": ");
        N = in.nextInt();
        cars = new String[N];
        for (int i = 0; i < N; i++) {
            cars[i] = in.next();
        }
        ret = 0;
        boolean[] used = new boolean[N];
        boolean[] alph = new boolean[26];
        go(0, used, alph, -1);
        out.println(ret);
    }

    int N;
    String[] cars;
    int ret;
    private void go(int c, boolean[] used, boolean[] alph, int last) {
        if (c == N) {
            ret++;
            return;
        }
        for (int i = 0; i < N; i++) {
            if (used[i]) continue;
            int s = cars[i].charAt(0) - 'a';
            if (last != -1 && alph[s] && s != last) continue;
            boolean can = true;
            TreeSet<Integer> newuse = new TreeSet<Integer>();
            int nlast = -1;
            int testlast = last;
            for (int j = 0; j < cars[i].length(); j++) {
                int a = cars[i].charAt(j) - 'a';
                if (a != testlast && (alph[a] || newuse.contains(a))) {
                    can = false;
                    break;
                }
                testlast = a;
                if (!alph[a]) newuse.add(a);
                if (j == cars[i].length() - 1) nlast = a;
            }
            if (!can) continue;
            used[i] = true;
            for (int nu: newuse) alph[nu] = true;
            go(c+1, used, alph, nlast);
            used[i] = false;
            for (int nu: newuse) alph[nu] = false;
        }
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

