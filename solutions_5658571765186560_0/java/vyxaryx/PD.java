import java.io.*;
import java.util.StringTokenizer;

public class PD implements Runnable {
    static String PROBLEM_NAME = PD.class.getSimpleName().toLowerCase();
    static String INPUT_FILE_NAME = PROBLEM_NAME + ".in";
    static String OUTPUT_FILE_NAME = PROBLEM_NAME + ".out";

    static class InputReader {
        final BufferedReader rd;
        StringTokenizer tok = null;

        public InputReader(String filename) throws IOException {
            rd = new BufferedReader(new FileReader(new File(filename)));
        }

        public void close() {
            try {
                rd.close();
            } catch (IOException e) {
            }
        }

        public String nextToken() throws IOException {
            while (tok == null || !tok.hasMoreTokens()) {
                tok = new StringTokenizer(rd.readLine());
            }
            return tok.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(nextToken());
        }

        public String readLine() throws IOException {
            tok = null;
            return rd.readLine();
        }
    }

    public static void main(String[] args) {
        try {
            new Thread(new PD()).start();
        } catch (Exception e) {
        }
    }

    @Override
    public void run() {
        try {
            solve();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    private void solve() throws IOException {
        InputReader rd = new InputReader(INPUT_FILE_NAME);
        PrintWriter wr = new PrintWriter(new FileWriter(new File(OUTPUT_FILE_NAME)));

//        for (int x = 1; x <= 6; ++x) {
//            for (int r = 1; r <= 20; ++r) {
//                for (int c = r; c <= 20; ++c) {
//                    System.out.println(String.format("%d, %d, %d -> %s", x, r, c, subsolve(x, r, c)));
//                }
//            }
//            System.out.println();
//        }

        int t = rd.nextInt();
        for (int ti = 0; ti < t; ++ti) {
            int x = rd.nextInt();
            int r = rd.nextInt();
            int c = rd.nextInt();
            boolean result = subsolve(x, r, c);
            wr.println(String.format("Case #%d: %s", ti + 1, result ? "RICHARD" : "GABRIEL"));
        }

        rd.close();
        wr.close();
    }

    private boolean subsolve(int x, int r, int c) {
        if (x >= 7) {  // can make x-omino with hole
            return true;
        }

        if (r * c % x != 0) {  // remaining cells are not divisible by x
            return true;
        }

        int maxrc = Math.max(r, c);
        int minrc = Math.min(r, c);
        if (x > maxrc) {  // can make long one which won't fit grid
            return true;
        }

        if (1 + ((x - 1) / 2) > minrc) {  // can make L or X or T which won't fit grid
            return true;
        }

        if (x == 1 || x == 2) {  // lose
            return false;
        }

        if (x == 3) {  // 3-omino
            return false;
        }

        if (x == 4) {  // 4-omino
            if (minrc == 2) {  // T is messing with parity
                return true;
            }
            return false;
        }

        if (x == 5) {
            return false;
        }

        if (x == 6) {
            if (minrc == 3) {  // other T is messing with parity
                return true;
            }
            return false;
        }

        return false;
    }
}
