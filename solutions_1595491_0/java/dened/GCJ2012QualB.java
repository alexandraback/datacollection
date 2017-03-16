import java.io.*;
import java.util.Locale;
import java.util.StringTokenizer;

public class GCJ2012QualB {
    int maxNS[] = new int[31];
    int maxS[] = new int[31];
    
    public void run() throws IOException {
        for (int s = 0; s <= 30; ++s) {
            maxNS[s] = maxS[s] = -1;
        }
        
        for (int a = 0; a <= 10; ++a) {
            for (int b = 0; b <= a; ++b) {
                for (int c = 0; c <= b; ++c) {
                    if (a - c <= 1) {
                        maxNS[a + b + c] = Math.max(maxNS[a + b + c], a);
                    }
                    else if (a - c <= 2) {
                        maxS[a + b + c] = Math.max(maxS[a + b + c], a);
                    }
                }
            }
        }
        
        int T = nextInt();
        for (int i = 1; i <= T; ++i) {
            out.println("Case #" + i + ": " + solve());
        }
    }

    private int solve() throws IOException {
        int N = nextInt();
        int S = nextInt();
        int p = nextInt();
        int na = 0;
        int nns = 0;
        int ns = 0;
        int nn = 0;
        
        for (int i = 0; i < N; ++i) {
            int t = nextInt();
            
            if (maxNS[t] >= p && maxS[t] >= p) {
                ++na;
            }
            else if (maxNS[t] >= p) {
                ++nns;
            }
            else if (maxS[t] >= p) {
                ++ns;
            }
            else {
                ++nn;
            }
        }
        
        assert S <= N;
        assert na + nns + ns + nn == N;
        
        if (ns >= S) {
            return na + nns + S;
        }
        else if (na + ns + nn >= S) {
            return na + nns + ns;
        }
        else {
            return na + nns + ns - (S - (na + ns + nn));
        }
    }

    public static BufferedReader in;
    public static PrintStream out;

    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);

        String className = GCJ2012QualB.class.getSimpleName();
        char lastChar = className.charAt(className.length() - 1);
        System.setIn(new FileInputStream(lastChar + ".in"));
        System.setOut(new PrintStream(lastChar + ".out"));

        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintStream(new BufferedOutputStream(System.out));

        new GCJ2012QualB().run();

        out.close();
    }

    public static StringTokenizer tokenizer;

    public static String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(in.readLine());
        }
        return tokenizer.nextToken();
    }

    public static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public static long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    public static double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }
}
