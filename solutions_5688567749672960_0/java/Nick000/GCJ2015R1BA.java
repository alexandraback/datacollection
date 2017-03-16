package gcj2015.round1b.a;

import java.io.*;
import java.util.Arrays;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ConcurrentSkipListMap;
import java.util.concurrent.Semaphore;

/**
 * Created by numnikov on 4/11/15.
 */
public class GCJ2015R1BA implements Runnable {

    private static final String FILE = "A-small-attempt0";

    Map<Integer, Object> results = new ConcurrentSkipListMap<Integer, Object>();

    void solve() throws IOException, InterruptedException {
        int t = nextInt();
        final Semaphore semaphore = new Semaphore(t);
        for (int i = 0; i < t; ++i) {
            final int temp = i;
            final int n = nextInt();
            semaphore.acquire();
            new Thread(new Runnable() {
                @Override
                public void run() {
                    try {
                        doSolve(temp, n);
                        semaphore.release();
                    } catch (IOException e) {
                        System.out.println("TEST " + temp);
                        e.printStackTrace();
                    }
                }
            }).start();
        }
        semaphore.acquire(t);
        for (Map.Entry<Integer, Object> entry : results.entrySet()) {
            writer.println("Case #" + (entry.getKey() + 1) + ": " + entry.getValue());
        }
    }

    public int reverse(int n) {
        int result = 0;
        int rem;
        while (n > 0) {
            rem = n % 10;
            n = n / 10;
            result = result * 10 + rem;
        }
        return result;
    }

    void doSolve(int t, int n) throws IOException {
        int[] count = new int[n + 2];
        Arrays.fill(count, n);
        for (int i = 1; i <= n; ++i) {
            count[i] = Math.min(count[i], i);
            count[i + 1] = Math.min(count[i] + 1, count[i + 1]);
            int reverse = reverse(i);
            if (reverse <= n) {
                count[reverse] = Math.min(count[i] + 1, count[reverse]);
            }
        }
        results.put(t, count[n]);
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    BufferedReader reader;
    PrintWriter writer;
    StringTokenizer tokenizer;
    @Override
    public void run() {
        try {
            reader = new BufferedReader(new FileReader(new File("src/gcj2015/round1b/a/" + FILE + ".in")));
            writer = new PrintWriter(new FileWriter(new File("src/gcj2015/round1b/a/" + FILE + ".out")));
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public static void main(String[] args) {
        new GCJ2015R1BA().run();
    }
}
