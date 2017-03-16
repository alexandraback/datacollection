import java.io.*;
import java.util.*;

public class ProblemD implements Runnable {

    void solveMultiTest() throws IOException {
        int testCases = nextInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            out.println("Case #" + testCase + ": " + solveOneTest());
        }
    }

    class Item implements Comparable<Item> {
        double val;
        int whose = 0;

        Item (double val, int whose) {
            this.val = val;
            this.whose = whose;
        }

        @Override
        public int compareTo(Item o) {
            return Double.compare(this.val, o.val);
        }
    }

    String solveOneTest() throws IOException {
        int n = nextInt();
        Item[] blocks = new Item[2 * n];
        for (int i = 0; i < n; i++) {
            blocks[i] = new Item(nextDouble(), 0);
        }
        for (int i = n; i < 2 * n; i++) {
            blocks[i] = new Item(nextDouble(), 1);
        }
        Arrays.sort(blocks);

        int ans1 = 0;
        int ans2 = 0;
        int c = 0;
        for (int i = 0; i < 2 * n; i++) {
            if (blocks[i].whose == 0) {
                c++;
            } else {
                c--;
            }
            if (ans1 < c)
                ans1 = c;
            if (ans2 > c)
                ans2 = c;
        }

        return (n - ans1) + " " + -ans2;
    }


    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public void run() {
        try {
            InputStream input = System.in;
            PrintStream output = System.out;
            File file = new File("d.in");
            if (file.exists() && file.canRead()) {
                input = new FileInputStream(file);
                output = new PrintStream(new File("d.out"));
            }
            br = new BufferedReader(new InputStreamReader(input));
            out = new PrintWriter(output);
            solveMultiTest();
            out.close();
        } catch (IOException e) {
        }
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    public static void main(String[] args) {
        new Thread(new ProblemD()).run();
    }
}