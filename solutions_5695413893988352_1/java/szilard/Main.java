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

    boolean ok = false;
    int[] v1, v2;
    long currDiff;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        String s = in.next();
        String t = in.next();

        int[] a = convert(s);
        int[] b = convert(t);

        ok = false;
        v1 = new int[a.length];
        v2 = new int[a.length];

        int[] curr1 = new int[a.length];
        int[] curr2 = new int[a.length];

        for (int i = 0; i <= s.length() && possible(a, b, i); i++) {

            if (i == s.length()) {
                fillEqual(curr1, curr2, a, b, i);
                updateRes(curr1, curr2);
                break;
            }

            for (int k1 = 0; k1 < 10; k1++) {
                for (int k2 = 0; k2 < 10; k2++) {
                    if (k1 == k2) continue;

                    if ((a[i] != -1 && a[i] != k1)
                            || (b[i] != -1 && b[i] != k2)) {
                        continue;
                    }

                    fillEqual(curr1, curr2, a, b, i);

                    curr1[i] = k1;
                    curr2[i] = k2;

                    fillRest(curr1, curr2, a, b, i + 1, k1 > k2);

                    updateRes(curr1, curr2);
                }
            }
        }

        String sol1 = arrToString(v1);
        String sol2 = arrToString(v2);

        out.println(String.format("Case #%d: %s %s", testNumber, sol1, sol2));
    }

    private String arrToString(int[] v1) {
        StringBuilder builder = new StringBuilder();

        for (int i = 0; i < v1.length; i++) {
            builder.append(v1[i]);
        }

        return builder.toString();
    }

    private void updateRes(int[] curr1, int[] curr2) {
        if (!ok) {
            copy(v1, curr1);
            copy(v2, curr2);
            ok = true;
            currDiff = Math.abs(toLong(curr1) - toLong(curr2));
        } else {
            long orV1 = toLong(v1);
            long orV2 = toLong(v2);

            long val1 = toLong(curr1);
            long val2 = toLong(curr2);
            long diff = Math.abs(val1 - val2);

            boolean useIt = false;
            if (diff < currDiff) {
                useIt = true;
            } else if (diff == currDiff) {
                useIt = (val1 < orV1 || (val1 == orV1 && val2 < orV2));
            }

            if (useIt) {
                currDiff = diff;
                copy(v1, curr1);
                copy(v2, curr2);
            }
        }
    }

    private long toLong(int[] v1) {
        long val = 0;

        for (int i = 0; i < v1.length; i++) {
            val = val * 10L + v1[i];
        }

        return val;
    }

    private void copy(int[] dst, int[] src) {
        for (int i = 0; i < src.length; i++) {
            dst[i] = src[i];
        }
    }

    private void fillRest(int[] curr1, int[] curr2, int[] a, int[] b, int index, boolean firstLarger) {

        for (int i = index; i < a.length; i++) {
            curr1[i] = getVal(a[i], firstLarger);
            curr2[i] = getVal(b[i], !firstLarger);
        }

    }

    private int getVal(int val, boolean useSmallest) {
        if (val != -1) {
            return val;
        }

        if (useSmallest) {
            return 0;
        } else {
            return 9;
        }
    }

    private void fillEqual(int[] curr1, int[] curr2, int[] a, int[] b, int size) {
        int val;

        for (int i = 0; i < size; i++) {

            if (a[i] == -1 || b[i] == -1) {

                if (a[i] == -1 && b[i] == -1) {
                    val = 0;
                } else {

                    if (a[i] == -1) {
                        val = b[i];
                    } else {
                        val = a[i];
                    }
                }
            } else {
                val = a[i];
            }

            curr1[i] = val;
            curr2[i] = val;
        }
    }

    private boolean possible(int[] a, int[] b, int size) {

        for (int i = 0; i < size; i++) {
            if (a[i] != b[i] && a[i] != -1 && b[i] != -1) {
                return false;
            }
        }

        return true;
    }

    private int[] convert(String s) {
        int[] a = new int[s.length()];

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '?') {
                a[i] = -1;
            } else {
                a[i] = s.charAt(i) - '0';
            }
        }

        return a;
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

}

