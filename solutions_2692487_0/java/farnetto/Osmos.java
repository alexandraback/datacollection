import java.io.*;
import java.util.*;

public class Osmos {
    static BufferedReader reader;
    static StringTokenizer tokenizer;
    static PrintWriter writer;

    static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    static String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    public static void main(String[] args) throws IOException {
        reader = new BufferedReader(new InputStreamReader(System.in));
        tokenizer = null;
        writer = new PrintWriter(System.out);
        solve();
        reader.close();
        writer.close();
    }


    private static void solve() throws IOException {
        int t = nextInt();
        for (int i = 0; i < t; i++) {
            System.out.print("Case #" + (i+1) + ": ");
            s();
        }
    }

    static void s() throws IOException {
        int changes = 0;
        int A = nextInt();
        int N = nextInt();
        List<Integer> motes = new ArrayList<Integer>();
        for (int i = 0; i < N; i++) {
            motes.add(nextInt());
        }
        Collections.sort(motes);
        //System.out.println("motes=" + motes + ", A=" + A);
        for (int i = 0; i < N; i++) {
            if (motes.get(i) < A) {
                A+=motes.get(i);
            } else {
                int a = add(A, motes.get(i));
                //System.out.println("a=" + a + ", A=" + A + ", m=" + motes.get(i));
                if (a < motes.size() - i) {
                    changes += a;
                    for (int j = 0; j < a; j++)
                        A += A-1;
                    A += motes.get(i);
                } else {
                    changes += motes.size() - i;
                    break;
                }
            }
        }
        if (changes > motes.size())
            changes = motes.size();
        System.out.println("" + changes);
    }

    static int add(int A, int T) {
        if (A == 1)
            return Integer.MAX_VALUE;
        int c = 0;
        while (A <= T) {
            A+=A-1;
            c++;
        }
        return c;
    }
}

