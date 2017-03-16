import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class TaskA implements Runnable {
    private int moteCount;
    private int moteSize;
    private int [] motes;
    private int solve() {
        Arrays.sort(motes);
        if (moteSize == 1) {
            return moteCount;
        }
        int result = Integer.MAX_VALUE;
        for (int remove = 0; remove <= moteCount; remove++) {
            int currentSize = moteSize;
            int currentResult = remove;
            for (int j = 0; j < moteCount - remove; j++) {
                if (currentSize > motes[j]) {
                    currentSize += motes[j];
                } else {
                    while (currentSize <= motes[j]) {
                        currentSize += (currentSize - 1);
                        currentResult += 1;
                    }
                    currentSize += motes[j];
                }
            }
            if (currentResult < result) result = currentResult;
        }
        return result;
    }

    public void run() {
        try {
            InputReader reader = new InputReader(System.in);
            PrintWriter writer = new PrintWriter(new File("a.txt"));
            reader.nextLine();
            int testCount = reader.nextInt();
            for (int test = 1; test <= testCount; test++) {
                reader.nextLine();
                moteSize = reader.nextInt();
                moteCount = reader.nextInt();
                reader.nextLine();
                motes = new int[moteCount];
                for (int i = 0; i < moteCount; i++) {
                    motes[i] = reader.nextInt();
                }
                writer.println("Case #" + test + ": " + solve());
            }

            writer.close();
        } catch(IOException e) {

        }
    }
    public static void main(String[] args) {
        new TaskA().run();
    }
    private class InputReader {
        BufferedReader reader;
        StringTokenizer token;

        private InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
        }

        private String next() {
            return token.nextToken();
        }

        private int nextInt() {
            return Integer.parseInt(this.next());
        }

        private double nextDouble() {
            return Double.parseDouble(this.next());
        }

        private long nextLong() {
            return Long.parseLong(this.next());
        }

        private String nextLine() {
            String line = "";
            try {
                line = reader.readLine();
                token = new StringTokenizer(line, " ");

            } catch(IOException e) {

            }
            return line;
        }
    }
}
