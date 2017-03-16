import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.FileReader;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.HashSet;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Pavel Chuprikov
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		B solver = new B();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class B {
    static HashSet<String> words = new HashSet<>();
    static {
        try {
            BufferedReader br = new BufferedReader(new FileReader("dict"));
            int maxLength = Integer.MIN_VALUE;
            while (true) {
                String line = br.readLine();
                if (line == null)
                    break;
                words.add(line);
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        } catch (IOException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        out.print("Case #" + testNumber + ": ");
        char[] s = in.next().toCharArray();
        int[][] dp = new int[s.length + 1][5];
        for (int[] ds : dp) {
            Arrays.fill(ds, Integer.MAX_VALUE);
        }
        for (int i = 0; i < 5; i++) {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= s.length; i++) {
            final int[] cdp = dp[i];
            for (int l = 1; l <= Math.min(10, i); l++) {
                final int[] pdp = dp[i - l];
                char[] trying = Arrays.copyOfRange(s, i - l, i);
                if (words.contains(new String(trying))) {
                    for (int pm = 0; pm < 5; pm++) {
                         cdp[Math.min(4, l + pm)] = Math.min(cdp[Math.min(4, l + pm)], pdp[pm]);
                    }
                }
                for (int m1 = 0; m1 < l; m1++) {
                    char orig1 = trying[m1];
                    for (trying[m1] = 'a'; trying[m1] <= 'z'; trying[m1]++) {
                        if (trying[m1] == orig1)
                            continue;
                        else {
                            int cidx = Math.min(4, l - m1 - 1);
                            if (words.contains(new String(trying))) {
                                for (int pm = 0; pm < 5; pm++)
                                    if (pdp[pm] != Integer.MAX_VALUE && pm + m1 >= 4)
                                        cdp[cidx] = Math.min(cdp[cidx], pdp[pm] + 1);
                            }
                            for (int m2 = m1 - 5; m2 >= 0; m2--) {
                                char orig2 = trying[m2];
                                for (trying[m2] = 'a'; trying[m2] <= 'z'; trying[m2]++) {
                                    if (trying[m2] == orig2)
                                        continue;
                                    if (words.contains(new String(trying)))
                                        for (int pm = 0; pm < 5; pm++)
                                            if (pdp[pm] != Integer.MAX_VALUE && pm + m2 >= 4)
                                                cdp[cidx] = Math.min(cdp[cidx], pdp[pm] + 2);
                                }
                                trying[m2] = orig2;
                            }
                        }
                    }
                    trying[m1] = orig1;
                }
            }
            for (int j = 3; j >= 0; j--) {
                    cdp[j] = Math.min(cdp[j], cdp[j + 1]);
            }
        }
        int result = Integer.MAX_VALUE;
        for (int i = 0; i < 5; i++) {
            result = Math.min(result, dp[s.length][i]);
        }
        out.println(result);
    }
}

class FastScanner {
    private BufferedReader br;
    private StringTokenizer st;

    public FastScanner(InputStream in) {
        this.br = new BufferedReader(new InputStreamReader(in));
    }

    public boolean hasNext() {
        try {
            while (st == null || !st.hasMoreTokens()) {
                final String nextLine = br.readLine();
                if (nextLine == null) {
                    return false;
                } else {
                    st = new StringTokenizer(nextLine);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
        return true;
    }

    public String next() {
        return hasNext() ? st.nextToken() : null;
    }

    }

