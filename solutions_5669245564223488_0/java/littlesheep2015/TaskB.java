import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author sheep
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
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
    private static final int MODULO = 1000000007;
    private static final long[] frac;

    static {
        frac = new long[1000];
        frac[0] = 1;
        for (int i = 1; i < frac.length; ++i) {
            frac[i] = frac[i - 1] * i % MODULO;
        }
    }

    private boolean[][] conn;
    private boolean[] inStack;
    private boolean[] vis;
    private boolean isValid;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        String[] parts = new String[n];
        for (int i = 0; i < parts.length; ++i) {
            parts[i] = compose(in.next().toCharArray());
        }

        long[] coef = new long[26];

        isValid = true;

        conn = new boolean[26][26];
        inStack = new boolean[26];
        vis = new boolean[26];

        int[] ind = new int[26];
        int[] outd = new int[26];

        for (int i = 0; i < n; ++i) {
            char[] current = parts[i].toCharArray();
            for (int j = 0; j < current.length; ++j) {
                for (int k = j + 1; k < current.length; ++k) {
                    if (current[j] == current[k]) {
                        isValid = false;
                    }
                }
            }
            for (int k = 0; k < current.length; ++k) {
                for (String res : parts) {
                    if (res == parts[i]) continue;

                    for (int j = 1; j + 1 < res.length(); ++j) {
                        if (res.charAt(j) == current[k]) {
                            isValid = false;
                        }
                    }
                }
            }

            if (current.length == 1) {
                ++coef[current[0] - 'a'];
            } else {
                ++ind[current[current.length - 1] - 'a'];
                ++outd[current[0] - 'a'];
                conn[current[0] - 'a'][current[current.length - 1] - 'a'] = true;
            }
        }

        int count = 0;

        for (int i = 0; i < 26; ++i) {
            if (ind[i] > 1 || outd[i] > 1) {
                isValid = false;
            }
            dfs(i, -1);
            if (ind[i] == 0 && outd[i] == 1) {
                ++count;
            } else if (ind[i] == 0 && outd[i] == 0 && coef[i] > 0) {
                ++count;
            }
        }

        long answer = isValid ? 1L : 0L;
        answer = answer * frac[count] % MODULO;
        for (int i = 0; i < 26; ++i) {
            answer = answer * frac[(int) coef[i]] % MODULO;
        }

        out.println("Case #" + testNumber + ": " + answer);

    }

    private void dfs(int x, int parent) {
        if (!isValid) {
            return;
        }
        vis[x] = true;
        inStack[x] = true;
        for (int i = 0; i < 26; ++i) {
            if (conn[x][i]) {
                if (inStack[i]) {
                    isValid = false;
                }
                if (!vis[i]) {
                    dfs(i, x);
                }
            }
        }
        inStack[x] = false;
    }

    private String compose(char[] s) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < s.length; ++i) {
            if (i == 0 || s[i] != s[i - 1]) {
                result.append(s[i]);
            }
        }
        return result.toString();
    }
}

class InputReader {
    BufferedReader reader;
    StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (Exception e) {
                throw new UnknownError();
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

}

