import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by admin on 4/11/2015.
 */
public class TaskD {

    static void solveMultiTest() throws IOException {
        int testCases = nextInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            st = null;
            out.println("Case #" + testCase + ": " + solve());
        }
    }

    static String solve() throws IOException{
        int X = nextInt(), R = nextInt(), C = nextInt();
        String playerLose = "RICHARD", playerWin = "GABRIEL";

        if (X == 1) {
            return playerWin;
        }

        if ((R * C) % X != 0 || (R * C) < X) {
            return playerLose;
        }

        if ((R == 1 || C == 1) && X > 2) {
             return playerLose;
        }

        if (X == 4) {
            if ((R == 3 && C == 4) || (R == 4 && C == 3) || (R == 4 && C == 4)) {
                return playerWin;
            }
            return playerLose;
        }

       return playerWin;
    }


    static BufferedReader br;
    static StringTokenizer st;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        InputStream input = System.in;
        PrintStream output = System.out;
        File file = new File("gcj/a.in");
        if (file.exists() && file.canRead()) {
            input = new FileInputStream(file);
            output = new PrintStream(new File("a.out"));
        }
        br = new BufferedReader(new InputStreamReader(input));
        out = new PrintWriter(output);
        solveMultiTest();
        out.close();
    }

    static long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    static String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    static String nextLine() throws IOException {
        String line=null;
        line = br.readLine();
        System.out.println(line);
        return line;
    }

}
