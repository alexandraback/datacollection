import java.io.FileInputStream;
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
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Kartik Singal (ka4tik)
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
    private int value(int a, int b) {
        int sign = 1;
        if (a < 0)
            sign *= -1;
        if (b < 0)
            sign *= -1;
        a = Math.abs(a);
        b = Math.abs(b);
        if (a == 1)
            return b * sign;
        if (a == 2) {
            if (b == 1)
                return 2 * sign;
            if (b == 2)
                return -1 * sign;
            if (b == 3)
                return 4 * sign;
            if (b == 4)
                return -3 * sign;
        }
        if (a == 3) {
            if (b == 1)
                return 3 * sign;
            if (b == 2)
                return -4 * sign;
            if (b == 3)
                return -1 * sign;
            if (b == 4)
                return 2 * sign;
        }
        if (a == 4) {
            if (b == 1)
                return 4 * sign;
            if (b == 2)
                return 3 * sign;
            if (b == 3)
                return -2 * sign;
            if (b == 4)
                return -1 * sign;
        }
        return 0 * sign;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        long n = in.nextLong();
        long x = in.nextLong();
        String str = in.next();

        int a[] = new int[(int) Math.min(10 * n, n * x)];
        int counter = 0;
        int total = 1;
        for (int i = 0; i < a.length; i++) {
            if (str.charAt(counter) == 'i')
                a[i] = 2;
            if (str.charAt(counter) == 'j')
                a[i] = 3;
            if (str.charAt(counter) == 'k')
                a[i] = 4;
            if (i < str.length())
                total = value(total, a[i]);
            counter++;
            if (counter >= str.length())
                counter %= str.length();
        }
        int current = 1;
        int i;
        boolean foundi = false;
        boolean foundj = false;
        boolean foundk = false;

        for (i = 0; i < a.length; i++) {
            current = value(current, a[i]);
            if (current == 2) {
                foundi = true;
                break;
            }
        }
        if (!foundi) {
            out.println("Case #" + testNumber + ": " + "NO");
            return;
        }
        i++;
        current = 1;
        for (; i < a.length; i++) {
            current = value(current, a[i]);
            if (current == 3) {
                foundj = true;
                break;
            }
        }
        if (!foundj) {
            out.println("Case #" + testNumber + ": " + "NO");
            return;
        }
        i++;
        current = 1;
        for (; i < a.length; i++)
            current = value(current, a[i]);

        long rem = (n * x - a.length) / n;
        if (total == 1 || total == -1) {
            if (rem % 2 == 1)
                current *= total;
        } else {
            if (rem % 4 == 1)
                current = value(current, total);
            if (rem % 4 == 2)
                current = value(current, -1);
            if (rem % 4 == 3)
                current = value(current, -total);
        }

        if (current == 4) {
            out.println("Case #" + testNumber + ": " + "YES");
        } else
            out.println("Case #" + testNumber + ": " + "NO");


    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) try {
            tokenizer = new StringTokenizer(reader.readLine());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        return tokenizer.nextToken();
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

}

